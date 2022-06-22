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
bool MCqueue<T>::empty()const{
	if (size == 0)
		return true;
	else 
		return false;
}
template <typename T>
T& MCqueue<T>::front()const{
	auto itr = queue.begin();
	return (*itr);
}
template <typename T>
T& MCqueue<T>::back()const{
	auto itr = queue.end();
	--itr;
	return (*itr);
}

template <typename T>	
void MCqueue<T>::print()const{
	/*auto itr = queue.begin();
	while (itr != queue.end()){
		std::cout << *itr << " ";
		itr++;
	};*/
	queue.print();
}
template <typename T>
unsigned int MCqueue<T>::getSize()const{
	return size;
}

};
