#define N 200005

class segtree{
  private:
    int n;
    int dat[N * 4];

  public:
    int e(void){
        return INF;
    }

    int f(int x, int y){
        return min(x, y);
    }

    int init(int nn) {
        n = 1;
        while (n < nn)
            n *= 2;
        for (int i = 0; i < n * 2 - 1; i++)
            dat[i] = e();
        return (n);
    }

    void set_dat(int nn, int *a){
        int i;
        rep0(i, nn){
            dat[i + n - 1] = a[i];
        }
        for (i = n - 2; i >= 0; i--){
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    void update(int k, int a) {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
        return ;
    }

    ll query_first(int a, int b){
        return (query(a, b, 0, 0, n));
    }

    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return e();
        if (a <= l && r <= b) return dat[k];
        ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return (f(vl, vr));
    }

};