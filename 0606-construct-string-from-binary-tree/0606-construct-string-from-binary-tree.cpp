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
    void dfs(TreeNode* t, string &answer){
        
        if(t == NULL){
            return;
        }
        answer += to_string(t->val);
        if(t->left == NULL && t->right == NULL){
            return;
        }
        answer.push_back('(');
        dfs(t->left, answer);
        answer.push_back(')');
        
        if(t->right != NULL){
            answer.push_back('(');
            dfs(t->right, answer);
            answer.push_back(')');
        }
    }
    
    string tree2str(TreeNode* root) {
        string answer = "";
        dfs(root, answer);
        return answer;
    }
};