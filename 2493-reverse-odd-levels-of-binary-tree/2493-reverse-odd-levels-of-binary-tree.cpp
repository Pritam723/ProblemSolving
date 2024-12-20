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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> bfsQ;
        stack<int> st;

        bfsQ.push(root);

        int level = 0;
        
        while(!bfsQ.empty()){
            int qSize = bfsQ.size();
            
            while(qSize--){
                TreeNode* frontNode = bfsQ.front();
                if(level % 2 == 1){
                    int newVal = st.top(); st.pop();
                    frontNode->val = newVal;
                }
                bfsQ.pop();

                if(frontNode->left){
                    bfsQ.push(frontNode->left);
                    if(level % 2 == 0) st.push(frontNode->left->val);    
                }
                if(frontNode->right){
                    bfsQ.push(frontNode->right);
                    if(level % 2 == 0) st.push(frontNode->right->val);
                }
            }

            level = level + 1;
        }
        return root;
    }
};