class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<bool> visited(rooms.size(),false);
        q.push(0);
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            if(!visited[x])
            {
            visited[x]=true;
            for(int i=0;i<rooms[x].size();i++)
              q.push(rooms[x][i]);
            }
        }
        for(int i=0;i<rooms.size();i++)
        if(!visited[i]) return false;
        return true;
    }
};