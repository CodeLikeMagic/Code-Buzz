# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findHeightLeft(self, root):
        ht = 0
        while root:
            ht += 1
            root = root.left
        return ht

    def findHeightRight(self, root):
        ht = 0
        while root:
            ht += 1
            root = root.right
        return ht
    
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        lh = self.findHeightLeft(root)
        rh = self.findHeightRight(root)

        if lh == rh:
            return (1 << lh) - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    