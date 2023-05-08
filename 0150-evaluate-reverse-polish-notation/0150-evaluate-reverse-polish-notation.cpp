class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for(auto s: tokens) {
            if(s == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a+b);
            } else if (s == "*") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a*b);
            } else if (s == "-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b-a);
            } else if (s == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b/a);
            } else {
                stk.push(stoi(s));
            }
        }
        
        return stk.top();        
    }
};