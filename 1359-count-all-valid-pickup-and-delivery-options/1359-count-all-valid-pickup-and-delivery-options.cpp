class Solution {
public:
    int countOrders(int n)
    {
        long long dp[502];
        dp[0] = 0;
        dp[1] = 1;
        
        long long res = 0;
        
        for(int i = 2; i <= n; i++)
        {
            long long prev = dp[i-1];
            long long pos = 2 + ((i-1) * 2) - 1;
            dp[i] = (pos * prev * i) % 1000000007;
        }
        
        return dp[n];
    }
};