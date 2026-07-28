class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        int p = m-1;
        int q = n-1;
        while(i>=0)
        {
            if(p < 0)
            {
                nums1[i] = nums2[q];
                q--;
            }
            else if(q < 0)
            {
                nums1[i] = nums1[p];
                p--;
            }
            else if(nums1[p]>nums2[q])
            {
                nums1[i] = nums1[p];
                p--;
            }
            else 
            {
                nums1[i] = nums2[q];
                q--;
            }
            i--;
            
        }
    }
};
