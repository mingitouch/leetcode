class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> path;
        if(S.size() == 0)
            return result;
        result.push_back(path);
        sort(S.begin(),S.end());
        dfs(S, 0, path, result);
        return result;
    }
    
    void dfs(vector<int> S, int start, vector<int> path, vector<vector<int> > & result)
    {
        for(int i=start;i<S.size();i++)
        {
            path.push_back(S[i]);
            result.push_back(path);
            if(i<S.size()-1)
                dfs(S, i+1, path, result);
            path.pop_back();
        }
    }
};
