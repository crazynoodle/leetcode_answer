# leetcode_answer
This is a copy of my answer in leetcode;I put them here for a backup;
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.ends());
        //vector<int>::iterator n_iter;
        int a = 0;
        int b = 0;
        int i = 0;
        vector<int> res;
        //for(int i =0;i<nums.size();i++){
        do{
            // if(a+b == target) break;
            a = nums[i];
            for(int j = i+1;j<nums.size();j++){
                if(a + nums[j] == target){
                    b = nums[j];
                    res.push_back(i);
                    res.push_back(j);
                    break;   
                }else if(a+nums[j] > target){
                    b = nums[j];
                    break;
                }else continue;
            }
            i++;
        }while(a+b != target && i <nums.size())
    }
};
```
