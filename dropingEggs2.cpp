/*
 *  get the least test times for the situation that using n eggs to find out on which floor that the eggs fall down will break
 *  Input:eggsNum = n;height = m;
 *  we will discuss the problem from the following case:
 *  the same as the situation with two eggs,we assume that kth floor is the original testing floor,so ,while droping the eggs
 *  from kth floor,it has two cases:
 *  1)the egg breaks,then ,we could test the previous (k-1) floors with n-1 eggs
 *  2)the egg doesn't break,we test the rest (m-k) floors with n eggs
 *  finally, we delivery the transform function,as fllows,
 *      f[n][m] = (min{1+max{f[n-1][k-1],f[n][m-k]}} | 0<=k<=m);
 */
 
 int getTestTime2(const int& eggsNum,const int& height){
      //some defination;
      int f[n+1][m+1];
      //some initialization
      f[0][0] = 0;
      for(int i=1;i<=n;i++){
          f[0][i] = 0;
          f[1][i] = i-1;
          f[i][0] = 0;
          f[i][1] = 0;
      }
      
      //the main logic
      for(int i = 2;i<=n;i++)
        for(int j=2;j<=m;j++){
          //ensure that the original value is the max value
          f[i][j] = m+1;
          for(int k=1;k<=j;k++){
            f[i][j] = min(f[i][j],1+max(f[i-1][k-1],f[i][j-k]));
          }
        }
        
      return f[n][m];
 }
