#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

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