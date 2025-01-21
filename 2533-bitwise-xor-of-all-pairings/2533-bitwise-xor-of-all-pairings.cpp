class Solution {
public:
    int xorAllNums(vector<int>& num1, vector<int>& num2) {
        int n = num1.size();
        int m = num2.size();
        if( (n &1) && (m & 1) )
        {
            int ans =0;
            for(auto & i : num1)
            {
                ans ^=i;
            }
            for(auto & i : num2)
            {
                ans ^=i;
            }
            return ans;
        }
        if( (n&1) || (m&1) )
        {
            int ans =0;
            if(!(m&1))
            {
                for(auto & i : num2)
                {
                    ans ^=i;
                }
                return ans;
            }
            else
            {
                 for(auto & i : num1)
                {
                    ans ^=i;
                }
                return ans;
            }

        }
        return 0;
    }
};