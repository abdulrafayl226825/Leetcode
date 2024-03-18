//
// Created by abdulr on 3/18/24.
//
#include <bits/stdc++.h>
using namespace  std;
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end(),[](const auto & a ,const auto & b){return a[0]<b[0];});
    int arrows=1;
    int end=points[0][1];
    for(int i=1,n=points.size();i<n;i++)
    {
        if(points[i][0]>end)
        {
            arrows++;
            end=points[i][1];
        }
        else
        {
            end=min(end,points[i][1]);
        }
    }
    return arrows;
}


int main()
{

}