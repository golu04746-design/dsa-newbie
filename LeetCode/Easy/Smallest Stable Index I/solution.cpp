class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int r=0;
        int ans=0;
        int res=INT_MAX;
        while(r<n){
            int inst=0;
           inst= *max_element(nums.begin(),nums.begin()+r)-*min_element(nums.begin()+r,nums.end());
           if(inst<=k) res=min(res,r);
           r++;
        }
        if(res==INT_MAX) return -1;
        return res;

        
        
    }
};