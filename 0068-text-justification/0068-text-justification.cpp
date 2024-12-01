class Solution {
public:
    
    string getSpaces(int num){
        string s = "";
        while(num--) s = s + " ";

        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int n = words.size();

        int l = 0;

        while(l < n){
            int r = l;

            vector<string> currentLine = {};
            int width = 0;

            while(width <= maxWidth){
                
                if(r == n){
                    // So, width is still <= maxWidth but we have reached r.
                    // So, actually this is the last line. So, apply rule of last line here.

                    string lastLine = "";

                    for(string w: currentLine){
                        if(lastLine.length() > 0) lastLine = lastLine + " ";
                        lastLine = lastLine + w;
                    }

                    // Finally add spaces also.
                    lastLine = lastLine + getSpaces(maxWidth - width);

                    ans.push_back(lastLine);
                    return ans;
                }
                
                currentLine.push_back(words[r]);
                if(width == 0) width = width + words[r].length();
                else width = width + 1 + words[r].length(); // +1 because if it is not the first word
                // we must add atleast 1 space.
                if(width > maxWidth) break;

                r = r + 1;
            }

            // Now, we are here means width > maxWidth. So, actually we should consider till previous index
            // only. So, do r = r - 1.
            currentLine.pop_back();
            width = width - (1 + words[r].length()); // Don't worry this will not be the first word in line
            // as Each word's length is guaranteed to be greater than 0 and not exceed maxWidth. So -1 is fine.
            r = r - 1;

            cout << "Line from " << l << " to " << r << " width is " << width << endl;

            // Now, we need to see how many spaces are left. And how many blanks to fill.
            int spacesLeft = maxWidth - width;
            int blanksToFill = currentLine.size() - 1;
            // Ex. 65 spaces left and there are 7 blanks to fill say. So, first see the remainder.
            // 65 % 7 = 2 and 65 / 7 = 9. So, basically means for the first 2 blanks, spaces will
            // be 9+1 = 10. And for the rest 5 blanks, spaces will be 9. But very careful about the
            // spacesLeft == 0 case. Also see, here we are talking about spaces after the natural single
            // space between words. So, actually first 2 blanks will have 11 spaces and rest 5 will have 10
            // spaces each. When spacesLeft == 0, we can simply use 1 space only.

            int extraSpaceTill = 0;;
            int spacesToFill = 1;

            if(blanksToFill != 0) extraSpaceTill = spacesLeft % blanksToFill;
            if(blanksToFill != 0) spacesToFill = 1 + spacesLeft / blanksToFill;
            if(currentLine.size() == 1) spacesToFill = maxWidth - currentLine[0].length();

            cout << extraSpaceTill << " and " << spacesToFill << endl;
            // Now, we generate the line.

            string thisLine = "";

            for(string w: currentLine){
                thisLine = thisLine + w;

                if(thisLine.length() == maxWidth) break;

                thisLine = thisLine + getSpaces(spacesToFill);
                if(extraSpaceTill-- > 0) thisLine = thisLine + " ";
            }
            

            ans.push_back(thisLine);
            l = r + 1;
        }
        return ans;
    }
};