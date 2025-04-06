# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def buildTree(inorderSeq, s, e):

    if(s > e): return None

    m = s + (e-s)//2
    val = inorderSeq[m]

    root = TreeNode(val)

    root.left = buildTree(inorderSeq, s, m-1)
    root.right = buildTree(inorderSeq, m+1, e)

    return root


def inorder(root, inorderSeq):
    if(root is None): return

    inorder(root.left, inorderSeq)
    inorderSeq.append(root.val)
    inorder(root.right, inorderSeq)

class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        inorderSeq = []
        inorder(root, inorderSeq)

        n = len(inorderSeq)
        s, e = 0, n-1

        root = buildTree(inorderSeq, s, e)

        return root