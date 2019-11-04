#include "Solver/solver.h"

int main() {
    char symbol = 'a';
    std::string regular;
    std::cin >> regular >> symbol;
    Solver s(symbol, regular);
    s.solve();
    s.printAns();
}