class Solution {
public:
    bool help(vector<vector<char>>& board, vector<vector<int>>& used, string word,int n,int i,int j)
    {
        vector<vector<int>> dirs= {{1,0},{-1,0},{0,-1},{0,1}};
        if(n==word.size()-1)
            {cout<<n;
            return true;}
        for(auto dir:dirs)
        {
           int nr=i+dir[0];
           int nc=j+dir[1];
            if(nr<0 || nc<0 ||nr>=board.size()||nc>=board[0].size())
                continue;
            if(!used[nr][nc] && board[nr][nc]==word[n+1])
            {
                used[nr][nc]=1;
                if(help(board,used,word,n+1,nr,nc))
                    { cout<<n;
                        return true;
                    }
                used[nr][nc]=0;
            }
            
        }
        cout<<n;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> used(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]==word[0])
                { 
                    used[i][j]=1;
                    if(help(board,used,word,0,i,j))
                        return true;
                    used[i][j]=0;
                    

                }
                   
        

        return false;
    }
};
