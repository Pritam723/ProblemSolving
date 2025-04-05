from collections import deque

class MinStack:

    def __init__(self):
        self.st = deque([])        
        self.minVal = 2**31

    def push(self, val: int) -> None:
        if(len(self.st) == 0):
            self.st.append(val)
            self.minVal = val
            return

        if(val >= self.minVal):
            self.st.append(val)
        else:
            # We need to encrypt. So, val < minVal
            # So, 2*val - minVal < val. And wkt val
            # will become new minVal
            encryptedVal = 2*val - self.minVal
            self.minVal = val
            self.st.append(encryptedVal)

        # print(self.st, self.minVal)

    def pop(self) -> None:
        if(len(self.st) == 0): return
        if(self.st[-1] >= self.minVal):
            self.st.pop()
            return
        else:
            # So, on top we have an encryptedVal.
            # we must extract minVal from it.
            encryptedVal = self.st.pop()
            currMin = self.minVal
            self.minVal = 2*currMin - encryptedVal
        

    def top(self) -> int:
        if(len(self.st) == 0): return -1
        if(self.st[-1] >= self.minVal):
            return self.st[-1]
        else:
            # So, on top we have an encryptedVal.
            # So surely actual value is the minVal
            return self.minVal

    def getMin(self) -> int:
        return self.minVal


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()