import heapq

class Elem:
    def __init__(self,passing,total):
        self.passing = passing
        self.total = total
        self.inc = float(self.passing + 1)/float(self.total + 1) - float(self.passing)/float(self.total)

    def __lt__(self, elem):
        # inc1 = round(float(self.passing + 1)/float(self.total + 1) - float(self.passing)/float(self.total),5)
        # inc2 = round(float(elem.passing + 1)/float(elem.total + 1) - float(elem.passing)/float(elem.total),5)
        # # Now we want the better increment. So actually we need opposite logic of
        # # min heap. (default is min heap in python).
        return self.inc > elem.inc
        # if(inc1 > inc2):
        #     return True
        # return False


class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        """
        :type classes: List[List[int]]
        :type extraStudents: int
        :rtype: float
        """
        elems = []
        for item in classes:
            # passing = item[0]
            # total = item[1]
            elems.append(Elem(item[0], item[1]))
            # print(passing, total)
            # print(float(passing + 1)/float(total + 1))
            # print((passing)/(total))

            # print((passing + 1)/(total + 1) - (passing)/(total))
            
        heapq.heapify(elems)

        # while len(elems) > 0:
        #     elem = heapq.heappop(elems)
        #     print(elem.passing,elem.total,elem.inc)

        for i in range(extraStudents):
            elem = heapq.heappop(elems)
            newElem = Elem(elem.passing+1, elem.total+1)
            heapq.heappush(elems,newElem)

        # Finally add up all the ratios.
        ans = 0.0
        for elem in elems:
            # print()
            ans = ans + float(elem.passing)/float(elem.total)

        return round(ans/len(classes),5)

        # return 0.0