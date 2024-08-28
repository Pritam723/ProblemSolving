class Solution {
public:
    bool isValid(int m, int n, int r, int c){
        if(r < 0 or r >= m) return false;
        if(c < 0 or c >= n) return false;
        return true;
    }

    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int m, int n, int r, int c, vector<int> &rowDirs, vector<int> &colDirs, bool &isSubIsland){
        // We are here means it is not yet visited. So, mark it visited, but before that check it with grid1.
        if(grid1[r][c] != 1) isSubIsland = false; // But do not return from here, we need to mark the entire island in grid2.
        
        grid2[r][c] = 2;

        for(int i = 0; i < 4; i++){
            int newR = r + rowDirs[i];
            int newC = c + colDirs[i];
            // cout << newR << " " << newC << endl;
            if(isValid(m,n,newR,newC) && grid2[newR][newC] == 1) dfs(grid1, grid2, m, n, newR, newC, rowDirs, colDirs, isSubIsland);
        }
        return;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        // Logic is: We will do dfs on both at the same time. But start from places for
        // which grid2[r][c] == 1 only. Now, for an island in grid2, we want to see if
        // all 1's atleast match with grid1.

        // grid2 = 1 && grid1 == 1, it is fine.
        // grid2 != 1, we do not care about grid1. It is fine.
        // grid2 = 1 && grid1 = 0, surely this is not a sub-island
        // but we need to mark all the area in this island in grid2
        // as visited area. We can use visited mtx, or can use the
        // same grid2 itself.

        vector<int> rowDirs = {1, -1, 0, 0};
        vector<int> colDirs = {0, 0, -1, 1};
        
        int ans = 0;
        
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid2[r][c] == 1){
                    bool isSubIsland = true;
                    dfs(grid1, grid2, m, n, r, c, rowDirs, colDirs, isSubIsland);
                    // If after this DFS isSubIsland remains true, we count it.
                    if(isSubIsland) ans++;
                }
            }
        }
        return ans;
    }
};