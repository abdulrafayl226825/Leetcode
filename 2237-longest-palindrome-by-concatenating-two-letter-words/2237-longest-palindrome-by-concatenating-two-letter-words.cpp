class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int cnt =0;
       
       
      for(auto & i : words)
        {
            if(i[0]==i[1]) continue;
            if(mp[i]<0)
            {
                cnt+=4;
                mp[i]++;
            }
            else
               {
                swap(i[0],i[1]);
                mp[i]--;
               }
        }
        mp.clear();
        for(auto & i : words)
        {
            if(i[0]!=i[1]) continue;
            mp[i]++;
        }
        bool odd = false;
        for(auto & [i,j] : mp)
        {
            if(j&1) odd = true;
            cnt +=(j&1)?2*(j-1):2*j;
        }
        if(odd) cnt+=2;
        return cnt;
        
    }
};