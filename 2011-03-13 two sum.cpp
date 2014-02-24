class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> mp;
        vector<int> result;
        for(int i=0;i<numbers.size();i++)
        {
            mp[numbers[i]] = i+1;
        }
        for(int i=0;i<numbers.size();i++)
        {
            if(mp.count(target-numbers[i]) && mp[target-numbers[i]] != i+1)
            {
                int maximum = max(i+1, mp[target-numbers[i]]);
                int minimum = min(i+1, mp[target-numbers[i]]);
                result.push_back(minimum);
                result.push_back(maximum);
            }
        }
        return result;
    }
};
