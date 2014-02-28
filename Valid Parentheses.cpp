class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if(s.empty())
                    return false;
                if(str[i] == ')' && s.top() != '(')
                    return false;
                if(str[i] == ']' && s.top() != '[')
                    return false;
                if(str[i] == '}' && s.top() != '{')
                    return false;
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
        }
        if(s.empty())
            return true;
        else
            return false;
    }
};
