# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def sol(root):
    if(root is None):
        return (-1,-1)

    if((root.left is None) and (root.right is None)):
        # It is a leaf
        return (0,0) # Returning Leval and Diameter.

    lstHeight, lstDiameter = sol(root.left)
    rstHeight, rstDiameter = sol(root.right)

    # Now what to return.
    h = max(lstHeight, rstHeight) + 1
    d = max(lstHeight + rstHeight + 2, max(lstDiameter, rstDiameter))

    return (h,d)

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        h,d = sol(root)
        return d

        