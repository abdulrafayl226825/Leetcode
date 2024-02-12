#include <bits/stdc++.h>
using namespace std;
int numSpecial(vector<vector<int>>& mat) {
    int count=0;
    for(int i=0,m=mat.size();i<m;i++)
    {
        for(int j=0,n=mat[i].size();j<n;j++)
        {
            if(mat[i][j]==1)
            {
                bool flag=true;
                for(int k=0;k<m;k++)
                    if(mat[k][j] && k !=i) {flag=false; break;}
                if(flag)
                    for(int k=0;k<n;k++)
                        if(mat[i][k] && k !=j) {flag=false; break;}
                if(flag) count++;
            }
        }
    }
    return count;
}  
int main()
{
    vector<vector<int>> V{{1,0,0},{0,0,1},{1,0,0}};
  cout<<numSpecial(V);
}
