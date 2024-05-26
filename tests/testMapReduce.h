#ifndef TEST_MAP_REDUCE_H
#define TEST_MAP_REDUCE_H
#include "assert.h"
#include "../Sequence.h"
#include "../ListSequence.h"
#include "../ArraySequence.h"
#include "../MapReduce.h"

int testMapFunc(int i)
{
    return i * i;
}

void testMap()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 4, 9, 16, 25, 36, 49, 64};
    MutableArraySequence<int> test1(a, 8);
    MutableListSequence<int> test2 = map(test1, &testMapFunc);
    assert(test1.GetLength() == 8);
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == b[i]);
    }
}

int testReduceFunc(int a, int b)
{
    return a + b;
}

void testReduce()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    MutableListSequence<int> test1(a, 8);
    int result = reduce(test1, &testReduceFunc, 0);
    assert(result == 36);
}

bool testWhereFunc(int i)
{
    return i % 2 == 0;
}

void testWhere()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {2, 4, 6, 8};
    MutableListSequence<int> test1(a, 8);
    MutableArraySequence<int> testRes = where(test1, &testWhereFunc);
    assert(testRes.GetLength() == 4);
    for (int i = 0; i < testRes.GetLength(); i++)
    {
        assert(testRes.Get(i) == b[i]);
    }
}

#endif
