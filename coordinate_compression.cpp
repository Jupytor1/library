#include "my_defines.h"

void comp(int* a, int n) { //   vector : (int* a) -> (vector<int>& a)
    int i;
    set<int> s;
    vector<int> v;

    for (i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    for (auto& sg : s) {
        v.push_back(sg);
    }
    for (i = 0; i < n; i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
}