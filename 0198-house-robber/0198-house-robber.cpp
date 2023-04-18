class Solution {
public:
    int rob(vector<int>& nums) {
         if(nums.size() == 0){
            return 0;
        }
        
        int N = nums.size();
        int dp[N+1];
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i=1; i<N; i++){
            
            ///if want values can be skipped 
            ///[1,2,3,1,1,100] - 5 / 103/ 104
            ///since adjancent values can't be taken
            ///choose bw current max and if prev max and curr index make max
            dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
        }
        
        return dp[N];
    }
};