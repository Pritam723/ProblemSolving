class Solution {
public:
    bool canMove(int r, int c, int m, int n,vector<string>& grid){
        if(r < 0 or r >= m) return false;
        if(c < 0 or c >= n) return false;
        
        if(grid[r][c] == '#') return false;

        return true;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int keys = 0;
        int keyStatus = 0;

        vector<int> startConfig = {0,0,0,0}; // row,col,steps,keyStatus.

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                char ch = grid[r][c];
                if(ch == '@') startConfig = {r,c,0,0};
                if(ch >= 'a' && ch <= 'f') keys++;
            }
        }

        int startRow = startConfig[0];
        int startCol = startConfig[1];

        int target = pow(2, keys) - 1; // If there are 3 keys, our target is to reach 7.

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(target + 1, false)));
        // So, visited has 3 states to maintain. {row, col, keyStatus}

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        // vector<vector<int>> dirs = {{0,1}};

        queue<vector<int>> bfsQ;
        bfsQ.push(startConfig);

        visited[startRow][startCol][keyStatus] = true;

        while(!bfsQ.empty()){
            vector<int> fn = bfsQ.front();
            bfsQ.pop();

            int r = fn[0], c = fn[1], steps = fn[2], currKeyStatus = fn[3];

            // cout << "printing " << r << " " << c << " " << steps << " " << currKeyStatus << endl;

            if(currKeyStatus == target){
                // cout << "got a match" << endl;
                return steps;
            }
            // Now from a node we want to see 4 directions.
            for(int i = 0; i < 4; i++){
            
                int newR = r + dirs[i][0];
                int newC = c + dirs[i][1];

                // Check if we can move to this cell or not.
                if(canMove(newR, newC, m, n, grid)){
                    // cout << " here with " << newR << " " << newC << endl;
                    // So, we can move in this direction. But before moving
                    // also check if we are getting a key here.

                    char ch = grid[newR][newC];

                    if(ch >= 'a' && ch <= 'f'){
                        // So, we got a key.
                        int chIdx = ch - 'a';
                        int mux = 1;
                        mux = mux << chIdx; // For 'b' mux is 000010.
                        // So, if keyStatus is 001001, we make it 001011 now.
                        int newKeyStatus = currKeyStatus | mux;
                        
                        cout << "Got a key " << newKeyStatus << endl;


                        if(visited[newR][newC][newKeyStatus] == false){
                            cout << "Push in bfsQ" << endl;
                            bfsQ.push({newR, newC, steps+1, newKeyStatus});
                            visited[newR][newC][newKeyStatus] = true;
                        }

                    }else if(ch >= 'A' && ch <= 'F'){
                        // cout << "Got a lock " << endl;

                        // So, we got a lock. We need to check if we have corresponding key or not.
                        int chIdx = ch - 'A';
                        // So, for 'B' we get 1. So, we need to make a mux = 000010.
                        int mux = 1;
                        mux = currKeyStatus >> chIdx;

                        // Now, see if keyStatus is set at that index or not.
                        // cout << (mux & currKeyStatus) << endl;
                        // if(mux & currKeyStatus == 0){
                        //     cout << "Do not have key" << endl;
                        // }
                        // if(mux & currKeyStatus == 1){
                        //     cout << "Got lock have key" << endl;
                        // }

                        if((mux & 1) == 1 and visited[newR][newC][currKeyStatus] == false){
                            bfsQ.push({newR, newC, steps+1, currKeyStatus});
                            visited[newR][newC][currKeyStatus] = true;
                        }
                    }else{
                        // So, it is a '.' No need to change the key status.
                        if(visited[newR][newC][currKeyStatus] == false){
                            bfsQ.push({newR, newC, steps+1, currKeyStatus});
                            visited[newR][newC][currKeyStatus] = true;
                        }
                    }
                }
            }
        }


        return -1;

    }
};