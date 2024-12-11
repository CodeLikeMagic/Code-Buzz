# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
   
    def guessNumber(self, n: int) -> int:
        
        if guess(n) == 0:
            return n
        
        start = 1
        end = n
        
        while start <= end:
            mid = start + (end - start) // 2
            predict = guess(mid)
            if predict == 0:
                return mid
            elif predict == -1:
                start = start 
                end = mid - 1                
            else:
                start = mid + 1        
                end = n
        return -1