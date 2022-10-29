class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         target = abs(target);  // make sure to make it positive 
	
        int val = accumulate(nums.begin(),nums.end(),0); //To find sum 

        int sum = (target + val)/2;   //This will be our target sum 

        if(((val + target) % 2 != 0) || (target > val)) // if sum is not even and taget > sum
            return 0;

        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));  // 2D dp matrix
        //Intialization

        for(int i = 0 ; i < sum + 1 ; i++)  // Row will be 0 (i.e first row )
            dp[0][i] = 0;
        for(int i = 0 ; i < nums.size() + 1 ; i++)   // making first col 1 
            dp[i][0] = 1;

        //choice dig

        for(int i = 1 ; i < nums.size()+1 ; i++)  
        {
            for(int j = 0 ; j < sum + 1 ; j++)  // Here we'll run the loop from 0 since it will be considered as 
            {                                                  // potential answer
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[nums.size()][sum];   // Return the answer
    }
};