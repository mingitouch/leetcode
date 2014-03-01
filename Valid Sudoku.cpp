class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool flag = true;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                    continue;
                int x = i / 3;
                int y = j / 3;
                for(int ix = 0;ix < 9;ix++)
                {
                    if(j != ix)
                    {
                        if(board[i][ix] == board[i][j])
                            return false;
                    }
                }
                for(int iy = 0;iy < 9;iy++)
                {
                    if(i != iy)
                    {
                        if(board[iy][j] == board[i][j])
                            return false;
                    }
                }
                for(int ix = x * 3; ix < (x+1)*3;ix++)
                {
                    for(int iy = y * 3;iy <(y+1)*3;iy++)
                    {
                        if(!(ix == i && iy == j))
                        {
                            if(board[ix][iy] == board[i][j])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
