# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        #inorder to get left subtree and right subtree details
        in_map = {val : idx for idx, val in enumerate(inorder)}
        return self._buildTree(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1, in_map)

    def _buildTree(self, preorder: List[int], pre_start: int,
                   pre_end: int, inorder: List[int], in_start: int, in_end: int, in_map: dict) -> Optional[TreeNode]:
        if pre_start > pre_end or in_start > in_end:
            return None

        #first in preorder is root
        root_val = preorder[pre_start]
        root = TreeNode(root_val)

        #find in-order occurence
        in_root_idx = in_map[root_val]

        #no of nodes in left subtree
        nums_left = in_root_idx - in_start

        root.left = self._buildTree(preorder, pre_start+1, pre_start+nums_left, inorder,
                                    in_start, in_root_idx - 1, in_map)
        root.right = self._buildTree(preorder, pre_start+nums_left+1, pre_end, inorder,
                                     in_root_idx+1, in_end, in_map)
        return root
