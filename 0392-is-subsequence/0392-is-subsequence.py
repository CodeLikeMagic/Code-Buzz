class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        slow = 0
        s_len = len(s)
        if s_len == 0:
            return True
        for fast in range(len(t)):
            if slow < s_len and s[slow] == t[fast]:
                slow += 1
        if slow == s_len:
            return True
        return False