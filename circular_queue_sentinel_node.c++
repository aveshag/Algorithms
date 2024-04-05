// Circular Queue with sentinel node
#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 4

class MyQueue
{
private:
    vector<int> q;
    int front;
    int rear;

public:
    MyQueue()
    {
        q.resize(MAX_SIZE); // 1 for sentinel node
        front = 0;
        rear = 0;
    }

    void enqueue(int ele)
    {
        if ((rear + 1) % MAX_SIZE == front)
        {
            cout << "Q is full!\n";
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            q[rear] = ele;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "Q is empty!\n";
            return -1;
        }

        front = (front + 1) % MAX_SIZE;
        return q[front];
    }
};

int main()
{
    MyQueue *q = new MyQueue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    cout<< q->dequeue()<< endl;
    cout<< q->dequeue()<< endl;
    cout<< q->dequeue()<< endl;
    cout<< q->dequeue()<< endl;
    cout<< q->dequeue()<< endl;
    q->enqueue(6);
    q->enqueue(7);
    cout<< q->dequeue()<< endl;
    cout<< q->dequeue()<< endl;
    return 0;
}
