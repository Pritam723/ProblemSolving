def insertUtil(root, word, i, n):
    
    if(i == n): return root

    ch = word[i]
    chIdx = ord(ch) - ord('a')

    if(root.children[chIdx] is None):
        tn = TrieNode(ch)
        tn = insertUtil(tn, word, i + 1, n)
        root.children[chIdx] = tn
    else:
        tn = root.children[chIdx]
        tn = insertUtil(tn, word, i + 1, n)
        root.children[chIdx] = tn

    if(i == n-1):
        root.children[chIdx].isTerminal = True
    return root

def searchUtil(root, word, i, n):
    
    if(i == n): return False
    
    ch = word[i]
    chIdx = ord(ch) - ord('a')
    tn = root.children[chIdx]

    if(tn is None): return False

    # So, tn is Not none
    if(i == n-1 and tn.isTerminal): return True
    return searchUtil(tn, word, i + 1, n)

def startswithUtil(root, word, i, n):
    
    if(i == n): return True
    
    ch = word[i]
    chIdx = ord(ch) - ord('a')
    tn = root.children[chIdx]

    if(tn is None): return False

    # So, tn is Not none
    if(i == n-1): return True
    return startswithUtil(tn, word, i + 1, n)


class TrieNode:
    def __init__(self, ch):
        self.ch = ch
        self.children = [None]*26
        self.isTerminal = False

    


class Trie:

    def __init__(self):
        self.root = TrieNode('\0')

    def insert(self, word: str) -> None:
    
        n = len(word)
        if(n == 0): return
        i = 0

        self.root = insertUtil(self.root, word, i, n)
        return


    def search(self, word: str) -> bool:
        n = len(word)
        if(n == 0): return
        i = 0

        return searchUtil(self.root, word, i, n)

    def startsWith(self, prefix: str) -> bool:
        n = len(prefix)
        if(n == 0): return
        i = 0

        return startswithUtil(self.root, prefix, i, n)


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)