vector<int> topo_sort(int n, vector<int> *g){
    int i, j;
    int indegree[n + 3] = {};
    int v;
    queue<int> ind_zero;
    rep0(i, n){
        rep0(j, (int)g[i].size()){
            indegree[g[i][j]]++;
        }
    }
    rep0(i, n){
        if (indegree[i] == 0){
            ind_zero.push(i);
        }
    }

    vector<int> ans;
    while (ind_zero.empty() == false){
        v = ind_zero.front();
        ind_zero.pop();
        ans.push_back(v);
        rep0(i, (int)g[v].size()){
            indegree[g[v][i]]--;
            if (indegree[g[v][i]] == 0){
                ind_zero.push(g[v][i]);
            }
        }
    }
    return (ans);
}