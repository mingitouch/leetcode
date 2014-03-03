#include <sstream>
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int A, B;
                string C;
                stringstream ss;
                ss << s.top();
                s.pop();
                ss >> A;
                ss.clear();
                ss << s.top();
                ss >> B;
                s.pop();
                ss.clear();
                if(tokens[i] == "+")
                {
                    ss << A+B;
                }
                else if(tokens[i] == "-")
                {
                    ss << B-A;
                }
                else if(tokens[i] == "*")
                {
                    ss << A*B;
                }
                else if(tokens[i] == "/")
                {
                    ss << B/A;
                }
                ss >> C;
                s.push(C);
            }
            else
            {
                s.push(tokens[i]);
            }
        }
        string t = s.top();
    	stringstream ss;
    	int val;
    	ss << t;
    	ss >> val;
        return val;
    }
};
