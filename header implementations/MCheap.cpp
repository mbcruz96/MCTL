#include "MCheap.h"
#include <iostream>

namespace mctl{
// MIN HEAP
min_MCheap<T>::min_MCheap(){
	size = 0;
}
// check MCvector later because I dont know what end() returns ******************
min_MCheap::min_MCheap(const MCvector<int>& h){
	auto itr = h.begin();
	while (itr != h.end()){
		heap.push(*itr);
		itr++;
	}
}
min_MCheap& min_MCheap::operator=(const MCvector<int>& h){
	if (size > 0){
		for (size; size > 0;)
			heap.pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		heap.push(*itr);
		itr++;
	}
}
min_MCheap::min_MCheap(MCvector<int>&& h){
	auto itr = h.begin();
	while (itr != h.end()){
		heap.push(std::move(*itr));
		itr++;
	}
}
min_MCheap& min_MCheap::operator=(MCvector<int>&& h){
	if (size > 0){
		for (size; size > 0;)
			heap.pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		heap.push(std::move(*itr));
		itr++;
	}
}

bool min_MCheap::empty()const{
	if (size == 0)
		return true;
	else 
		return false;
}
void min_MCheap::push(int val){
	heap.push_back(val);
	size++;
}
void min_MCheap::pop(){
	heap.pop();
	size--;
}

unsigned int min_MCheap::getSize()const{
	return size;
}
void min_MCheap::print()const{
	heap.print();
}

void min_MCheap::heap(){
	int index = getParent(size - 1);
	for (index; index >= 0; index--)
		heapify(index);
}
void min_MCheap::heapify(int i){
	int index = getFirstChild(i);
	// need to overload [] operator on MCvector first **************************
}

int min_MCheap::getParent(int i)const{
	return ((i - 1) / 2);
}
			
int min_MCheap::getFirstChild(int i)const{
	return (i * 2 + 1);
}
///////////////////////////////////////////////////////////////////////////////////////////

// MAX HEAP
max_MCheap::max_MCheap(): min_MCheap() {}
max_MCheap::max_MCheap(const MCvector<int>& h){
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::heap.push(*itr);
		itr++;
	};
}
max_MCheap& max_MCheap::operator=(const MCvector<int>& h){
	if (min_MCheap::size > 0){
		for (min_MCheap::size; min_MCheap::size > 0;)
			min_MCheap::heap.pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::heap.push(*itr);
		itr++;
	};
}
max_MCheap::max_MCheap(MCvector<int>&& h){
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::heap.push(std::move(*itr));
		itr++;
	};
}
max_MCheap& max_MCheap::operator=(MCvector<int>&& h){
	if (min_MCheap::size > 0){
		for (min_MCheap::size; min_MCheap::size > 0;)
			min_MCheap::heap.pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::heap.push(std::move(*itr));
		itr++;
	};
}

void max_MCheap::heap(){}
void max_MCheap::heapify(int i){}
}