#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
    int size;

    struct Node
    {
        T data;
        Node * previous;
        Node * next;
    };

    Node * head;
    Node * tail;

public:

    DoubleLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        if (head == nullptr || tail == nullptr)
        {
            head = newNode;
            tail = newNode;

            newNode->data = data;
            newNode->next = nullptr;
            newNode->previous = nullptr;

        }
        else
        {
            while (head->previous != nullptr && tail->next != nullptr)
            {
                newNode->next = newNode->previous;
                newNode->previous = nullptr;

                newNode->previous = newNode->next;
                newNode->next = nullptr;
            }

                newNode->data = data;
        }

        size++;
    }

    void push_back(T data)
    {

    }





    ~DoubleLinkedList()
    {

    }

};

int main()
{
    


    return 0;
}
