//Permutations
/* Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 *
 * [
 *    [1,2,3],
 *    [1,3,2],
 *    [2,1,3],
 *    [2,3,1],
 *    [3,1,2],
 *    [3,2,1]
 * ]
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums,0);
        return res;
    }
    
    void helper(vector<vector<int>>& res,vector<int>& nums,int index){
        if(index == nums.size()){
            // for(int i=0;i<index;i++)
                res.push_back(nums);
        }
            
        for(int i = index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            helper(res,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
};
