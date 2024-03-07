#include <iostream>

using namespace std;

// Calculate the length of the array.
template <typename T, int N>
int length(T (&array)[N]) {
    return N;
}

// Print all the elements of the array.
template <typename T>
void printArray(T &array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

template <typename T>
struct Array {
    T array[0];
    int size;
};

int main()
{
    int newArray[3] = {0, 1, 2};
    Array<int> array;

    for(int i = 0; i < length(newArray); i++) {
        array.array[i] = newArray[i];
    }
    array.size = 3;
    printArray(array.array, array.size);

    return 0;
}
