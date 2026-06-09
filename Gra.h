#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Obiekt.h"
#include "Gracz.h"

class Gra {
private:
    sf::RenderWindow window;
    std::vector<std::unique_ptr<Obiekt>> obiekty;
    Gracz* graczPtr;

    sf::Font font;
    sf::Text hudText;

    int punkty;
    int poziom;
    int maxWynik;
    float timerSpawnu;
    int paramIloscPrzeszkod;

    void spawnPrzeciwnikow(float dt);
    void sprawdzKolizje();
    void wyczyscObiekty();
    void aktualizujHUD();

    void zapiszStan();
    void wczytajStan();
    void zapiszWynik();
    void wczytajWynik();

    void dodajEksplozje(sf::Vector2f poz, sf::Color kol);

public:
    Gra();
    void uruchom();
};
