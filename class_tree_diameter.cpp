#define N 100003

class tree_diameter{
  private:
    vector<int> g[N];

  public:
    void add_edge(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }

    P maxdepth(int v, int par){
        int i;
        P res, chr;
        res = P(0, v);
        rep0(i, g[v].size()){
            if (g[v][i] != par){
                chr = maxdepth(g[v][i], v);
                chr.first++;
                if (res.first < chr.first){
                    res = chr;
                }
            }
        }
        return (res);
    }

    int diameter(int *u, int *v){
        P res1, res2;
        res1 = maxdepth(0, -1);
        res2 = maxdepth(res1.second, -1);
        *u = res1.second;
        *v = res2.second;
        return (res2.first);
    }

    int diameter(){
        P res1, res2;
        res1 = maxdepth(0, -1);
        res2 = maxdepth(res1.second, -1);
        return (res2.first);
    }

};