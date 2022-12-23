class Solution {
public:
    vector<int> pricess;
    int cache[5004][2];
    int go(int idx, int state){
        if(idx >= pricess.size()) return 0;
        int &ret = cache[idx][state];
        if(ret != -1) return ret;
        
        if(!state){
            return ret = max(-pricess[idx] + go(idx+1, true), go(idx+1, false));
        }      
        else{
            return ret = max(pricess[idx] + go(idx+2, false), go(idx+1, true));
        }  
    }
    int maxProfit(vector<int>& prices) {
        memset(cache, -1, sizeof(cache));
        pricess = prices;
        return go(0, 0);
        // return 0;
    }
};