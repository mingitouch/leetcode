class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();
        if(len <= nRows)
            return s;
        char array[nRows][len];
        for(int i=0;i<nRows;i++)
            for(int j=0;j<len;j++)
                array[i][j] = '&';
        int x=0;
        int y=0;
        bool flag = false;
        for(int i=0;i<s.length();i++)
        {
            if(!flag)
            {
                array[x][y] = s[i];
                x++;
            }
            else
            {
                x--;
                y++;
                if(x==0)
				{
					flag = false;
					array[x][y] = s[i];
					x++;
					continue;
				}
                array[x][y] = s[i];
            }
            if(x==nRows)
            {
                x--;
                flag = true;
            }
            else if(x==0)
            {
                flag = false;
            }
            
        }
        int index = 0;
        for(int i=0;i<nRows;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(array[i][j] != '&')
                {
                    s[index] = array[i][j];
                    index++;
                }
            }
        }
        return s;
    }
};
