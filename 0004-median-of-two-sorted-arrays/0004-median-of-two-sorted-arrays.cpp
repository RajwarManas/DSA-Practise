class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        std::vector<int> vec ;
        while(i<nums1.size()&&j<nums2.size()) {
            if(nums1[i]<=nums2[j]) {
                vec.push_back(nums1[i]);
                i++;
            }
            else {
                vec.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()) {
            vec.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()) {
            vec.push_back(nums2[j]);
            j++;
        }
        if (vec.size()%2==0) {
            return ((double)vec[(int)vec.size()/2]+(double)vec[(int)vec.size()/2-1])/2;
        }
        else return (double)vec[vec.size()/2] ;
    }
};