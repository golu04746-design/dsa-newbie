class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int>mp;
        vector<string>res1;
        mp.insert({{'q',1},{'w',1},{'e',1},{'r',1},{'t',1},{'y',1},{'u',1},{'i',1},{'o',1},{'p',1}});
        mp.insert({{'a',2},{'s',2},{'d',2},{'f',2},{'g',2},{'h',2},{'j',2},{'k',2},{'l',2}});
        mp.insert({{'z',3},{'x',3},{'c',3},{'v',3},{'b',3},{'n',3},{'m',3}});
        for(int i=0;i<words.size();i++){
            string s=words[i];
            string res="";
            for(int j=0;j<s.length();j++){ 

                if(mp[tolower(s[j])]!=mp[tolower(s[0])])  break;  
                else
                res=res+s[j];
                  }
                  if(res==words[i]) res1.push_back(res);


        } 

        return res1;
    }
};