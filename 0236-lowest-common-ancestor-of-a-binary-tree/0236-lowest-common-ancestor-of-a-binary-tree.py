# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def sol(root, p, q):
    if(root is None):
        return None
    
    if(root.val == p.val or root.val == q.val):
        return root
    
    lstInfo = sol(root.left, p, q)
    rstInfo = sol(root.right, p, q)

    if((lstInfo is None) and (rstInfo is None)):
        return None
    elif(lstInfo and rstInfo):
        return root
    elif(lstInfo): # So, rstInfo is None
        return lstInfo
    else:
        return rstInfo

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return sol(root, p, q)