class Solution {
public:
    vector<int> adj[100004];
    long long int go(int cur, int prev, vector<bool>& hasApple){
        long long int ret = 0;
        for(auto nxt: adj[cur]){
            if(nxt == prev) continue;
            long long int tmp = go(nxt, cur, hasApple);
            if(tmp > 0) ret += (tmp + 2);
            else if(hasApple[nxt]) ret += (tmp + 2);
        }

        return ret;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(int i = 0; i < n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return go(0, -1, hasApple);
    }
};