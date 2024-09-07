# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(inorder) != len(postorder):
            return None

        in_map = {val: idx for idx, val in enumerate(inorder)}
        return self._buildTree(inorder, 0, len(inorder) - 1, postorder, 0, len(postorder) - 1, in_map)

    def _buildTree(self, inorder, in_start, in_end, postorder, post_start, post_end, in_map):
        if in_start > in_end or post_start > post_end:
            return None

        # The last element in postorder is the root of the tree/subtree
        root_val = postorder[post_end]
        root = TreeNode(root_val)

        # Find the index of the root in the inorder list
        in_root_idx = in_map[root_val]

        # Number of nodes in the left subtree
        nums_left = in_root_idx - in_start

        # Recursively build the left and right subtrees
        root.left = self._buildTree(inorder, in_start, in_root_idx - 1,
                                    postorder, post_start, post_start + nums_left - 1, in_map)
        root.right = self._buildTree(inorder, in_root_idx + 1, in_end,
                                     postorder, post_start + nums_left, post_end - 1, in_map)
        return root
