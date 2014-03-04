class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int profit=0;
        int maxpro=INT_MIN;
        int minpro=INT_MAX;
        int maxindex=0;
        int minindex=0;
        for(int i=0;i<prices.size();i++)
        {
            if(maxpro<prices[i])
            {
                maxpro = prices[i];
                maxindex = i;
            }
            if(minpro>prices[i])
            {
                minpro = prices[i];
                minindex = i;
            }
            if(maxindex>minindex)
            {
                if(profit < maxpro-minpro)
                {
                    profit = maxpro-minpro;
                }
            }
            else
            {
                maxindex=minindex;
                maxpro=minpro;
            }
        }
        return profit;
    }
};
