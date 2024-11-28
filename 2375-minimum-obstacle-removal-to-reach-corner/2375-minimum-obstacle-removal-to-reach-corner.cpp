const int dx[4]={0, 0, 1, -1};
const int dy[4]={1, -1, 0, 0};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dist(n+1, vector<int>(m+1, 1e9));
        dist[0][0]=0;
        
        deque<pair<int, int>> qq;
        qq.push_front({0, 0});
        
        
        while(!qq.empty())
        {
            auto [x, y]=qq.front();
            qq.pop_front();
            
            for(int k=0; k<4; k++)
            {
                int xx=x+dx[k];
                int yy=y+dy[k];
                
                if(xx>=0 && yy>=0 && xx<n && yy<m && dist[xx][yy]>dist[x][y]+grid[xx][yy])
                {
                    dist[xx][yy]=dist[x][y]+grid[xx][yy];
                    if(grid[xx][yy])
                        qq.push_back({xx, yy});
                    else
                        qq.push_front({xx, yy});
                }
            }
        }
        return dist[n-1][m-1];
    }
};