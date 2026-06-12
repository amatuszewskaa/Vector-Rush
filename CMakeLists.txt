cmake_minimum_required(VERSION 3.10)
project(VectorRush)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


add_executable(${PROJECT_NAME}
    PROJEKT.cpp
    Gra.cpp
    Gracz.cpp
    Przeszkoda.cpp
    Bonus.cpp
    Czasteczka.cpp
)


target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
