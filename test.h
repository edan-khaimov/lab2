#ifndef TEST_H
#define TEST_H

#include "tests/TestDynamicArray.h"
#include "tests/TestLinkedList.h"
#include "tests/TestListSequence.h"
#include "tests/TestArraySequence.h"

void testDynamicArray()
{
    testDynamicArrayConstructors();
    testDynamicArrayGet();
    testDynamicArrayGetSize();
    testDynamicArraySet();
    testDynamicArrayResize();
    testDynamicArrayIndexOperator();
}

void testLinkedList()
{
    testLinkedListConstructors();
    testLinkedListGetFirst();
    testLinkedListGetLast();
    testLinkedListGet();
    testLinkedListGetSubList();
    testLinkedListGetLength();
    testLinkedListAppend();
    testLinkedListPrepend();
    testLinkedListInsertAt();
    testLinkedListConcat();
    testLinkedListIndexOperator();
}

void testListSequence()
{
    testLinkedList();
    testDynamicArray();
    testListSequenceConstructors();
    testListSequenceGetFirst();
    testListSequenceGetLast();
    testListSequenceGet();
    testListSequenceGetLength();
    testListSequenceAppend();
    testListSequencePrepend();
    testListSequenceInsertAt();
    testListSequenceConcat();
    testListSequenceGetSubSequence();
}

void testArraySequence()
{
    testArraySequenceConstructors();
    testArraySequenceGetFirst();
    testArraySequenceGetLast();
    testArraySequenceGet();
    testArraySequenceGetLength();
    testArraySequenceAppend();
    testArraySequencePrepend();
    testArraySequenceInsertAt();
    testArraySequenceConcat();
    testArraySequenceGetSubSequence();
}

#endif
