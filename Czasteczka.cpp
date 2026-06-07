#include "Czasteczka.h"
#include <cstdlib>
#include <cmath>

Czasteczka::Czasteczka(sf::Vector2f startPoz, sf::Color kol) : pozycja(startPoz), kolor(kol), czasZycia(0) {
    maxCzasZycia = 0.5f + (std::rand() % 10) / 10.f;
    shape.setSize(sf::Vector2f(6.f, 6.f));
    shape.setOrigin(3.f, 3.f);
    shape.setPosition(pozycja);
    shape.setFillColor(kolor);

    float kat = (std::rand() % 360) * 3.14159f / 180.f;
    float szybkosc = 100.f + std::rand() % 200;
    predkosc = sf::Vector2f(std::cos(kat) * szybkosc, std::sin(kat) * szybkosc);
}

void Czasteczka::aktualizuj(float dt) {
    czasZycia += dt;
    pozycja += predkosc * dt;
    shape.setPosition(pozycja);

    sf::Uint8 alpha = 255 - static_cast<sf::Uint8>((czasZycia / maxCzasZycia) * 255);
    kolor.a = alpha;
    shape.setFillColor(kolor);
}
void Czasteczka::rysuj(sf::RenderWindow& win) { win.draw(shape); }
sf::FloatRect Czasteczka::pobierzGranice() const { return sf::FloatRect(0, 0, 0, 0); }
bool Czasteczka::czyUsunac() const { return czasZycia >= maxCzasZycia; }
