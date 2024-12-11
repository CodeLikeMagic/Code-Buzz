class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        result = 0
        N = len(nums)
        start = 0
        end = N-1
        
        if N == 0 or N == 1:
            return 0
        
        
        while start <= end:
            mid = start + (end - start) // 2

            if 0 < mid < N - 1: #middle range
                if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                    return mid
                    break
                elif nums[mid - 1] > nums[mid]: #looking for promising side
                    end = mid - 1
                else:
                    start = mid + 1
            elif mid == 0:
                if nums[0] > nums[1]:
                    result = 0
                    break
                else:
                    result = 1
                    break
            elif mid == N - 1:
                if nums[N-1] > nums[N-2]:
                    result = N-1
                    break
                else:
                    result = N-2
                    break
        return result