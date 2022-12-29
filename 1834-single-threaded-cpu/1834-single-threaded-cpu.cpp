class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int N = tasks.size();
        for(int i = 0; i < N; i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        
        vector<int> ret;
        long long int tt = tasks[0][0];
        int idx = 0;
        while(!pq.empty() || idx < N){
            while(idx < N && tt >= tasks[idx][0]){
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
            if(pq.empty()){
                tt = tasks[idx][0];
            }
            else{
                auto cur = pq.top();
                pq.pop();
                ret.push_back(cur.second);
                tt += cur.first;
            }
        }
        return ret;
    }
};