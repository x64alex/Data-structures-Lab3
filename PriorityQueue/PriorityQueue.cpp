
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
            this->nodes[this->head] = newNode;
            this->firstFree++;
        } else {
            int iteratorNode;
            iteratorNode = this->head;

            while (this->nodes[iteratorNode].next != -1 &&
                   relation(this->nodes[iteratorNode].data.second, newNode.data.second)) {
                iteratorNode = this->nodes[iteratorNode].next;
            }

            // Either at the ends of the list
            // or at required position
            Node n = this->nodes[iteratorNode];
            cout<<n.data.first<<" "<<n.data.second<<"  "<<n.next<<endl;
            n.next = this->firstFree;
            this->nodes[iteratorNode].next = this->firstFree;
            this->nodes[firstFree] = newNode;
            this->firstFree++;

            //iteratorNode->next = newNode;
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
* Worst Case: Theta(n)
* Average Case: Theta(n)
* Total case: Theta(n)
*/
PriorityQueue::~PriorityQueue() {

}
