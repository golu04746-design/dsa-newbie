class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int psum=0;
        int ssum=0;
        vector<int>vp;
        vector<int>vs;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            vp.push_back(psum);
        }
        for(int i=nums.size()-1;i>=0;i--){
            ssum+=nums[i];
            vs.push_back(ssum);
        }
        reverse(vs.begin(),vs.end());
        for(int i=0;i<nums.size();i++){
            if (vs[i]==vp[i]) return i;
        }
        return -1;
        
    }
};