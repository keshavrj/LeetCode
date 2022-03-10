class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(dfs(board, i, j, word, 0))
                    return true;
        return false;
        
    }
    
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int k)
    {
        if(k==word.size())return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[k])
            return false;
        char c= board[i][j];
        board[i][j]= '!';
        if(dfs(board, i+1, j, word, k+1)||dfs(board, i-1, j, word, k+1)||
          dfs(board, i, j+1, word, k+1)||dfs(board, i, j-1, word, k+1))return true;
        
        board[i][j]= c;
        return false;
        
    }
};