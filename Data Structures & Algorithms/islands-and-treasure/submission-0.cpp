class Solution {
public:

    void bfs(vector<vector<int>>& grid,int i,int j)
    {
     vector<vector<int>> dirs= {{1,0},{-1,0},{0,-1},{0,1}};
     queue<pair<int,int>> qu;
     qu.push({i,j});
     while(qu.size())
     {
        auto[i,j]=qu.front();
        qu.pop();
        for(auto dir:dirs)
        {   int nr=i+dir[0];
            int nc=j+dir[1];
            if( nr<0 || nc<0|| nr>=grid.size()||nc>=grid[0].size())
                continue;
            if(grid[nr][nc]==-1)
                continue;
            if(grid[nr][nc]>grid[i][j]+1)
            {
                grid[i+dir[0]][j+dir[1]]=grid[i][j]+1;
                qu.push({nr,nc});
            }
            
        }
     }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {

        int len=grid.size();
        int wid=grid[0].size();
        for (int i=0;i<len;i++)
            for (int j=0;j<wid;j++)
                if(grid[i][j]==0)
                    bfs(grid,i,j);
    }
};
