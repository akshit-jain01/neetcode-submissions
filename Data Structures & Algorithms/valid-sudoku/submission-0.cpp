class Solution {
public:
    bool isrow(int row, vector<vector<char>>& board)
    {
        vector<int> count(10, 0);
        for(int i=0;i<9;i++)
        {
            if(board[row][i]=='.') continue;
            int num = board[row][i]-'0';
            if(count[num] != 0)
            {
                return false;
            }
            else
            {
                count[num] = 1;
            }
        }
        return true;
    }
    bool iscol(int col, vector<vector<char>>& board)
    {
        vector<int> count(10, 0);
        for(int i=0;i<9;i++)
        {
            if(board[i][col]=='.') continue;
            int num = board[i][col]-'0';
            if(count[num] != 0)
            {
                return false;
            }
            else
            {
                count[num] = 1;
            }
        }
        return true;
    }
    bool isgrid(int row, int col, vector<vector<char>>& board)
    {
        vector<int> count(10, 0);
        for(int i=row;i<row+3;i++)
        {
            for(int j = col; j<col+3;j++)
            {
                if(board[i][j]=='.') continue;
                int num  = board[i][j]-'0';
                if(count[num] != 0)
                {
                    return false;
                }
                else
                {
                    count[num] = 1;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            if(!isrow(i, board))
            {
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(!iscol(i, board))
            {
                return false;
            }
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                if(!isgrid(i, j, board))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
