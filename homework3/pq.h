#ifndef PQ
#define PQ
#include "heap.h"

class PriorityQueue
{
public:
    PriorityQueue()
    {
        elements = new Heap();
    }
    // insert an element into the priority queue
    void Insert(int x);
    // return element in the queue with the largest key
    int Max();
    // return element in the queue with the largest key, and remove
    // that element from the key
    int ExtractMax();
    // change element x to newx and fix the PQ if new insertion
    // violates its property
    void Modify(int x, int newx);

    bool isViolated();

    void print();

private:
    Heap *elements;
};

#endif
