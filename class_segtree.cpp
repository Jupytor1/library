#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define N 100005

class segtree{
private:
    int dat[N * 4];

public:
    int seginit(int n_) {
        int n = 1;
        while (n < n_)
            n *= 2;
        for (int i = 0; i < n * 2 - 1; i++)
            dat[i] = INF;
        return (n);
    }

    void update(int n, int k, int a) {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            if (dat[k] <= a)
                return ;
            dat[k] = a;
        }
        return ;
    }

    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return (1e9);
        if (a <= l && r <= b) return (dat[k]);
        ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return (min(vl, vr));
    }

};