class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Refer notes, Dijkstra's will not work here.
        // Bellman Ford at i-th stpe says: What is the shortest distance from src to other node
        // using i edge at max. So, actually we need to use this algo here.

        // We need to relax all edges for k+1 times. (k at max is n-1 so it is fine).
        // But we must avoid the continuous updation thing as that will not be appropriate
        // with current logic here.

        vector<int> prev_distance(n, INT_MAX);
        vector<int> new_distance(n, INT_MAX);

        prev_distance[src] = 0;
        new_distance[src] = 0;

        int t = 0;
        while(t <= k){
            for(vector<int> flight: flights){
                int src = flight[0], dest = flight[1], weight = flight[2];
                // Now, relax this edge.
                if((long long)new_distance[dest] > (long long)prev_distance[src] + (long long)weight){
                    // So, we need to update the weight.
                    new_distance[dest] = prev_distance[src] + weight;
                }
            }
            // After this, make
            prev_distance = new_distance;
            t++;
        }

        if(new_distance[dst] == INT_MAX) return -1;
        return new_distance[dst];

    }
};