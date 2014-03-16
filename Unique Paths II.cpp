class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n;
        if(m != 0)
        {
            n = obstacleGrid[0].size();
        }
        int cost[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                    cost[i][j] = 0;
                else if(i-1>=0 && j-1>=0)
                    cost[i][j] = cost[i-1][j] + cost[i][j-1];
                else if(i-1>=0)
                    cost[i][j] = cost[i-1][j];
                else if(j-1>=0)
                    cost[i][j] = cost[i][j-1];
                else
                    cost[i][j] = 1;
            }
        }
        return cost[m-1][n-1];
    }
};
