class Solution {
public:
    string reverseWords(string s) {
        string s1="";
        vector<string>v;
        int i=0;
        while(i<s.length()){
            while( i<s.length() && s[i]!=' '){
                s1+=s[i];
                i++;
            }
            
          if(!s1.empty())  v.push_back(s1);
            s1="";
            i++;
            
        }
        string res="";
        int n=v.size();
        reverse(v.begin(),v.end());
        for(int i=0;i<n;i++){
           if(i!=n-1) res=res+v[i]+' ';
           else res=res+v[i];
        }
        return res;
        
    }
};