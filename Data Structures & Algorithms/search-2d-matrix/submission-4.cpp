class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp.push_back(matrix[i][j]);
            }
        }
        int low = 0;
        int high = m*n-1;

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(target<temp[mid])
            {
                high = mid-1;
            }
            else if(target>temp[mid])
            {
                low = mid+1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
