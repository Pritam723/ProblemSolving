class Solution {
public:
    bool isValid(int r, int c, int m, int n, vector<vector<bool>> &visited,vector<vector<int>>& heights, int currHeight){
        if(r < 0 or r >= m) return false;
        if(c < 0 or c >= n) return false;
        if(visited[r][c]) return false;

        if(currHeight > heights[r][c]) return false;

        return true;
    }
    void applyBFS(vector<vector<int>>& heights, int m, int n, vector<vector<int>> &coordinates){

        queue<vector<int>> bfsQ;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for(vector<int> coordinate: coordinates){

            int r = coordinate[0];
            int c = coordinate[1];

            bfsQ.push({r,c});

            visited[r][c] = true;
        }

        // Now, since we are doing reverse search, so only go to cells with more height.
        // Because from there only water can flow to this cell.

        while(!bfsQ.empty()){
            vector<int> currCoordinate = bfsQ.front();
            bfsQ.pop();

            int r = currCoordinate[0];
            int c = currCoordinate[1];

            int currHeight = heights[r][c];

            for(int i = 0; i < 4; i++){
                int newR = r + dirs[i][0];
                int newC = c + dirs[i][1];

                if(isValid(newR, newC, m, n, visited, heights, currHeight)){
                    bfsQ.push({newR, newC});
                    visited[newR][newC] = true;
                    // Also we need to add it in coordinates.
                    coordinates.push_back({newR, newC});
                }
            }
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // See, only cells from which water can flow to both Pacific and Atlantic are
        // cell (m-1, 0) and (0, n-1).
        // But a cell indirectly can flow to both Oceans using different paths. Ex. See
        // (1,3) cell can flow to AO -> (1,4) -> AO.
        // (1,3) cell can flow to PO -> (0,3) - > PO.

        // One way is to calculate 2 lists PO and AO and take their intersections.
        // We can use BFS to see which cells are reachable.

        vector<vector<int>> POs = {};
        vector<vector<int>> AOs = {};

        // Now, we know that POs can be reached from following cells directly.
        for(int r = 0; r < m; r++) POs.push_back({r,0});
        for(int c = 0; c < n; c++) POs.push_back({0,c});


        // Now, we know that AOs can be reached from following cells directly.
        for(int r = 0; r < m; r++) AOs.push_back({r,n-1});
        for(int c = 0; c < n; c++) AOs.push_back({m-1,c});


        applyBFS(heights, m, n, POs);
        applyBFS(heights, m, n, AOs);

        // Take intersection of the 2 lists and get the answer.
        unordered_map<string, bool> mp;
        unordered_map<string, bool> added;

        vector<vector<int>> ans = {};

        for(vector<int> PO: POs){
            cout << PO[0] << " " << PO[1] << endl;
            string s = to_string(PO[0]) + "@" + to_string(PO[1]);
            mp[s] = true;
        }

        cout << "--------" << endl;

        for(vector<int> AO: AOs){
            cout << AO[0] << " " << AO[1] << endl;

            string s = to_string(AO[0]) + "@" + to_string(AO[1]);
            if(mp[s] == true and added[s] == false){
                ans.push_back(AO);
                added[s] = true;
            }
        }

        return ans;


    }
};