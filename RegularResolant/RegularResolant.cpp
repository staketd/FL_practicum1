#include "RegularResolant.h"
#include <algorithm>


RegularResolant::RegularResolant(char c): RegularResolant() {
    if (c == symbol) {
        max_suff = 1;
        max_pref = 1;
        ans = 1;
        full = true;
    }
    if (c == '1') {
        can_be_skipped = true;
    }
}

RegularResolant::RegularResolant(): max_pref(0), ans(0), max_suff(0), full(false), can_be_skipped(false) {}

RegularResolant RegularResolant::concatenate(const RegularResolant &r) const {
    RegularResolant res;
    if (full && r.full) {
        res.full = true;
        res.max_pref = max_pref + res.max_pref;
        res.max_suff = max_pref + res.max_pref;
        res.ans = ans + res.ans;
    } else {
        res.max_pref = max_pref;
        res.max_suff = r.max_suff;
        res.ans = std::max({ans, res.ans, max_suff + r.max_pref});
    }
    if (can_be_skipped) {
        res.max_pref = std::max(r.max_pref, res.max_pref);
    }
    if (r.can_be_skipped) {
        res.max_suff = std::max(res.max_suff, max_suff);
    }
    res.can_be_skipped = can_be_skipped && r.can_be_skipped;
    return res;
}

RegularResolant RegularResolant::add(const RegularResolant &r) const {
    RegularResolant res;
    res.full = std::max(r.full, full);
    res.max_pref = std::max(max_pref, r.max_pref);
    res.max_suff = std::max(max_suff, r.max_suff);
    res.ans = std::max(ans, r.ans);
    res.can_be_skipped = can_be_skipped | r.can_be_skipped;
    return res;
}

RegularResolant RegularResolant::clini_star() const {
    RegularResolant res;
    if (full) {
        res.max_suff = INF;
        res.max_pref = INF;
        res.ans = INF;
    } else {
        res.max_pref = max_pref;
        res.max_suff = max_suff;
        res.ans = std::max(ans, max_suff + max_pref);
    }
    res.can_be_skipped = true;
    return res;
}

long long RegularResolant::getAns() const {
    return ans;
}

char RegularResolant::symbol;

