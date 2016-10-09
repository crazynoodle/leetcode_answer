/*
 * assum F[n] to be the least testing time for the answer that using two eggs to test from nth floor;
 * droping from the ith floor two case:
 *     1)the first eggs broke,then we need to test the second eggs from 0th floor from (i-1)th floor;
 *     2)the first eggs didn't break,then we could use two eggs to test the rest (n-i) floor;
 * so,finally,we delivered the function F(n) = 1 + F(n-i);
 * -> F(n) = (min{1+max{i-1,F(n-i)}} | 0 <= i <= n);
 */
 
 //in this case, we only discuss the situation of using two eggs;later,we will expand the situation that using n eggs,and m floors;
 int getTest(const int& height){
    int f[height+1];
    f[0] = 0;
    f[1] = 1;
    //only to ensure that the original value is the max value
    for(int i=2;i<=height;i++)
      f[i] = height+1;
      
    for(int i=2;i<=height;i++){
      for(int j=1;j<=i;j++)
        f[j]=min(f[j],1+max(j-1,f[i-j]));
    }
    
    return f[height];
 }
