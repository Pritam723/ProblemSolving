# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:
    
    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.val = 0
        self.mp = {}
        self.recover(self.root, self.val, self.mp)    

    def recover(self, root, val, mp):
        if(root is None):
            return
        
        self.recover(root.left, 2 * val + 1, mp)
        self.recover(root.right, 2 * val + 2, mp)

        # We are here means LST & RST are fixed.
        # Now, fix this node.
        root.val = val
        mp[val] = True
        return

    def find(self, target: int) -> bool:
        return self.mp.get(target, False)


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)