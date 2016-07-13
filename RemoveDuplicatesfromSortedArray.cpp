//Remove Duplicates from Sorted Array
/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory. 
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
            
        // int i,k,j;
        // for(i=1,k=0,j=1;i<size;i++){
        //     if(nums[i] != nums[k]){
        //         nums[j] = nums[i]; 
        //         k = j;
        //         j++;
        //     }else continue;
        // }
        
        int i,j;
        for(i=1,j=0;i<size;i++){
            if(nums[j] != nums[i]){
                nums[++j] = nums[i];
            }else continue;
        }
        
        return j+1;
    }
};
