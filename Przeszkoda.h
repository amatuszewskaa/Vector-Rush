#pragma once
#include "Obiekt.h"

//WYMÓG 3: zastosowanie dziedziczenia 
class Przeszkoda : public Obiekt {
//WYMÓG 9: podxiał klas 
private:
    sf::RectangleShape shape;
    sf::Vector2f predkosc;
    float predkoscObrotowa;

public:
    Przeszkoda(float startX, float startY, float predkoscX, float obrot);
//WYMÓG 4: zastosowanie polimorfizmu(nadpisywanie metod wirtualnych)
    void aktualizuj(float dt) override;
    void rysuj(sf::RenderWindow& win) override;
    sf::FloatRect pobierzGranice() const override;
    bool czyUsunac() const override;
};
