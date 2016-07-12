/*
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int k = n1 + n2 -1;
        int res[k] = {0};
        for(int i=n1-1;i>=0;--i)
            for(int j=n2-1;j>=0;--j)
                res[i+j] += (num1[i]-'0')*(num2[j]-'0');
        
        int carry = 0;
        for(int i=k-1;i>=0;i--){
            res[i] += carry;
            carry = res[i]/10;
            res[i] %= 10;
        }
        
        bool zeroflag = false;
        string sum("");        
        if(carry){
            sum.push_back(carry+'0');
            zeroflag = true;
        }
        
        
        // bool zeroflag = false;
        for(int i=0;i<k;i++){
            if(!res[i] && !zeroflag){
                if(i==k-1)
                    sum.push_back(res[i]+'0');
                continue; 
            }else{
                zeroflag = true;
                sum.push_back(res[i]+'0');
            }
        }
        
        return sum;
    }
};
