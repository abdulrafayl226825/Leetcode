class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<bool> visited(n,false);    
        vector<bool> recStack(n,false);    
        vector<vector<int>> g(n);
        stack<int> stk;
        for(auto & i : prerequisites)
        {
            g[i[1]].push_back(i[0]);
        }

        auto isCycle = [&](this auto && isCycle , int x)->bool
        {
            if(!visited[x])
            {
                visited[x]= true;
                recStack[x]= true;
                for(auto & i : g[x])
                {
                    if(recStack[i]) return true;
                    if(!visited[i] && isCycle(i))
                    {
                        return true;
                    }
                }
            }

            return recStack[x]=false;
        };
        auto dfs = [&](this auto && dfs , int x)->void
        {
            if(!visited[x])
            {
                visited[x]=true;
                for(auto & i : g[x])
                {
                    if(!visited[i])
                        dfs(i);
                }
                stk.push(x);
            }
        };
        for(int i=0;i<n;i++)
        {
            if(isCycle(i))
            return {};
        }
        visited.assign(n,false);
        for(int i=0;i<n;i++)
        {
            dfs(i);
        }
        vector<int> ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};