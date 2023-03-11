class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int temp, maxSoFar = 0;
        temp = 0;
        for(auto x : accounts){
            
            maxSoFar = max(maxSoFar, accumulate(x.begin(), x.end(), temp));
        }
        
        return maxSoFar;
    }
};