class Solution {
public:
    bool solve(int x,int y,int idx,vector<vector<char>> &board,string &word) {
        if(idx==word.size()) return true;
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]!=word[idx]) return false;
        char temp=board[x][y];
        board[x][y]='#';
        bool found= solve(x+1,y,idx+1,board,word)||solve(x,y+1,idx+1,board,word)||solve(x-1,y,idx+1,board,word)||solve(x,y-1,idx+1,board,word);
        board[x][y]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(solve(i,j,0,board,word)) return true;
            }
        }
        return false;
    }
};