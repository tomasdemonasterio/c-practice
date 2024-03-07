#include <iostream>

using namespace std;

// Calculate the length of the array.
template <typename T, int N>
int length(T (&array)[N]) {
    return N;
}

// Print all the elements of the array.
template <typename T>
void printArray(T &array) {
    for(int i = 0; i < length(array); i++) {
        cout << array[i] << endl;
    }
}

// Overriding the printArray to work with a dynamical array. Not the best solution. Only for educational purpose.
template <typename T>
void printArray(T &array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

// Add an element to the end of the array.
// NOTE: You cannot change the size of the array because they are fixed at compile-time. This is just an example, another workaround is to make a struct or just using vector class.
template <typename T, int N>
void addElement(T (&array)[N], int &size, T value) {
    array[size] = value;
    size++;
}

// Remove an element from the given position.
template <typename T, int N>
void removeElementAtPos(T (&array)[N], int &size, int pos) {
    for(int i = pos; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

// Sort the array in ascending order using Bubble Sort.
template <typename T, int N>
void sortArray(T (&array)[N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                int auxValue = array[j];
                array[j] = array[j + 1];
                array[j + 1] = auxValue;
            }
        }
    }
}

// Overriding the sortArray to work with a dynamical array. Not the best solution. Only for educational purpose.
template <typename T>
void sortArray(T &array, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                int auxValue = array[j];
                array[j] = array[j + 1];
                array[j + 1] = auxValue;
            }
        }
    }
}



int main()
{
    int integerArray[] = {10, 2, 30, 1, 40, -12, 3};
    char charArray[] = {'b', 'c', 'a', 'd', 'z', 'p'};

    int integerArraySize = length(integerArray);
    int charArraySize = length(charArray);

    cout << "Printing Integer array..." << endl;
    printArray(integerArray);

    cout << endl << "Printing Char array..." << endl;;
    printArray(charArray);

    cout << endl << "Adding new elements to Integer array..." << endl;;
    addElement(integerArray, integerArraySize, -999);
    addElement(integerArray, integerArraySize, 55);
    addElement(integerArray, integerArraySize, 23);
    printArray(integerArray, integerArraySize);

    cout << endl << "Removing element at position..." << endl;;
    removeElementAtPos(integerArray, integerArraySize, 2);
    printArray(integerArray, integerArraySize);

    cout << endl << "Printing sorted Integer array..." << endl;
    sortArray(integerArray, integerArraySize);
    printArray(integerArray, integerArraySize);

    cout << endl << "Printing sorted Char array..." << endl;
    sortArray(charArray);
    printArray(charArray);

    return 0;
}
