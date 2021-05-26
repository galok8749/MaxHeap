#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap {

public:

	// construct empty max heap
	// it will hold object of type T and priority is decided
	// by the user
	MaxHeap<T> (bool (*comp)(T obj1, T obj2));

	// if max heap is empty return true else false
	bool isEmpty();

	// insert element in the max heap
	void push(T obj);

	// delete highest priority element in the max heap
	void pop();

	// return highest priority element in the max heap
	T top();

private:

	// return true if obj1 compares less than obj2
	bool (*compare)(T obj1, T obj2);

	// max heap is implemented using vector
	std::vector<T> heap;

	// maintain max heap property moving from child to parent
	void heapifyUp(int idx);

	// maintain max heap property moving from parent to child
	void heapifyDown(int idx);

	int leftChild(int p) {
		return 2*p + 1;
	}

	int rigtChild(int p) {
		return 2*p + 2;
	}

	int parent(int c) {
		return (c - 1) / 2;
	}
};


template<class T> bool MaxHeap<T>::isEmpty() {
	return heap.empty();
}

template<class T> void MaxHeap<T>::push(T obj) {
	heap.push_back(obj);

	// insert object at end so heapifyUp
	heapifyUp(heap.size()-1);
}

template<class T> void MaxHeap<T>::pop() {
	
	// check heap is empty
	if(!isEmpty()) {
		// swap the last element to first
		std::swap(heap[0], heap[ heap.size() - 1 ]);
		
		// ignore last element i.e. decrease heap size by 1
		heap.pop_back();

		// now heapifyDown 
		if(!isEmpty) {
			heapifyDown(0);
		}
	}
}

template<class T> T MaxHeap<T>::top() {
	if(!isEmpty()) {
		return heap[0];
	}
}

template<class T> void MaxHeap<T>::heapifyDown(int parent) {
	
	int leftChildIndex = leftChild(parent);
	int rigtChildIndex = rigtChild(parent);
	int parentIndex = parent;

	if(leftChildIndex < heap.size()) {
		if(compare(heap[parentIndex], heap[leftChildIndex]))
			parentIndex = leftChildIndex;
	}

	if(rigtChildIndex < heap.size()) {
		if(compare(heap[parentIndex], heap[rigtChildIndex]))
			parentIndex = rigtChildIndex;
	}

	if(parentIndex != parent) {
		std::swap(heap[parentIndex], heap[parentIndex])
		heapifyDown(parentIndex);
	}

}

template<class T> void MaxHeap<T>::heapifyUp(int child) {
	
	int parentIndex = parent(child);

	if(parentIndex < 0)
		return;

	if(compare(heap[parentIndex], heap[child])) {
		std::swap(heap[parentIndex], heap[child]);
		heapifyUp(parentIndex);
	}
}

#endif
