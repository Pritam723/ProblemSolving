class Solution:
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        earliestRound = float('inf')
        latestRound = -float('inf')
        isPlaying = [True for player in range(n+1)]

        def solve(round, start, end):
            
            # 1. print current state :
            #print('-'*20)
            #print('round:',round,":",start,end)
            #print('\t>',isPlaying)
            # for i in range(1,n+1):
            #     if isPlaying[i]:
                    #print(i,end=" ")
            #print()

            nonlocal earliestRound
            nonlocal latestRound

            # move start pointer to next player
            while start <= n and not isPlaying[start]:
                start += 1
            # move end pointer to next player
            while end >= 1 and not isPlaying[end]:
                end -= 1
            #print('\t> players found',start,end)


            if start == end or start > end:
                # if we don't have enough players left to make a competition, proceed with the next round. this also handles the case of odd players and moving center player in the next round.
                #print('\t> invalid!','moving to next round')
                solve(round+1, 1, n)
            else:
                first = start
                second = end
                #print('\t> final players in this round',start,end)
                if first == firstPlayer and second == secondPlayer:
                    # TOP PLAYERS in this competition.
                    #print('\t> first and second found in this round',start,end)
                    earliestRound = min(earliestRound, round)
                    latestRound = max(latestRound, round)
                    #print('\t> ANSWER UPDATED',earliestRound,latestRound)
                    return
                # make first win
                if second != secondPlayer and second != firstPlayer: # here I forgot to put a check `second != firstPlayer` which caused infinite recursion.
                    # second player is loosing here, so we are checking if he is not a TOP PLAYER
                    #print('\t> making first win',start,end, ' | loosing',second)
                    isPlaying[second] = False
                    solve(round, start+1,end-1)
                    isPlaying[second] = True
                # make second win
                if first != firstPlayer and first != secondPlayer: # here I forgot to put a check `first != secondPlayer`
                    # first player is loosing here, so we are checking if he is not a TOP PLAYER
                    #print('\t> making second win',start,end, ' | loosing',first)
                    isPlaying[first] = False
                    solve(round, start+1,end-1)
                    isPlaying[first] = True

        solve(1,1,n)
        return [earliestRound, latestRound]

# ----
# > debugging 
# 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11

#  , 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
#      , 2, 3, 4, 5, 6, 7, 8, 9, , 11

#         , 2, , 4, 5, 6, 7, 8, 9, , 11
#             , 2, , 4, 5, 6, 7, , 9, , 11
#                 , 2, , 4, , 6, 7, , 9, , 11

#                 , 2, , 4, 5, 6, , , 9, , 11

#         , 2, 3, 4, 5, 6, 7, 8, , , 11