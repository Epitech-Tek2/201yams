/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-201yams-clement.muth [WSL: Ubuntu]
** File description:
** operand
*/

#include "operand.hpp"

yams::Operand::Operand(char **av, std::vector<std::string> array) noexcept
    : _dice(getDice(av)), _cmd(array) {}

void yams::Operand::raise(std::string const message, int stdout)
{
    std::cerr << message << std::endl;
    std::exit(stdout);
}

int yams::Operand::checkTimes(int const value)
{
    int s = 0;

    for (int i = 0; i <= 5; i++)
        if (value == _dice[i]) s++;
    return (s);
}

double yams::Operand::same(int value)
{
    int times = checkTimes(std::stoi(_cmd[1]));
    double res = 0;

    if (times >= value) return (100);
    for (double k = value - times; k <= SAME_N; k++) res += binomiale(SAME_N, k);
    return (res * 100);
}

double yams::Operand::straightProcess()
{
    int times = 0;

    for (int i = 2; i != 6; ++i)
        if (checkTimes(i) >= 1) times++;
    if (5 == std::stoi(_cmd[1]) && checkTimes(1) >= 1 ) times++;
    else if (6 == std::stoi(_cmd[1]) && checkTimes(6) >= 1) times++;
    return (STRAIGHT);
}

double yams::Operand::fullProcess()
{
    double nbPair = checkTimes(std::stoi(_cmd[2]));
    double nbBrelan = checkTimes(std::stoi(_cmd[1]));
    double bernBrelan = 0;

    full_assign(2, nbPair);
    full_assign(3, nbBrelan);
    if (2 == nbPair && 3 == nbBrelan) return (100);
    bernBrelan = FACT_PROCESS;
    return (bernBrelan / powf(6, 5 - nbBrelan - nbPair) * 100);
}

void yams::Operand::exec()
{
    std::string type[4] = {"pair", "three", "four", "yams"};
    std::string print[4] = {"Chances to get a %d pair: %.2f%%\n", "Chances to get a %d three-of-a-kind: %.2f%%\n", "Chances to get a %d four-of-a-kind: %.2f%%\n", "Chances to get a %d yams: %.2f%%\n"};

    for (int i = 0; i != 5; i++)
        if (type[i] == _cmd[0]) output(i);
    if ("full" == _cmd[0])
        printf("Chances to get a %d full of %d: %.2f%%\n", std::stoi(_cmd[1]), std::stoi(_cmd[2]), fullProcess());
    else if ("straight" == _cmd[0]) {
        assert(std::stoi(_cmd[1]) < 5, "Select a straight of 5 or 6 only", 84);
        printf("Chances to get a %d straight: %.2f%%\n", std::stoi(_cmd[1]), (float)straightProcess());
    } else yams::Operand::raise("The combinaison is invalid\n");
}

int *yams::Operand::getDice(char const *const *av)
{
    int *tab = new int[5];

    for (int i = 0; i < 5; i++) tab[i] = atoi(av[i + 1]);
    return (tab);
}