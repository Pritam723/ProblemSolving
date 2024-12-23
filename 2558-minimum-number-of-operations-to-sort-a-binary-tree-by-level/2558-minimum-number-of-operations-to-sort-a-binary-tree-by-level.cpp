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
    int minimumOperations(TreeNode* root) {
        // Read this editorial first:
        // https://www.geeksforgeeks.org/problems/minimum-swaps/1?itm_source=geeksforgeeks

        queue<TreeNode*> bfsQ;
        bfsQ.push(root);
        
        int ans = 0; // For first step swaps are 0.

        while(!bfsQ.empty()){
            int qSize = bfsQ.size();

            vector<vector<int>> temp;
            int pos = 0;
            
            while(qSize--){
                TreeNode* fn = bfsQ.front();
                bfsQ.pop();
                temp.push_back({fn->val, pos});
                pos++;

                if(fn->left) bfsQ.push(fn->left);
                if(fn->right) bfsQ.push(fn->right);
            }
            // We are here means a level is done.
            sort(temp.begin(), temp.end());
            // Now check for cycles.
            int sz = temp.size();
            vector<bool> visited(sz, false);

            for(int i = 0; i < sz; i++){
                // Values are unique, so no need to worry.
                if(visited[i] == true or temp[i][1] == i) continue; // Either visited or 1 sized cycle(self loop).
                // Otherwise check the loop size.
                int loopSize = 1;
                int loopStart = temp[i][0];
                int nextIdx = temp[i][1];
                
                visited[i] = true;
                
                while(temp[nextIdx][0] != loopStart){
                    visited[nextIdx] = true;
                    nextIdx = temp[nextIdx][1];
                    loopSize++;
                }
                ans = ans + (loopSize - 1);
            }
        }

        return ans;
    }
};