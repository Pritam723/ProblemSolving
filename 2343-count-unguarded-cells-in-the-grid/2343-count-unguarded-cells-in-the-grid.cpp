class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<guards.size();i++)
        {
            int x=guards[i][0];
            int y=guards[i][1];
            vis[x][y]=-1;
        }
        for(int i=0;i<walls.size();i++)
        {
            int x=walls[i][0];
            int y=walls[i][1];
            vis[x][y]=2;
        }
        for(int i=0;i<guards.size();i++)
        {
            for(int j=0;j<4;j++)
            {
                int x=guards[i][0];
                int y=guards[i][1];
                while(true)
                {
                    x=x+dx[j];
                    y=y+dy[j];
                    if(x<0 || y<0 || x>=m || y>=n || vis[x][y]==-1 || vis[x][y]==2)
                    {
                        break;
                    }
                    else vis[x][y]=1;
                }

            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0)
                ans++;
            }
        }
        return ans;
        
    }
};