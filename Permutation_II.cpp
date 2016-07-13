//Permutation II 

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums,0);
        return res;
    }
    
    void helper(vector<vector<int>>& res,vector<int> nums,int index){
        if(index == nums.size()){
            // for(int i=0;i<index;i++)
                res.push_back(nums);
        }else{
        
            sort(nums.begin()+index,nums.end());//the most important
            for(int i = index;i<nums.size();i++)
            {
                if( i != index && nums[i] == nums[i-1]){
                    continue;
                }
                swap(nums[i],nums[index]);
                helper(res,nums,index+1);
                swap(nums[i],nums[index]);
            }
        }
    }
};
