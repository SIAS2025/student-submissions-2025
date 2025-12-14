#include <vector>
#include <iostream>
using namespace std;

class MyCircularQueue {
public:
    int w;
    int r;
    vector<int> rqueue;
    int capacity;
    int flag;
    MyCircularQueue(int k) : capacity(k),w(0),r(0),flag(0){
        rqueue.resize(capacity);
    }
    
    bool enQueue(int value){
        if(w==r)//队列空/满
        {
            if(flag==1) return false;//队列满
            //队列空
            else if(flag==0)
            {
                rqueue[w]=value;
                w=(w+1)%capacity;
                if(w==r) flag=1;
            }
        }
        else if(w!=r)//队列未满
        {
            rqueue[w]=value;
            w=(w+1)%capacity;
            if(w==r) flag=1;
        }
        return true;
        
    }
    
    bool deQueue() {
        if(r==w && flag==0)//队列空
        {
            return false;
        }
        r=(r+1)%capacity;
        if(flag==1) flag=0;
        return true;
    }
    
    int Front() {
        if(r==w && flag==0)//队列空
        {
            return -1;
        }
        else
        {
            return rqueue[r];
        }
    }
    
    int Rear() {
        if(r==w && flag==0)//队列空
        {
            return -1;
        }
        if(w==0) return rqueue[capacity-1];
        return rqueue[w-1];
    }
    
    bool isEmpty() {
        if(r==w && flag==0)//队列空
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(r==w && flag==1)//队列空
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */