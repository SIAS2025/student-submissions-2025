#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x= text1.size();
        int y= text2.size();
        if(x==0 || y==0) return 0;
        vector<vector<int>> status(x+1,vector<int>(y+1,0));//x*y的二维数组
        //status[1][1]=text1[0]==text2[0]? 1:0;
        for(int i=1 ; i<=x ; i++)
        {
            //从st[0][0]到st[0][y]遍历最长子串
            for(int j=1 ; j<=y ;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    status[i][j]=status[i-1][j-1]+1;
                }
                else
                {
                    status[i][j]=max(status[i][j-1],status[i-1][j]);
                }
            }
        }
        return status[x][y];
    }
};