/*
 * To Write a Repository about backtracking algorithm
 *
 */

//queue problem

//wordSearching problem
class queen{
  public:
    queen(const int x):dimension(x){
      pos.resize(dmension);
    }
    void setDimension(const int x){
      dimension = x;
      pos.resize(dimension);
      return;
    }
    int getDimension(){
      return dimension;
    }
    
    void findSolution(){
      for(int i=0;i<dimension;i++){
          pos[0] = i;
          search(1);
      }
    }
    
    void search(int index){
      if(index == dimension){
        res.push_back(pos);
        return;
      }
      
      for(int i = 0;i<dimesion;i++){
        pos[index] = i;
        int k = 0;
        while(k++ < index){
          //judge it is suitable or not to place at this postion 
          if(){
            if(k == index){
              search(index+1);
            }
          }else
            break;
        }
      }
    }
  private:
    vector<vector<int>> res;
    vector<int> pos;
    int dimension;
}
