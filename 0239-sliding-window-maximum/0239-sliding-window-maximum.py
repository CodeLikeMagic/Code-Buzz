from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        ans = []
        i,j = 0,0

        while j < len(nums):
            while dq and dq[-1] < nums[j]:           #calc
                dq.pop()    #removing smaller elements on left
            dq.append(nums[j])

            if j-i+1 < k:   #move j
                j += 1
            elif j-i+1 == k:  #slide window
                ans.append(dq[0])   #queue's front is max for the window
                if nums[i] == dq[0]:
                    dq.popleft()
                i += 1
                j += 1
        return ans


