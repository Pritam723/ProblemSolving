from collections import defaultdict
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right





class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        n = len(inorder)
        inorderIdxMap = defaultdict(int)
        for idx in range(n):
            inorderIdxMap[inorder[idx]] = idx

        root = None
        # print(inorderIdxMap)
        s, e = 0, n-1
        i = 0

        def sol(n, preorder, inorderIdxMap, s, e):
            nonlocal i
            if(i >= n): return None
            if(s > e): return None

            root = None

            val = preorder[i]
            root = TreeNode(val)

            inorderIdx = inorderIdxMap[val]

            i = i + 1

            root.left = sol(n, preorder, inorderIdxMap, s, inorderIdx - 1)
            root.right = sol(n, preorder, inorderIdxMap, inorderIdx + 1, e)

            return root



        root = sol(n, preorder, inorderIdxMap, s, e)

        return root