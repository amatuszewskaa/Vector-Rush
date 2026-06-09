#pragma once
#include <SFML/Graphics.hpp>

// Abstrakcyjna klasa bazowa - po niej dziedzicz¹ wszystkie obiekty w grze
class Obiekt {
public:
    virtual ~Obiekt() = default;

    virtual void aktualizuj(float dt) = 0;
    virtual void rysuj(sf::RenderWindow& win) = 0;
    virtual sf::FloatRect pobierzGranice() const = 0;
    virtual bool czyUsunac() const = 0;
};