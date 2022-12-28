class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto v : piles) pq.push(v);
        
        int ans = 0;
        for(auto v : piles) ans += v;
        for(int i = 0; i < k; i++){
            auto cur = pq.top(); pq.pop();
            ans -= cur/2;
            pq.push(cur - cur/2);
        }
        return ans;
    }
};