class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        vector<vector<int>>v;
        
        
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        while(i<n){
            int p=intervals[i][0];
            int q=intervals[i][1];
        while(i<n-1 && q>=intervals[i+1][0]){
            
            q=max(q,intervals[i+1][1]);
        
             
            i++;
        }
        v.push_back({p,q});
        i++;
        }
       
    
        return v;
    }
};