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

class BIT {
private:
    int bit[N] = {};

public:
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & (-i);
        }
        return (s);
    }

    void add(int n, int i, int k) {
        while (i <= n) {
            bit[i] += k;
            i += i & (-i);
        }
    }

};