#include <iostream>

using namespace std;

template <typename E>

class ArrayList {
public:
    explicit ArrayList(int size) {
        capacity = size;
        numberElements = 0;
        cursorPosition = 0;
        arrayValues = new E[size];
    }

    void print() {
        for (int i = 0; i < numberElements; ++i) {
            cout << "[" << i << "] = " << arrayValues[i] << endl;
        }
    }

    E getValue() {
        if (cursorPosition < 0 || cursorPosition > numberElements - 1) {
            cerr << "Error: there is no element at the current cursor";
            exit(1);
        }
        return arrayValues[cursorPosition];
    }

    void insert(E value) {
        if (numberElements >= capacity) {
            cerr << "Error: the list is full!";
            exit(1);
        }

        for (int i = numberElements; i > cursorPosition; --i) {
            arrayValues[i] = arrayValues[i - 1];
        }

        arrayValues[cursorPosition] = value;
        numberElements++;
    }

    E remove() {
        if (cursorPosition >= numberElements) {
            cerr << "Error: cursor position is out of bounds!";
            exit(1);
        }

        E value = arrayValues[cursorPosition];
        for (int i = cursorPosition; i < numberElements - 1; ++i) {
            arrayValues[i] = arrayValues[i + 1];
        }

        numberElements--;
        return value;
    }

    int getCursorPosition() {
        return cursorPosition;
    }

    void cursorToPosition (int position) {
        if (position < 0 || position > numberElements - 1) {
            cerr << "Error: position is out of range!";
            exit(1);
        }

        cursorPosition = position;
    }

    void cursorToStart() {
        cursorPosition = 0;
    }

    void cursorToEnd() {
        cursorPosition = numberElements - 1;
    }

    void cursorPrevious() {
        if (cursorPosition > 0) {
            cursorPosition--;
        }
    }

    void cursorNext() {
        if (cursorPosition < numberElements - 1) {
            cursorPosition++;
        }
    }

    int getNumberElements() {
        return numberElements;
    }

private:
    int capacity;
    int numberElements;
    int cursorPosition;
    E* arrayValues;
};

int main()
{
    int n = 5;
    auto* pointerList = new ArrayList<int>(n);
    for (int i = n; i > 0; --i) {
        pointerList->insert(i);
    }

    pointerList->print();

    delete pointerList;

    return 0;
}