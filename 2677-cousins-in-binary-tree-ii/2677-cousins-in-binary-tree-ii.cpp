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
    // void dfs(TreeNode* &root, unordered_map<int, int> &mp, int currentLevel, int parentSumm){
    //     // See, execution for a node will only be done when we have already calculated
    //     // required value for its children.
    //     // if(root->left == NULL && root->right == NULL){
    //     //     root->val = 0;
    //     //     return;
    //     // }

    //     if(root->left) dfs(root->left, mp, currentLevel + 1, root->val);
    //     if(root->right) dfs(root->right, mp, currentLevel + 1, root->val);

    //     // So, if children are done, we can calculate for parent.
    //     root->val = mp[currentLevel] - parentSumm;
    //     return;
    // }

    TreeNode* replaceValueInTree(TreeNode* root) {
        // So, understand this. For a node the final value
        // will be sum(all nodes in its level) - sum(all nodes of its parent).
        // So, first using a BFS we will store LevelWise Summ in a MAP. Also
        // We will store sum of children value in each node. Ex. Leaf nodes will
        // store value 0, root in example1 will store value 13 etc. Let's do that
        // first. Then finally we will run a DFS which will evaluate for leaves then
        // level above and finally at root to calculate the actual value. But DFS is
        // causing it to hit TLE. Try to do it in 1 iteration BFS only.

        // For that we can use BFS. While on level-i, we can get levelSumm for level-(i+1)
        // Also WKT a node at max has 1 sibling. So, while processing we will make a node
        // sum = node val + its sibling val. Now in next level we will do levelSum - nodeVal
        // which will ultimately give desired answer.

        // unordered_map<int, int> mp; // Will store levelWiseSumm.
        
        int nextLevelSumm = root->val;
        
        // root already satisfies the summ = node val + sibling val criteria.

        queue<TreeNode*> bfsQ;
        bfsQ.push(root);

        while(!bfsQ.empty()){
            int qSize = bfsQ.size();

            int levelSumm = nextLevelSumm;
            nextLevelSumm = 0;
            // cout << "levelsum is " << levelSumm << endl;
            for(int i = 0; i < qSize; i++){
                TreeNode* frontNode = bfsQ.front();
                bfsQ.pop();

                // Now, we need to add its children and also
                // make their values = sum of sibling + own val.

                int lc_val = 0;
                int rc_val = 0;

                if(frontNode->left){
                    bfsQ.push(frontNode->left);
                    lc_val = (frontNode->left)->val;     
                }
                if(frontNode->right){
                    bfsQ.push(frontNode->right);
                    rc_val = (frontNode->right)->val; 
                }

                if(frontNode->left) (frontNode->left)->val = lc_val + rc_val;
                if(frontNode->right) (frontNode->right)->val = lc_val + rc_val;

                nextLevelSumm = nextLevelSumm + (lc_val + rc_val);

                // Now before popping frontNode, we set its value.
                frontNode->val = levelSumm - frontNode->val;
            }
            // We are here means previous level is done.
            // So, before starting nextLevel make levelSumm = nextLevelSumm; again.
        }
        return root;
    }
};