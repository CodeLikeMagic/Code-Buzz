class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        N = len(nums)
        start = 0
        end = N

        while(start < end):
            mid = start + (end - start) // 2
            if nums[mid] >= target:
                end = mid    
            else:
                start = mid + 1
        return start