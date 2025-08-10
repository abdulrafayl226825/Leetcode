class Solution {
public:
    void print(vector<int>& num)
    {
        for(auto & i : num)
        cout<<i<<" ";
        cout<<endl;
    }
    void builthash(int n , set<vector<int>>& st)
    {
        // cout<<" n: "<<n<<endl;
        vector<int> num;
        while(n>=10)
        {
            num.push_back(n%10);
            n/=10;
        }
        num.push_back(n);
        sort(num.begin(),num.end());
        // cout<<"arr"<<endl;
        // print(num);
        st.insert(num);
    }
    
    bool reorderedPowerOf2(int n) {
        int mx = 1e9;
        int d =1;
        set<vector<int>> st;
        while(d<=mx)
        {
            builthash(d,st);
            d<<=1;
        }
        vector<int> curr;
        while(n>=10)
        {
            curr.push_back(n%10);
            n/=10;
        }
        curr.push_back(n);
        sort(curr.begin(),curr.end());
        // print(curr);
        return st.count(curr);
    }
};