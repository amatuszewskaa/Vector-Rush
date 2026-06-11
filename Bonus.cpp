#include "Bonus.h"
#include <cmath>

Bonus::Bonus(float startX, float startY) : czas(0), zebrany(false) {
    shape.setRadius(15.f);
    shape.setOrigin(15.f, 15.f);
    pozycjaStartowa = sf::Vector2f(startX, startY);
    shape.setPosition(pozycjaStartowa);
    shape.setFillColor(sf::Color::Green);
    predkoscX = -150.f;
}

void Bonus::aktualizuj(float dt) {
    czas += dt;
    //WYMÓG 10: wykorzystanie prędkości liniowej w pikselach/sekundę(mnożenie przez dt)
    float noweX = shape.getPosition().x + predkoscX * dt;
    //WYMÓG 18: kreatywne rozwiązanie-ruch obiektu po sinusoidzie
    float noweY = pozycjaStartowa.y + std::sin(czas * 3.f) * 60.f;
    shape.setPosition(noweX, noweY);
}
void Bonus::rysuj(sf::RenderWindow& win) { win.draw(shape); }
sf::FloatRect Bonus::pobierzGranice() const { return shape.getGlobalBounds(); }
bool Bonus::czyUsunac() const { return zebrany || shape.getPosition().x < -50.f; }
