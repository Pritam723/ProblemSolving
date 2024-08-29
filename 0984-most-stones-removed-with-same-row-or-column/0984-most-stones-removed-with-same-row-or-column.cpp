class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int n, int i, int &count, vector<bool> &visited){
        visited[i] = true;
        count = count + 1;
        vector<int> neighbours = adjList[i];

        for(int neighbour: neighbours){
            if(visited[neighbour] == true) continue;
            // Otherwisw visit it.
            dfs(adjList, n, neighbour, count, visited);
        }

        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        // So, if we imagine the stones as nodes of a graph, we can say that if
        // 2 stones have any of the atleast one common co-ordinate, then they are
        // basically part of same component i.e., connected by a graph.
        // And here for a component having x-nodes we can remove x-1 nodes. (Even true for x = 1).

        // So, we can use dfs to count no. of nodes in each components (Or learn SCC algorithms).
        int n = stones.size();
        vector<vector<int>> adjList(n, vector<int>(0));

        for(int i = 0; i < n; i++){
            vector<int> stone1 = stones[i];
            for(int j = i+1; j < n; j++){
                vector<int> stone2 = stones[j];
                // Check if stone1 and stone2 should be connected.
                if(stone1[0] == stone2[0] or stone1[1] == stone2[1]){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Now, apply dfs, and we must keep track of the visited.
        vector<bool> visited(n, false);

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(visited[n] == true) continue;
            // Otherwise we need to visit it using dfs.
            // And also count the no. of nodes it is connected to.

            int count = 0;
            dfs(adjList, n, i, count, visited);
            ans = ans + (count - 1);
        }

        return ans;
    }
};