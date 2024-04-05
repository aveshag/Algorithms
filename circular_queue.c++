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
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        q[rear] = ele;
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Q is empty!\n";
            return -1;
        }

        int data = q[front];
        q[front] = -1;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % MAX_SIZE;

        return data;
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
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    q->enqueue(6);
    q->enqueue(7);
    q->enqueue(8);
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    return 0;
}
