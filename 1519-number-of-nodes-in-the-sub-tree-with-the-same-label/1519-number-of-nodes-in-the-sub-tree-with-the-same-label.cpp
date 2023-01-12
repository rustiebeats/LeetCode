class Solution {
public:
    vector<int> go(int cur, int prev, const string& labels, vector<int> &ans){
        vector<int> cnt(26, 0);
        cnt[labels[cur] - 'a']++;
        for(auto nxt: adj[cur]){
            if(nxt == prev) continue;
            vector<int> child = go(nxt, cur, labels, ans);
            for(int i = 0; i < 26; i++){
                cnt[i] += child[i];
            }
        }
        ans[cur] = cnt[labels[cur] - 'a'];
        return cnt;
    }
    vector<int> adj[100004];
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(int i = 0; i < n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n);
        go(0, -1, labels, ans);
        return ans;
    }
};