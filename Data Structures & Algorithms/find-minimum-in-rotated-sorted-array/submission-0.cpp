class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;

        while(low<high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid]>nums[high])   //smallest lies in right half
            {
                low = mid+1;
            }
            else
            {
                high = mid;    // the smallest can be the mid element itself
            }
        }
        return nums[low];
    }
};
