class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()> nums2.size()) {
            return findMedianSortedArrays(nums2,nums1);
        }

        int n= nums1.size();
        int m= nums2.size();
        int totalleft = (m+n+1)/2;
        int left= 0, right = n;
        while(left<= right){
           int i = (left+right) /2;
           int j= totalleft- i;
           int leftA = (i>0)? nums1[i-1]: INT_MIN;
           int rightA = (i>= n)? INT_MAX: nums1[i];
           int leftB = (j>0)? nums2[j-1]: INT_MIN;
           int rightB = (j>= m)? INT_MAX: nums2[j];
            if(leftA<= rightB && leftB<= rightA) {
                if((m+n)%2 == 0) return double(max(leftA,leftB)+ min(rightB,rightA))/2;
                else return max(leftA,leftB);
            }
            else if(leftA > rightB) right = i;
            else left = i+1;
        } 
        return -1.00;
    }
};