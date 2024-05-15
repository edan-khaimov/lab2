#ifndef TEST_LINKED_LIST_H
#define TEST_LINKED_LIST_H

#include <assert.h>
#include "../LinkedList.h"

void testLinkedListConstructors()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    LinkedList<int> test;
    assert(test.GetLength() == 0);

    LinkedList<int> test1(arr, 6);
    assert(test1.GetLength() == 6);
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == arr[i]);
    }

    LinkedList<int> test2(test1);
    assert(test1.GetLength() == test2.GetLength());
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == test2.Get(i));
    }
}

void testLinkedListGetFirst()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    assert(test.GetFirst() == arr[0]);
}

void testLinkedListGetLast()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    assert(test.GetLast() == arr[5]);
}

void testLinkedListGet()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    for (int i = 0; i < test.GetLength(); i++)
    {
        assert(test.Get(i) == arr[i]);
    }
}

void testLinkedListGetSubList()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    LinkedList<int> *result = test.GetSubList(1, 3);
    for (int i = 1; i < 3; i++)
    {
        assert(result->Get(i - 1) == test.Get(i));
    }
}

void testLinkedListGetLength()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    assert(6 == test.GetLength());
}

void testLinkedListAppend()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    test.Append(129);
    assert(test.GetLength() == 6 + 1);
    for (int i = 0; i < test.GetLength() - 1; i++)
    {
        assert(test.Get(i) == arr[i]);
    }
    assert(test.Get(test.GetLength() - 1) == 129);
}

void testLinkedListPrepend()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    test.Prepend(129);
    assert(test.GetLength() == 6 + 1);
    for (int i = 1; i < test.GetLength(); i++)
    {
        assert(test.Get(i) == arr[i - 1]);
    }
    assert(test.Get(0) == 129);
}

void testLinkedListInsertAt()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    test.InsertAt(7, 2);
    assert(test.GetLength() == 6 + 1);
    for (int i = 0; i < 2; i++)
    {
        assert(test.Get(i) == arr[i]);
    }
    assert(test.Get(2) == 7);
    for (int i = 3; i < test.GetLength(); i++)
    {
        assert(test.Get(i) == arr[i - 1]);
    }
}

void testLinkedListConcat()
{
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[3] = {213, 33, 2};
    LinkedList<int> test1(arr1, 6);
    LinkedList<int> test2(arr2, 3);
    LinkedList<int> *res = test1.Concat(test2);
    assert(res->GetLength() == test1.GetLength() + test2.GetLength());
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(res->Get(i) == test1.Get(i));
    }
    for (int i = 0; i < test2.GetLength(); i++)
    {
        assert(res->Get(test1.GetLength() + i) == test2.Get(i));
    }
}

void testLinkedListIndexOperator()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> test(arr, 6);
    for (int i = 0; i < test.GetLength(); i++)
    {
        assert(test[i] == arr[i]);
    }
}

#endif
