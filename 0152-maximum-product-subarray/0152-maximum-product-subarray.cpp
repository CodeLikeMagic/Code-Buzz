class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int ans = INT_MIN;
        int cprod = 1;
        
        for(int i=0; i<nums.size(); i++){
            
            cprod*=nums[i];
            
            ans = max(ans, cprod);
            if(cprod == 0){
                cprod = 1;
            }
        }
        
        cprod = 1;
        
        for(int i=nums.size()-1; i>=0; i--){
            
            cprod*=nums[i];
            
            ans = max(ans, cprod);
            if(cprod == 0){
                cprod = 1;
            }           
        }
        return ans;       
    }
};