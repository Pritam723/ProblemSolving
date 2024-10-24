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

    bool isEqual(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL && n2 == NULL) return true;
        if(n1 == NULL or n2 == NULL) return false;

        if(n1->val == n2->val) return true;
        return false;
    }

    bool makeChildrenEqual(TreeNode* &fn1, TreeNode* &fn2){
        if(isEqual(fn1->left, fn2->left) && isEqual(fn1->right, fn2->right)) return true;

        // Otherwise first we swap fn1's children.
        TreeNode* temp = fn1->right;
        fn1->right = fn1->left;
        fn1->left = temp;

        // Now check again.
        if(isEqual(fn1->left, fn2->left) && isEqual(fn1->right, fn2->right)) return true;

        // Otherwise return false.
        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Consider both trees as complete. Apply Level
        // Order Traversal on both. At a level we try to
        // make the next levels equal for both trees.
        // In next iteration if we see that we were unable to do so,
        // We will return false. See here all values are unique, so
        // no 2 values will clash. See, we need to consider the NULLs
        // carefully. Say at a level we have 2 and 3.
        // In one tree 2 has children = {4,5}, 3 has None. But in other tree
        // 2 has child = 4, 3 has child = 5. So, in level order they may look same,
        // But actually they can never be same after ny no. of flip. So, consider
        // the tree as CBT and use NULLs wisely. Ex. they will differ like
        // tree1 = {4,5,N,N}, tree2 = {4,N,5,N}. So, they won't match.


        // BUT: See no. of nodes = 100, in case of skewed tree we will get
        // queue size = O(2^100) i.e., MLE.So, we must try to bypass NULLs.
        // So, instead of checking this level, we build this level in previous
        // iteration & try to make next level equal. If we fail to do so,
        // we may return false.

        if(!isEqual(root1, root2)) return false;

        queue<TreeNode*> bfsQ1;
        queue<TreeNode*> bfsQ2;

        if(root1) bfsQ1.push(root1);
        if(root2) bfsQ2.push(root2);

        while(!bfsQ1.empty() && !bfsQ2.empty()){
            
            // We are starting this level means we are sure that this level
            // is same for both the trees. We need to try to make next level
            // equal. Say we are trying to change tree1 to tree2.

            int qSize = bfsQ1.size();
            for(int i = 0; i < qSize; i++){

                TreeNode* fn1 = bfsQ1.front(); bfsQ1.pop();
                TreeNode* fn2 = bfsQ2.front(); bfsQ2.pop();

                bool isPossible = makeChildrenEqual(fn1, fn2);
                if(!isPossible) return false;

                // If possible we push the children of both in the queues.
                if(fn1->left) bfsQ1.push(fn1->left);
                if(fn1->right) bfsQ1.push(fn1->right);

                if(fn2->left) bfsQ2.push(fn2->left);
                if(fn2->right) bfsQ2.push(fn2->right);
            }
            

        }

        // We are here means at least one of the queues are empty.
        // If not return false.
        if(!bfsQ1.empty() or !bfsQ2.empty()) return false;
        return true;
    }
};