//Set Matrix Zeroes

/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */
 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // map<int,vector<int>> zeroTag;

        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> cowTag(m,0);
        vector<int> colTag(n,0);
        
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(matrix[i][j] == 0){
                    cowTag[i] = 1;
                    colTag[j] = 1;
                }
 
        for(int i = 0;i<m;i++){
            if(cowTag[i]){
              for(int x=0;x<n;x++)
                matrix[i][x] = 0;
            }
        }
        
        for(int i = 0;i<n;i++){
            if(colTag[i]){
              for(int x=0;x<m;x++)
                matrix[x][i] = 0;
            }
        }
        
       return; 
                // zeroTag.insert(pair<int,int>(i,j));
                
    }
};
