class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> psum(nums.size());
        psum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            psum[i] = psum[i-1] + nums[i];
        }
        
        int ret = -1;
        for(int i = 0; i < nums.size(); i++){
            if(psum[nums.size()-1] - psum[0] == 0) return 0;
            if(i != 0) if(psum[i-1] == psum[nums.size()-1]-psum[i]) return i;
        }
        return ret;
    }
};