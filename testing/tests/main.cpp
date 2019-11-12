#include "gtest/gtest.h"
#include <RegularResolant.h>
#include <solver.h>
#include <string>
#include <WrongNotationException.h>

TEST(testIncorrectInput, input1) {
    std::string reg = "ab++";
    char symbol = 'a';
    Solver solve(symbol, reg);
    try {
        solve.solve();
    } catch (WrongNotationException &e) {
        SUCCEED();
    }
}

TEST(testIncorrectInput, input2) {
    std::string reg = "ab+-";
    char symbol = 'a';
    Solver solve(symbol, reg);
    try {
        solve.solve();
    } catch (WrongNotationException &e) {
        SUCCEED();
    }
}


TEST(testIncorrectInput, input3) {
    std::string reg = "ab+*+";
    char symbol = 'a';
    Solver solve(symbol, reg);
    try {
        solve.solve();
    } catch (WrongNotationException &e) {
        SUCCEED();
    }
}


TEST(testIncorrectInput, input4) {
    std::string reg = "*";
    char symbol = 'a';
    Solver solve(symbol, reg);
    try {
        solve.solve();
    } catch (WrongNotationException &e) {
        SUCCEED();
    }
}

TEST(testCorrectSolution, Test0_1) {
    std::string reg = "acb..bab.c.*.ab.ba.+.+*a.";
    char symbol = 'a';
    Solver solve(symbol, reg);
    solve.solve();
    EXPECT_EQ(solve.getAns(), 2);
}

TEST(testCorrectSolution, Test0_2) {
    std::string reg = "ab+c.aba.*.bac.+.+*";
    char symbol = 'a';
    Solver solve(symbol, reg);
    solve.solve();
    EXPECT_EQ(solve.getAns(), 2);
}

TEST(testCorrectSolution, Test1) {
    std::string reg = "a*b*+";
    char symbol = 'a';
    Solver solve(symbol, reg);
    solve.solve();
    EXPECT_GE(solve.getAns(), RegularResolant::INF);
}

TEST(testCorrectSolution, Test2) {
    std::string reg = "a*b*+";
    char symbol = 'a';
    Solver solve(symbol, reg);
    solve.solve();
    EXPECT_GE(solve.getAns(), RegularResolant::INF);
}

TEST(testCorreectSolution, Test3) {
    std::string reg = "ab*.a.";
    char symbol = 'a';
    Solver solve(symbol, reg);
    solve.solve();
    EXPECT_EQ(solve.getAns(), 2);
}

TEST(testCorrectSolution, Test4) {
    std::string reg = "ab.ba.+*a.";
    char symbol = 'a';
    Solver solve(symbol, reg);
    solve.solve();
    EXPECT_EQ(solve.getAns(), 2);
}

TEST(testCorrectSolution, Test5) {
    std::string reg = "ab.*";
    char symbol = 'a';
    Solver solve(symbol, reg);
    solve.solve();
//    EXPECT_GE(solve.getAns(), RegularResolant::INF);
    EXPECT_EQ(solve.getAns(), 1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}