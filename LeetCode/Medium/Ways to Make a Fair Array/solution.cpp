class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int rodsum=0;
        int revsum=0;
        int lodsum=0;
        int levsum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) revsum+=nums[i];
            else rodsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0) revsum-=nums[i];
            else rodsum-=nums[i];
            int currod=rodsum+levsum;
            int currev=revsum+lodsum;
            if(currod==currev) cnt++;
            if(i%2==0) levsum+=nums[i];
            else lodsum+=nums[i];
        }
        return cnt;
        
    }
};