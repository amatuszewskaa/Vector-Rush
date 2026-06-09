#include "Gracz.h"
#include <cmath>

Gracz::Gracz() : hp(100), maxHp(100), czasNiewrazliwosci(0), czasGry(0) {
    shape.setRadius(20.f);
    shape.setOrigin(20.f, 20.f);
    shape.setFillColor(sf::Color::Cyan);
    pozycja = sf::Vector2f(200.f, 300.f);
    predkosc = sf::Vector2f(0.f, 0.f);
    shape.setPosition(pozycja);
}

void Gracz::aktualizuj(float dt) {
    czasGry += dt;

    if (czasNiewrazliwosci > 0) {
        czasNiewrazliwosci -= dt;
        if (static_cast<int>(czasNiewrazliwosci * 10) % 2 == 0)
            shape.setFillColor(sf::Color::Red);
        else
            shape.setFillColor(sf::Color(0, 255, 255, 128));
    }
    else {
        float radius = 20.f + std::sin(czasGry * 5.f) * 2.f;
        shape.setRadius(radius);
        shape.setOrigin(radius, radius);
        shape.setFillColor(sf::Color::Cyan);
    }

    sf::Vector2f przyspieszenie(0.f, 0.f);
    float sila = 2000.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) przyspieszenie.x -= sila;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) przyspieszenie.x += sila;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) przyspieszenie.y -= sila;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) przyspieszenie.y += sila;

    predkosc += przyspieszenie * dt;
    predkosc *= 0.95f;
    pozycja += predkosc * dt;

    if (pozycja.x < 20.f) { pozycja.x = 20.f; predkosc.x *= -0.5f; }
    if (pozycja.x > 780.f) { pozycja.x = 780.f; predkosc.x *= -0.5f; }
    if (pozycja.y < 20.f) { pozycja.y = 20.f; predkosc.y *= -0.5f; }
    if (pozycja.y > 580.f) { pozycja.y = 580.f; predkosc.y *= -0.5f; }

    shape.setPosition(pozycja);
}

void Gracz::rysuj(sf::RenderWindow& win) { win.draw(shape); }
sf::FloatRect Gracz::pobierzGranice() const { return shape.getGlobalBounds(); }
bool Gracz::czyUsunac() const { return false; }

void Gracz::otrzymajObrazenia(int dmg) {
    if (czasNiewrazliwosci <= 0) {
        hp -= dmg;
        czasNiewrazliwosci = 1.0f;
        predkosc.x -= 600.f;
    }
}

void Gracz::lecz(int ile) {
    hp += ile;
    if (hp > maxHp) hp = maxHp;
}

void Gracz::setPozycja(sf::Vector2f poz) {
    pozycja = poz;
    shape.setPosition(poz);
}
