class MyCircularQueue {
    vector<int> que;
    int head;
    int tail;
    int capacity;
public:
    MyCircularQueue(int k) {
        que.resize(k + 1);
        head = 0;
        tail = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        tail = (tail + 1) % (capacity + 1);
        que[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        head = (head + 1) % (capacity + 1);
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return que[(head + 1) % (capacity + 1)];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return que[tail];
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        return (tail + 1) % (capacity + 1) == head;
    }
};
