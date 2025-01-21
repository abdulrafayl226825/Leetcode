class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> a(26,make_pair(INT_MAX,-1));
        // vector<int> sc(s.length());
       
        for(int i=0;i<s.length();i++)
        {
            // st.insert(s[i]);
            // sc[i]=st.size();
            a[s[i]-'a'].first = min(i,a[s[i]-'a'].first);
            a[s[i]-'a'].second = max(i,a[s[i]-'a'].second);
        }    
        int res =0;
        // for(auto & i : sc) cout << i << " ";
        cout<<endl;
        for(auto & i : a)
        {
            if(i.first!=INT_MAX  && i.second!=-1 && i.second-i.first > 1)
            { 

                unordered_set<int> st;
                for(int j=i.first+1;j<i.second;j++)
                {
                    st.insert(s[j]-'a');
                }
                res += st.size();
                // cout << i.first << " " << i.second  << " "<< res << endl;
                // cout << i.first <<" " << i.second << " " << sc[i.first+1] << " " << sc[i.second-1]  << " "<< res << endl;
                
            }
        }
        return res;
    }
};