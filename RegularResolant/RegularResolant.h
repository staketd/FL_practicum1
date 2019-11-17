#ifndef PRACT_1_REGULARRESOLANT_H
#define PRACT_1_REGULARRESOLANT_H
#pragma once

class RegularResolant {
    long long max_pref, max_suff, ans, full_length;
    bool contains_full, contains_empty;
public:
    const static long long INF = 1e15;
    static char symbol;

    RegularResolant();
    explicit RegularResolant(char c);

    RegularResolant concatenate(const RegularResolant &r) const;
    RegularResolant add(const RegularResolant &r) const;
    RegularResolant kleene_star() const;

    long long getAns() const;
};


#endif //PRACT_1_REGULARRESOLANT_H