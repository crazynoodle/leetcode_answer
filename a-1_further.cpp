/*
 *  For example, given array S = [-1, 0, 1, 2, -1, -4],
 *  A solution set is:
 *  [
 *    [-1, 0, 1],
 *    [-1, -1, 2]
 *  ]
 */
 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > result;
        if(num.size()<3) return result;
    
        sort(num.begin(),num.end());
        int size = num.size();
        typedef vector<int>::iterator iter;
        iter last = num.end();
        for(iter a=num.begin();a<(last-2);a=upper_bound(a,last-2,*a))
            for(iter b = a+1;b<(last-1);b=upper_bound(b,last-1,*b))
                for(iter c = b+1;c<last;c++){
                    if(*c+*b+*a == 0){
                        vector<int> vec;  
                        vec.push_back(*a);  
                        vec.push_back(*b);  
                        vec.push_back(*c);  
                        result.push_back(vec);
                        break;
                    }
                }
                    
        return result;
     
    //  if(num.size()<3)return result;  
    //  sort(num.begin(),num.end());  
    //  const int target=0;  
  
    //  vector<int>::iterator last=num.end();  
    //  for(vector<int>::iterator a=num.begin();a<(last-2);a=upper_bound(a,last-2,*a)){//ensure that while there is two similar number,it won take the same number twice;  
    //   for(vector<int>::iterator b=a+1;b<(last-1);b=upper_bound(b,last-1,*b)){  
    //          int c=target-*b-*a;  
  
    //          if(binary_search(b+1,last,c)){  
    //                 vector<int> vec;  
    //                 vec.push_back(*a);  
    //                 vec.push_back(*b);  
    //                 vec.push_back(c);  
    //                 result.push_back(vec);  
    //             }    
    //   }  
       
    //  }  
    //  return result;
    }
};
