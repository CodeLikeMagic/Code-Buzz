# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is p or root is q:
            return root
        #leaf node
        if root is None or (root.left is None and root.right is None):
            return None
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        #if both values are returned
        if left and right:
            return root
        #either
        if left is None:
            return right    #either can be value or None
        elif right is None:
            return left