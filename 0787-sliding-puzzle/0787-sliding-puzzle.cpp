class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        if(r < 0 or r >= m) return false;
        if(c < 0 or c >= n) return false;
        return true;
    }

    vector<string> getNeighbours(string &frontNode, int m, int n, unordered_map<string, bool> &visited){
        vector<string> neighbours;

        // First see where the number 0 is.
        int idx = 0;
        while(frontNode[idx] != '0') idx++;

        // So, we got the index of '0'. Say it is 4.
        // So, as per cell logic we can get row and col.

        int r = idx/n;
        int c = idx % n;

        // Now, we can apply the 4 directions and can see what are the possibilities.
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = 0; i < 4; i++){
            int newR = r + dirs[i][0];
            int newC = c + dirs[i][1];

            if(!isValid(newR, newC, m, n)) continue; // There is no point in checking this.

            // Otherwise it is a valid cell. Now we need to see which idx in the String it is.
            int newIdx = newR * n + newC;

            swap(frontNode[idx], frontNode[newIdx]);
            // So, we got a new string. But check if it is visited or not.
            if(visited[frontNode] == false) neighbours.push_back(frontNode);
            // And then swap back the idx for next directions.
            swap(frontNode[idx], frontNode[newIdx]);
        }

        return neighbours;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int count = 0;

        int m = board.size();
        int n = board[0].size();

        string source = "";
        string target = "123450";

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = board[i][j];
                char ch = '0' + val;
                source.push_back(ch);
            }
        }

        // cout << source << endl;
        // We will apply BFS to see how quickly we can reach from source to target.
        if(source == target) return 0;

        // Now, in BFS at each step the 0 can move 4 directions. We need to mathematically
        // see what strings those movements (of 0) lead to.
        unordered_map<string, bool> visited;
        queue<string> bfsQ;
        bfsQ.push(source);
        visited[source] = true;

        while(!bfsQ.empty()){

            int qSize = bfsQ.size();
            // At a step we move following.
            count = count + 1;

            while(qSize--){   
                string frontNode = bfsQ.front();
                bfsQ.pop();

                // Now, we need to move the 0 to possible 4 directions.
                // So, we need to see what are the neighbours of frontNode
                // actually.

                vector<string> neighbours = getNeighbours(frontNode, m, n, visited);
                // So, we got the unvisited neighbours only.

                for(string neighbour: neighbours){
                    bfsQ.push(neighbour);
                    visited[neighbour] = true;
                }
            }

            // Now, if we see target is reached, we can stop.
            if(visited[target] == true) break;
        }


        if(visited[target] != true) return -1;
        return count;
    }
};