class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int count = 1;
        while(x / count >= 10)
        {
            count = count * 10;
        }
        while(x >= 10)
        {
            int high = x / count;
            int low = x % 10;
            
            if(high != low)
                return false;
            
            x = (x%count) / 10;
            count = count / 100;
        }
        return true;
    }
};
