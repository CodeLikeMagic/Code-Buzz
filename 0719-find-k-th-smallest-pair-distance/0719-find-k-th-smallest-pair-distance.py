class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        
        def helper(dist):
            #count total nums of pairs, with diff <= dist
            n = len(nums)
            count, i, j = 0, 0, 0
            while i < n or j < n:
                while j < n and (nums[j] - nums[i] <= dist): #move fast pointer
                    j += 1
                count += j - i - 1 #count pairs
                i += 1
            return count

        nums.sort()
        l = 0
        r = max(nums)
        while l < r:
            m = l + (r - l) // 2
            pairs = helper(m)
            if pairs >= k:
                r = m
            else:
                l = m + 1
        return r