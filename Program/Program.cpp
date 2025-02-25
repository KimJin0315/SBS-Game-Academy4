#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
    int size;
    int capacity;

    T* container;

public:

    Vector()
    {
        size = 0;
        capacity = 0;
        container = nullptr;
    }

    void resize(int newSize)
    {
        T* newContainer = new T[size];
        
        if (container == nullptr)
        {
            cout << "Empty" << endl;
        }
        else
        {
            capacity = newSize;
            container = nullptr;


            container[0] = *newContainer;

        }
    }

    void push_back(T data)
    {

    }

};

int main()
{
    Vector<int> vector;



    return 0;
}
