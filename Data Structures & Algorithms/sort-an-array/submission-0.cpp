class Solution {
public:
    int partition(vector<int>& nums, int low, int high)
    {
        int pivot = nums[low], i=low, j=high;
        while(i<j)
        {
            while(nums[i]<=pivot && i<high)
            {
                i++;
            }
            while(nums[j]>pivot && j>low)
            {
                j--;
            }
            if(i<j)
            swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    
    void quickSort(vector<int>& nums, int low, int high)
    {
        if(low<high)
        {
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot-1);
            quickSort(nums, pivot+1, high);
        }
    }


    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        
        return nums;
    }
};