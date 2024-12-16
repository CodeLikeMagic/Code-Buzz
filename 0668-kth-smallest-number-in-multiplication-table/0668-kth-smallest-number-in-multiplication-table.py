class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def enough(num):
            count = 0
            for val in range(1, m+1): #count row by row
                add = min(num // val, n)
                if add == 0: #early exit
                    break
                count += add
            return count >= k
        left = 1
        right = n * m
        while left < right:
            mid = left + (right - left) // 2
            if enough(mid):
                right = mid
            else:
                left = mid + 1
        return left