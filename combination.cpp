#include "my_defines.h"

#define N 100005
ll fac[N], inv[N], finv[N];

void cominit(int n) {
    int i;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (i = 2; i < n + 2; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
    return;
}

ll com(int n, int r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    return (fac[n] * finv[r]) % mod * finv[n - r] % mod;
}