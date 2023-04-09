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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *newRoot = new TreeNode();
        
        if(root1 != NULL && root2 != NULL){
            newRoot->val = root1->val + root2->val;    
        }
        else if(root1 == NULL && root2 != NULL){
            newRoot = root2;
        }
        else if(root1 != NULL && root2 == NULL){
            newRoot = root1;
        }
        else{
            return NULL;
        }
        
        if(root1 != NULL && root2 != NULL){
            newRoot->left = mergeTrees(root1->left, root2->left);
            
            newRoot->right = mergeTrees(root1->right, root2->right);
        }
        
        return newRoot;
    }
};