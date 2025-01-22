class Node{
    public:
    int r;
    int c;
    int dist;

    Node(int r, int c, int dist){
        this->r = r;
        this->c = c;
        this->dist = dist;
    }
};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // For visited we can use -ve value.
        queue<Node> bfsQ;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(isWater[r][c] == 1){
                    isWater[r][c] = 0;
                    bfsQ.push(Node(r,c,0));
                }else{
                    isWater[r][c] = 1;
                }
            }
        }

        while(!bfsQ.empty()){
            Node fn = bfsQ.front();
            bfsQ.pop();
            int r = fn.r;
            int c = fn.c;
            int dist = fn.dist;

            for(vector<int> dir: dirs){
                int newR = r + dir[0];
                int newC = c + dir[1];

                if(newR < 0 or newR >= m) continue;
                if(newC < 0 or newC >= n) continue;

                if(isWater[newR][newC] <= 0) continue; // Means it is already visited.

                isWater[newR][newC] = -(dist+1);
                bfsQ.push(Node(newR,newC,dist+1));
            }
        }

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                isWater[r][c] = abs(isWater[r][c]);
            }
        }

        return isWater;

    }
};