#pragma once
#include <vector>
#include <utility>

using namespace std;

//ADT Priority Queue – using a SLL with (element, priority) pairs ordered based on a relation
//between the priorities.

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool (*Relation)(TPriority p1, TPriority p2);
#define NULL_TELEM pair<TElem, TPriority> (-11111,-11111);

struct Node {
    Element data;
    int next;
};


class PriorityQueue {
private:
    Node nodes[10000];
    Relation relation;
    int firstFree;
    int head;

public:
	//implicit constructor
	PriorityQueue(Relation r);

	//pushes an element with priority to the queue
	void push(TElem e, TPriority p);

	//returns the element with the highest priority with respect to the order relation
	//throws exception if the queue is empty
	Element top()  const;

	//removes and returns the element with the highest priority
	//throws exception if the queue is empty
	Element pop();

	//checks if the queue is empty
	bool isEmpty() const;

    //merges the two priority queues
    void merge(PriorityQueue& pq);

	//destructor
	~PriorityQueue();

};
