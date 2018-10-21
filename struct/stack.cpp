// Benjamin Hurley
// stack.cpp

// Stack template using vectors

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack {
public:
    Stack() {
        maxSize = 2;
        currentSize = 0;
        stack = new vector<T>[maxSize];
    };
    
    ~Stack() {
        for (int i = 0; i < currentSize; i++) {
            stack->pop_back();
        }
    };
    
    void Push(T node) {
        if (currentSize+1 <= maxSize) {
            stack->push_back(node);
            currentSize++;
        }
        else {
            Resize();
            cout << endl << "*** Resized Array. Capacity is now: " << getMaxSize() << endl;
            stack->push_back(node);
            currentSize++;
        }

    };

    void Pop() {
        stack->pop_back();
        currentSize--;
    };

    void Peek() {
        T temp = stack->back();
        cout << temp;
    };

    int getCurrentSize() {
        return currentSize;
    };

    int getMaxSize() {
        return maxSize;
    };

private:
    vector<T> * stack;
    int maxSize;
    int currentSize;

    void Resize() {
        int newMax = maxSize + (maxSize/2);
        vector<T> * newStack = new vector<T>[newMax];

        for (int i = 0; i < currentSize; i++) {
            newStack[i] = stack[i];
        }
        stack = newStack;
        maxSize = newMax;
    }
};

int main() {

    cout << "Initializing Stack of ints" << endl;
    Stack<int> intStack;

    cout << "Pushing 6";
    intStack.Push(6);
    cout << endl << "Pushing 8";
    intStack.Push(8);
    cout << endl << "Peeking: ";
    intStack.Peek();
    cout << endl << "Pushing 2";
    intStack.Push(2);
    cout << endl << "Pushing 1";
    intStack.Push(1);
    cout << endl << "Pushing 7";
    intStack.Push(7);
    cout << endl << "Pushing 7";
    intStack.Push(7);
    cout << endl << "Pushing 1";
    intStack.Push(1);
    cout << endl << "Popping off top element";
    intStack.Pop();
    cout << endl << "Pushing 9";
    intStack.Push(9);
    cout << endl << "Peeking: ";
    intStack.Peek();
    cout << endl << "Printing size of stack: " << intStack.getCurrentSize() << endl;;

    cout << endl << endl << "Initalizing Stack of chars" << endl;
    Stack<char> charStack;

    cout << endl << "Pushing H";
    charStack.Push('H');
    cout << endl << "Pushing I";
    charStack.Push('I');
    cout << endl << "Peeking: ";
    charStack.Peek();
    cout << endl << "Popping off top element";
    charStack.Pop();
    cout << endl << "Peeking: ";
    charStack.Peek();
    cout << endl << "Printing size of stack: " << charStack.getCurrentSize() << endl;
    cout << endl << endl;
    
    return 0;
}