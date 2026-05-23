#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct Point {
    int x, y;
};

// 按x坐标排序
bool cmpX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// 按y坐标排序
bool cmpY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// 计算两点欧氏距离
double dist(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// 分治求最近点对
double closestPair(vector<Point>& points, int l, int r) {
    if (l >= r) return 1e18; // 单个点返回无穷大
    if (r - l == 1) return dist(points[l], points[r]); // 两个点直接算距离
    
    int mid = (l + r) / 2;
    int midX = points[mid].x;
    double d = min(closestPair(points, l, mid), closestPair(points, mid+1, r));
    
    // 提取中间区域的点
    vector<Point> strip;
    for (int i = l; i <= r; ++i) {
        if (abs(points[i].x - midX) < d) {
            strip.push_back(points[i]);
        }
    }
    
    // 按y排序，检查相邻点
    sort(strip.begin(), strip.end(), cmpY);
    int m = strip.size();
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m && (strip[j].y - strip[i].y) < d; ++j) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    
    return d;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end(), cmpX);
    int minDist = closestPair(points, 0, n-1);
    
    cout << minDist << endl;
    
    return 0;
}