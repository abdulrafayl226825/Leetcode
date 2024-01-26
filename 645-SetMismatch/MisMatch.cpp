class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n=nums.size();
        int first,second;
        int num=n;
        unordered_set<int> st;

        for(auto i:nums)
        {
            if(st.find(i)!=st.end())
            {
                first=i;continue;
            }
            st.insert(i);
        }

        for(second=1,n=nums.size();second<=n;second++)
        {
            if(st.find(second)==st.end())
                break;    
        }
        return {first,second};   
    }
};
