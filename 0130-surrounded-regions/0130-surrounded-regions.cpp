class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> safe(m,vector<int> (n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O') {
                    board[i][j]='#';
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            pair<int,int> node=q.front();
            int x=node.first,y=node.second;
            q.pop();
            if(x-1>=0&&board[x-1][y]=='O') {
                q.push({x-1,y});
                board[x-1][y]='#';
            }
            if(y-1>=0&&board[x][y-1]=='O') {
                q.push({x,y-1});
                board[x][y-1]='#';
            }
            if(x+1<m&&board[x+1][y]=='O') {
                q.push({x+1,y});
                board[x+1][y]='#';
            }
            if(y+1<n&&board[x][y+1]=='O') {
                q.push({x,y+1});
                board[x][y+1]='#';
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='#') {
                    board[i][j]='O';
                }
                else board[i][j]='X';
            }
        }
    }
};