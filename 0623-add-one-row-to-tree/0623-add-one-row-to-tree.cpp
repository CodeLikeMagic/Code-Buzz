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
    void printLevel(TreeNode* root, int depth, queue<pair<TreeNode *, int>> &q){
        
        if(root == NULL) return;

        int level = 1;
        q.push({root, level});
     
        if(level+1 == (depth)){
            return;
        }else{
            while(q.empty() == false)
            {
                auto x = q.front();
                TreeNode *curr = x.first;
                int lev = x.second;
                if(lev+1 == depth){
                    return;
                }
                q.pop();

                cout<<curr->val<<" "<<lev<<endl;

                if(curr->left != NULL){
                    q.push({curr->left, lev+1});
                }

                if(curr->right != NULL){
                    q.push({curr->right, lev+1});
                }
            }    
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<pair<TreeNode *, int>>q;
        
        if(depth == 1){
            
            TreeNode *temp = NULL;
            TreeNode *newRoot = new TreeNode(val);        
            
            temp = root;
            newRoot->left = root;
            root = newRoot;
            return root;
        }
        printLevel(root, depth, q);
        
        while(q.empty() == false){
            
            auto x  = q.front();
            TreeNode *curr = x.first;
            
            TreeNode *temp = NULL;
            
            TreeNode *newNode1 = new TreeNode(val);
            temp = curr->left;
            newNode1->left = temp;
            curr->left = newNode1;
            
            TreeNode *newNode2 = new TreeNode(val);
            temp = curr->right;
            newNode2->right = temp;
            curr->right = newNode2;  
            
            q.pop();
        }
        
        return root;
    }
};