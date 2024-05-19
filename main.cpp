#include <iostream>
using namespace std;

template <typename E>
class ArrayList {
public:
    ArrayList(int listCapacity) {
        array = new E[listCapacity];
        capacity = listCapacity;
        length = cursor = 0;
    }

    void insert(E value) {
        if (length >= capacity) {
            cerr << "Error: the list is full!";
            exit(1);
        }

        for (int i = length; i > cursor; --i) {
            array[i] = array[i - 1];
        }

        array[cursor] = value;

        length++;
    }

    E remove() {
        if (cursor < 0 || cursor >= length) {
            cerr << "Error: current cursor position is out of bounds!";
            exit(1);
        }

        E tempValue = array[cursor];

        for (int i = cursor; i < length - 1; ++i) {
            array[i] = array[i + 1];
        }

        length--;

        return tempValue;
    }

    void clear() {
        length = cursor = 0;
    }

    void cursorToPosition(int cursorPos) {
        if (cursorPos < 0 || cursorPos > length) {
            cerr << "Error: this cursor position is out of range!";
            exit(1);
        }

        cursor = cursorPos;
    }

    void cursorToStart() {
        cursor = 0;
    }

    void cursorToEnd() {
        cursor = length;
    }

    void cursorPrev() {
        if (cursor != 0) {
            cursor--;
        }
    }

    void cursorNext() {
        if (cursor < length) {
            cursor++;
        }
    }

    E getValue() {
        if (cursor >= length) {
            cerr << "Error: there is no element at the current cursor position!";
        }

        return array[cursor];
    }

    int getCursor() {
        return cursor;
    }

    int getLength() {
        return length;
    }

private:
    E* array;
    int capacity;
    int length;
    int cursor;
};

int main() {
    return 0;
}
