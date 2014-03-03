class Solution {
public:
    bool isNumber(const char *str) {
        int state = 0;
        char last = *str;
        while(*str == ' ')
            str++;
        while(*str != '\0')
        {
            if(*str == ' ')
            {
                while(*str == ' ')
                {
                    str++;
                }
                if(*str != '\0')
                    return false;
				else
					break;
            }
            if(state == 0)
            {
                if(*str>='0' && *str<='9')
                    state = 1;
                else if(*str == '.')
                    state = 8;
                else if(*str == '+' || *str == '-')
                    state = 0;
                else state = -1;
            }
            else if(state == 1)
            {
                if(*str>='0' && *str<='9')
                    state = 1;
                else if(*str == '.')
                    state = 2;
                else if(*str == 'e')
                    state = 6;
                else
                    state = -1;
            }
            else if(state == 2)
            {
                if(*str>='0' && *str<='9')
                    state = 3;
                else if(*str == 'e')
                    state = 4;
                else state = -1;
            }
            else if(state == 3)
            {
                if(*str>='0' && *str<='9')
                    state = 3;
                else if(*str == 'e')
                    state = 4;
                else
                    state = -1;
            }
            else if(state == 4)
            {
                if(*str>='0' && *str<='9')
                    state = 5;
                else if(*str == '+' || *str == '-')
                    state = 4;
                else
                    state = -1;
            }
            else if(state == 5)
            {
                if(*str>='0' && *str<='9')
                    state = 5;
                else
                    state = -1;
            }
            else if(state == 6)
            {
                if(*str>='0' && *str<='9')
                    state = 7;
                else if(*str == '+' || *str == '-')
                    state = 6;
                else
                    state = -1;
            }
            else if(state == 7)
            {
                if(*str>='0' && *str<='9')
                    state = 7;
                else
                    state = -1;
            }
            else if(state == 8)
            {
                if(*str>='0' && *str<='9')
                    state = 9;
                else
                    state = -1;
            }
            else if(state == 9)
            {
                if(*str>='0' && *str<='9')
                    state = 9;
                else if(*str == 'e')
                    state = 6;
                else 
                    state = -1;
            }
            else if(state == -1)
            {
                return false;
            }
            last = *str;
            str++;
        }
        if(state == 1 || state == 2 || state == 3 || state == 5 || state == 7 || state == 9)
            return true;
        else return false;
    }
};
