#include "MClist.h"
namespace mctl{
// CONST ITERATOR
template <typename T>
MClist<T>::const_MCiterator::const_MCiterator(){
	data = nullptr;
}
template <typename T>
MClist<T>::const_MCiterator::const_MCiterator(Node* node){
	data = node;
}
template <typename T>
MClist<T>::const_MCiterator::const_MCiterator(const const_MCiterator& it){
	data = it.data;
}
template <typename T>
MClist<T>::const_MCiterator::const_MCiterator(const_MCiterator&& it){
	data = std::move(it.data);
}
template <typename T>
const T MClist<T>::const_MCiterator::operator*()const{
	return retrieve();
}
			
template <typename T>		
typename MClist<T>::const_MCiterator& MClist<T>::const_MCiterator::operator++(){
	if (data->next != nullptr)
		data = data->next;
	return (*this);
}

template <typename T>
typename MClist<T>::const_MCiterator  MClist<T>::const_MCiterator::operator++(int){
	const_MCiterator old = *this;	
	if (data->next != nullptr)
		data = data->next;
	return old;
}
template <typename T>
typename MClist<T>::const_MCiterator& MClist<T>::const_MCiterator::operator--(){
	if (data->prev != nullptr)
		data = data->prev;
	return (*this);
}
template <typename T>
typename MClist<T>::const_MCiterator  MClist<T>::const_MCiterator::operator--(int){
	const_MCiterator old = *this;
	if (data->prev != nullptr)
		data = data->prev;
	return old;
}

template <typename T>					
bool MClist<T>::const_MCiterator::operator==(const const_MCiterator& rhs)const{
	if (rhs.data == data)
		return true;
	else 
		return false; 
}
template <typename T>
bool MClist<T>::const_MCiterator::operator!=(const const_MCiterator& rhs)const{
	return !(rhs.data == data);
}

/////////////////////////////////////////////////////////////////////////////////

// ITERATOR 
template <typename T>
MClist<T>::MCiterator::MCiterator(): const_MCiterator{}{}
template <typename T>
MClist<T>::MCiterator::MCiterator(Node* node): const_MCiterator{node}{}
template <typename T>
MClist<T>::MCiterator::MCiterator(const MCiterator& it): const_MCiterator{it.data}{}
template <typename T>
MClist<T>::MCiterator::MCiterator(MCiterator&& it): const_MCiterator{std::move(it.data)}{}
template <typename T>
T MClist<T>::MCiterator::operator*()const{
	return const_MCiterator::retrieve();
}
			
template <typename T>					
typename MClist<T>::MCiterator& MClist<T>::MCiterator::operator++(){
	if (const_MCiterator::data->next != nullptr)
		const_MCiterator::data = const_MCiterator::data->next;
	return (*this);
}
template <typename T>
typename MClist<T>::MCiterator  MClist<T>::MCiterator::operator++(int){
	MCiterator old = *this;
	if (const_MCiterator::data->next != nullptr)
		const_MCiterator::data = const_MCiterator::data->next;
	return old;
}
template <typename T>
typename MClist<T>::MCiterator& MClist<T>::MCiterator::operator--(){
	if (const_MCiterator::data->prev != nullptr)
		const_MCiterator::data = const_MCiterator::data->prev;
	return (*this);
}
template <typename T>
typename MClist<T>::MCiterator  MClist<T>::MCiterator::operator--(int){
	MCiterator old = *this;
	if (const_MCiterator::data->prev != nullptr)
		const_MCiterator::data = const_MCiterator::data->prev;
	return old;
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
MClist<T>::MClist(const MClist<T>& l){
	head = new Node(l.head);
	tail = new Node(l.tail);
	size = l.size;
	auto itr = l.begin();
	while(itr != l.end()){
		push_back(itr.data);
		itr++;
	};
}
template <typename T>
MClist<T>& MClist<T>::operator=(const MClist<T>& l){
	if (size > 0){
		while (pop_back()){
			continue;
		};
		delete head;
		delete tail;
	}
	head = new Node(l.head);
	tail = new Node(l.tail);
	size = l.size;
	auto itr = l.begin();
	while (itr != nullptr){
		itr = push_back(new Node(itr.data));
		itr++;
	};
	return (*this);
}
template <typename T>
MClist<T>::~MClist(){
	while (size > 0){
		while(pop_back()){
			continue;
		};
		delete head;
		delete tail;		
	};
}

template <typename T>			
MClist<T>::MClist(T val, int copies){}
			
template <typename T>			
MClist<T>::MClist(MClist<T>&& l){
	head = std::move(l.head);
	tail = std::move(l.tail);
	size = std::move(l.size);
	auto itr = l.begin();
	while (itr != l.end()){
		push_back(std::move(itr.data));
		++itr;
	};
}
template <typename T>
MClist<T>& MClist<T>::operator=(MClist<T>&& l){
	if (size > 0){
		while (pop_back()){
			continue;
		};
		delete head;
		delete tail;
	}
	head = std::move(l.head);
	tail = std::move(l.tail);
	size = std::move(l.size);
	auto itr = l.begin();
	while (itr != l.end()){
		push_back(std::move(itr.data));
		++itr;
	};
	return (*this);
}
			
template <typename T>			
void MClist<T>::push_back(T val){
	if (size > 0){
		Node* node = new Node(val, tail->prev, tail);
		tail->prev->next = node;
		tail->prev = node;
	}
	else
		head->next = tail->prev = new Node(val, head, tail);
	++size;
}
template <typename T>
void MClist<T>::push_front(T val){
	if (size > 0){
		Node* node = new Node(val, head, head->next);
		head->next->prev = node;
		head->next = node;
	}
	else
		tail->prev = head->next = new Node(val, head, tail);
	++size;
}
template <typename T>
bool MClist<T>::pop_back(){
	Node* node = tail->prev;
	if (size > 1){
		node->prev->next = tail;
		tail->prev = node->prev;
		delete node;
		--size;
		return true;
	}
	else if (size == 1){
		tail->prev = nullptr;
		head->next = nullptr;
		delete node;
		--size;
		return true;
	}
	else
		return false;
}
template <typename T>
bool MClist<T>::pop_front(){
	Node* node = head->next;
	if (size > 1){
		node->next->prev = head;
		head->next = node->next;
		delete node;
		--size;
		return true;
	}
	else if (size == 1){
		head->next = nullptr;
		tail->prev = nullptr;
		delete node;
		--size;
		return true;
	}
	else 
		return false;

}
		
template <typename T>			
typename MClist<T>::MCiterator MClist<T>::begin()const{
	auto itr = MCiterator(head->next);
	return itr;
}
template <typename T>
typename MClist<T>::MCiterator MClist<T>::end()const{
	auto itr = MCiterator(tail);
	return itr;
}

template <typename T>			
typename MClist<T>::MCiterator MClist<T>::insert(MCiterator it, T val){}
template <typename T>
void MClist<T>::print()const{
	if (size > 0){
		auto itr = begin();
		while (itr != end()){
			std::cout << *itr << " ";
			++itr;
		};
		std::cout << '\n';
	}
}
template <typename T>
unsigned int MClist<T>::getSize()const{
	return size;
}
};
