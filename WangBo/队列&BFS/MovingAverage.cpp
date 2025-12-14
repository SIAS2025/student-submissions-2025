#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    int size;
    queue<int> myque;
    int sum;
    MovingAverage(int size) : size(size),sum(0){
    }
    
    double next(int val) {
        myque.push(val);
        sum+=val;
        if(myque.size()>size) 
        {
            sum-=myque.front();
            myque.pop();
        }
        return static_cast<double>(sum)/myque.size();
    }
};


// class MovingAverage {
// public:
//     /** Initialize your data structure here. */
//     int size;
//     vector<int> myvec;
//     int sum;
//     MovingAverage(int size) : size(size),sum(0){
//     }
    
//     double next(int val) {
//         myvec.push_back(val);
//         sum+=val;
//         if(myvec.size()>size) 
//         {
//             sum-=myvec.front();
//             myvec.erase(myvec.begin());
//         }
//         return static_cast<double>(sum)/myvec.size();
//     }
// };

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */