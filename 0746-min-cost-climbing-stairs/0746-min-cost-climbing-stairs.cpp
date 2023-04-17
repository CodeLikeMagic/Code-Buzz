class Solution {
public:
    int mcs(int n, vector<int> &cost,vector<int> &dp){
        
        if(n <= 1){
            return dp[n] = cost[n];
        }
        
        if(dp[n]!=0){
            return dp[n];
        }
        
        return dp[n] = min(mcs(n-1, cost, dp), mcs(n-2, cost, dp)) + cost[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        cost.push_back(0);
        
        vector<int> dp(n+1, 0);
        int ans = mcs(n,cost,dp);
        return ans;
    }
};