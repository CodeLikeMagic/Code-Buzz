class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        
        def binarySearch(potions ,success, spell):
            l = 0
            h = n
            index = -1
            while l < h:
                m = l + (h - l) // 2
                if potions[m] * spell >= success:
                    h = m
                    index = h
                else:
                    l = m + 1
            return index
            
        potions.sort()
        n = len(potions)
        ans = []
        for i in range(len(spells)):
            res = binarySearch(potions, success, spells[i])
            if res == -1:
                ans.append(0)
            else:
                ans.append(n - res)
        return ans
