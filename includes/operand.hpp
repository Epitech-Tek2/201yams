/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-201yams-clement.muth [WSL: Ubuntu]
** File description:
** operand
*/

#ifndef OPERAND_HPP_
#define OPERAND_HPP_

#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <csignal>
#include <math.h>
#include "macro.hpp"
#include "error.hpp"

namespace yams
{
    class Operand
    {
        public:
            Operand(char **, std::vector<std::string>) noexcept;
            ~Operand() = default;

            double fullProcess();
            double same(int value);
            double straightProcess();
            int *getDice(char const *const *av);
            int checkTimes(int const value);
            void exec();
            static void raise(std::string const message, int stdout = 84);

        private:
            int *_dice;
            std::vector<std::string> _cmd;
    };
}

int display_help();
std::vector<std::string> getCommands(std::string str, char c);
bool isNan(char const *str, int const option);

static inline int fact(int value)
{
    int res = 1;

    for (int i = value; i >= 1; i--) res *= i;
    return (res);
}

#endif
