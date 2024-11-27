class Solution {
public:
    int bfs(int n, vector<vector<int>> &adjList){
        int src = 0;
        int dest = n-1;
        vector<bool> visited(n, false);

        queue<int> bfsQ;
        bfsQ.push(src);
        visited[src] = true;

        int dist = 0;

        while(!bfsQ.empty()){
            int qSize = bfsQ.size();
            // Taking a step.
            dist++;
            while(qSize--){
                int frontNode = bfsQ.front(); bfsQ.pop();
                vector<int> neighbours = adjList[frontNode];

                for(int neighbour: neighbours){
                    if(visited[neighbour]) continue;
                    bfsQ.push(neighbour);
                    visited[neighbour] = true;
                }
            }
            // Now, check whether we have reached n-1 or not.
            if(visited[n-1] == true) break;
        }
        return dist;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distance(n, 0);
        vector<vector<int>> adjList(n, vector<int>(0));

        for(int i = 0; i <= n-2; i++){
            adjList[i].push_back(i+1);
            distance[i] = i; // Denotes distance of i from node-0.
        }

        distance[n-1] = n-1;

        int q = queries.size();
        vector<int> ans(q, 0);

        // Now, process the queries one by one.
        int idx = 0;
        for(vector<int> query: queries){
            int src = query[0], dest = query[1];
            // So, suppose, we get (2,4)
            adjList[src].push_back(dest);
            int dist = bfs(n, adjList);

            ans[idx] = dist;
            idx++;
        }
        return ans;
    }
};