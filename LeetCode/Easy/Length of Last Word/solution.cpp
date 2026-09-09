class Solution {
public:
    int lengthOfLastWord(string s) {
        std::stringstream ss(s);
        vector<string>v;
        string temp;
        while(ss >> temp){
            v.push_back(temp);
        }
        int n=v.size();
        return v[n-1].size();
    }
};