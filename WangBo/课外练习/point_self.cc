#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct point{
    int x;
    int y;
};

bool cmpx(const point& a, const point& b){
    return a.x < b.x;
}
bool cmpy(const point& a, const point& b){
    return a.y < b.y;
}

double dist(const point& a, const point& b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closestPair(vector<point>& points, int l, int r){
    if(l>=r) return 1e18;
    if(r-l==1) return dist(points[l],points[r]);
    int mid=(l+r)/2;
    double left= closestPair(points, l, mid);
    double right= closestPair(points, mid+1, r);
    double d=min(left,right);

    vector<point> strip;
    for(int i=l ; i<=r ; i++){
        if(abs(points[i].x-points[mid].x)<d){
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(),strip.end(),cmpy);
    int m=strip.size();
    for(int i=0 ; i<m ; i++){
        for(int j=i+1 ; j<m && (strip[j].y-strip[i].y)<d ; j++){
            d=min(d,dist(strip[i],strip[j]));
        }
    }
    return d;


}

int main(){
    int n;
    cin>>n;
    vector<point> points(n);
    for(int i=0 ; i<n ; i++){
        cin>>points[i].x>>points[i].y;
    }
    sort(points.begin(),points.end(),cmpx);
    int min_dist;
    min_dist=closestPair(points,0,n-1);

    cout<<min_dist<<endl;
    return 0;
}