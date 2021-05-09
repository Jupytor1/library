#define N 100003

class dijkstra {
  private:
    int n;
    vector<int> d = vector<int>(N);
    vector<P> g[N];

  public:
    void init(int nn){
        int i;
        n = nn;
    }

    void add_directed_edge(int u, int v, int c){
        g[u].push_back(P(v, c));
    }

    void add_nondirected_edge(int u, int v, int c){
        g[u].push_back(P(v, c));
        g[v].push_back(P(u, c));
    }

    vector<int> calc_d(int start){
        int i;
        priority_queue<P, vector<P>, greater<P>> pq;
        P p;
        int c, v;
        int nv, nc;

        rep0(i, n){
            d[i] = INF;
        }
        d[start] = 0;
        pq.push(P(0, start));
        while (pq.empty() == false){
            p = pq.top();
            pq.pop();
            c = p.first;
            v = p.second;
            if (d[v] < c){
                continue;
            }
            rep0(i, g[v].size()){
                nv = g[v][i].first;
                nc = g[v][i].second;
                if (d[nv] > d[v] + nc){
                    d[nv] = d[v] + nc;
                    pq.push(P(d[nv], nv));
                }
            }
        }

        return (d);
    }

};