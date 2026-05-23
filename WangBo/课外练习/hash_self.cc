#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


int main(){
    int N,Q;
    cin>>N>>Q;

    map<pair<int,int>,int> pair_cnt;
    for (int i=0 ; i<N ; i++) {
        int tmps;
        cin>>tmps;
        set<int> goods;
        for(int j=0 ; j<tmps ; j++){
            int id;
            cin>>id;
            goods.insert(id);
        }
        vector<int> goods_vec(goods.begin(),goods.end());
        for(int j=0 ; j<tmps-1 ; j++){
            for(int k=j+1 ; k<tmps ; k++){
                pair<int,int> good_pair={goods_vec[j],goods_vec[k]};
                pair_cnt[good_pair]++;
            }
        }
    }
    int max_cnt=0;
    for(auto& it : pair_cnt){
        if(it.second>max_cnt) max_cnt=it.second;
    }
    vector<int> freq(max_cnt+1,0);
    for(auto& it : pair_cnt){
        freq[1]++;
        freq[it.second+1]--;
    }
    for(int i=2 ; i<max_cnt+1 ; i++){
        freq[i]+=freq[i-1];
    }

    vector<int> input;
    input.reserve(Q);
    while(Q--){
        int num;
        cin>>num;
        input.push_back(num);
    }
    for(auto&T : input){
        if(T>max_cnt){
            cout<<0<<endl;
        }
        cout<<freq[T]<<endl;
    }
    return 0;
}