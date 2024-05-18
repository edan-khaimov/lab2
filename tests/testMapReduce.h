#ifndef TEST_MAP_REDUCE_H
#define TEST_MAP_REDUCE_H
#include "assert.h"
#include "../Sequence.h"
#include "../ListSequence.h"
#include "../ArraySequence.h"

int testMapFunc(int i)
{
    return i * i;
}

void testMap()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 4, 9, 16, 25, 36, 49, 64};
    MutableListSequence<int> test1(a, 8);
    test1.Map(&testMapFunc);
    assert(test1.GetLength() == 8);
    for (int i = 0; i < test1.GetLength(); i++)
    {
        assert(test1.Get(i) == b[i]);
    }
    ImmutableListSequence<int> test2(a, 8);
    test2.Map(&testMapFunc);
    for (int i = 0; i < test2.GetLength(); i++)
    {
        assert(test2[i] == a[i]);
    }
    ImmutableListSequence<int> test3 = static_cast<ImmutableListSequence<int> &>(test2.Map(&testMapFunc));
    for (int i = 0; i < test3.GetLength(); i++)
    {
        assert(test3[i] == b[i]);
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
    int result = test1.Reduce(&testReduceFunc, 0);
    assert(result == 36);
}

#endif
