class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        def enough(mid):
            ab = a * b // math.gcd(a, b)
            ac = a * c // math.gcd(a, c)
            bc = b * c // math.gcd(b, c)
            abc = a * bc // math.gcd(a, bc)
            print("ab, ac, bc, abc", ab, ac, bc, abc)
            total = mid//a + mid//b + mid//c - mid//ab - mid//ac - mid//bc + mid//abc
            print("total ", total)
            return total >= n
        
        left = 1
        right = 10**10
        while left < right:
            mid = left + (right - left) // 2
            print("mid ", mid)
            if enough(mid):
                right = mid
            else:
                left = mid + 1
        return left