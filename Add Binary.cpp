class Solution {
public:
    string addBinary(string a, string b) {
        int indexa = a.length()-1;
        int indexb = b.length()-1;
        bool flag = false;
        string result = "";
        while(indexa >=0 && indexb >= 0)
        {
            if(a[indexa] == '1' && b[indexb] == '1')
            {
                if(flag == true)
                {
                    result = '1' + result;
                }
                else
                {
                    result = '0' + result;
                }
                flag = true;
            }
            else if((a[indexa] == '1' && b[indexb] == '0') || (a[indexa] == '0' && b[indexb] == '1'))
            {
                if(flag == true)
                {
                    result = '0' + result;
                    flag = true;
                }
                else
                {
                    result = '1' + result;
                    flag = false;
                }
            }
            else if(a[indexa] == '0' && b[indexb] == '0')
            {
                if(flag == true)
                {
                    result = '1' + result;
                    flag = false;
                }
                else
                {
                    result = '0' + result;
                    flag = false;
                }
            }
            indexa--;
            indexb--;
        }
        
        while(indexa>=0)
        {
            if(a[indexa] == '1')
            {
                if(flag == true)
                {
                    result = '0' + result;
                    flag = true;
                }
                else
                {
                    result = '1' + result;
                    flag = false;
                }
            }
            else
            {
                if(flag == true)
                {
                    result = '1' + result;
                    flag = false;
                }
                else
                {
                    result = '0' + result;
                    flag = false;
                }
            }
            indexa--;
        }
        while(indexb>=0)
        {
            if(b[indexb] == '1')
            {
                if(flag == true)
                {
                    result = '0' + result;
                    flag = true;
                }
                else
                {
                    result = '1' + result;
                    flag = false;
                }
            }
            else
            {
                if(flag == true)
                {
                    result = '1' + result;
                    flag = false;
                }
                else
                {
                    result = '0' + result;
                    flag = false;
                }
            }
            indexb--;
        }
        if(flag)
        {
            result = '1' + result;
        }
        return result;
    }
};
