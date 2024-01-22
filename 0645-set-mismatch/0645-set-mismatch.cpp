class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        vector<int> answer(2);
        int idx_val = 0;
        
        for(int i=0; i<nums.size(); i++){
            idx_val = abs(nums[i]);
            nums[idx_val - 1] = -nums[idx_val - 1];
            
            if(nums[idx_val - 1] > 0) {
                //been negated twice -> duplicate
                answer[0] = idx_val;    //duplicate number
            }  
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0 && i+1 != answer[0]){
                answer[1] = i+1;
            }
        }
        
        return answer;
    }
};