class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sort(nums.begin(),nums.end());
        //vector<int>::iterator n_iter;
        int a = 0;
        int b = 0;
        int i = 0;
        int j = 0;
        vector<int> res;
        //for(int i =0;i<nums.size();i++){
        do{
            // if(a+b == target) break;
            a = nums[i];
            for(j = i+1;j<nums.size();j++){
                b = nums[j];
                if(a+b == target){
                    res.push_back(i);
                    res.push_back(j);
                    break;   
                }
            }
            i++;
        }while((a+b != target) && i < nums.size());
        return res;
    };
};
