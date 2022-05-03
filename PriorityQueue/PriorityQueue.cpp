
#include "PriorityQueue.h"
#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;


PriorityQueue::PriorityQueue(Relation r):head{-1}, relation{r},firstFree{1}
{}

/*
* Best Case: Theta(1)
* Worst Case: Theta(n)
* Average Case: Theta(n)
* Total case: O(n)
*/
void PriorityQueue::push(TElem e, TPriority p)
{
	Element item(e,p);

    Node newNode;
    newNode.data = item;
    newNode.next = -1;

    if(this->head == -1)
    {
        this->head = firstFree;
        firstFree++;
        this->nodes[this->head] = newNode;
    }
    else
    {
        if (relation(newNode.data.second, this->nodes[this->head].data.second)) {
            newNode.next = head;
            this->head = this->firstFree;
            this->nodes[this->firstFree] = newNode;
            this->firstFree++;
        }
        else {
            int iteratorNode= this->head;

            while (this->nodes[iteratorNode].next != -1 &&
                   relation(this->nodes[iteratorNode].data.second, newNode.data.second)) {
                iteratorNode = this->nodes[iteratorNode].next;
            }
            if(relation(this->nodes[iteratorNode].data.second, newNode.data.second))
            {
                // At the ends of the list
                this->nodes[iteratorNode].next = this->firstFree;
                this->nodes[this->firstFree] = newNode;
                this->nodes[this->firstFree].next =-1;
                this->firstFree++;
            }
            else {
                // or at required position
                Node n = this->nodes[iteratorNode];
                newNode.next = this->firstFree;
                this->nodes[iteratorNode] = newNode;
                this->nodes[firstFree] = n;
                this->firstFree++;
            }

        }
    }
}

//throws exception if the queue is empty
/*
* Best Case: Theta(1)
* Worst Case: Theta(1)
* Average Case: Theta(1)
* Total case: Theta(1)
*/
Element PriorityQueue::top() const {
    if(this->isEmpty())
    {
        throw exception_ptr();
    }

    return this->nodes[this->head].data;
}

/*
* Best Case: Theta(1)
* Worst Case: Theta(1)
* Average Case: Theta(1)
* Total case: Theta(1)
*/
Element PriorityQueue::pop() {
    if(this->isEmpty())
    {
        throw exception_ptr();
    }
    Node p = this->nodes[this->head];
    this->head = p.next;
    return p.data;
}

/*
* Best Case: Theta(1)
* Worst Case: Theta(1)
* Average Case: Theta(1)
* Total case: Theta(1)
*/
bool PriorityQueue::isEmpty() const {
	return head == -1;
}

/*
* Best Case: Theta(n)
* Worst Case: Theta(n^2)
* Average Case: Theta(n^2)
* Total case: O(n^2)
*/
void PriorityQueue::merge(PriorityQueue& pq) {
    while(pq.head !=-1)
    {
        TElem e = pq.nodes[pq.head].data.first;
        TPriority p = pq.nodes[pq.head].data.second;
        this->push(e,p);
        pq.head = pq.nodes[pq.head].next;
    }
}

/*
* Best Case: Theta(n)
* Worst Case: Theta(1)
* Average Case: Theta(1)
* Total case: Theta(1)
*/
PriorityQueue::~PriorityQueue() {

}
