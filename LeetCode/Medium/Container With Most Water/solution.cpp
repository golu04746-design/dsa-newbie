class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int res=INT_MIN;
        while(l<r){
            int h=min(height[r],height[l]);
            int b=r-l;
            res=max(res,b*h);
            if(height[r]<height[l]) r--;
            else l++;
        }
        return res;
    }
};