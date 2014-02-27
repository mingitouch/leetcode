class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_set<int> hash;
        for(int i=0;i<num.size();i++)
        {
            hash.insert(num[i]);
        }
        int max = 0;
        for(int i=0;i<num.size();i++)
        {
            int start = -1;
            int end = 1;
            while(hash.count(num[i]+end))
            {
                hash.erase(num[i]+end);
                end++;
            }
            while(hash.count(num[i]+start))
            {
                hash.erase(num[i]+start);
                start--;
            }
            if(end-start-1 > max)
                max = end-start-1;
        }
        return max;
    }
};
