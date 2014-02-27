class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1)
            return 1;
        int max = 0;
        int start=0, end=0;
        bool hash[26];
        for(int i=0;i<26;i++)
        {
            hash[i] = false;
        }
        for(start=0;start<s.length();start++)
        {
            hash[s[start]-'a'] = true;
            for(end = start+1;end<s.length();end++)
            {
                if(hash[s[end]-'a'])
                {
                    if(end-start > max)
                        max = end - start;
                    break;
                }
                else if(end == s.length()-1)
                {
                    if(end-start+1 > max)
                        max = end - start + 1;
                }
                else
                {
                    hash[s[end]-'a'] = true;
                }
            }
            for(int i=0;i<26;i++)
            {
                hash[i] = false;
            }
        }
        return max;
    }
};
