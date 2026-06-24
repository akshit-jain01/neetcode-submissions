class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=m,j=0;
        while(i<(m+n))
        {
            nums1[i]=nums2[j];
            j++;
            i++;
        }
        sort(nums1.begin(), nums1.end());
    }
};