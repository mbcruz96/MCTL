#include "MCqueue.h"
#include <iostream>

namespace mctl{
template <typename T>
MCqueue<T>::MCqueue(){
	size = 0;
}
template <typename T>
MCqueue<T>::MCqueue(const MCqueue<T>& q){
	auto itr = q.begin();
	while (itr != q.end()){
		queue.push(*itr);
		itr++;
	};
}
template <typename T>
MCqueue<T>& MCqueue<T>::operator=(const MCqueue<T>& q){
	if (size > 0){
		for (size; size > 0;)
			queue.pop();
	}
	auto itr = q.begin();
	while (itr != q.end()){
		queue.push(*itr);
		itr++;
	};
}
template <typename T>
MCqueue<T>::MCqueue(MCqueue<T>&& q){
	auto itr = q.begin();
	while (itr != q.end()){
		queue.push(std::move(*itr));
		itr++;
	};
}
template <typename T>
MCqueue<T>& MCqueue<T>::operator=(MCqueue<T>&& q){
	if (size > 0){
		for (size; size > 0;)
			queue.pop();
	}
	auto itr = q.begin();
	while (itr != q.end()){
		queue.push(std::move(*itr));
		itr++;
	};
}
	
template <typename T>
void MCqueue<T>::push(const T& val){
	queue.push_back(val);
	size++;
}
template <typename T>
void MCqueue<T>::pop(){
	queue.pop_front();
	size--;
}
template <typename T>
bool MCqueue<T>::isEmpty()const{
	if (size == 0)
		return true;
	else 
		return false;
}
// *** problem when the queue is empty
template <typename T>
T MCqueue<T>::front()const{
	auto itr = queue.begin();
	T temp = *itr;
	return (*itr);
}
// *** problem when the queue is empty
template <typename T>
T MCqueue<T>::back()const{
	auto itr = queue.end();
	--itr;
	return (*itr);
}

template <typename T>	
void MCqueue<T>::print()const{
	queue.print();
}
template <typename T>
unsigned int MCqueue<T>::getSize()const{
	return size;
}

template <typename T>
void MCqueue<T>::empty(){
	queue.empty();
}
};
