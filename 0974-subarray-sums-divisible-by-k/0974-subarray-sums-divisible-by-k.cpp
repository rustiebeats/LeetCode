class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        int cur = 0;
        int ans = 0;
        mp[0]++;
        for(auto v : nums){
            cur = ((cur + v) % k + k) % k;
            ans += mp[cur];
            mp[cur]++;
        }
        return ans;
    }
};