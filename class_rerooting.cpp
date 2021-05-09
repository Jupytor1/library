#define V 200003

class rerooting{
  private:
    vector<P> g[V];
    vector<int> v1[V], v2[V];

  public:
    void add_directed_edge(int u, int v, int c){
        g[u].push_back(P(v, c));
        v1[u].push_back(0);
        v2[u].push_back(0);
    }

    void add_nondirected_edge(int u, int v, int c){
        add_directed_edge(u, v, c);
        add_directed_edge(v, u, c);
    }

    int dfs1(int v, int par){
        int i;
        int res;
        res = 0;
        rep0(i, (int)g[v].size()){
            if (g[v][i].first == par){
                continue;
            }
            v1[v][i] = dfs1(g[v][i].first, v) + g[v][i].second;
            v2[v][i] = v1[v][i];
            res += v1[v][i];
        }
        return (res);
    }

    void dfs2(int v, int par){
        int i;
        if (v != 0){
            rep0(i, (int)g[v].size()){
                if (g[v][i].first == par){
                    val += g[v][i].second;
                    v1[v][i] = val;
                    v2[v][i] = val;
                    break;
                }
            }
        }
        rep1(i, 1, (int)g[v].size()){
            v1[v][i] += v1[v][i - 1];
        }
        for (i = g[v].size() - 2; i >= 0; i--){
            v2[v][i] += v2[v][i + 1];
        }

        ll nval;
        rep0(i, (int)g[v].size()){
            if (g[v][i].first == par){
                continue;
            }
            nval = 0;
            if (i > 0){
                nval += v1[v][i - 1];
            }
            if (i < (int)g[v].size() - 1){
                nval += v2[v][i + 1];
            }
            dfs2(g[v][i].first, v, nval);
        }
    }

    void calc(void){
        dfs1(0, -1);
        dfs2(0, -1);
    }

    ll value(int v){
        return (v2[v][0]);
    }

};