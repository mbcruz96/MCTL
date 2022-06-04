#include "MClist.h"
namespace mctl{
// CONST ITERATOR
template <typename T>
MClist<T>::const_MCiterator::const_MCiterator(){
	data = new Node();
}
template <typename T>
MClist<T>::const_MCiterator::~const_MCiterator(){
	delete data;
}

template <typename T>
const T& MClist<T>::const_MCiterator::operator*()const{
	return retrieve();
}
			
template <typename T>		
typename MClist<T>::const_MCiterator& MClist<T>::const_MCiterator::operator++(){
	if (data->next != nullptr)
		data = data->next;
	else 
		data = nullptr;
	return (*this);
}

template <typename T>
typename MClist<T>::const_MCiterator  MClist<T>::const_MCiterator::operator++(int){
	const_MCiterator old = *this;
	data = data->next;
	return old;
}
template <typename T>
typename MClist<T>::const_MCiterator& MClist<T>::const_MCiterator::operator--(){
	data = data->prev;
	return (*this);
}
template <typename T>
typename MClist<T>::const_MCiterator  MClist<T>::const_MCiterator::operator--(int){
	const_MCiterator old = *this;
	data = data->prev;
	return old;
}

template <typename T>					
bool MClist<T>::const_MCiterator::operator==(const const_MCiterator& rhs){
	if (rhs->value == this->value && rhs->prev == this->prev && rhs->next == this->next)
		return true;
	else 
		return false; 
}
template <typename T>
bool MClist<T>::const_MCiterator::operator!=(const const_MCiterator& rhs){
	return !(rhs == *this); 
}

/////////////////////////////////////////////////////////////////////////////////

// ITERATOR 
template <typename T>
MClist<T>::MCiterator::MCiterator(): const_MCiterator(){
	const_MCiterator::data = new Node();
}
template <typename T>
T& MClist<T>::MCiterator::operator*()const{
	return const_MCiterator::retrieve();
}
			
template <typename T>					
typename MClist<T>::MCiterator& MClist<T>::MCiterator::operator++(){
	if (const_MCiterator::data->next != nullptr)
		const_MCiterator::data = const_MCiterator::data->next;
	else 
		const_MCiterator::data = nullptr;
	return (*this);
}
template <typename T>
typename MClist<T>::MCiterator  MClist<T>::MCiterator::operator++(int){
	MCiterator old = *this;
	if (const_MCiterator::data->next != nullptr)
		const_MCiterator::data = const_MCiterator::data->next;
	else 
		const_MCiterator::data = nullptr;
	return old;
}
template <typename T>
typename MClist<T>::MCiterator& MClist<T>::MCiterator::operator--(){
	if (const_MCiterator::data->prev != nullptr){
		const_MCiterator::data = const_MCiterator::data->prev;
		return (*this);
	}
	else 
		const_MCiterator::data = nullptr;
		return new Node();
}
template <typename T>
typename MClist<T>::MCiterator  MClist<T>::MCiterator::operator--(int){
	if (const_MCiterator::data->prev != nullptr){
		MCiterator old = *this;
		const_MCiterator::data = const_MCiterator::data->prev;
		return old;
	}
	else 
		return new Node();
}


///////////////////////////////////////////////////////////////////////////////

// LIST
template <typename T>
MClist<T>::MClist(){
	head = new Node();
	tail = new Node();
	size = 0;
}
template <typename T>
MClist<T>& MClist<T>::operator=(const MClist<T>& l){}
template <typename T>
MClist<T>::~MClist(){
	auto itr = begin();
	while (itr != end()){
		auto tempItr = *itr;
		itr = itr->next;
		delete tempItr;		
	}
}

template <typename T>			
MClist<T>::MClist(T val, int copies){}
			
template <typename T>			
MClist<T>::MClist(MClist<T>&& l){}
template <typename T>
MClist<T>& MClist<T>::operator=(MClist<T>&& l){}
			
template <typename T>			
void MClist<T>::push_back(T val){
	auto temp = *tail;
	tail = new Node(val, temp, nullptr);
	temp->next = tail;
	
}
template <typename T>
void MClist<T>::push_front(T val){
	auto temp = *head;
	head = new Node(val, nullptr, temp);
	temp->prev = head; 
}
template <typename T>
void MClist<T>::pop_back(){
	auto temp = *tail;
	tail = tail->prev;
	delete temp;
}
template <typename T>
void MClist<T>::pop_front(){
	auto temp = *head;
	head = head->next;
	delete temp;
}
		
template <typename T>			
typename MClist<T>::MCiterator MClist<T>::begin(){
	return head;
}
template <typename T>
typename MClist<T>::MCiterator MClist<T>::end(){
	return new Node();
}

template <typename T>			
typename MClist<T>::MCiterator MClist<T>::insert(MCiterator it, T val){}
template <typename T>
void MClist<T>::print(){}
template <typename T>
unsigned int MClist<T>::getSize(){
	return size;
}
};
/*
Node* head;
Node* tail;
unsigned int size;
*/

