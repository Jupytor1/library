#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

ll ml_pow(ll n, ll k, int p) {
    ll y, res;

    res = 1;
    y = n;
    while (k > 0) {
        if (k % 2 == 1) {
            res = res * y % p;
        }
        y = y * y % p;
        k /= 2;
    }

    return res;
}