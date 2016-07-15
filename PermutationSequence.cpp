/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 */
 
class Solution {
public:
    string getPermutation_old(int n, int k) {
        // int array[n-1] = {0};
        vector<int> array(n,0);
        for(int i=0;i<n;i++)
            array[i] = i+1;
            
        // vector<vector<int>> res;
        // int count = 0;
        // helper(res,array,0,count,k);
        if(k!= 1){
            for(int i=0;i<k-1;i++)
                nextPermutation(array);            
        }
        // for(int i=0;i<k;i++)
        //     nextPermutation(array);
            
        string a("");
        for(int i=0;i<n;i++)
            a += array[i] + '0';
            // a += res[k-1][i] + '0';
            
        return a;
    }
    
    string getPermutation(int n, int k) {  
        int i,j,data[10],sign[10];  
        data[1]=1;  
        for(i=2;i<=n;++i)data[i]=data[i-1]*i;  
        memset(sign,0,sizeof(sign));  
        string s="";  
        i-=2;  
        --k;  
        while(i>=0)  
        {  
            int temp=k/data[i];  
            for(j=1;j<10;++j)  
            {  
                if(sign[j]==0)temp--;  
                if(temp<0)break;  
            }  
            sign[j]=1;  
            s+=j+'0';  
            k%=data[i];  
            i--;  
        }  
        return s;  
    } 
    
    // void helper(vector<vector<int>>& res,vector<int> nums,int index,int &count,int k)
    // {
    //     if(count == k)
    //         return;
    //     if(index == nums.size()){
    //         res.push_back(nums);
    //         count++;
    //     }
        
    //     for(int i=index;i<nums.size();i++){
    //         swap(nums[i],nums[index]);
    //         helper(res,nums,index+1,count,k);
    //         swap(nums[i],nums[index]);
    //     }
    // }
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
