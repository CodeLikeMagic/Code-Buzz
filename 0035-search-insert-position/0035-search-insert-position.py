class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        N = len(nums)
        start = 0
        end = N - 1

        while(start <= end):
            mid = start + (end - start) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        return end+1