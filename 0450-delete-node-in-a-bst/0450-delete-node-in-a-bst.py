# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def sol(root, key):
    if(root is None):
        return None

    if(key < root.val):
        # We go left.
        root.left = sol(root.left, key)
        return root
    
    if(key > root.val):
        # We go right.
        root.right = sol(root.right, key)
        return root

    # So, root.val == key now. # So, we need to delete.
    if((root.left is None) and (root.right is None)):
        # Deleting a leaf.
        nodeToDelete = root
        del nodeToDelete
        return None

    if(root.left and root.right):
        # So, this is a tricky case.
        # So, here we take help of IP or IS.
        # And those will not be necessarily 
        # in Leaf Actually. So, use recursion.
        # Lst's take IS. Which is in LST.
        # Max value in LST.
        ip = root.left

        while(ip.right):
            ip = ip.right
        
        # So, we are at ip.
        root.val, ip.val = ip.val, root.val
        
        # So, the change is in lst. So, recursively go there to 
        # delete key.
        root.left = sol(root.left, key)

        return root


    if(root.left):
        # So, Onlt LST is present.
        nodeToDelete = root
        lst = root.left
        del nodeToDelete
        return lst

    if(root.right):
        # So, Only RST is present.
        nodeToDelete = root
        rst = root.right
        del nodeToDelete
        return rst


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        root = sol(root, key)
        return root