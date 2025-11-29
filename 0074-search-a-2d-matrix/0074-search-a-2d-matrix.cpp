class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rsize=matrix.size(),csize=matrix[0].size();
        int low=0,high=rsize*csize-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            int row=mid/csize,col=mid%csize;
            if(matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};