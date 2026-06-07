#pragma once
#include "Obiekt.h"

class Czasteczka : public Obiekt {
private:
    sf::RectangleShape shape;
    sf::Vector2f pozycja;
    sf::Vector2f predkosc;
    float czasZycia;
    float maxCzasZycia;
    sf::Color kolor;

public:
    Czasteczka(sf::Vector2f startPoz, sf::Color kol);
    void aktualizuj(float dt) override;
    void rysuj(sf::RenderWindow& win) override;
    sf::FloatRect pobierzGranice() const override;
    bool czyUsunac() const override;
};