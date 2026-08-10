class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    
        double avg=0;
        int n=nums.size();
        int left=0;
        
        int right=k-1;
    
        for(int i=0;i<k;i++){
            avg=avg+nums[i];
        }
         double res=avg;
        for( right;right<n;right++){
            if(right-left+1>k) {
                avg=avg-nums[left]+nums[right];
                res=max(res,avg);
                left++;
            }
            res=max(res,avg);

        }

            
        
         double rees=res/k;
     return rees;
        
        
    }
};