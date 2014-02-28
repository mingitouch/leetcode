class Solution {
public:
    string key[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void rec(string digits, int index, string path, vector<string> & result)
    {
        if(index == digits.size())
        {
            result.push_back(path);
            return ;
        }
        for(int i=0;i<key[digits[index]-'2'].length();i++)
        {
            rec(digits, index+1, path+key[digits[index]-'2'][i], result);
        }
            
    }

    vector<string> letterCombinations(string digits) {
        int index = 0;
        vector<string> result;
        string path = "";
        rec(digits, index, path, result);
        return result;
    }

};
