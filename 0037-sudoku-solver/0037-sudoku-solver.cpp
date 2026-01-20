class Solution {
public:
    bool isSafe(char num,int x,int y,vector<vector<char>> &board) {
        for(int i=0;i<9;i++) {
            if(board[x][i]==num||board[i][y]==num) return false;
        }
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[(x/3)*3+i][(y/3)*3+j]==num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                    for(char ch='1';ch<='9';ch++) {
                        if(isSafe(ch,i,j,board)) {
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};