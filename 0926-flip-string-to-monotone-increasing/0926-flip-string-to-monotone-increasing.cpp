class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int tmp = 0;
        for(auto v: s){
            if(v == '0')tmp++;
        }
        int ans = tmp;
        for(auto v: s){
            if(v == '0'){
                ans = min(ans, --tmp);
            }
            else{
                tmp++;
            }
        }
        return ans;
    }
};