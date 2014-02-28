class Solution {
public:
    int atoi(const char *str) {
        bool flag=false;
        long long sum = 0;
        while(*str == ' ')
            str++;
        if(*str == '+')
            str++;
        else if(*str == '-')
        {
            str++;
            flag=true;
        }
        while(*str != '\0')
        {
            //while(*str != '\0' && *str == ' ')
            //    break;
            if(*str>'9' || *str<'0')
                break;
            
            if(sum * 10 + (*str - '0') > INT_MAX){
				if(flag)
					return INT_MIN;
				else return INT_MAX;
            }
			sum = sum * 10 + (*str - '0');
            str++;
        }
        if(flag)
            sum = sum * (-1);

        return sum;
    }
};
