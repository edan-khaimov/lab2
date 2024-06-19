#ifndef TEST_LIST_SEQUENCE_H
#define TEST_LIST_SEQUENCE_H

#include <assert.h>
#include "../ListSequence.h"

void testListSequenceConstructors()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    MutableListSequence<int> test1;
    ImmutableListSequence<int> test2;
    assert(test1.GetLength() == 0);
    assert(test2.GetLength() == 0);

    MutableListSequence<int> test3(arr, 6);
    ImmutableListSequence<int> test4(arr, 6);
    assert(test3.GetLength() == 6);
    assert(test4.GetLength() == 6);
    for (int i = 0; i < test3.GetLength(); i++)
    {
        assert(test3.Get(i) == arr[i]);
        assert(test4.Get(i) == arr[i]);
    }

    MutableListSequence<int> test5(test3);
    ImmutableListSequence<int> test6(test4);
    assert(test3.GetLength() == test5.GetLength());
    assert(test4.GetLength() == test6.GetLength());
    for (int i = 0; i < test3.GetLength(); i++)
    {
        assert(test3.Get(i) == test5.Get(i));
        assert(test4.Get(i) == test6.Get(i));
    }

    LinkedList<int> testList1(arr, 6);
    LinkedList<int> testList2(arr, 6);
    MutableListSequence<int> test7(testList1);
    ImmutableListSequence<int> test8(testList2);
    assert(test7.GetLength() == testList1.GetLength());
    assert(test8.GetLength() == testList2.GetLength());
    for (int i = 0; i < test7.GetLength(); i++)
    {
        assert(test3.Get(i) == testList1.Get(i));
        assert(test4.Get(i) == testList2.Get(i));
    }
}

void testListSequenceGetFirst()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    assert(test1.GetFirst() == arr[0]);
}

void testListSequenceGetLast()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    assert(test1.GetLast() == arr[5]);
}

void testListSequenceGet()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == arr[i]);
    }
}

void testListSequenceGetLength()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    assert(test1.GetLength() == 6);
}

void testListSequenceAppend()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    test1.Append(12);
    assert(test1.GetLength() == 6 + 1);
    for (int i = 0; i < test1.GetLength() - 1; i++)
    {
        assert(test1[i] == arr[i]);
    }
    assert(test1[test1.GetLength() - 1] == 12);

    ImmutableListSequence<int> test2(arr, 6);
    ImmutableListSequence<int> *test3 = static_cast<ImmutableListSequence<int> *>(test2.Append(12));
    assert(test2.GetLength() == 6);
    assert(test3->GetLength() == 7);
    for (int i = 0; i < test2.GetLength(); i++)
    {
        assert(test3->Get(i) == arr[i]);
    }
    assert(test3->Get(6) == 12);
}

void testListSequencePrepend()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    test1.Prepend(12);
    assert(test1.GetLength() == 6 + 1);
    for (int i = 1; i < test1.GetLength(); i++)
    {
        assert(test1[i] == arr[i - 1]);
    }
    assert(test1[0] == 12);
    ImmutableListSequence<int> test2(arr, 6);
    ImmutableListSequence<int> *test3 = static_cast<ImmutableListSequence<int> *>(test2.Prepend(12));
    assert(test2.GetLength() == 6);
    assert(test3->GetLength() == 7);
    for (int i = 1; i < test3->GetLength(); i++)
    {
        assert(test3->Get(i) == arr[i - 1]);
    }
    assert(test3->Get(0) == 12);
}

void testListSequenceInsertAt()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    test1.InsertAt(12, 2);
    assert(test1.GetLength() == 6 + 1);
    for (int i = 0; i < 2; i++)
    {
        assert(test1[i] == arr[i]);
    }
    assert(test1[2] == 12);
    for (int i = 3; i < test1.GetLength(); i++)
    {
        assert(test1[i] == arr[i - 1]);
    }

    ImmutableListSequence<int> test2(arr, 6);
    ImmutableListSequence<int> *test3 = static_cast<ImmutableListSequence<int> *>(test2.InsertAt(12, 2));
    assert(test2.GetLength() == 6);
    assert(test3->GetLength() == 7);
    for (int i = 0; i < 2; i++)
    {
        assert(test3->Get(i) == arr[i]);
    }
    assert(test3->Get(2) == 12);
    for (int i = 3; i < test1.GetLength(); i++)
    {
        assert(test3->Get(i) == arr[i - 1]);
    }
}

void testListSequenceConcat()
{
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[4] = {54, 22, 21, 3};
    MutableListSequence<int> test1(arr1, 6);
    MutableListSequence<int> test2(arr2, 4);
    test1.Concat(test2);
    assert(test1.GetLength() == 6 + 4);
    for (int i = 0; i < 6; i++)
    {
        assert(test1[i] == arr1[i]);
    }
    for (int i = 6; i < 10; i++)
    {
        assert(test1[i] == arr2[i - 6]);
    }

    ImmutableListSequence<int> test3(arr1, 6);
    ImmutableListSequence<int> test4(arr2, 4);
    ImmutableListSequence<int> *test5 = test3.Concat(test4);
    assert(test3.GetLength() == 6);
    assert(test5->GetLength() == 6 + 4);

    for (int i = 0; i < 6; i++)
    {
        assert(test5->Get(i) == arr1[i]);
    }
    for (int i = 6; i < 10; i++)
    {
        assert(test5->Get(i) == arr2[i - 6]);
    }
}

void testListSequenceGetSubSequence()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    MutableListSequence<int> *test2 = test1.GetSubSequence(1, 4);
    assert(test2->GetLength() == 4);
    for (int i = 0; i < test2->GetLength(); i++)
    {
        assert(test2->Get(i) == arr[i + 1]);
    }
}

#endif
