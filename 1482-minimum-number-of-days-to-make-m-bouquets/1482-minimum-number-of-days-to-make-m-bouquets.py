class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def feasible(days):
            bonquets = 0
            flowers = 0
            for bloom in bloomDay:
                if bloom > days:
                    flowers = 0
                else:
                    bonquets += (flowers + 1) // k
                    #print("b ",bonquets)
                    flowers = (flowers + 1) % k
                    #print("f ",flowers)
            return bonquets >= m

        if len(bloomDay) < m * k:
            return -1
        left = 1
        right = max(bloomDay)
        while left < right:
            mid = left + (right - left) // 2
            #print("mid ",mid)
            if feasible(mid):
                right = mid
            else:
                left = mid + 1
        return left