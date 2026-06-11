#pragma once
#include "Obiekt.h"

//WYMÓG 3: zastosowanie dziedziczenia
class Bonus : public Obiekt {
//WYMÓG 9: podział klas na pola public,protected,private
private:
    sf::CircleShape shape;
    sf::Vector2f pozycjaStartowa;
    float czas;
    float predkoscX;
    bool zebrany;

public:
    Bonus(float startX, float startY);
//WYMÓG 4: zastosowanie polimorfizmu
    void aktualizuj(float dt) override;
    void rysuj(sf::RenderWindow& win) override;
    sf::FloatRect pobierzGranice() const override;
    bool czyUsunac() const override;
    void oznaczZebrany() { zebrany = true; }
};
