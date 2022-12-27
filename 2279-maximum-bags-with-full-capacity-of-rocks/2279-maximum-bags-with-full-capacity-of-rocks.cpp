class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ret = 0;
        int N = capacity.size();
        vector<int> V(capacity.size());
        for(int i = 0; i < N; i++) V[i] = capacity[i] - rocks[i];
        sort(V.begin(), V.end());
        for(int i = 0; i < N; i++){
            if(V[i] == 0) ret++;
            else{
                if(V[i] <= additionalRocks){
                    ret++;
                    additionalRocks -= V[i];
                }
            }
        }
        return ret;
    }
};