class Solution {
public:
    long long gridGame(vector<vector<int>> &a) {
    auto f = accumulate(a[0].begin(),a[0].end(),0LL);
    long long s = 0;
    long long minimumscore =LLONG_MAX;
    for(int i=0;i<a[0].size();i++)
    {
        f-=a[0][i];
       
        minimumscore = min(minimumscore , max(f,s));
        s+=a[1][i];
    }
    return minimumscore;
}

};