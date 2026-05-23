#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    cin >> N >> Q;

    //用pair(a,b),int hash来维护商品对出现次数
    map<pair<int, int>, int> pair_cnt;

    for (int i = 0; i < N; ++i) {
        //循环处理每个用户的产品列表
        //用set维护产品列表,去重+排序
        //用数组来处理商品,生成商品对pair(a,b),更新hash表
        int k;
        cin >> k;
        set<int> s; // 用set自动去重+排序
        for (int j = 0; j < k; ++j) {
            int id;
            cin >> id;
            s.insert(id);
        }
        vector<int> items(s.begin(), s.end());
        int m = items.size();
        if (m < 2) continue; // 不足2个商品，不生成商品对

        // 生成所有a < b的商品对，统计共现次数
        for (int x = 0; x < m; ++x) {
            for (int y = x + 1; y < m; ++y) {
                pair<int, int> p = {items[x], items[y]};
                pair_cnt[p]++;
            }
        }
    }

    // 预处理：统计最大共现频率，构建频率数组
    int max_cnt = 0;
    for (auto &entry : pair_cnt) {
        max_cnt = max(max_cnt, entry.second);
    }

    vector<int> ans(max_cnt + 2, 0); // ans[T] 表示共现频率 >= T 的商品对数量
    for (auto &entry : pair_cnt) {
        int cnt = entry.second;
        ans[1]++;
        ans[cnt + 1]--;
    }

    // 前缀和转换
    for (int T = 1; T <= max_cnt; ++T) {
        ans[T] += ans[T - 1];
    }

    // 处理查询
    vector<int> input;
    input.reserve(Q);
    while (Q--) {
        int T;
        cin >> T;
        input.push_back(T);
    }
    for(auto& T:input){
        cout<<ans[T]<<endl;
    }

    return 0;
}