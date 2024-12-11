class Solution:
    def num_rotations(self, nums, N, result):
        start = 0
        end = N - 1
        if nums[start] < nums[end]:
            result = start
            return result
        while start <= end:
            if nums[start] <= nums[end]:
                result = start
                break

            mid = start + (end - start) // 2
            nxt = (mid + 1)%N
            prev = (mid + N - 1)%N
            #that minimum element is always in unsorted part   jo previous aur next dono se small ho
            if nums[mid] <= nums[nxt] and nums[mid] <= nums[prev]: #min element
                result = mid
                break
            #if it is that means that array is in sorted order of that portion then, move to another portion and repeat process
            if nums[start] <= nums[mid]:
                #if portion 1 is sorted
                start = mid + 1
            elif nums[mid] <= nums[end]:
                end = mid - 1
        return result
        
    def findMin(self, nums: List[int]) -> int:
        result = 0
        N = len(nums)
        result = self.num_rotations(nums, N, result)
        return nums[result]