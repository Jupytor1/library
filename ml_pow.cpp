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