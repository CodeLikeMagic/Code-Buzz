/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findPath(TreeNode* root, vector<TreeNode*> &p, TreeNode* k){
        if(root == NULL)    return false;
        p.push_back(root);
        
        if(root->val == k->val) return true;
        
        if(findPath(root->left, p, k)   ||  findPath(root->right, p, k)){
            return true;
        }
        
        p.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        
        if(findPath(root, v1, p) == false ||    findPath(root, v2, q) == false){
            return NULL;
        }
        TreeNode * k;
        for(int i=0; i<v1.size() && i<v2.size(); ){
            
            if(v1[i] == v2[i])
            {
                k = v1[i];
            }
            i++;
        }
        //cout<<k->val<<endl;
        return k;
    }
};