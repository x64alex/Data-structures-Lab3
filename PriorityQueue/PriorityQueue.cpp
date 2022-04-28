
#include "PriorityQueue.h"
#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;


PriorityQueue::PriorityQueue(Relation r):head{NULL}, relation{r}
{}

/*
* Best Case: Theta(1)
* Worst Case: Theta(n)
* Average Case: Theta(n)
* Total case: O(n)
*/
void PriorityQueue::push(TElem e, TPriority p) {
	Element item(e,p);

    Node* newNode = new Node();
    newNode->data = item;
    newNode->next =NULL;

    if(this->head == NULL){
        this->head = newNode;
        this->head->next = NULL;
    }
    else {

        if (relation(newNode->data.second, this->head->data.second)) {
            newNode->next = head;
            this->head = newNode;
        } else {
            Node* iteratorNode;
            iteratorNode = this->head;

            while (iteratorNode->next != NULL &&
                   relation(iteratorNode->next->data.second, newNode->data.second)) {
                iteratorNode = iteratorNode->next;
            }

            // Either at the ends of the list
            // or at required position
            newNode->next = iteratorNode->next;
            iteratorNode->next = newNode;
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

    return this->head->data;
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

    Element e;
    Node* p = this->head;
    e.first = this->head->data.first;
    e.second = this->head->data.second;
    this->head = this->head->next;
    free(p);
    return e;
}

/*
* Best Case: Theta(1)
* Worst Case: Theta(1)
* Average Case: Theta(1)
* Total case: Theta(1)
*/
bool PriorityQueue::isEmpty() const {
	return head == NULL;
}

/*
* Best Case: Theta(n)
* Worst Case: Theta(n)
* Average Case: Theta(n)
* Total case: Theta(n)
*/
PriorityQueue::~PriorityQueue() {
	while(!isEmpty()){
        Node* p = this->head;
        this->head = this->head->next;
        free(p);
    }
}

/*
* Best Case: Theta(1)
* Worst Case: Theta(n)
* Average Case: Theta(n)
* Total case: O(n)
*/
TPriority PriorityQueue::IncreasePriority(TElem elem, TPriority newPriority) {
    Node* iteratorNode;
    TPriority oldPriority;

    iteratorNode = this->head;

    while (iteratorNode!= NULL && iteratorNode->data.first !=elem ) {
        iteratorNode = iteratorNode->next;
    }
    if(iteratorNode!=NULL)
    {
        oldPriority = iteratorNode->data.first;
        if(relation(newPriority,oldPriority)){
            throw exception_ptr();
        }
        iteratorNode->data.second = newPriority;
        return oldPriority;
    }
    else{
        return -1;
    }
};

