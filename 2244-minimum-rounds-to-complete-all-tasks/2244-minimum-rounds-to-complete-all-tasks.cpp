class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // sort(tasks.begin(), tasks.end());
        map<int, int> mp;
        for(auto v : tasks) mp[v]++;
        int ans = 0;
        
        for(auto &[k, v]: mp){
            if(v == 1) return -1;
            else{
                if(v % 3 == 0) ans += v/3;
                else if(v % 3 == 1) ans += v/3 + 1;
                else ans += v/3 + 1;
            }
        }
        return ans;
    }
};