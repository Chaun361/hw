#ifndef HEAP
#define HEAP

const int MAX_SIZE = 100;

class Heap
{
public:
    Heap();

    Heap(int initData[], int len);

    void build_heap();

    int GetRoot();

    void insert(int x);

    void printArray();

    bool isHeap();

    int RemoveRoot();

    void fixInsert();

    void swapWithLastIndex(int x, int newx);

private:
    // i is the numbering of node (starting from 1)
    // i is not 1 (as root node has no parent)
    // the numbering of node i's parent is returned
    int parent(int i);
    // return i/2
    // return the numbering of the left child of node i
    // if node i has no left child, return -1
    int leftchild(int i);
    // return 2*i
    // return the numbering of the right child of node i
    //  if node i has no right child, return -1
    int rightchild(int i);
    // return 2*i+1
    int data[MAX_SIZE];
    int heapLength;
    // You could store elements from index 1
    //  the actual number of elements in the heap

    // swap element
    void swap(int indexOne, int indexTwo);

    void heapify(int i);
};

#endif