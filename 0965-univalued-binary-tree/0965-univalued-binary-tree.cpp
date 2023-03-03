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
    bool isUnivalTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false){
            
            auto node = q.front();
            int prev_val = node->val;
            q.pop();
            
            if(node->left){
                if(prev_val == node->left->val){
                    q.push(node->left)    ;
                }else{
                    return false;
                }
            }
            if(node->right){
                if(prev_val == node->right->val){
                    q.push(node->right)    ;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};