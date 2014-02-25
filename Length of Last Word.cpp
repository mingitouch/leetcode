class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int count=0;
        int lastcount=0;
        if(s==NULL)
            return 0;
        while(*s!='\0')
        {
            if(*s == ' ')
            {
                if(count != 0)
                    lastcount=count;
                count=0;
                if(*(s+1)=='\0')
                {
                    count = lastcount;
                }
            }
            else
            {
                count++;
            }
            s++;
        }
        return count;
    }
};
