class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        nums.sort()
        low = 0
        high = len(nums) - 1
        while low < high:
            if nums[low] + nums[high] < k:
                low += 1
            elif nums[low] + nums[high] > k:
                high -= 1
            else:
                low += 1
                high -= 1
                ans += 1
        return ans