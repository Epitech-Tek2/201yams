/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-201yams-clement.muth [WSL: Ubuntu]
** File description:
** utils
*/

#include <csignal>
#include "operand.hpp"

int display_help()
{
    std::string line;
    std::ifstream file("./help.txt");

    if (file) while (getline(file, line)) cOut(line);
    else std::raise(84);
    return (0);
}

std::vector<std::string> getCommands(std::string str, char c)
{
    std::vector<std::string> array;
    std::string tmp;

    std::replace(str.begin(), str.end(), c, ' ');
    std::stringstream ss(str);
    while (ss >> tmp) array.push_back(tmp);
    return array;
}

bool isNan(char const *str, int const option)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9') return (true);
    if (1 == option)
        if (atoi(str) < 1 || atoi(str) > 6) return (true);
    return (false);
}