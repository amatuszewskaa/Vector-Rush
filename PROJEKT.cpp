#include "Gra.h"
#include <ctime>
#include <cstdlib>

#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Gra gra;
    gra.uruchom();
    return 0;
}
