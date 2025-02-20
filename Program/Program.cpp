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

    void push_front(T data)
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
            
        }

        size++;
    }

    const int& Size()
    {
        return size;
    }

    void Show()
    {
  
        if (head != nullptr)
        {
            Node* currentNode = head->next;

            for (int i = 0; i < size; i++)
            {
                cout << currentNode->data << " ";

                currentNode = currentNode->next;
            }
        }
    }

    void pop_front()
    {

        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head->next;

            if (head == head->next)
            {
                head = nullptr;
            }
            else
            {
                head->next = deleteNode->next;          
            }

            delete deleteNode;

            size--;
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;
            Node* currentNode = head;

            if(size == 1)
            {
                head = nullptr;
            }
            else
            { 
               
                while (currentNode->next != head)
                {
                    currentNode = currentNode->next;
                }

                head = currentNode;
                head->next = deleteNode->next;
            }

            delete deleteNode;

            size--;
        }
    }

    ~CircleLinkedList()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
};

int main()
{
    CircleLinkedList<int> circleLinkedList;

    circleLinkedList.push_back(10);
    circleLinkedList.push_back(20);
    circleLinkedList.push_back(30);

    circleLinkedList.push_front(5);
    circleLinkedList.push_front(1);

    circleLinkedList.pop_back();

    cout << "Linked List is Size : " << circleLinkedList.Size() << endl;

    circleLinkedList.Show();

    return 0;
}
