class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        queue<pair<int,int>> q;
        int orgCol=image[sr][sc];
        if(color==orgCol) return image;
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                pair<int,int> node=q.front();
                q.pop();
                int x=node.first,y=node.second;
                if(x-1>=0&&image[x-1][y]==orgCol) {
                    image[x-1][y]=color;
                    q.push({x-1,y});
                }
                if(y-1>=0&&image[x][y-1]==orgCol) {
                    image[x][y-1]=color;
                    q.push({x,y-1});
                }
                if(x+1<m&&image[x+1][y]==orgCol) {
                    image[x+1][y]=color;
                    q.push({x+1,y});
                }
                if(y+1<n&&image[x][y+1]==orgCol) {
                    image[x][y+1]=color;
                    q.push({x,y+1});
                }
            }
        }
        return image;
    }
};