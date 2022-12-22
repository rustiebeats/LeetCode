class Solution {
public:
    vector<vector<int> > adj;
    
    int cnt[30004];
    int ans[30004];
    
    void go(int cur, int pre){
        for(auto nxt: adj[cur]){
            if(nxt == pre) continue;
            go(nxt, cur);
            cnt[cur] += cnt[nxt];
            ans[cur] += ans[nxt];
            ans[cur] += cnt[nxt];
        }
        cnt[cur]++;
    }
    
    void gogo(int cur, int ccnt, int pre){
        for(auto nxt: adj[cur]){
            if(nxt == pre) continue;
            ans[nxt] = ans[cur] + ccnt - 2 * cnt[nxt];
            gogo(nxt, ccnt, cur);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        go(0, -1);
        gogo(0, n, -1);
        vector<int> ret;
        for(int i = 0; i < n; i++) ret.push_back(ans[i]);
        return ret;
    }
};