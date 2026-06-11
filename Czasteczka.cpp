#include "Czasteczka.h"
#include <cstdlib>
#include <cmath>

Czasteczka::Czasteczka(sf::Vector2f startPoz, sf::Color kol) : pozycja(startPoz), kolor(kol), czasZycia(0) {
   //WYMÓG 14: wprowadzenie losowości(losowy czas życia pojedynczej cząsteczki)
    maxCzasZycia = 0.5f + (std::rand() % 10) / 10.f;
    shape.setSize(sf::Vector2f(6.f, 6.f));
    shape.setOrigin(3.f, 3.f);
    shape.setPosition(pozycja);
    shape.setFillColor(kolor);

    //WYMÓG 14: wprowadzenie losowości(losowy kąt i szybkość)
    float kat = (std::rand() % 360) * 3.14159f / 180.f;
    float szybkosc = 100.f + std::rand() % 200;
    //WYMÓG 10: wykorzystanie rotacji/kątów do modelowania wektora ruchu
    predkosc = sf::Vector2f(std::cos(kat) * szybkosc, std::sin(kat) * szybkosc);
}

void Czasteczka::aktualizuj(float dt) {
    czasZycia += dt;
    //WYMÓG 10: wykorzystanie prędkości liniowej w pikselach/sekundę
    pozycja += predkosc * dt;
    shape.setPosition(pozycja);

    //WYMÓG 7: zastosowanie animacji(płynne znikanie cząsteczki w czasie)
    //WYMÓG 11: wykorzystanie rzutowania typów(static_cast)
    sf::Uint8 alpha = 255 - static_cast<sf::Uint8>((czasZycia / maxCzasZycia) * 255);
    kolor.a = alpha;
    shape.setFillColor(kolor);
}
void Czasteczka::rysuj(sf::RenderWindow& win) { win.draw(shape); }
sf::FloatRect Czasteczka::pobierzGranice() const { return sf::FloatRect(0, 0, 0, 0); }
bool Czasteczka::czyUsunac() const { return czasZycia >= maxCzasZycia; }
