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
	else 
		data = nullptr;
	return (*this);
}

template <typename T>
typename MClist<T>::const_MCiterator  MClist<T>::const_MCiterator::operator++(int){
	const_MCiterator old = *this;	
	if (data->next != nullptr)
		data = data->next;
	else 
		data = nullptr;
	return old;
}
template <typename T>
typename MClist<T>::const_MCiterator& MClist<T>::const_MCiterator::operator--(){
	if (data->next != nullptr)
		data = data->prev;
	else
		data = nullptr;
	return (*this);
}
template <typename T>
typename MClist<T>::const_MCiterator  MClist<T>::const_MCiterator::operator--(int){
	const_MCiterator old = *this;
	if (data->next != nullptr)
		data = data->prev;
	else 
		data = nullptr;
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
MClist<T>::MCiterator::MCiterator(): const_MCiterator{}{
	const_MCiterator::data = nullptr;
}
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
	if (const_MCiterator::data->prev != nullptr)
		const_MCiterator::data = const_MCiterator::data->prev;
	else 
		const_MCiterator::data = nullptr;
	return (*this);
}
template <typename T>
typename MClist<T>::MCiterator  MClist<T>::MCiterator::operator--(int){
	MCiterator old = *this;
	if (const_MCiterator::data->prev != nullptr){
		const_MCiterator::data = const_MCiterator::data->prev;
	}
	else 
		const_MCiterator::data = nullptr;
	return old;
}


///////////////////////////////////////////////////////////////////////////////

// LIST
template <typename T>
MClist<T>::MClist(){
	head = nullptr;
	tail = nullptr;
	size = 0;
}
template <typename T>
MClist<T>::MClist(const MClist<T>&){
	
}
template <typename T>
MClist<T>& MClist<T>::operator=(const MClist<T>& l){
	if (size > 0){
		while (size > 0){
			auto tempNode = pop_back();
			delete tempNode;
		};
	}
	head = new Node(l.head);
	size = l.size;
	auto itr = l.begin();
	itr++;
	while (itr != l.end()){
		push_back(new Node(itr.data));
		itr++;
	};
	tail = 
	return (*this);
}
template <typename T>
MClist<T>::~MClist(){
	while (size > 0){
		auto tempNode = pop_back();
		delete tempNode;		
	};
}

template <typename T>			
MClist<T>::MClist(T val, int copies){}
			
template <typename T>			
MClist<T>::MClist(MClist<T>&& l){
	head = std::move(l.head);
	auto itr = l.begin();
	itr++;
	while (itr != l.end()){
		push_back(std::move(itr.data));
		itr++;
	};
}
template <typename T>
MClist<T>& MClist<T>::operator=(MClist<T>&& l){
	if (size > 0){
		while (size > 0){
			auto tempNode = pop_back();
			delete tempNode;
		};
	}
	auto itr = l.begin();
	while (itr != l.end()){
		push_back(new Node(std::move(itr.data)));
		itr++;
	};
	head = std::move(l.head);
	tail = std::move(l.tail);
	size = std::move(l.size);
	return (*this);
}
			
template <typename T>			
void MClist<T>::push_back(T val){
	Node* node = new Node(val, tail, nullptr);
	tail->next = node;
	tail = node;
	size++;
	if (size == 1)
		head = tail;
	
}
template <typename T>
void MClist<T>::push_front(T val){
	Node* node = new Node(val, nullptr, head);
	head->prev = node;
	head = node; 
	size++;
	if (size == 1)
		tail = head;
}
template <typename T>
typename MClist<T>::Node* MClist<T>::pop_back(){
	if (size > 0){
		Node* node = tail;
		tail = node->prev;
		size--;
		return node;
	}
	else
		return nullptr;
}
template <typename T>
typename MClist<T>::Node* MClist<T>::pop_front(){
	if (size > 0){
		Node* node = head;
		head = node->next;
		size--;
		return node;
	}
	else 
		return nullptr;

}
		
template <typename T>			
typename MClist<T>::MCiterator MClist<T>::begin()const{
	return MCiterator(head);
}
template <typename T>
typename MClist<T>::MCiterator MClist<T>::end()const{
	return MCiterator();
}

template <typename T>			
typename MClist<T>::MCiterator MClist<T>::insert(MCiterator it, T val){}
template <typename T>
void MClist<T>::print()const{
	auto itr = begin();
	while (itr != end()){
		std::cout << *itr << " ";
		++itr;
	}
	std::cout << *itr << std::endl;
}
template <typename T>
unsigned int MClist<T>::getSize()const{
	return size;
}
};
