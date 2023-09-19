class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, itr = 0;
        
        while(true){
            
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if(slow == fast){
                break;
            }
        }
        
        while(true){
            itr = nums[itr];
            slow = nums[slow];
            
            if(slow == itr){
                return slow;
            }
        }
    }
};