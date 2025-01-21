class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
       
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            int x =0;
             unordered_set<int> st;
            for(int k = i;k>=0;k--)
            {

                if(st.find(A[k])!=st.end())
                    x++;
                else
                    st.insert(A[k]);
                if(st.find(B[k])!=st.end())
                    x++;
                else
                    st.insert(B[k]);
                // cout << x << " ";
            }
            // cout << endl;
            res[i]=x;
        }
        return res;
    }
};