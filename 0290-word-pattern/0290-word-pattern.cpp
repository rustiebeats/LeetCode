class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> V;
        stringstream ss(s);
        string word;
        while(ss >> word) V.push_back(word);
        
        if(V.size() != pattern.size()) return false;
        
        unordered_map<char, string> mp;
        set<string> st;
        for(int i = 0; i < pattern.size(); i++){
            if(mp.count(pattern[i])){
                if(mp[pattern[i]] != V[i]) return false;
            }
            else{
                if(st.count(V[i])) return false;
                mp[pattern[i]] = V[i];
                st.insert(V[i]);
            }
        }
        return true;
    }
};