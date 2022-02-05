#include <iostream>
using namespace std;

#define n 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void Push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void Pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Top() << endl;
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    cout << st.empty() << endl;
    return 0;
}