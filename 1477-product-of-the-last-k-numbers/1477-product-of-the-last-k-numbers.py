class ProductOfNumbers:

    def __init__(self):
        self.lastZeroIdx = -1
        self.currSize = 0
        self.container = []
        self.prefixProduct = 1

    def add(self, num: int) -> None:
        if(num == 0):
            self.lastZeroIdx = self.currSize
            self.container.append(0)
            self.prefixProduct = 1
        else:
            product = self.prefixProduct * num
            self.prefixProduct = product
            self.container.append(product)

        self.currSize = self.currSize + 1
    def getProduct(self, k: int) -> int:
        # print(self.container)
        if(k > self.currSize - self.lastZeroIdx - 1):
            return 0
        if(k == self.currSize - self.lastZeroIdx - 1): return self.prefixProduct
        return int(int(self.prefixProduct)/ int(self.container[self.currSize - k - 1]))
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)