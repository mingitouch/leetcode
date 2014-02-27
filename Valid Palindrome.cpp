class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.length()-1;
        while(end > begin)
        {
            while(begin<s.length() && !((s[begin]<='z' && s[begin]>='a') || (s[begin]<='Z' && s[begin]>='A') || (s[begin]<='9' && s[begin]>='0')))
            {
                begin++;
            }
            while(end>=0 && !((s[end]<='z' && s[end]>='a') || (s[end]<='Z' && s[end]>='A') || (s[end]<='9' && s[end]>='0')))
            {
                end--;
            }
			if(s[begin]>='A' && s[begin] <= 'Z')
                s[begin] = (s[begin] - 'A') + 'a';
            if(s[end]>='A' && s[end] <= 'Z')
                s[end] = (s[end] - 'A') + 'a';
            if(end <= begin)
                break;
            if(s[begin] != s[end])
                return false;
            begin++;
            end--;
        }
        return true;
    }
};
