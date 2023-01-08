class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n <= 1) return n;
        
        //min possible answer
        int ans = 2;
        
        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){
                ///chose i and j and then check k for every other pair
                int total = 2;
                
                for(int k=0; k<n; k++){
                    
                    //skip chosen i and j
                    if(k == i || k == j){
                        continue;
                    }
                    
                    if((points[j][0] - points[i][0])*(points[k][1] - points[i][1]) == (points[k][0] - points[i][0])*(points[j][1] - points[i][1])){
                        //point lies in same slope
                        total++;
                    }
                }
                   //total max 
                    ans = max(ans ,total);
            }             
        }
        return ans;
    }
};