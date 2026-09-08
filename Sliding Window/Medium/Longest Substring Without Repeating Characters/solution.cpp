class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int n=s.length();
        int r=0;
        int res=0;
        unordered_map<char,int>mp;
        while(r<n){
            if(mp.find(s[r])==mp.end()) {
                mp[s[r]]++;
                res=max(res,r-l+1);
                r++;
            }
            else if(mp.find(s[r])!=mp.end()){
                while(mp[s[r]]!=0){
                    mp[s[l]]--;
                    l++;
                }
                    mp[s[r]]++;
                    res=max(res,r-l+1);
                    r++;
                }


            


        }
        return res;

        
    }
};