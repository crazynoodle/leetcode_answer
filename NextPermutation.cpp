//Next Permutation
/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        //当只有一个数的时候 或者 没有数的时候，直接返回
        if(size == 0 || size == 1)
            return;
        
        bool reFalg = false;//用于判断是否存在可变位置，使得更换位置后的数大于原来的数值；
        int left = 0;
        int right = 0;
        //从数组逆序遍历，第一次发现后一个数比前一个数大的时候，停止，记录下此两个数的位置，left和right;
        for(int i=size-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                reFalg = true;
                left = i-1;
                right = i;
                break;
            }
        }
        
        //若此时数组排列的数已是最大，重新排序，获取最小值
        if(!reFalg){
            sort(nums.begin(),nums.end());
            return;
        }else{
            //从left的后一个位置开始，寻找比left大数中最小的那一个，并记录位置,更新right
            for(int i=left+1;i<size;i++){
                if(nums[i] < nums[right] && nums[i] >nums[left])
                    right = i;
            }
            
            //将right位置的数往前移至left的位置中；
            for(int i=right;i>left;i--)
                swap(nums[i],nums[i-1]);
            
            //将left后的所有数排序，使left后面数组合最小
            sort(nums.begin()+left+1,nums.end());            
        }

        return;
    }
};
