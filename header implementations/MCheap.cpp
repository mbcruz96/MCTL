#include "MCheap.h"
#include <iostream>

namespace mctl{
// MIN HEAP
min_MCheap::min_MCheap(){
	size = 0;
}
// check MCvector later because I dont know what end() returns ******************
min_MCheap::min_MCheap(const MCvector<int>& h){
	auto itr = h.begin();
	while (itr != h.end()){
		push(*itr);
		itr++;
	}
}
min_MCheap& min_MCheap::operator=(const MCvector<int>& h){
	if (size > 0){
		for (size; size > 0;)
			pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		push(*itr);
		itr++;
	}
	return (*this);
}
min_MCheap::min_MCheap(MCvector<int>&& h){
	auto itr = h.begin();
	while (itr != h.end()){
		push(std::move(*itr));
		itr++;
	}
}
min_MCheap& min_MCheap::operator=(MCvector<int>&& h){
	if (size > 0){
		for (size; size > 0;)
			pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		push(std::move(*itr));
		itr++;
	}
	return (*this);
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
	heap.pop_back();
	size--;
}

unsigned int min_MCheap::getSize()const{
	return size;
}
void min_MCheap::print()const{
	heap.print();
}

void min_MCheap::makeHeap(){
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
max_MCheap::max_MCheap(): min_MCheap{}{}

max_MCheap::max_MCheap(const MCvector<int>& h){
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::push(*itr);
		itr++;
	};
}
max_MCheap& max_MCheap::operator=(const MCvector<int>& h){
	if (min_MCheap::size > 0){
		for (min_MCheap::size; min_MCheap::size > 0;)
			min_MCheap::pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::push(*itr);
		itr++;
	};
	return (*this);
}
max_MCheap::max_MCheap(MCvector<int>&& h){
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::push(std::move(*itr));
		itr++;
	};
}
max_MCheap& max_MCheap::operator=(MCvector<int>&& h){
	if (min_MCheap::size > 0){
		for (min_MCheap::size; min_MCheap::size > 0;)
			min_MCheap::pop();
	}
	auto itr = h.begin();
	while (itr != h.end()){
		min_MCheap::push(std::move(*itr));
		itr++;
	};
	return (*this);
}

void max_MCheap::makeHeap(){}
void max_MCheap::heapify(int i){}
}
