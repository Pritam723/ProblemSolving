import heapq
class Elem:
    def __init__(self, ch, count):
        self.ch = ch
        self.count = count

    def __lt__(self, elem):
        return self.ch > elem.ch 


class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        charCount = [0]*26
        for ch in s:
            chIdx = ord(ch) - ord('a')
            charCount[chIdx] = charCount[chIdx] + 1
        
        elems = []
        for i in range(26):
            if(charCount[i] == 0): continue
            elems.append(Elem(chr(ord('a') + i), charCount[i]))

        heapq.heapify(elems)

        ans = ""
        lastChar = '#'

        while len(elems) > 0:

            elem1 = heapq.heappop(elems)
            ch1 = elem1.ch
            count1 = elem1.count

            if(ch1 == lastChar):
                if(len(elems) == 0): return ans

                elem2 = heapq.heappop(elems)
                ch2 = elem2.ch
                count2 = elem2.count

                # times = min(repeatLimit, count2)
                times = 1 # Because we want lexicographically largest.
                rem = count2 - times

                while(times > 0):
                    ans = ans + ch2
                    times = times - 1
                
                lastChar = ch2

                if(rem > 0):
                    newElem = Elem(ch2, rem)
                    heapq.heappush(elems, newElem)
                
                # Also push elem1.    
                heapq.heappush(elems, elem1)

            else:
                times = min(repeatLimit, count1)
                rem = count1 - times

                while(times > 0):
                    ans = ans + ch1
                    times = times - 1
                
                if(rem > 0):
                    newElem = Elem(ch1, rem)
                    heapq.heappush(elems, newElem)

                lastChar = ch1

        return ans