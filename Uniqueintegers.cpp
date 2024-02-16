#iinclude <bits/stdc++.h>
using namespace std;
int findLeastNumOfUniqueInts(vector<int> arr, int k) {
    unordered_map<int,int> mp;

    for(auto &i : arr)
    {
        mp[i]++;
    }
    auto cmp=[](const pair<int,int> & a,const pair<int,int> & b)
    {
        return a.second>b.second;
    };
    priority_queue<pair<int,int> ,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

    int s=mp.size();
//        sort(mp.begin(),mp.end());
    for (auto & i: mp  )
    {
        pq.push(i);
    }
    while(k>=0)
    {
        auto x=pq.top();
        k-=x.second;
        if(k>=0)
        {
            pq.pop();
        }
    }
    return pq.size();
}
int main()
{
  cout<<findLeastNumOfUniqueInts({4,3,1,1,3,3,2},3)<<endl;
  
}
