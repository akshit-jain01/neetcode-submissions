class Solution {
public:
    vector<vector<string>> ans;
    bool valid(int row, int col, vector<string>& board)
    {
        int n = board.size();
        for(int i = row-1;i>=0;i--)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
            
        }
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i = row-1, j = col+1; i>=0 && j<=n ;i--, j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        return true;
    }
    void solve(vector<string> board, int row)
    {
        int n = board.size();
        if(row == n)
        {
            ans.push_back(board);
            return ;
        }

        for(int col = 0; col < n; col++)
        {
            //explore
            if(valid(row, col, board))
            {
                board[row][col] = 'Q';

                solve(board, row+1);

                board[row][col] = '.';
            }


        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return ans;

    }
};
