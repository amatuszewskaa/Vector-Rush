#pragma once
#include "Obiekt.h"

class Gracz : public Obiekt {
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