class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            int maxrow=0;
            for(int i=1;i<n;i++) {
                if(mat[i][mid]>mat[maxrow][mid]) maxrow=i;
            }
            int leftval= mid-1>=0?mat[maxrow][mid-1]:-1;
            int rightval= mid+1<m?mat[maxrow][mid+1]:-1;
            int curval= mat[maxrow][mid];
            if(curval>leftval&&curval>rightval) return {maxrow,mid};
            else if(leftval>curval) high =mid-1;
            else low=mid+1;
        }
        return {0,0};
    }
};