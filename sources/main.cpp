/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-201yams-clement.muth [WSL: Ubuntu]
** File description:
** main
*/

#include "operand.hpp"

static void error_handling(int const ac, char const * const *av)
{
    assert(7 != ac, INVALID_NBR_ARG, 84);
    for (int i = 1; i <= 5; i++) {
        assert(isNan(av[i], 0), std::string(NOT_NBR), 84);
        assert(atoi(av[i]) < 0 || atoi(av[i]) > 6, DICE_INVALID, 84);
    }
}

int main(int ac, char **av)
{
    std::vector<std::string> cmd;

    if (ac == 2 && strcmp(av[1], "-h") == 0) return (display_help());
    error_handling(ac, av);
    cmd = getCommands(av[6], '_');
    assert(cmd[0] == "full" && cmd.size() != 3, FULL_MISSING_ARG, 84);
    assert(cmd.size() != 2 && cmd[0] != "full", INVALID_ARG, 84);
    assert(isNan(cmd[1].c_str(), 1) || (cmd[0] == "full" && isNan(cmd[2].c_str(), 1)), BAD_CMD, 84);
    assert(cmd[0] == "full" && stoi(cmd[1]) == stoi(cmd[2]), SAME_ARG, 84);
    yams::Operand calc(av, cmd);
    calc.exec();
    return (0);
}