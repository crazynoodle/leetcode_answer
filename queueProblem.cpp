#include <iostream>
#include <string>
#include <vector>

using namespace std;

class queen{
  public:
    queen(const int x):dimension(x){
      pos.resize(dimension,0);
    }
    void setDimension(const int x){
      dimension = x;
      pos.reserve(dimension);
      return;
    }
    int getDimension(){
      return dimension;
    }
    
    vector<vector<int> > findSolution(){
      for(int i=0;i<dimension;i++){
          pos[0] = i;
          search(1);
      }
      return res;
    }
    
    void search(int index){
      if(index == dimension){
        res.push_back(pos);
        return;
      }
      
      for(int i = 0;i<dimension;i++){
        pos[index] = i;
        int k = 0;
        while(k < index){
            //judge it is suitable or not to place at this postion 
            if((pos[index] != pos[k])  && index-k != pos[index]-pos[k] && index-k != pos[k]-pos[index]){
                k++;
                if(k == index){
                  search(index+1);
                }
                // k++;
            }else
                break;
        }
      }
    }
    
  private:
    vector<vector<int> > res;
    vector<int> pos;
    int dimension;
};

int main(int argc, char const *argv[])
{
	queen q(4);
	vector<vector<int> > v;
	v = q.findSolution();

	cout << v.size() << endl;
	return 0;
}
