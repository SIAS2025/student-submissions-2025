#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int l = grid.size();
        int c = grid[0].size();
        if(l==0) return 0;
        queue<pair<int , int>> myque;
        int res=0;
        for(int i=0 ; i<l ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    myque.push({i,j});
                    grid[i][j]='0';
                    while(!myque.empty())
                    {
                        pair<int,int> p=myque.front();
                        myque.pop();
                        grid[p.first][p.second]='0';
                        if(p.first<l-1 && grid[p.first+1][p.second]=='1') 
                        {myque.push({p.first+1,p.second});grid[p.first+1][p.second]='0';};
                        if(p.second<c-1 && grid[p.first][p.second+1]=='1') 
                        {myque.push({p.first,p.second+1});grid[p.first][p.second+1]='0';}
                        if(p.second>0 && grid[p.first][p.second-1]=='1')
                        {myque.push({p.first,p.second-1});grid[p.first][p.second-1]='0';} 
                        if(p.first>0 && grid[p.first-1][p.second]=='1')
                        {myque.push({p.first-1,p.second});grid[p.first-1][p.second]='0';} 
                    }
                }
            }
        }
        return res;

    }
};