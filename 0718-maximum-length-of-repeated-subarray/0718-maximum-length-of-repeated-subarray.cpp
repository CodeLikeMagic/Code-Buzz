class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int N = nums1.size();
        int M = nums2.size();
        
        vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
        
        int ans = 0;
        
        for(int i=1; i<N+1; i++){
            
            for(int j=1; j<M+1; j++){
                
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;                    
                }                
                ans = max(ans, dp[i][j]);
            }           
            
        }
        return ans;
    }
};