#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//二维动态规划
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return 0;
        }
        int rows=matrix.size();
        int colmuns=matrix[0].size();
        int maxside=0;
        vector<vector<int>> pd(rows,vector<int>(colmuns,0));
        pd[0][0]=matrix[0][0]=='1' ? 1:0;
        maxside=max(maxside,pd[0][0]);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<colmuns;j++)
            {
                if(i==0||j==0)
                {
                    pd[i][j]=matrix[i][j]=='1' ? 1:0;
                }
                else
                {
                    if(matrix[i][j]=='1')
                    {
                        pd[i][j]=min(pd[i-1][j],min(pd[i-1][j-1],pd[i][j-1]))+1;
                    }
                    
                }
                maxside=max(maxside,pd[i][j]);
            }
        }
        return maxside*maxside;
    }
};


//暴力法
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int maxside=0;
        int rows=matrix.size();
        int columns=matrix[0].size();
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<columns ; j++)
            {
                //bool flag=true;
                if(matrix[i][j]=='1')
                {
                    //bool flag = true;
                    int curmaxside=min(rows-i,columns-j);
                    maxside=max(maxside,1);
                    for(int k=1 ; k<curmaxside ; k++)
                    {
                        bool flag = true;
                        if(matrix[i+k][j+k]=='0')
                        {
                            break;
                        }
                        for(int m=0 ; m<k ; m++)
                        {
                            if(matrix[i+m][j+k]=='0' || matrix[i+k][j+m]=='0')
                            {
                                flag=false;
                                break;
                            }
                        }
                        if(flag)
                        {
                            maxside=max(maxside,k+1);
                        }
                        else
                        {break;}
                    }
                }
            }
        }
        return maxside*maxside;
    }
};