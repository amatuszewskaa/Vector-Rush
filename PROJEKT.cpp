#include "Gra.h"
#include <ctime>
#include <cstdlib>
//do linkowania biblioteki SFML w visual studio
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")


int main() {
    //WYMÓG 14: inicjalizacja generatora liczb pseudolosowych 
    //WYMÓG 11: zastosowanie rzutowania typów(static_cast)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Gra gra;
    gra.uruchom();
    return 0;
}
