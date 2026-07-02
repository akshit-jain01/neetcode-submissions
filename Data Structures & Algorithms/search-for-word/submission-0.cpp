class Solution {
public:
    vector<vector<bool>> visited;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index)
    {
        int m = board.size();
        int n = board[0].size();
        if(board[i][j] != word[index])
        {
            return false;
        }
        
        if(index==word.size()-1)
        {
            return true;
        }
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        //choose
        visited[i][j] = true;

        //explore
        for(int k = 0 ; k<4;k++)
        {
            int row = i + delx[k];
            int col = j + dely[k];
            if(row>=0 && row<m && col>=0 && col<n && !visited[row][col])
            {
                if(dfs(board, word, row, col, index+1))
                return true;
            }
        }
        //backtrack
        visited[i][j] = false;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board, word, i, j, 0))
                    return true;
                }
            }
        }
        return false;
    }
};
