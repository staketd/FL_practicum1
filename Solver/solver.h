#pragma once
#ifndef PRACT_1_SOLVER_H
#define PRACT_1_SOLVER_H

#include <string>
#include <iostream>

class Solver {
private:
    char symbol;
    std::string regular_expression;
    long long ans;
    static bool isLetter(char x);
public:
    Solver();
    Solver(const char &, std::string &);
    int solve();
    long long getAns() const;
    void printAns() const;
};

#endif //PRACT_1_SOLVER_H
