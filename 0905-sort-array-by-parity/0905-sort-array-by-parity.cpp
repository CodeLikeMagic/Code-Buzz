class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;  // Move the left pointer if the number is even
            } else {
                swap(nums[left], nums[right]);  // Swap odd number with the number at the right pointer
                right--;  // Move the right pointer
            }
        }

        return nums;
    }
};