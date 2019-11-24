#include "solver.h"
#include "RegularResolant.h"
#include <vector>
#include <WrongNotationException.h>

int Solver::solve() {
    if (!isLetter(symbol)) {
        throw WrongNotationException();
    }
    RegularResolant::symbol = symbol;
    std::vector<RegularResolant> stack;
    int n = regular_expression.size();
    for (int i = 0; i < n; ++i) {
        char x = regular_expression[i];
        if (isLetter(x) || x == '1') {
            RegularResolant r(x);
            stack.push_back(r);
            continue;
        }
        if (x == '*') {
            if (stack.empty()) {
                throw WrongNotationException();
            }
            RegularResolant a = stack.back();
            stack.pop_back();
            stack.push_back(a.kleene_star());
            continue;
        }
        if (x == '+') {
            if (stack.size() < 2) {
                throw WrongNotationException();
            }
            RegularResolant b = stack.back();
            stack.pop_back();
            RegularResolant a = stack.back();
            stack.pop_back();
            stack.push_back(a.add(b));
            continue;
        }
        if (x == '.') {
            if (stack.size() < 2) {
                throw WrongNotationException();
            }
            RegularResolant b = stack.back();
            stack.pop_back();
            RegularResolant a = stack.back();
            stack.pop_back();
            stack.push_back(a.concatenate(b));
            continue;
        }
        throw WrongNotationException();
    }
    if (stack.size() != 1) {
        throw WrongNotationException();
    }
    ans = stack[0].getAns();
    return 0;
}

bool Solver::isLetter(char x) {
    return (x >= 'a' && x <= 'c');
}

Solver::Solver() {
    symbol = 'a';
    ans = 0;
}

Solver::Solver(const char &symb, std::string &expr) {
    symbol = symb;
    regular_expression = expr;
    ans = 0;
}

void Solver::printAns() const {
    if (ans >= RegularResolant::INF) {
        std::cout << "INF\n";
    } else {
        std::cout << ans << "\n";
    }
}

long long Solver::getAns() const {
    return ans;
}


