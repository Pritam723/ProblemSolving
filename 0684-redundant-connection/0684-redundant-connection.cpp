class Solution {
public:

    int findParent(int node, vector<int> &parent){
        if(parent[node] == node) return node;

        int p = findParent(parent[node], parent);
        parent[node] = p;

        return p;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // We can surely apply union find algorithm for this one.
        // Also UF will follow this only: If there are multiple answers,
        // return the answer that occurs last in the input.
        int n = edges.size();
        // So, nodes are from 1 to n.

        // Initially every one has rank = 0. Parent(i) = i.
        // Logic of union is. If Rank(u) > Rank(v), then make
        // parent(v) = prent(u). No need to do Rank++. If Rank(u) and
        // Rank(v) are same, choose any as parent and do Rank(that)++.

        // Now, how to detect a cycle? See, if we ever see for an edge
        // (s,d), parent(s) == parent(d), we can say that this is a cycle
        // causing edge.

        vector<int> rank(n+1, 0);
        vector<int> parent(n+1, -1);

        for(int i = 1; i <= n; i++) parent[i] = i;
        // Do not consider Node-0.

        vector<int> ans;

        for(vector<int> edge: edges){
            int src = edge[0], dst = edge[1];

            if(findParent(src, parent) == findParent(dst, parent)){
                ans = edge;
                break;
            }

            // So, they have different parent. We will do union.

            if(rank[src] > rank[dst]){
                int src_parent = findParent(src, parent);
                int dst_parent = findParent(dst, parent);

                parent[dst_parent] = src_parent;

            }else if(rank[dst] > rank[src]){
                int src_parent = findParent(src, parent);
                int dst_parent = findParent(dst, parent);

                parent[src_parent] = dst_parent;
            }else{
                // Equal case.
                int src_parent = findParent(src, parent);
                int dst_parent = findParent(dst, parent);

                parent[dst_parent] = src_parent;
                rank[src_parent]++;
            }
        }

        return ans;
    }
};