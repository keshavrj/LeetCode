class Solution {
public:
    bool rowCheck(vector<vector<char>>& board, int row=0)
    {
        while(row<9){
        set<int> st;
        for(int i=0;i<9;i++)
        {
            char x= board[i][row];
            if(x!='.' && st.find(x-'0')!=st.end())
                return false;
            else if(x!='.')st.insert(x-'0');
        }
            row++;
        }
        return true;
    }
    bool colCheck(vector<vector<char>>& board, int col=0)
    {
        while(col<9){
        set<int> st;
        for(int i=0;i<9;i++)
        {
            char x= board[col][i];
            if(x!='.' && st.find(x-'0')!=st.end())
                return false;
            else if(x!='.')st.insert(x-'0');
        }
            col++;
        }
        return true;
    }
    bool check(vector<vector<char>> &b, int row, int col)
    {
        set<int> st;
        for(int i=row;i<row+3;i++)
        {
            for(int j= col;j<col+3;j++)
            {
                char x= b[i][j];
                if(x!='.' && st.find(x-'0')!=st.end())
                     return false;
                else if(x!='.')st.insert(x-'0');
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        if(colCheck(board)==false or rowCheck(board)==false)return false;
        
        for(int i=0;i<8;i+=3)
        {
            for(int j=0;j<8;j+=3)
            {
                if(!check(board, i, j))
                    return false;
            }
        }
        return true;
    }
};