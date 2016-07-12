/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int size = digits.size();
        vector<int> res;
        digits[size-1] += 1;
        for(int i=size-1;i>=0;i--){
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;            
        }
        
        if(carry)
            res.push_back(carry);
            
        for(int i=0;i<size;i++)
            res.push_back(digits[i]);
            
        return res;
    }
};
