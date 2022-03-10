class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            int n= digits[i]+carry;
            carry=n/10;
            digits[i]= n%10;
        }
        if(carry>0)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};