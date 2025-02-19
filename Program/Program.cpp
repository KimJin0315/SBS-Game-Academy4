#include <iostream>

using namespace std;

template<typename T>
class CircleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;

    int size;

public:

    CircleLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;

            head->next = newNode;

            head = newNode;
        }

        size++;
    }

    void Show()
    {
        Node* currentNode = head;

        while (head->next != currentNode)
        {
            cout << currentNode->data << " ";

            currentNode = currentNode->next;
        }
    }


    ~CircleLinkedList()
    {

    }
};

int main()
{
    CircleLinkedList<int> circleLinkedList;

    circleLinkedList.push_back(10);
    circleLinkedList.push_back(20);
    circleLinkedList.push_back(30);

    circleLinkedList.Show();

    return 0;
}
