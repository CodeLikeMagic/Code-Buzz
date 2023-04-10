/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         if (!root) return nullptr;

        vector<Node*> level;

        queue<Node*> q;

        q.push(root);
        q.push(nullptr);


        while (!q.empty()) {
            Node *front = q.front();
            q.pop();

            if (front == nullptr) {
                int n = level.size();
                
                for (int i=0; i<n-1; i++) level[i]->next = level[i+1];

                level.clear();

                if (!q.empty()) q.push(nullptr);

            } 
            else{

                level.push_back(front);

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

        }
        return root;
    }
};