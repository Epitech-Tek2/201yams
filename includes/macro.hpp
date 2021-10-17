/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-201yams-clement.muth [WSL: Ubuntu]
** File description:
** macro
*/

#pragma once

/* When possible, define assert so that it does not add extra
    parentheses around EXPR.  Otherwise, those added parentheses would
    suppress warnings we'd expect to be detected by gcc's -Wparentheses. */
#define assert(expr, message, output) (static_cast <bool> (expr) \
    ? yams::Operand::raise(message, output) : void (0))

#define cOut(message) std::cout << message << std::endl

#define binomiale(n, k) \
    (powf((1.0 / 6.0), k) * powf((1 - (1.0 / 6.0)), n - k) * fact(n) / (fact(k) * fact(n - k)))

#define STRAIGHT fact(5 - times) / pow(6, 5 - times) * 100

#define full_assign(n, v) (v = (n < v) ? (n) : (v))

#define FACT_PROCESS \
    fact(5 - nbBrelan - nbPair) / (fact(3 - nbBrelan) * fact((5 - nbBrelan - nbPair) - (3 - nbBrelan)))

#define output(i) ({ \
    printf(print[i].c_str(), std::stoi(_cmd[1]), same(i + 2)); \
    return; \
})

#define SAME_N 5 - times
