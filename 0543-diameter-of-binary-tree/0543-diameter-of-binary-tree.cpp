/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res = 0;
    
public: 
    int modH(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int lh =  modH(root->left);
        int rh =  modH(root->right);
        
        res = max(res, lh + rh);
        
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int k = modH(root);
        return res;
    }
};