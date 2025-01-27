class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses);  
        vector<unordered_set<int>> res(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> ans;
        auto dfs = [&](this auto && dfs , int i)->void
        {
            for(auto & x : g[i])
            {
                if(!visited[x])
                    {
                        visited[x]=true;
                        dfs(x);
                    }
                res[i].insert(res[x].begin(),res[x].end());
                res[i].insert(x);
            }
        };    
        for(auto & i : prerequisites)
        {
            g[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++)
            dfs(i);

        for(auto & i : queries)
        {
                if(res[i[1]].find(i[0])!=res[i[1]].end())
                ans.push_back(true);
                else
                ans.push_back(false);
        }
        return ans;
       
    }
};