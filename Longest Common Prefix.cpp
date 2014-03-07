class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string pre = "";
        if(strs.size() == 0)
            return pre;
        if(strs.size() == 1)
            return strs[0];
        pre = strs[0];
        if(pre == "")
            return pre;
        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            if(strs[i] == "")
                return "";
            for(;j<pre.length();j++)
            {
                if(j>=strs[i].length())
                {
                    break;
                }
                if(strs[i][j] != pre[j])
                    break;
            }
            if(j == 0)
                return "";
            pre=pre.substr(0,j);
        }
        return pre;
    }
};
