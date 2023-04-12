class Solution {
public:
     void reverse(vector<int>& nums, int l, int r){
        
        int temp = 0;
        for(int i=l, j=r; i<j; i++, j--){
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
};