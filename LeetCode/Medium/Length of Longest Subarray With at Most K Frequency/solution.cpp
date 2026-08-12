class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int cnt=0;
        int i=0;
        int res=0;
        int left=0;
        while(i<n){
            if(mp.find(nums[i])==mp.end()){
                cnt++;
                mp[nums[i]]++;
                i++;
                res=max(res,cnt);

                
            }
            else
            if(mp[nums[i]]<k){
                cnt++;
                mp[nums[i]]++;
                i++;
                res=max(res,cnt);
            }
            else{
                mp[nums[left]]--;
                 left++;
                 
                 cnt--;
                 
            }
        }
        return res;
        
    }
};