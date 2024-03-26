class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        onesPresence = False
        
        for i in range(n):
            if nums[i] == 1:
                onesPresence = True
            if nums[i] < 1 or nums[i] > n:
                nums[i] = 1
              
            
        if not onesPresence:
            return 1
        
        
        for i in range(n):
            indx = abs(nums[i])
            nums[indx - 1] = - abs(nums[indx - 1]) #mark
            
            
        for i in range(n):
            if nums[i] > 0:
                return i+1
            
            
        return n+1
            