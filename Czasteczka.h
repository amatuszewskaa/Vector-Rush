#pragma once
#include "Obiekt.h"

//WYMÓG 3: zastosowanie dziedziczenia 
class Czasteczka : public Obiekt {
//WYMÓG 9: podział klas na pola private,protected,public
private:
    sf::RectangleShape shape;
    sf::Vector2f pozycja;
    sf::Vector2f predkosc;
    float czasZycia;
    float maxCzasZycia;
    sf::Color kolor;

public:
    Czasteczka(sf::Vector2f startPoz, sf::Color kol);
//WYMÓG 4: zastosowanie polimorfizmu
    void aktualizuj(float dt) override;
    void rysuj(sf::RenderWindow& win) override;
    sf::FloatRect pobierzGranice() const override;
    bool czyUsunac() const override;
};
