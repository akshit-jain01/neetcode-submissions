class Solution {
public:
    int getSum(int a, int b) {
        int carry = a & b;
        int sum = a ^ b;
        while(carry)
        {
            sum = a ^ b;
            carry = (a&b)<<1;

            a = sum;
            b = carry;
        }
        return sum;
    }
};
