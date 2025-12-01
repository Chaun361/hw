#include "heap.h"
#include "pq.h"

#include <iostream>
using namespace std;

void PriorityQueue::Insert(int x)
{
    elements->insert(x);
}

int PriorityQueue::Max()
{
    return elements->GetRoot();
}

int PriorityQueue::ExtractMax()
{
    return elements->RemoveRoot();
}

void PriorityQueue::Modify(int x, int newx)
{
    elements->swapWithLastIndex(x, newx);
}

bool PriorityQueue::isViolated()
{
    return elements->isHeap();
}

void PriorityQueue::print()
{
    elements->printArray();
}