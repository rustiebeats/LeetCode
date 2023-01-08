class Solution {
public:
    int maxPoints(vector<vector<int>>& points){
        int N =points.size();
        if(N == 1) return 1;
        if(N == 2) return 2;
        int ans = 2;
        for(int i = 0; i < N; i++){
            unordered_map<long double, int> mp;
            for(int j = 0; j < N; j++){
                if(i == j) continue;
                if(points[i][0] == points[j][0]) mp[1e9]++;
                else{
                    long double tmp = ((long double)points[j][1] - (long double)points[i][1]) / ((long double)points[j][0]-(long double)points[i][0]);
                    mp[tmp]++;
                }
            }
            for(auto [k, v]: mp){
                ans = max(ans, v+1);
            }
        }
        return ans;
    }
};