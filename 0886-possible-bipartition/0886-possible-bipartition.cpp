class Solution {
public:
    int parent[2004];
    vector<int> adj[2004];
    
    int find(int n){
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        parent[u] = v;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i = 0; i <= n; i++) parent[i] = i;
        for(auto v : dislikes){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(int i = 1; i <= n; i++){
            for(auto nxt : adj[i]){
                if(find(i) == find(nxt)) return false;
                merge(adj[i][0], nxt);
            }
        }
        return true;
    }
};