class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int start = 0, currPt = 0, prevPt = 0;
        
        for(int i=0; i<n; i++){
            
            currPt += (gas[i] - cost[i]);
            
            if(currPt < 0){
                
                start = i+1;
                prevPt += currPt;
                currPt = 0;
            }            
        }
        return ((currPt + prevPt) >= 0)?(start):-1;
    }
};