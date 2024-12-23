class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        len1 = len(nums1)
        len2 = len(nums2)
        #swap lens if len1 > len2 
        if (len1 > len2): 
            return self.findMedianSortedArrays(nums2, nums1)
        low = 0
        high = len1
        left = (len1 + len2 + 1) // 2
        n = len1 + len2
        while low <= high:
            mid1 = (low + high ) // 2
            mid2 = left - mid1
            l1 = l2 = float('-inf')
            r1 = r2 = float('inf')

            if mid1 < len1:
                r1 = nums1[mid1] 
            if mid2 < len2:
                r2 = nums2[mid2] 
            if mid1 - 1 >= 0:
                l1 = nums1[mid1 - 1]
            if mid2 - 1 >= 0:
                l2 = nums2[mid2 - 1]

            if l1 <= r2 and l2 <= r1:
                if n%2 == 1:
                    return max(l1, l2)
                else:
                    return (max(l1, l2) + min(r1, r2)) / 2.0
            elif l1 > r2:
                high = mid1 - 1
            else:
                low = mid1 + 1	
        return 0	
        
			
