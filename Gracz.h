#pragma once
#include "Obiekt.h"

//WYMÓG 3: zastosowanie dziedziczenia
class Gracz : public Obiekt {
//WYMÓG 9: podział klas na pola private,public
private:
    sf::CircleShape shape;
    sf::Vector2f pozycja;
    sf::Vector2f predkosc;
    int hp;
    int maxHp;
    float czasNiewrazliwosci;
    float czasGry;

public:
    Gracz();

//WYMÓG 4: zasosowanie polimorfizmu(nadpisywanie metod wirtualnych)   
void aktualizuj(float dt) override;
    void rysuj(sf::RenderWindow& win) override;
    sf::FloatRect pobierzGranice() const override;
    bool czyUsunac() const override;

    int getHp() const { return hp; }
    void setHp(int noweHp) { hp = noweHp; }
    sf::Vector2f getPozycja() const { return pozycja; }
    void setPozycja(sf::Vector2f poz);

    void otrzymajObrazenia(int dmg);
    void lecz(int ile);
};
