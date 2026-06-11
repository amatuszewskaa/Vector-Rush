#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Obiekt.h"
#include "Gracz.h"

class Gra {
private:
    sf::RenderWindow window;
//WYMÓG 5: przechowywanie wszystkich obiektów gry w jednym kontenerze
//WYMÓG 11: wykorzystanie unigue_ptr
    std::vector<std::unique_ptr<Obiekt>> obiekty;
//WYMÓG 8: wykorzystanie wskaźników(surowy wskaźnik do nawigacji po kontenerze)    
Gracz* graczPtr;

    sf::Font font;
    sf::Text hudText;

    int punkty;
    int poziom;
    int maxWynik;
    float timerSpawnu;
//WYMÓG 15: parametryzacja gry(zmienna kontrolująca ilość przeciwników)
    int paramIloscPrzeszkod;

    void spawnPrzeciwnikow(float dt);
    void sprawdzKolizje();
    void wyczyscObiekty();
    void aktualizujHUD();

//WYMÓG 12 i 13: zapis i wczytanie stanu gry/tablicy wyników
    void zapiszStan();
    void wczytajStan();
    void zapiszWynik();
    void wczytajWynik();

    void dodajEksplozje(sf::Vector2f poz, sf::Color kol);

public:
    Gra();
    void uruchom();
};
