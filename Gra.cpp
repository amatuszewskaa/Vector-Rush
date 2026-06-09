#include "Gra.h"
#include "Przeszkoda.h"
#include "Bonus.h"
#include "Czasteczka.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>

Gra::Gra() : window(sf::VideoMode(800, 600), L"Vector Rush"), punkty(0), poziom(1), timerSpawnu(0), paramIloscPrzeszkod(2) {
    window.setFramerateLimit(60);

    auto gracz = std::make_unique<Gracz>();
    graczPtr = gracz.get();
    obiekty.push_back(std::move(gracz));

    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        std::cerr << "Nie udalo sie zaladowac czcionki\n";
    }

    hudText.setFont(font);
    hudText.setCharacterSize(20);
    hudText.setFillColor(sf::Color::White);
    hudText.setPosition(10.f, 10.f);

    wczytajWynik();
}

void Gra::uruchom() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) zapiszStan();
                if (event.key.code == sf::Keyboard::L) wczytajStan();
            }
        }

        if (graczPtr && graczPtr->getHp() > 0) {
            static float timerPunktow = 0;
            timerPunktow += dt;
            if (timerPunktow > 0.5f) {
                punkty++;
                timerPunktow = 0;
                if (punkty > 0 && punkty % 50 == 0) {
                    poziom++;
                    paramIloscPrzeszkod++;
                }
            }
            spawnPrzeciwnikow(dt);
        }
        else if (graczPtr && graczPtr->getHp() <= 0) {
            zapiszWynik();
        }

        for (auto& obj : obiekty) {
            obj->aktualizuj(dt);
        }

        sprawdzKolizje();
        wyczyscObiekty();
        aktualizujHUD();

        sf::Color kolorTla(10, 10, 10 + (poziom * 10) % 50);
        window.clear(kolorTla);

        for (auto& obj : obiekty) {
            obj->rysuj(window);
        }
        window.draw(hudText);
        window.display();
    }
}

void Gra::spawnPrzeciwnikow(float dt) {
    timerSpawnu += dt;
    float czestotliwosc = 2.0f / (float)poziom;

    if (timerSpawnu > czestotliwosc) {
        timerSpawnu = 0;

        for (int i = 0; i < paramIloscPrzeszkod % 5 + 1; i++) {
            float startY = 50.f + std::rand() % 500;
            float predkoscX = -100.f - (std::rand() % 150) - (poziom * 20.f);
            float obrot = (std::rand() % 180) - 90.f;
            obiekty.push_back(std::make_unique<Przeszkoda>(850.f, startY, predkoscX, obrot));
        }

        if (std::rand() % 100 < 15) {
            float startY = 100.f + std::rand() % 400;
            obiekty.push_back(std::make_unique<Bonus>(850.f, startY));
        }
    }
}

void Gra::sprawdzKolizje() {
    if (!graczPtr || graczPtr->getHp() <= 0) return;
    sf::FloatRect rGracza = graczPtr->pobierzGranice();

    for (auto& obj : obiekty) {
        if (obj.get() == graczPtr) continue;

        if (Przeszkoda* p = dynamic_cast<Przeszkoda*>(obj.get())) {
            if (rGracza.intersects(p->pobierzGranice())) {
                graczPtr->otrzymajObrazenia(20);
                dodajEksplozje(graczPtr->getPozycja(), sf::Color::Red);
            }
        }
        else if (Bonus* b = dynamic_cast<Bonus*>(obj.get())) {
            if (rGracza.intersects(b->pobierzGranice())) {
                graczPtr->lecz(20);
                punkty += 25;
                b->oznaczZebrany();
                dodajEksplozje(graczPtr->getPozycja(), sf::Color::Green);
            }
        }
    }
}

void Gra::wyczyscObiekty() {
    obiekty.erase(std::remove_if(obiekty.begin(), obiekty.end(),
        [](const std::unique_ptr<Obiekt>& obj) { return obj->czyUsunac(); }),
        obiekty.end());
}

void Gra::dodajEksplozje(sf::Vector2f poz, sf::Color kol) {
    for (int i = 0; i < 15; i++) {
        obiekty.push_back(std::make_unique<Czasteczka>(poz, kol));
    }
}

void Gra::aktualizujHUD() {
    if (!graczPtr) return;
    if (graczPtr->getHp() <= 0) {
        std::wstring infoKoniec = L"KONIEC GRY! Twoj wynik: " + std::to_wstring(punkty) + L"\nZrestartuj program by zagrac ponownie.";
        hudText.setString(infoKoniec);
        hudText.setFillColor(sf::Color::Red);
    }
    else {
        std::wstring info = L"Punkty: " + std::to_wstring(punkty) +
            L" | HP: " + std::to_wstring(graczPtr->getHp()) +
            L" | Poziom: " + std::to_wstring(poziom) +
            L"\nNajlepszy wynik z pliku: " + std::to_wstring(maxWynik) +
            L"\n[S] Zapisz   [L] Wczytaj";
        hudText.setString(info);
    }
}

void Gra::zapiszStan() {
    if (!graczPtr || graczPtr->getHp() <= 0) return;
    std::ofstream plik("stan_gry.txt");
    if (plik.is_open()) {
        plik << punkty << " " << poziom << " " << paramIloscPrzeszkod << "\n";
        plik << graczPtr->getHp() << " " << graczPtr->getPozycja().x << " " << graczPtr->getPozycja().y << "\n";
        plik.close();
    }
}

void Gra::wczytajStan() {
    if (!graczPtr) return;
    std::ifstream plik("stan_gry.txt");
    if (plik.is_open()) {
        plik >> punkty >> poziom >> paramIloscPrzeszkod;
        int hp; float x, y;
        plik >> hp >> x >> y;
        graczPtr->setHp(hp);
        graczPtr->setPozycja(sf::Vector2f(x, y));
        plik.close();
    }
}

void Gra::zapiszWynik() {
    if (punkty > maxWynik) {
        maxWynik = punkty;
        std::ofstream plik("wyniki.txt");
        if (plik.is_open()) {
            plik << maxWynik;
            plik.close();
        }
    }
}

void Gra::wczytajWynik() {
    std::ifstream plik("wyniki.txt");
    if (plik.is_open()) {
        plik >> maxWynik;
        plik.close();
    }
    else {
        maxWynik = 0;
    }
}