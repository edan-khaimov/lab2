#ifndef TEST_ARRAY_SEQUENCE_H
#define TEST_ARRAY_SEQUENCE_H

#include <cassert>
#include "../ArraySequence.h"

void testArraySequenceConstructors()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    MutableArraySequence<int> test1;
    ImmutableArraySequence<int> test2;
    assert(test1.GetLength() == 0);
    assert(test2.GetLength() == 0);

    MutableArraySequence<int> test3(arr, 6);
    ImmutableArraySequence<int> test4(arr, 6);
    assert(test3.GetLength() == 6);
    assert(test4.GetLength() == 6);
    for (int i = 0; i < test3.GetLength(); i++)
    {
        assert(test3.Get(i) == arr[i]);
        assert(test4.Get(i) == arr[i]);
    }

    MutableArraySequence<int> test5(test3);
    ImmutableArraySequence<int> test6(test4);
    assert(test3.GetLength() == test5.GetLength());
    assert(test4.GetLength() == test6.GetLength());
    for (int i = 0; i < test3.GetLength(); i++)
    {
        assert(test3.Get(i) == test5.Get(i));
        assert(test4.Get(i) == test6.Get(i));
    }

    DynamicArray<int> testArray1(arr, 6);
    DynamicArray<int> testArray2(arr, 6);
    MutableArraySequence<int> test7(testArray1);
    ImmutableArraySequence<int> test8(testArray2);
    assert(test7.GetLength() == testArray1.GetSize());
    assert(test8.GetLength() == testArray2.GetSize());
    for (int i = 0; i < test7.GetLength(); i++)
    {
        assert(test3.Get(i) == testArray1.Get(i));
        assert(test4.Get(i) == testArray2.Get(i));
    }
}


void testArraySequenceGetFirst()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
    assert(test1.GetFirst() == arr[0]);
}

void testArraySequenceGetLast()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
    assert(test1.GetLast() == arr[5]);
}

void testArraySequenceGet()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == arr[i]);
    }
}

void testArraySequenceGetLength()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
    assert(test1.GetLength() == 6);
}

void testArraySequenceAppend()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
    test1.Append(12);
    assert(test1.GetLength() == 6 + 1);
    for (int i = 0; i < test1.GetLength() - 1; i++)
    {
        assert(test1[i] == arr[i]);
    }
    assert(test1[test1.GetLength() - 1] == 12);

    ImmutableArraySequence<int> test2(arr, 6);
    ImmutableArraySequence<int> *test3 = static_cast<ImmutableArraySequence<int> *>(test2.Append(12));
    assert(test2.GetLength() == 6);
    assert(test3->GetLength() == 7);
    for (int i = 0; i < test2.GetLength(); i++)
    {
        assert(test3->Get(i) == arr[i]);
    }
    assert(test3->Get(6) == 12);
}

void testArraySequencePrepend()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
    test1.Prepend(12);
    assert(test1.GetLength() == 6 + 1);
    for (int i = 1; i < test1.GetLength(); i++)
    {
        assert(test1[i] == arr[i - 1]);
    }
    assert(test1[0] == 12);
    ImmutableArraySequence<int> test2(arr, 6);
    ImmutableArraySequence<int> *test3 = static_cast<ImmutableArraySequence<int> *>(test2.Prepend(12));
    assert(test2.GetLength() == 6);
    assert(test3->GetLength() == 7);
    for (int i = 1; i < test3->GetLength(); i++)
    {
        assert(test3->Get(i) == arr[i - 1]);
    }
    assert(test3->Get(0) == 12);
}

void testArraySequenceInsertAt()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
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

    ImmutableArraySequence<int> test2(arr, 6);
    ImmutableArraySequence<int> *test3 = static_cast<ImmutableArraySequence<int> *>(test2.InsertAt(12, 2));
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

void testArraySequenceConcat()
{
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[4] = {54, 22, 21, 3};
    MutableArraySequence<int> test1(arr1, 6);
    MutableArraySequence<int> test2(arr2, 4);
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

    ImmutableArraySequence<int> test3(arr1, 6);
    ImmutableArraySequence<int> test4(arr2, 4);
    ImmutableArraySequence<int> *test5 = test3.Concat(test4);
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

void testArraySequenceGetSubSequence()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableArraySequence<int> test1(arr, 6);
    MutableArraySequence<int> *test2 = test1.GetSubSequence(1, 4);
    assert(test2->GetLength() == 4 - 1);
    for (int i = 0; i < test2->GetLength(); i++)
    {
        assert(test2->Get(i) == arr[i + 1]);
    }
}

#endif
