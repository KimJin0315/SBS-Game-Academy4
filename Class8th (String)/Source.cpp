#include <iostream>

using namespace std;

class String
{
private:
    int size;
    char* pointer;

public:
    String()
    {
        size = 0;
        pointer = nullptr;
    }

    void operator = (const char* word)
    {
        size = strlen(word) + 1;

        if (pointer == nullptr)
        {
            pointer = new char[size];

            for (int i = 0; i < size; i++)
            {
                pointer[i] = word[i];
            }
        }
        else
        {
            char* newPointer = new char[size];

            for (int i = 0; i < size; i++)
            {
                newPointer[i] = word[i];
            }

            delete[] pointer;

            pointer = newPointer;
        }
    }

    const int& Size()
    {
        return size - 1;
    }

    const char& operator [ ](const int& index)
    {
        return pointer[index];
    }

    void Append(const char* word)
    {
        int resize = size;

        size = size + strlen(word) + 1;

        char* newPointer = new char[size];

        for (int i = 0; i < resize; i++)
        {
            newPointer[i] = pointer[i];

        }

        for (int i = 0; i < strlen(word) + 1; i++)
        {
            newPointer[resize + i] = word[i];
        }

        if (pointer != nullptr)
        {
            delete[] pointer;
        }

        pointer = newPointer;
    }

    unsigned long long Find(const char* word)
    {
        int length = size - strlen(word);

        int i = 0;
        int j = 0;

        for (i = 0; i < length; i++)
        {
            for (j = 0; j < strlen(word); j++)
            {
                if (pointer[i + j] != word[j])
                {
                    break;
                }
            }

            if (j == strlen(word))
            {
                return i;
            }
        }

        return 18446744073709551615;
    }

    ~String()
    {
        if (pointer != nullptr)
        {
            delete[] pointer;
        }
    }

};

int main()
{
    String string;

    string = "hello";

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    cout << endl;

    string.Append(" world");

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    cout << endl;

    string.Append(" !!");

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }

    cout << endl;

    unsigned long long findIndex = string.Find("wo");
    if (findIndex == -1)
    {
        cout << "해당 문자열을 찾을 수 없습니다." << endl;
    }
    else
    {
        cout << "문자열을 찾았습니다. 위치 : " << findIndex << endl;
    }

    return 0;
}
