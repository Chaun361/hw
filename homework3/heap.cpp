#include "heap.h"
#include <iostream>
using namespace std;

Heap::Heap()
{
    heapLength = 0;
}

Heap::Heap(int initData[], int len)
{
    for (int i = 0; i < len && i + 1 < MAX_SIZE; i++)
    {
        data[i + 1] = initData[i];
    }
    heapLength = len;

    build_heap();
}

void Heap::swap(int indexOne, int indexTwo)
{
    int temp = data[indexOne];
    data[indexOne] = data[indexTwo];
    data[indexTwo] = temp;
}

void Heap::swapWithLastIndex(int x, int newx)
{
    data[heapLength] = newx;
}

void Heap::insert(int x)
{
    heapLength++;
    data[heapLength] = x;
}

// แก้ไขตอน insert มีปัญหาด้วย bubble up
void Heap::fixInsert()
{
    int currentIndex = heapLength;
    while (currentIndex > 1 && data[parent(currentIndex)] < data[currentIndex])
    {
        swap(currentIndex, parent(currentIndex));
        currentIndex = parent(currentIndex);
    }
}

int Heap::parent(int i) { return i / 2; }
int Heap::leftchild(int i) { return i * 2; }
int Heap::rightchild(int i) { return i * 2 + 1; }

void Heap::heapify(int i)
{
    int largest = i;
    int l = leftchild(i);
    int r = rightchild(i);

    if (l <= heapLength && data[l] > data[largest])
        largest = l;

    if (r <= heapLength && data[r] > data[largest])
        largest = r;

    if (largest != i)
    {
        swap(i, largest);
        // Recursively heapify the affected subtree
        heapify(largest);
    }
}

void Heap::build_heap()
{
    int i = heapLength / 2;
    while (i > 0)
    {
        heapify(i);
        i--;
    }
}

int Heap::GetRoot()
{
    return data[1];
}

void Heap::printArray()
{
    for (int i = 1; i <= heapLength; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

bool Heap::isHeap()
{
    int i = heapLength / 2;
    while (i > 0)
    {
        int largerChildIndex = leftchild(i);
        int rightIndex = rightchild(i);

        if (rightIndex <= heapLength && data[rightIndex] > data[largerChildIndex])
        {
            largerChildIndex = rightIndex;
        }

        if (data[i] < data[largerChildIndex])
        {
            return false;
        }

        i--;
    }

    return true;
}

int Heap::RemoveRoot()
{
    if (heapLength < 1)
    {
        cout << "Cannot remove root Heap is empty." << endl;
    }

    int x = data[1];
    swap(1, heapLength);
    heapLength--;

    if (heapLength > 0)
        heapify(1);

    return x;
}
