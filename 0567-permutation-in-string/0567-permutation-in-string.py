class Solution:
    def check(self, one, two) -> bool:
        for i in range(26):
            if one[i] != two[i]:
                return False    #freq not same
        return True

    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        one = [0] * 26      #freq map for s1
        for x in s1:
            one[ord(x) - ord('a')] += 1

        two = [0] * 26
        k = len(s1) #window size

        for i in range(k):
            two[ord(s2[i]) - ord('a')] += 1 #move for fixed window

        if self.check(one, two):
            return True

        for i in range(k, len(s2)):
            two[ord(s2[i]) - ord('a')] += 1
            two[ord(s2[i-k]) - ord('a')] -= 1
            if self.check(one, two):
                return True
        return False
