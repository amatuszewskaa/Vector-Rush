#pragma once
#include "Obiekt.h"

class Bonus : public Obiekt {
private:
    sf::CircleShape shape;
    sf::Vector2f pozycjaStartowa;
    float czas;
    float predkoscX;
    bool zebrany;

public:
    Bonus(float startX, float startY);
    void aktualizuj(float dt) override;
    void rysuj(sf::RenderWindow& win) override;
    sf::FloatRect pobierzGranice() const override;
    bool czyUsunac() const override;
    void oznaczZebrany() { zebrany = true; }
};
