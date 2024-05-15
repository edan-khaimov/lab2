#ifndef TEST_DYNAMIC_ARRAY_H
#define TEST_DYNAMIC_ARRAY_H

#include <assert.h>
#include "../DynamicArray.h"

void testDynamicArrayConstructors()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    DynamicArray<int> test;
    assert(test.GetSize() == 0);

    DynamicArray<int> test1(6);
    assert(test1.GetSize() == 6);

    DynamicArray<int> test2(arr,6);
    assert(test2.GetSize() == 6);
    for (int i = 0; i < test2.GetSize(); i++)
    {
        assert(test2.Get(i) == arr[i]);
    }

    DynamicArray<int> test3(test2);
    assert(test2.GetSize() == test3.GetSize());
    for (int i = 0; i < test2.GetSize(); i++)
    {
        assert(test2.Get(i) == test3.Get(i));
    }
}

void testDynamicArrayGet()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    DynamicArray<int> test(arr,6);
    for (int i = 0; i < test.GetSize(); i++)
    {
        assert(test.Get(i) == arr[i]);
    }
}

void testDynamicArrayGetSize()
{
    const int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    DynamicArray<int> test(arr,n);
    assert(test.GetSize() == n);
}

void testDynamicArraySet()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    DynamicArray<int> test(arr,6);
    test.Set(0, 100);
    assert(test.Get(0) == 100);
}

void testDynamicArrayResize()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    DynamicArray<int> test1(arr,6);
    test1.Resize(8);
    assert(test1.GetSize() == 8);
    for (int i = 0; i < 6; i++)
    {
        assert(test1.Get(i) == arr[i]);
    }
    DynamicArray<int> test2(arr,6);
    test2.Resize(2);
    assert(test2.GetSize() == 2);
    for (int i = 0; i < test2.GetSize(); i++)
    {
        assert(test1.Get(i) == arr[i]);
    }
}

void testDynamicArrayIndexOperator()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    DynamicArray<int> test(arr,6);
    for (int i = 0; i < test.GetSize(); i++)
    {
        assert(test[i] == arr[i]);
    }
}

#endif
