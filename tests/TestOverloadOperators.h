#ifndef TEST_OVERLOAD_OPERATORS_H
#define TEST_OVERLOAD_OPERATORS_H

#include <cassert>
#include "../ArraySequence.h"
#include "../ListSequence.h"

void testIndexOperator()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        assert(test[i] == arr[i]);
    }
}

void testEqualOperator()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr, 6);
    MutableListSequence<int> test2(arr, 6);
    assert(test1 == test2);
}

void testNotEqualOperator()
{
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[6] = {0, 2, 3, 4, 5, 6};
    MutableListSequence<int> test1(arr1, 6);
    MutableListSequence<int> test2(arr2, 6);
    assert(!(test1 == test2));
}


#endif
