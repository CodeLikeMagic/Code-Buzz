class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = fast = itr = 0
        
        #detect the dupe
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            
            if slow == fast:
                break
        #find the dupe
        while True:
            itr = nums[itr]
            slow = nums[slow]
            
            if slow == itr:
                return slow
        