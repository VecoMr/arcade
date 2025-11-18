/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./arcade path_to_graphical_library.so" << std::endl;
        return 84;
    }
    srand(std::time(0));
    try {
        arcade::Core core(av[1]);
        core.run();
    } catch (arcade::ErrorH const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}