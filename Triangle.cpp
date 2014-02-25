class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle[triangle.size()-1].size();
        int matrix[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                matrix[i][j]=INT_MAX;
        }
        matrix[0][0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j-1<0)
                    matrix[i][j]=matrix[i-1][j]+triangle[i][j];
                else
                    matrix[i][j]=min(matrix[i-1][j-1], matrix[i-1][j])+triangle[i][j];
            }
        }
        int minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(matrix[n-1][i]<minimum)
                minimum=matrix[n-1][i];
        }
        return minimum;
    }
};
