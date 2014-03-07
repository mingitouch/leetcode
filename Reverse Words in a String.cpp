class Solution {
public:
    void reverseWords(string &s) {
        vector<string> vec;
        string result = "";
        string temp = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] != ' ')
            {
                temp = temp + s[i];
            }
            else if(s[i] == ' ')
            {
                if(temp != "")
                    vec.push_back(temp);
                temp = "";
            }
            if(i==s.length()-1 && temp != "")
                vec.push_back(temp);
        }
        for(int i=vec.size()-1;i>=0;i--)
        {
            if(i!=0)
            {
                result = result + vec[i] + " ";
            }
            else
                result = result + vec[i];
        }
        s = result;
    }
};
