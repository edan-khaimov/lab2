#include <iostream>
#include "test.h"
#include "UI.h"

int main()
{
    testDynamicArray();
    testLinkedList();
    testArraySequence();
    testListSequence();
    testOperators();

    int userChoice = selectSequenceType();
    int type = selectElementsType();
    MutableListSequence<int> listInt;
    MutableArraySequence<int> arrayInt;
    MutableListSequence<double> listDouble;
    MutableArraySequence<double> arrayDouble;
    MutableListSequence<char> listChar;
    MutableArraySequence<char> arrayChar;
    MutableListSequence<std::string> listString;
    MutableArraySequence<std::string> arrayString;


    while (userChoice != 0)
    {
        switch (userChoice)
        {
            case 1:
                switch (type)
                {
                    case 1:
                        setSequence(listInt);
                        sequenceInterface(listInt, userChoice);
                        break;
                    case 2:
                        setSequence(listDouble);
                        sequenceInterface(listDouble, userChoice);
                        break;
                    case 3:
                        setSequence(listChar);
                        sequenceInterface(listChar, userChoice);
                        break;
                    case 4:
                        setSequence(listString);
                        sequenceInterface(listString, userChoice);
                        break;
                }
            case 2:
                switch (type)
                {
                    case 1:
                        setSequence(arrayInt);
                        sequenceInterface(arrayInt, userChoice);
                        break;
                    case 2:
                        setSequence(arrayDouble);
                        sequenceInterface(arrayDouble, userChoice);
                        break;
                    case 3:
                        setSequence(arrayChar);
                        sequenceInterface(arrayChar, userChoice);
                        break;
                    case 4:
                        setSequence(arrayString);
                        sequenceInterface(arrayString, userChoice);
                        break;
                }
        }
        userChoice = selectSequenceType();
        type = selectElementsType();
    }
    return 0;
}
