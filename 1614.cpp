#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
        int len=s.length();
        int count=0;
        int Max=0;
        for(auto & i : s)
            if(i=='(') count++,Max=max(Max,count);
            else if(i==')') count--;
        return Max;   
}

int main()
{
    cout<<maxDepth("(1)+((2))+(((3)))")<<endl;
}