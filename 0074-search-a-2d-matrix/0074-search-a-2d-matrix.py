class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        N = len(matrix)
        M = len(matrix[0])
        i = 0
        j = M -1
        while(i >= 0 and i < N and j >= 0 and j < M):
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:  
                j -= 1  #decrease the column
            elif matrix[i][j] < target:
                i += 1  #increase the column
        return False