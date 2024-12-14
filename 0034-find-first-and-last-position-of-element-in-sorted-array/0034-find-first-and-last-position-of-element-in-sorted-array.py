class Solution:
    def firstOcc(self, nums, target):
        start = 0
        end = len(nums) - 1
        result = -1
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                result = mid
                end = mid - 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        return result

    def lastOcc(self, nums, target):
        start = 0
        end = len(nums) - 1
        result = -1
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                result = mid
                start = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        return result

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        fc = self.firstOcc(nums, target)
        lc = self.lastOcc(nums, target)
        result = [fc, lc]
        return result