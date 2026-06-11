#include "Przeszkoda.h"

Przeszkoda::Przeszkoda(float startX, float startY, float predkoscX, float obrot) {
    shape.setSize(sf::Vector2f(40.f, 40.f));
    shape.setOrigin(20.f, 20.f);
    shape.setPosition(startX, startY);
    shape.setFillColor(sf::Color::Magenta);
    predkosc = sf::Vector2f(predkoscX, 0.f);
    predkoscObrotowa = obrot;
}

void Przeszkoda::aktualizuj(float dt) {
    //WYMÓG 10: wykorzystanie prędkości liniowej w pikselach/sekundę(mnożenie wektora przez dt)
    shape.move(predkosc * dt);
    //WYMÓG 10: wykorzystanie kątów i rotacji w mechanice(obrót obiektu)
    //WYMÓG 7: zastosowanie prostej animacji proceduralnej(ciągły ruch obrotowy przeszkody)
    shape.rotate(predkoscObrotowa * dt);
}
void Przeszkoda::rysuj(sf::RenderWindow& win) { win.draw(shape); }
sf::FloatRect Przeszkoda::pobierzGranice() const { return shape.getGlobalBounds(); }
bool Przeszkoda::czyUsunac() const { return shape.getPosition().x < -50.f; }
