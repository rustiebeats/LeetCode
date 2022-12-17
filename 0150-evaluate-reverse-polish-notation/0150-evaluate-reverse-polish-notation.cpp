class Solution {
public:
    stack<long long int> st;
    int evalRPN(vector<string>& tokens) {
        for(auto c : tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                long long int a = st.top(); st.pop();
                long long int b = st.top(); st.pop();
                long long int qq; 
                if(c == "+") qq = a+b;
                else if(c == "-") qq = b-a;
                else if(c == "*") qq = a*b;
                else qq = b/a;                
                st.push(qq);
            }
            else{
                st.push(stoll(c));
            }
        }
        return st.top();
    }
};