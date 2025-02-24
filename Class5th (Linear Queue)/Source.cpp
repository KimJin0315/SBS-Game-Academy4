#include <iostream>

#define SIZE 5

using namespace std;

template<typename T>
class LinearQueue
{
private:
    int rear;
    int front;

    T container[SIZE];

public:
    LinearQueue()
    {
        rear = 0;
        front = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data)
    {
        if (rear >= SIZE)
        {
            cout << "LinearQueue Overflow" << endl;
        }
        else
        {
            container[rear++] = data;
        }
    }

    void pop()
    {
        if (Empty())
        {
            cout << "LinearQueue is Empty" << endl;
        }
        else
        {
            container[front++] = NULL;
        }
    }

    bool Empty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    const T& Front()
    {
        if (Empty())
        {
            cout << "LinearQueue is Empty" << endl;

            exit(1);
        }
        else
        {
            return container[front];
        }
    }

    const int& Size()
    {
        return rear - front;
    }

};

int main()
{
    LinearQueue<int> linearQueue;

    linearQueue.push(10);
    linearQueue.push(20);
    linearQueue.push(30);
    linearQueue.push(40);
    linearQueue.push(50);

    cout << "LinearQueue Size : " << linearQueue.Size() << endl;

    while (linearQueue.Empty() == false)
    {
        cout << linearQueue.Front() << " ";

        linearQueue.pop();
    }




    return 0;
}
