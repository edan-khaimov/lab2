#ifndef UI_H
#define UI_H

#include <string>
#include "ListSequence.h"
#include "tests/testMapReduce.h"
#include "MapReduce.h"

int selectSequenceType()
{
    int n;
    std::cout << "Enter one option from the following list" << std::endl;
    std::cout << "0 - stop the program" << std::endl;
    std::cout << "1 - work with List Sequence" << std::endl;
    std::cout << "2 - work with Array Sequence" << std::endl;
    std::cin >> n;
    if (n != 0 && n != 1 && n != 2)
    {
        throw std::invalid_argument("Unknown option");
    }
    return n;
}

int selectElementsType()
{
    int n;
    std::cout << "Enter one option from the following list" << std::endl;
    std::cout << "1 - int" << std::endl;
    std::cout << "2 - double" << std::endl;
    std::cout << "3 - char" << std::endl;
    std::cout << "4 - string" << std::endl;
    std::cin >> n;
    if (n < 1 || n > 4)
    {
        throw std::invalid_argument("Unknown type");
    }
    return n;
}

int selectOperation(int type)
{
    int n;
    std::string typeOfSequence;
    type == 1 ? typeOfSequence = "List Sequence" : typeOfSequence = "Array Sequence";
    std::cout << "Enter one option from the following list" << std::endl;
    std::cout << "1 - get first element from " << typeOfSequence << std::endl;
    std::cout << "2 - get last element from " << typeOfSequence << std::endl;
    std::cout << "3 - get element by index from " << typeOfSequence << std::endl;
    std::cout << "4 - get length of " << typeOfSequence << std::endl;
    std::cout << "5 - append element to " << typeOfSequence << std::endl;
    std::cout << "6 - prepend element to " << typeOfSequence << std::endl;
    std::cout << "7 - insert element at index into " << typeOfSequence << std::endl;
    std::cout << "8 - get sub " << typeOfSequence << " " << "from source " << typeOfSequence << std::endl;
    std::cout << "9 - concatenate two " << typeOfSequence << "s" << std::endl;
    std::cin >> n;
    if (n < 1 || n > 9)
    {
        throw std::invalid_argument("Unknown option");
    }
    return n;
}

template <typename T>
void printSequence(Sequence<T> *seq)
{
    std::cout << "Result: " << std::endl;
    for (int i = 0; i < seq->GetLength(); i++)
    {
        std::cout << (*seq)[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void setSequence(Sequence<T> &sequence)
{
    int size;
    std::cout << "Enter size" << std::endl;
    std::cin >> size;
    T *items = new T[size];
    std::cout << "Enter elements" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> items[i];
        sequence.Append(items[i]);
    }
    delete []items;
}

template <typename T>
void sequenceInterface(Sequence<T> &sequence, int type)
{
    int operation = selectOperation(type);
    T item;
    int index;
    MutableListSequence<T> result;
    switch (operation)
    {
        case 1:
            std::cout << "First element is " << sequence.GetFirst() << std::endl;
            break;
        case 2:
            std::cout << "Last element is " << sequence.GetLast() << std::endl;
            break;
        case 3:
            std::cout << "Enter index" << std::endl;
            std::cin >> index;
            std::cout << "Element with index " << index << " is " << sequence.Get(index) << std::endl;
            break;
        case 4:
            std::cout << "Length of Sequence is " << sequence.GetLength() << std::endl;
            break;
        case 5:
            std::cout << "Enter item you want to append" << std::endl;
            std::cin >> item;
            printSequence(sequence.Append(item));
            break;
        case 6:
            std::cout << "Enter item you want to prepend" << std::endl;
            std::cin >> item;
    printSequence(sequence.Prepend(item));
            break;
        case 7:
            std::cout << "Enter index " << std::endl;
            std::cin >> index;
            std::cout << "Enter item you want to insert" << std::endl;
            std::cin >> item;
            printSequence(sequence.InsertAt(item, index));
            break;
        case 8:
            int startIndex, endIndex;
            std::cout << "Enter start and end indexes of sub sequence" << std::endl;
            std::cin >> startIndex >> endIndex;
            printSequence(sequence.GetSubSequence(startIndex, endIndex));
            break;
        case 9:
            std::cout << "Set second sequence" << std::endl;
            if (type == 1)
            {
                MutableListSequence<T> concatList;
                setSequence(concatList);
                printSequence(sequence.Concat(concatList));
            }
            else
            {
                MutableArraySequence<T> concatArray;
                setSequence(concatArray);
                printSequence(sequence.Concat(concatArray));
            }
            break;
    }
}

#endif