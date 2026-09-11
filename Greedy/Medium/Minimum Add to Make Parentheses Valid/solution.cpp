class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(s[i]);
            else {
                if(!st.empty()) st.pop();
                else cnt++;
            }
        }
        if(st.empty()) return cnt;
        return st.size()+cnt;
        
    }
};