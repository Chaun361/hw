#include <cstddef>
#include <string>
#include "heap.h"
#include "pq.h"
#include <iostream>

using namespace std;

void insertLoop(PriorityQueue *pq)
{
    string str;
    int lastInserted = 0;
    bool hasLast = false;

    while (true)
    {
        cout << "Number to insert :  ";
        getline(cin, str);

        // ถ้าไม่มี input ออกจากโปรแกรม
        if (str.empty())
        {
            break;
        }

        try
        {
            // Convert input string to integer
            int x = stoi(str);

            // Insert ไปที่ priority queue
            pq->Insert(x);
            lastInserted = x;
            hasLast = true;

            // ถ้า heap ไม่ถูกต้องจะให้ user เลือกว่าจะเปลี่ยนไหมเป็นการเรียกใช้ Modify()
            if (!pq->isViolated())
            {
                cout << "Insertion violated heap property. Swap last input? (y/n): ";
                string ans;
                getline(cin, ans);
                if (!ans.empty() && (ans[0] == 'y' || ans[0] == 'Y'))
                {
                    cout << "Enter new value to replace " << lastInserted << ": ";
                    string repl;
                    getline(cin, repl);
                    try
                    {
                        int newx = stoi(repl);
                        pq->Modify(lastInserted, newx);
                        lastInserted = newx;
                        cout << "Replaced with " << newx << "." << endl;
                    }
                    catch (const exception &e)
                    {
                        cout << "Invalid replacement value. No changes made." << endl;
                    }
                }
            }
        }
        catch (const exception &e)
        {
            // Handle invalid input
            cout << "Invalid input. Do you want to swap the last inserted value? (y/n): ";
            string ans;
            getline(cin, ans);
            if (!ans.empty() && (ans[0] == 'y' || ans[0] == 'Y'))
            {
                if (!hasLast)
                {
                    cout << "No previous value to swap." << endl;
                }
                else
                {
                    cout << "Enter new value to replace " << lastInserted << ": ";
                    string repl;
                    getline(cin, repl);
                    try
                    {
                        int newx = stoi(repl);
                        pq->Modify(lastInserted, newx);
                        lastInserted = newx;
                        cout << "Replaced with " << newx << "." << endl;
                    }
                    catch (const exception &e)
                    {
                        cout << "Invalid replacement value. No changes made." << endl;
                    }
                }
                continue;
            }
            // ถ้า user ไม่ต้องการใส่ค่าใหม่รันโปรแกรมต่อไป
            cout << "Ignored invalid input. Continue entering numbers or press Enter to finish." << endl;
            continue;
        }
    }
}

int main()
{
    // ทดสอบ heap class ------------------------------------------------------------------------
    int arr[] = {5, 2, 3, 1};
    Heap *heap = new Heap(arr, 4);

    if (!heap->isHeap())
        heap->build_heap();

    cout << "Initial Array: " << endl;
    heap->printArray();

    heap->insert(12);
    if (!heap->isHeap())
        // bubble up
        heap->fixInsert();

    cout << "Array after heap fixed if insert number violated heap property: " << endl;
    heap->printArray();

    // ทดสอบ priority queue ------------------------------------------------------------------------
    PriorityQueue *pq = new PriorityQueue();

    cout << "add value to the priority queue (exit press enter)" << endl;
    insertLoop(pq);

    pq->print();

    cout << "Max value: " << pq->Max() << endl;
    cout << "Popped max: " << pq->ExtractMax() << endl;
    cout << "queue array after poped: ";
    pq->print();
}