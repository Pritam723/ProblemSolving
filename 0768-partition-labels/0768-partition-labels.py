class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        
        char_last_pos = {}
        
        for idx, char in enumerate(S):
            
            # update latest position index for each character is S
            char_last_pos[char] = idx
        
        
        # ------------------------------------------------------------
        
        start, partition_length = 0, []
        last_position = 0
        
        # make partition based on lastest position index of characters
        for idx, char in enumerate(S):
            
			# update and maximize last position of character
            last_position = max(last_position, char_last_pos[char])
            
            if idx == last_position:
                
                # those characters from start to last_position forms a partition
                cur_partition_length = last_position - start + 1
                
                partition_length.append( cur_partition_length )
                
                # update start for next partition
                start = idx + 1
                
        
        return partition_length
                