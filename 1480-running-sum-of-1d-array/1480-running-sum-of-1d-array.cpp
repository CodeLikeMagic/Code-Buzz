class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        
        int Rsum = 0;
        
        for(int i=0; i<nums.size(); i++){
            Rsum += nums[i];
            sum.push_back(Rsum);
        }
        
        return sum;
    }
};