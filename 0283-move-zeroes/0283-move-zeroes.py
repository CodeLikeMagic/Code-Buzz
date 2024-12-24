class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #either move 0s to right or non-zeros to left --
        """if the current element is not 0, then we need to
        append it just in front of last non-zero element we found """
        lastNonZero = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[lastNonZero] = nums[i]
                lastNonZero += 1
        """
        After we have finished processing new elements, all the non-zero elements are already at the beginning of the array. We just need to fill the remaining array with 0's.
        """
        for i in range(lastNonZero, len(nums)):
            nums[i] = 0