class Solution {
public:
    set<int> S;
    bool isHappy(int n) {
        string nn = to_string(n);
        int tmp = 0;
        for(auto v : nn) tmp += (v-'0') * (v-'0');
        if(tmp == 1) return true;
        if(S.count(tmp)) return false;
        else{
            S.insert(tmp);
            return isHappy(tmp);
        }
    }
};