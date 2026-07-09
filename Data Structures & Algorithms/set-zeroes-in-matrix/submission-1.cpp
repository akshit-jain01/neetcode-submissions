class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        stack<int> row;
        stack<int> col;

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    row.push(i);
                    col.push(j);
                }
            }
        }

        while(!row.empty())
        {
            int i = row.top();
            for(int k = 0; k<n; k++)
            {
                matrix[i][k] = 0;
            }
            row.pop();
        }
        while(!col.empty())
        {
            int i = col.top();
            for(int k = 0; k<m; k++)
            {
                matrix[k][i] = 0;
            }
            col.pop();
        }
    }
};
