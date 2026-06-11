#pragma once
#include <SFML/Graphics.hpp>

//WYMÓG 3: zastosowanie dziedziczenia(Obiekt to abstrakcyjna klasa bazowa dla wszystkich elementów gry)
class Obiekt {
public:
//wirtualny destruktor
    virtual ~Obiekt() = default;

//WYMÓG 4: zastosowanie polimorfizmu(funkcje czysto wirtualne definiujące wspólny interfejs)
    virtual void aktualizuj(float dt) = 0;
    virtual void rysuj(sf::RenderWindow& win) = 0;
    virtual sf::FloatRect pobierzGranice() const = 0;
    virtual bool czyUsunac() const = 0;
};
