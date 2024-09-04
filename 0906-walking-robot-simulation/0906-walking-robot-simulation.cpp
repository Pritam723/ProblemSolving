class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Robot is initially facing North. Going north will make x, y+1
        // Going east: x+1, y
        // Going south x, y-1
        // Going west x-1, y

        // Now, turning Right will cycle like: north->east->south->west->cycle.
        // Turning left will cycle like: north->west->south->east->cycle.

        // So, we can maintain 2 simple vectors.
        vector<int> xDirs = {0,1,0,-1};
        vector<int> yDirs = {1,0,-1,0};

        // Since initially we are facing north, so take dir = 0.
        int dir = 0;
        // Surely if we get -1 i.e., turn right, we do (dir + 1) % 4
        // When we get -2 i.e., turn left, we do dir-1, but in case
        // dir is 0, make it 3 (Not -1).

        unordered_map<string, bool> mp;
        for(vector<int> obstacle: obstacles){
            int xC = obstacle[0];
            int yC = obstacle[1];
            string s = to_string(xC) + "@" + to_string(yC);
            mp[s] = true;
        } 

        // Euclidean Distance: sqrt(x^2 + y^2). So, square of it is x^2 + y^2.


        int currX = 0, currY = 0;

        int maxDist = 0;

        for(int command: commands){
            if(command == -1) dir = (dir + 1) % 4;
            else if(command == -2){
                if(dir == 0) dir = 3;
                else dir = dir - 1;
            }else{
                // So, here we need to move.
                // Don't calculate rightway, move one step and check if
                // we hit a obstacle. 1 <= k <=9, so no need to worry about TLE.

                for(int i = 0; i < command; i++){
                    int newX = currX + xDirs[dir];
                    int newY = currY + yDirs[dir];
                    
                    string s = to_string(newX) + "@" + to_string(newY);
                    // cout << s << endl;
                    if(mp[s] == true) break;

                    int dist = newX*newX + newY*newY;
                    maxDist = max(dist, maxDist);

                    currX = newX;
                    currY = newY;
                }
            }
        }


        return maxDist;


    }
};