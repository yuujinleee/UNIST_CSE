#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

/** 
 * Assignment 5 for CSE221 Data Structures
 *
 * 2014. 11. 17
 *
 */


// Heap element
class heapElem {
public:
	unsigned int vidx; // vertex index
	double dist; // shortest path distance
};


// MinHeap class
class MinHeap {
public:
	MinHeap(unsigned int maxheapsize)
	{
		size = 0;      // current heap size
		capacity = maxheapsize; // maximum heap capacity
		heapArray = new heapElem[capacity+1]; // first element is stored in heapElem[1]
		mapVidxToArray = new unsigned int[capacity];
		for(int i=0; i<capacity; i++) mapVidxToArray[i] = 0; // new init
	};
	
	~MinHeap();
	
	void Push(const heapElem& e);
	
	const heapElem & Top();
	
	void Pop();
	
	bool Modify(const heapElem& e);
	
	bool IsEmpty();

	void Swap(unsigned int i1, unsigned int i2);

	void Up(unsigned int i1);

	void Down(unsigned int i1);
	
	// new function
	bool IsInHeap(const heapElem& e) 
	{
		if(mapVidxToArray[e.vidx] == 0) return false;
		return true;		
	};
	
private:
	heapElem* heapArray;
	unsigned int* mapVidxToArray; // map between vertex index to heapArray
	unsigned int capacity, size;
};

#endif
