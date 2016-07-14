//Unique Paths II
/*
 *  Follow up for "Unique Paths":
 *  
 *  Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *  
 *  An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *  
 *  For example,
 *  There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *  
 *  [
 *    [0,0,0],
 *    [0,1,0],
 *    [0,0,0]
 *  ]
 *  The total number of unique paths is 2.
 */
 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int array[m][n] = {0};
        for(int i=0;i<m;i++)
            for(int j =0;j<n;j++)
                array[i][j] = 0;
        
        bool flag = true;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0] == 1)
                break;
            array[i][0] = 1;
        }
        
        for(int i = 0;i<n;i++){
            if(obstacleGrid[0][i] == 1)
                break;
            array[0][i] = 1;
        }
        
        for(int i = 1;i<m;i++)
            for(int j=1;j<n;j++){
                if(obstacleGrid[i-1][j] != 1)
                    array[i][j] += array[i-1][j];
                if(obstacleGrid[i][j-1] != 1)
                    array[i][j] += array[i][j-1];
                
                if(obstacleGrid[i][j]==1)
                    array[i][j] = 0;
            }
            
        return array[m-1][n-1];
                
    }
};
