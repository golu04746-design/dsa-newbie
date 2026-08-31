class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int v=points.size();
        sort(points.begin(),points.end());
        vector<pair<int,int>>v1;
        int i=0;
         while(i<v){
            int p=points[i][0];
            int q=points[i][1];
        while(i<v-1 && q>=points[i+1][0]){
            
            q=min(q,points[i+1][1]);
        
             
            i++;
        }
        v1.push_back({p,q});
        i++;
        }
        return v1.size();
       
    }
};