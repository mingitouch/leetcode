class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(strlen(needle) == 0)
            return haystack;
        if(strlen(needle) > strlen(haystack))
            return NULL;
        else if(strlen(needle) == strlen(haystack))
        {
            if(needle[strlen(needle)-1] != haystack[strlen(haystack)-1])
                return NULL;
        }
        bool flag = false;
        vector<int> next(strlen(needle),0);
    	getNext(next, needle);
    	int pos = jump(haystack, needle, next, flag);
    	if(!flag)
    	    return NULL;
    	return (haystack+pos);
    }
    
    void getNext(vector<int> & next, char * str)
    {
    	int j=0;
    	int len = strlen(str);
    	for(int i=1;i<len;i++)
    	{
    		int k = i;
    		while(k<len && str[j] == str[k])
    		{
    			next[k] = max(next[k],j+1);
    			k++;
    			j++;
    		}
    		j=0;
        }
    }
    
    int jump(char * target, char * str, vector<int> next, bool & flag)
    {
    	int len_t = strlen(target);
    	int len_s = strlen(str);
    	int index = 0;
    	for(int i=0;i<len_t;i++)
    	{
    
    		if(target[i] == str[index])
    			index++;
    		else
    		{
    			if(index != 0)
    			{
    				i = i - next[index-1] -1;
    				index = 0;
    			}
    		}
    		if(index == len_s)
    		{
                flag = true;
    			return i-len_s+1;
    		}
    	}
    }
    
};
