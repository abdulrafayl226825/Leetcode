class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(auto & i: s)
          mp[i]++;
          
        priority_queue<pair<char,int>> pq;
        for(auto [i,j] : mp )
            pq.push(make_pair(i,j));
        pair<char,int> prev;
        prev=make_pair('A',-1);
        string res ;
        while(!pq.empty())
        {
            auto x = pq.top();pq.pop();
           if(prev.first=='A' || prev.first < x.first  )
           {
             res.insert(res.length(),min(repeatLimit,x.second),x.first);
            
             x.second -=min(repeatLimit,x.second);
           }
           else
           {
             res.insert(res.length(),1,x.first);
            
             x.second -=1;
            
           }

            if(prev.first != 'A')
            {
                pq.push(prev);
            }
            if(x.second>0)
            prev  = x;
            else
            prev=make_pair('A',-1);
        }
        return res;
    }
};