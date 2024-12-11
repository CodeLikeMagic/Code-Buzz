class Solution:
    def binary_search(self, nums: List[int], low, high, target: int) -> int:
        start = low
        end = high

        while(start <= end):
            mid = start + (end - start) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        return -1

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
            nxt = (mid + 1) % N
            prev = (mid + N - 1) % N

            # that minimum element is always in unsorted part   jo previous aur next dono se small ho
            if nums[mid] <= nums[nxt] and nums[mid] <= nums[prev]:  # min element
                result = mid
                break
            # if it is that means that array is in sorted order of that portion then, move to another portion and repeat process
            if nums[start] <= nums[mid]:  # if portion 1 is sorted
                start = mid + 1
            elif nums[mid] <= nums[end]:  # if portion 2 is sorted
                end = mid - 1
        return result

    def search(self, nums: List[int], target: int) -> int:
        min_index = self.num_rotations(nums, len(nums), target)

        p1 = self.binary_search(nums, 0, min_index - 1, target)
        p2 = self.binary_search(nums, min_index, len(nums) - 1, target)

        if p1 == -1 and p2 == -1:
            return -1
        if p1 != -1:
            return p1
        if p2 != -1:
            return p2
         