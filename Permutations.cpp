class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        int begin = 0;
        int end = num.size();
        perm(num, begin, end, result);
        return result;
    }
    
    void perm(vector<int> &num, int begin, int end, vector<vector<int> > &result)
    {
        if(begin == end)
        {
            result.push_back(num);
        }
        else
        {
            for(int i=begin;i<end;i++)
            {
                vector<int>::iterator iter = num.begin();
                int tmp = num[begin];
                num[begin] = num[i];
                num[i] = tmp;
                perm(num, begin+1, end, result);
                tmp = num[begin];
                num[begin] = num[i];
                num[i] = tmp;
            }
        }
    }
    
    void swap(vector<int>::iterator ix, vector<int>::iterator iy)
    {
        vector<int>::iterator temp = iy;
        iy = ix;
        ix = temp;
    }
};
