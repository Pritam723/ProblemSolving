class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        # Solution 3:
        n = len(status)
        has_box = [False] * n # have we discovered this box?
        has_key = [False] * n # have we acquired a key for this box?
        opened  = [False] * n # have we already opened this box?
        queue = deque()
        for b in initialBoxes:
            has_box[b] = True
            if status[b] == 1:
                queue.append(b)

        total = 0
        while queue:
            box = queue.popleft()
            if opened[box]: continue
            opened[box] = True      # “Open” it
            total += candies[box]            
            for k in keys[box]:     # 1. Process any keys found
                if not has_key[k]:
                    has_key[k] = True
                    if has_box[k] and not opened[k]:
                        queue.append(k)
            for inner in containedBoxes[box]: # 2. Process newly 
                if not has_box[inner]:        # discovered boxes
                    has_box[inner] = True
                    if status[inner] == 1 or has_key[inner]:
                        if not opened[inner]:
                            queue.append(inner)
        return total
        
        
        
        # Solution 2:
        owned = set(initialBoxes)
        keysHeld = set()
        processed = set()
        waiting = set()
        queue = deque()
        for b in initialBoxes:
            if status[b] == 1:
                queue.append(b)
            else:
                waiting.add(b)
        total_candies = 0
        while queue:
            box = queue.popleft()
            if box in processed:
                continue
            total_candies += candies[box]
            processed.add(box)
            for k in keys[box]:
                if k not in keysHeld:
                    keysHeld.add(k)
                    if k in waiting:
                        waiting.remove(k)
                        queue.append(k)
            for inner in containedBoxes[box]:
                if inner not in owned:
                    owned.add(inner)
                    if status[inner] == 1 or inner in keysHeld:
                        queue.append(inner)
                    else:
                        waiting.add(inner)
        return total_candies