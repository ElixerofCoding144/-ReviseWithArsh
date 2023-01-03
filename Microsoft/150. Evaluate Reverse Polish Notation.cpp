class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <long> s;
        long operand1, operand2;
        long ans;
       
        for(int itr = 0; itr < tokens.size(); itr++)
        {
            if(tokens[itr] == "+" || tokens[itr] == "-" || tokens[itr] == "*" || tokens[itr] == "/")
            {
                operand1 = s.top();
                s.pop();
                operand2 = s.top();
                s.pop();
                string sign = tokens[itr];
                if(sign == "+") 
                {
                    ans = operand1 + operand2;
                    s.push(ans);
                }
                else if(sign == "-") {
                    if(operand1<operand2)
                        ans = operand2 - operand1;
                    else
                        ans = operand1 - operand2;
                    s.push(ans);
                }
                else if(sign == "*") {
                    ans = operand1*operand2;
                    s.push(ans);
                }
                else if(sign == "/"){
                    ans = (long)operand1/operand2;
                    s.push(ans);
                }
            }      
            else
            {
                s.push(stol(tokens[itr]));
            }
        }
        return s.top();
    }
};
