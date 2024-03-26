class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        ans = []
        for i in range(len(nums)):
            indx = abs(nums[i])
            nums[indx - 1] = - abs(nums[indx - 1])
            
        for i in range(len(nums)):
            if nums[i] > 0:
                ans.append(i+1)
                
        return ans