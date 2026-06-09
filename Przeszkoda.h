#pragma once
#include "Obiekt.h"

class Przeszkoda : public Obiekt {
private:
    sf::RectangleShape shape;
    sf::Vector2f predkosc;
    float predkoscObrotowa;

public:
    Przeszkoda(float startX, float startY, float predkoscX, float obrot);
    void aktualizuj(float dt) override;
    void rysuj(sf::RenderWindow& win) override;
    sf::FloatRect pobierzGranice() const override;
    bool czyUsunac() const override;
};