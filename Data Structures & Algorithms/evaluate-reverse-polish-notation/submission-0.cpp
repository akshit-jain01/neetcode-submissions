class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i<tokens.size(); i++)
        {
            if(tokens[i]=="+" ||tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/")
            {
                int sol;
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                if(tokens[i]=="+")
                {
                    sol = op1+op2;
                }
                else if(tokens[i]=="-")
                {
                    sol = op1-op2;
                }
                else if(tokens[i]=="*")
                {
                    sol = op1*op2;
                }
                else
                {
                    sol = op1/op2;
                }
                st.push(sol);
                
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
            
        }
        return st.top();
    }
};
