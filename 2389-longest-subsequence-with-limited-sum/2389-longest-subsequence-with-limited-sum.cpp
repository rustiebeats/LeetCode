class Solution {
public:
    vector<int> psum;
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        psum.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            psum.push_back(nums[i]+psum[i-1]);   
        }
        vector<int> res(m);
        for(int i = 0; i < m; i++){
            res[i] = upper_bound(psum.begin(), psum.end(), queries[i]) - psum.begin();
        }
        return res;
    }
};