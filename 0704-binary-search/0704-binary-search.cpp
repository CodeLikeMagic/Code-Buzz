class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        int answer = -1;
        
        while(low <= high){
            
            int mid = high + (low - high)/2;
            
            if(nums[mid] == target){
                answer = mid;
                break;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;                
            }            
        }
        
        return answer;
    }
};