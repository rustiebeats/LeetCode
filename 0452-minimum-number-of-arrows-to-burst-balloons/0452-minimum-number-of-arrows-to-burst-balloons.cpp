class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        // int cur = points[0].second;
        int cur = points[0][1];
        int ans = 1;
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > cur){
                ans++;
                cur = points[i][1];
            }
            else cur = min(cur, points[i][1]);
        }
        return ans;
    }
};