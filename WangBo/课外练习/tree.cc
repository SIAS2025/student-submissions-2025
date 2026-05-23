#include <iostream>
#include <vector>
using namespace std;


int dfs(int idx, vector<int>& arr) {
    int n = arr.size();
    if (arr[idx] == -1) {
        return -1;
    }

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    int left_val = 0;
    if (left < n && arr[left] != -1) {
        left_val = dfs(left, arr);
    }

    int right_val = 0;
    if (right < n && arr[right] != -1) {
        right_val = dfs(right, arr);
    }

    arr[idx] += left_val + right_val;
    return arr[idx];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    int num;
    // 改用更稳定的方式读取所有剩余输入
    while (cin >> num && num != '\n') {
        arr.push_back(num);
    }

    dfs(0, arr);

    // 严格按格式输出
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;

    return 0;
}