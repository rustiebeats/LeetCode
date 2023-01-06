class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cur = 0;
        int cnt = 0;
        for(int i = 0; i < costs.size(); i++){
            if(cur + costs[i] <= coins){
                cur += costs[i];
                cnt++;
            }
            else break;
        }
        return cnt;
    }
};