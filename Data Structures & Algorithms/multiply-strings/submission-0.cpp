class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1=="0" || num2=="0")
        {
            return "0";
        }

        int m = num1.size();
        int n = num2.size();

        vector<int> ans(m+n, 0);

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >=0 ; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = ans[i+j+1] + mul;   // add the current multiplication with carry

                ans[i+j+1] = sum%10;   // actual mult

                ans[i+j] += sum/10;    // carry
            }
        }
        int i = 0;
        while(i<ans.size() && ans[i]==0)
        {
            i++;
        }
        string result = "";
        while(i < ans.size())
        {
            result += ans[i++] + '0';
        }
        return result;
    }
};
