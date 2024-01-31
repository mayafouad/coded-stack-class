#include <iostream>
#include <cstdlib> 
#define ll long long 
#define Maya() ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

class full:public exception{
    const char* what() const noexcept{
        return "Full Stak, can't add another item\n";
    }
};

class Empty:public exception{
    const char* what() const noexcept{
        return "Empty Stak, can't remove any item\n";
    }
};

// A class to represent a stack
template <class T>
class Stack
{
    T *arr;
    int top;
    const int capacity = 3;

public:
    Stack();  
    // Copy Constructor
    Stack(const Stack& other);
    // Move Constructor
    Stack(Stack&& other);
    // Copy Assignment Operator
    Stack& operator=(const Stack& other);
    // Move Assignment Operator
    Stack& operator=(Stack&& other);       
    ~Stack();                       

    void push(const T&);
    T peek()const;
    T pop();

    int size()const;
    bool isEmpty()const;
    bool isFull()const;
};

// Constructor to initialize the stack
template <class T>
Stack<T>::Stack() {
    arr = new T[capacity];
    top = -1;
}
// Copy Constructor
template <class T>
Stack<T>::Stack(const Stack& other) {
    capacity = other.capacity;
    top = other.top;
    arr = new T[capacity];
    for (int i = 0; i <= top; ++i) {
        arr[i] = other.arr[i];
    }
}

// Move Constructor
template <class T>
Stack<T>::Stack(Stack&& other)  {
    capacity = other.capacity;
    top = other.top;
    arr = other.arr;

    other.top = -1;
    other.arr = nullptr;
}

// Copy Assignment Operator
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        capacity = other.capacity;
        top = other.top;
        arr = new T[capacity];
        for (int i = 0; i <= top; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// Move Assignment Operator
template <class T>
Stack<T>& Stack<T>::operator=(Stack&& other) {
    if (this != &other) {
        capacity = other.capacity;
        top = other.top;
        arr = other.arr;

        other.top = -1;
        other.arr = nullptr;
    }
    return *this;
}
// Destructor to free memory allocated 
template <class T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <class T>
// Utility function to add an element `x` to the stack
void Stack<T> :: push(const T& x) {
    if (isFull())
    {
        throw full();
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
template <class T>
// Utility function to return the top element of the stack
T Stack<T> ::peek() const {
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

template <class T>
// Utility function to pop a top element from the stack
T Stack<T> ::pop() {
    // check for stack underflow
    if (isEmpty())
    {
        throw Empty();
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    // decrease stack size by 1 and return the popped element
    return arr[top--];
}
template <class T>
// Utility function to return the size of the stack
int Stack<T>::size() const {
    return top + 1;
}
template <class T>
// Utility function to check if the stack is empty or not
bool Stack<T>::isEmpty() const {
    return top == -1;               // or return size() == 0;
}
template <class T>
// Utility function to check if the stack is full or not
bool Stack<T>::isFull() const {
    return top == capacity - 1;     // or return size() == capacity;
}


int main() {
	Maya();
    Stack<char> st; char choice; char item;
    while (true) {
        cout << "1- push\n2- pop\n3- peek\n4- size\nQ to end\n==> ";
        cin >> choice;
        try
        {
            switch (choice) {
            case '1': cout << "Input item: ";
                cin >> item;
                st.push(item);
                break;
            case '2': st.pop();
                break;
            case '3': cout << "Top item: " << st.peek() << endl;
                break;
            case '4': cout << "size = " << st.size() << endl;
                break;
            case 'Q':  case 'q':
                cout << "Goodbye\n ";
                return 0;
            default: cout << "Invalid choice\n";
            }
        }
        catch(exception& e)
        {
            cerr << e.what() << '\n';
        } 
    }

}
