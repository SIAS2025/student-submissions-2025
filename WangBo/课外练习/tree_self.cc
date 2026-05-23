#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dfs(int idx,vector<int>& arr){
    if(arr[idx]==-1) return -1;
    int left=2*idx+1;
    int right=2*idx+2;
    int left_val=0;
    if(left<arr.size() && arr[left]!=-1) left_val=dfs(left,arr);
    int right_val=0;
    if(right<arr.size() && arr[right]!=-1) right_val=dfs(right,arr);
    arr[idx]+=left_val+right_val;
    return arr[idx];
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    arr.reserve(pow(2,n)-1);
    int num;
    while(cin>>num){
        arr.push_back(num);
        if(cin.get()=='\n') break;
    }
    dfs(0,arr);
    for(int i=0 ; i<arr.size() ; i++){
        if(i>0){
            cout<<" ";
        }
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}