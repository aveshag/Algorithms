// Circular Queue
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
        q.resize(MAX_SIZE);
        front = -1;
        rear = -1;
    }

    void enqueue(int ele)
    {
        if ((rear == MAX_SIZE - 1 && front == -1) || ((rear + 1) % MAX_SIZE == front))
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
    return 0;
}
