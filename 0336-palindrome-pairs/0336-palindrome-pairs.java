class Solution {
public List<List<Integer>> palindromePairs(String[] words) {
        List <List<Integer>> res = new ArrayList();
        Map<String, Integer> map = new HashMap();
        
        //Populating the map with words and it's indexes
        for(int i=0; i<words.length; i++){
            map.put(words[i],i);
        }
        
        //2nd case
        if(map.containsKey("")){
            int blankIdx = map.get("");
            for(int i=0; i<words.length; i++){
                if(i != blankIdx && isPalindrome(words[i])){
                    List<Integer> temp = new ArrayList();
                    List<Integer> temp2 = new ArrayList();
                    temp.add(blankIdx);
                    temp.add(i);
                    temp2.add(i);
                    temp2.add(blankIdx);
                    res.add(temp);
                    res.add(temp2);
                }
            }
        }
        
        //Reflection case
        for(int i=0; i<words.length; i++){
          //Reverse the string
            String reversed = new StringBuilder(words[i]).reverse().toString();
            Integer reverseIdx = map.get(reversed);
            
            //If the reverseIdx does exist and is not equal to the current id, then we add
            if(reverseIdx != null && reverseIdx != i){
                    List<Integer> temp = new ArrayList();
                    temp.add(i);
                    temp.add(reverseIdx);
                    res.add(temp);
            }
        }
        
        //3rd Case
        for(int i=0; i<words.length; i++){
            //--cutting the string--//
            String cur = words[i];
            for(int cut=1; cut<cur.length(); ++cut){        
                String left = cur.substring(0,cut);
                String right = cur.substring(cut);
                
                if(isPalindrome(left)){
                    String reverseRight = new StringBuilder(right).reverse().toString();
                    if(map.containsKey(reverseRight)){
                    List<Integer> temp = new ArrayList();
                    temp.add(map.get(reverseRight));
                    temp.add(i);
                    res.add(temp);
                    }
                }
                
                if(isPalindrome(right)){
                    String reverseLeft = new StringBuilder(left).reverse().toString();
                    if(map.containsKey(reverseLeft)){
                    List<Integer> temp = new ArrayList();
                    temp.add(i);
                    temp.add(map.get(reverseLeft));
                    res.add(temp);
                    }
                }
            }
        }
        return res;
    }
    
    private boolean isPalindrome(String word){
        int i = 0;
        int j = word.length()-1;
        while(i < j){
            if(word.charAt(i++) != word.charAt(j--)) return false;
        }
        return true;
    }




    
}