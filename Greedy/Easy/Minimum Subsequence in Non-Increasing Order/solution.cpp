class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        
        if(nums.size()==1) return nums;
        for(int i=nums.size()-1;i>=0;i--){
            int j=i-1;
            int sum=0;
            int vsum=0;
            int v1sum=0;
            
            while(j>=0){
                sum=sum+nums[j];
                j--;
            }
            for(int k=0;k<v.size();k++){
                vsum=vsum+v[k];
            }
            v1sum=vsum+nums[i];
            if(sum>=v1sum){
                v.push_back(nums[i]);
                
            }
            else {
                v.push_back(nums[i]);
                break;
            }
        
        }
        return v;

        
    }
};