#include "RegularResolant.h"
#include <algorithm>


RegularResolant::RegularResolant(char c) : RegularResolant() {
    if (c == symbol) {
        max_suff = 1;
        max_pref = 1;
        ans = 1;
        contains_full = true;
        full_length = 1;
    }
    if (c == '1') {
        contains_empty = true;
    }
}

RegularResolant::RegularResolant() : max_pref(0), ans(0), max_suff(0), contains_full(false), contains_empty(false), full_length(0) {}

RegularResolant RegularResolant::concatenate(const RegularResolant &r) const {
    RegularResolant res;

    res.contains_full = (contains_full && r.contains_full) || (contains_full && r.contains_empty) || (r.contains_full && contains_empty);

    res.max_pref = max_pref;
    res.max_suff = max_suff;
    res.ans = std::max({ans, r.ans, max_suff + r.max_pref});

    if (contains_full) {
        res.max_pref = std::max(res.max_pref, r.max_pref + full_length);
    }

    if (r.contains_full) {
        res.max_suff = std::max(res.max_suff, max_suff + r.full_length);
    }

    if (contains_full && r.contains_full) {
        res.full_length = full_length + r.full_length;
    }

    if (contains_empty) {
        res.max_pref = std::max(r.max_pref, res.max_pref);
    }

    if (r.contains_empty) {
        res.max_suff = std::max(res.max_suff, max_suff);
    }

    res.contains_empty = contains_empty && r.contains_empty;
    return res;
}

RegularResolant RegularResolant::add(const RegularResolant &r) const {
    RegularResolant res;
    res.contains_full = contains_full || r.contains_full;

    if (contains_full) {
        res.full_length = full_length;
    }

    if (r.contains_full) {
        res.full_length = std::max(res.full_length, r.full_length);
    }

    res.max_pref = std::max(max_pref, r.max_pref);
    res.max_suff = std::max(max_suff, r.max_suff);
    res.ans = std::max(ans, r.ans);
    res.contains_empty = contains_empty || r.contains_empty;
    return res;
}

RegularResolant RegularResolant::clini_star() const {
    RegularResolant res;
    if (contains_full) {
        res.max_suff = INF;
        res.max_pref = INF;
        res.ans = INF;
        res.full_length = INF;
        res.contains_full = true;
    } else {
        res.max_pref = max_pref;
        res.max_suff = max_suff;
        res.ans = std::max(ans, max_suff + max_pref);
    }
    res.contains_empty = true;
    return res;
}

long long RegularResolant::getAns() const {
    return ans;
}

char RegularResolant::symbol;

