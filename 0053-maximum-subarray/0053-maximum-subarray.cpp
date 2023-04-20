class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msf = nums[0], me = nums[0];
        
        for(int i=1; i<nums.size(); i++){
    
            me = max(me+nums[i], nums[i]);
            
            msf = max(msf, me);
        }
        return msf;
    }
};