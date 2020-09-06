#include "my_defines.h"

#define N 100005

class unionfind {
private:
    int par[N] = {}, r[N] = {}, size[N] = {};

public:
    unionfind(int n) {
        int i;
        for (i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int root(int a) {
        if (par[a] == a) return (a);
        return (par[a] = root(par[a]));
    }

    void unite(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return ;
        if (r[a] > r[b]) {
            par[b] = a;
            r[a]++;
            size[a] += size[b];
        }
        else {
            par[a] = b;
            r[b]++;
            size[b] += size[a];
        }
    }

    int show_size(int a) {
        return (size[root(a)]);
    }

    int num_group(int n) {
        int i, t, res = 0;
        bool u[N] = { false };
        for (i = 0; i < n; i++) {
            t = root(i);
            if (!u[t]) {
                res++;
                u[t] = true;
            }
        }
        return (res);
    }

    bool is_root(int a) {
        return (par[a] == a);
    }

};