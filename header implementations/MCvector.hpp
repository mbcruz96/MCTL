#include "MCvector.h"
#include <iostream>

namespace mctl{
// CONST ITERATOR
template <typename T>
MCvector<T>::const_MCiterator::const_MCiterator(){
	data = nullptr;
	index = -1;
	vecSize = 0;
}
template <typename T>
MCvector<T>::const_MCiterator::const_MCiterator(const const_MCiterator& it){
	data = it.data;
	index = it.index;
	vecSize = it.vecSize;
}
template <typename T>
MCvector<T>::const_MCiterator::const_MCiterator(const_MCiterator&& it){
	data = std::move(it.data);
	index = std::move(it.index);
	vecSize = std::move(it.vecSize);
}
template <typename T>
typename MCvector<T>::const_MCiterator& MCvector<T>::const_MCiterator::operator=(const const_MCiterator& it){
	data = it.data;
	index = it.index;
	vecSize = it.vecSize;
	return *this;
}
template <typename T>
typename MCvector<T>::const_MCiterator& MCvector<T>::const_MCiterator::operator=(const_MCiterator&& it){
	data = std::move(it.data);
	index = std::move(it.index);
	vecSize = std::move(it.vecSize);
	return *this;
}

template <typename T>
MCvector<T>::const_MCiterator::const_MCiterator(unsigned int in, unsigned int s, T* val){
	data = val;
	index = in;
	vecSize = s;
}

template <typename T>
const T & MCvector<T>::const_MCiterator::operator*() const{
	std::cout << "\noverloading * operator from const_MCiterator";
	return retrieve();
}	

template <typename T>
typename MCvector<T>::const_MCiterator & MCvector<T>::const_MCiterator::operator++(){
	if (index < (vecSize -1)){
		index += 1;
		return (*this);
	}
	else {
		data = nullptr;
		index = -1;
		vecSize = 0;
		return (*this);
	}
			
}
template <typename T>
typename MCvector<T>::const_MCiterator MCvector<T>::const_MCiterator::operator++(int){
	const_MCiterator old = *this;
	if (index < (vecSize - 1)){
		index += 1;
	}
	else {
		index = -1;
		data = nullptr;
		vecSize = 0;
	}
	return old;
}
template <typename T>
typename MCvector<T>::const_MCiterator & MCvector<T>::const_MCiterator::operator--(){
	if (index > 0){
		index -= 1;
	}
	else {
		index = -1;
		data = nullptr;
		vecSize = 0;
	}
	return (*this);
}
template <typename T>
typename MCvector<T>::const_MCiterator MCvector<T>::const_MCiterator::operator--(int){
	const_MCiterator old = *this;
	if (index > 0){
		index -= 1;
	}
	else {
		index = -1;
		data = nullptr;
		vecSize = 0;
	}
	return (*this);
}
	
template <typename T>
bool MCvector<T>::const_MCiterator::operator==(const const_MCiterator& rhs){
	return (*data == rhs->data && index == rhs.index);
}
template <typename T>
bool MCvector<T>::const_MCiterator::operator!=(const const_MCiterator& rhs){
	return (data != rhs.data);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ITERATOR
template <typename T>
MCvector<T>::MCiterator::MCiterator(): const_MCiterator{}
{}
template <typename T>
MCvector<T>::MCiterator::MCiterator(const MCiterator& it): const_MCiterator{it}{}
template <typename T>
MCvector<T>::MCiterator::MCiterator(MCiterator&& it): const_MCiterator{std::move(it)}{}
template <typename T>
typename MCvector<T>::MCiterator& MCvector<T>::MCiterator::operator=(const MCiterator& it){
	const_MCiterator::data = it.data;
	const_MCiterator::index = it.index;
	const_MCiterator::vecSize = it.vecSize;
	return *this;
}
template <typename T>
typename MCvector<T>::MCiterator& MCvector<T>::MCiterator::operator=(MCiterator&& it){
	const_MCiterator::data = std::move(it.data);
	const_MCiterator::index = std::move(it.index);
	const_MCiterator::vecSize = std::move(it.vecSize);
	return *this;
}

template <typename T>
MCvector<T>::MCiterator::MCiterator(unsigned int in, unsigned int s, T* val): const_MCiterator{in, s, val}
{}

template <typename T>
T MCvector<T>::MCiterator::operator*(){
	return const_MCiterator::retrieve();
}


template <typename T>			
typename MCvector<T>::MCiterator & MCvector<T>::MCiterator::operator++(){
	if (const_MCiterator::index < (const_MCiterator::vecSize -1)){
		const_MCiterator::index += 1;
		return (*this);
	}
	else {
		const_MCiterator::index = -1;
		const_MCiterator::data = nullptr;
		const_MCiterator::vecSize = 0;
	}
}
template <typename T>
typename MCvector<T>::MCiterator MCvector<T>::MCiterator::operator++(int){
	MCiterator old = *this;
	if (MCvector<T>::index < (const_MCiterator::vecSize - 1)){
		const_MCiterator::index += 1;	

	}
	else {
		const_MCiterator::index = -1;
		const_MCiterator::data = nullptr;	
		const_MCiterator::vecSize = 0;
	}
	return old;
}
template <typename T>
typename MCvector<T>::MCiterator & MCvector<T>::MCiterator::operator--(){
	if (const_MCiterator::index > 0){
		const_MCiterator::index -= 1;
	}
	else {
		const_MCiterator::index = -1;
		const_MCiterator::data = nullptr;
		const_MCiterator::vecSize = 0;
	}
	return (*this);
}
template <typename T>
typename MCvector<T>::MCiterator MCvector<T>::MCiterator::operator--(int){
	MCiterator old = *this;
	if (const_MCiterator::index > 0){
		const_MCiterator::index -= 1;
	}
	else {
		const_MCiterator::index = -1;
		const_MCiterator::data = nullptr;
		const_MCiterator::vecSize = 0;
	}
	return (*this);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VECTOR
template <typename T>
MCvector<T>::MCvector(){
	capacity = 10;
	size = 0;
	mcVec = new T[capacity];
	
}
template <typename T>
MCvector<T>::MCvector(int size){
	capacity = size;
	this.size = 0;
	mcVec = new T[capacity];
}
template <typename T>
MCvector<T>::MCvector(const T& val, int copies){
	capacity = copies + 10;
	size = copies;
	mcVec = new T[capacity];
	for (int i =0; i < size; i++)
		mcVec[i] = val;
}
	
template <typename T>	
MCvector<T>::~MCvector(){
	delete [] mcVec;
}

template <typename T>
MCvector<T> & MCvector<T>::operator=(const MCvector<T>& v){
	if (size > 0)
		delete [] mcVec;
	mcVec = new T[v.capacity];
	for (int i = 0; i < v.size; i++)
		mcVec[i] = v[i];
	return *this;
}

template <typename T>
MCvector<T>::MCvector(MCvector<T>&& v){
	mcVec = new T[v.capacity];
	for (int i = 0; i < v.size; i++)
		mcVec[i] = std::move(v[i]);
}
template <typename T>
MCvector<T> & MCvector<T>::operator=(MCvector<T> && v){
	if (size > 0)
		delete [] mcVec;
	mcVec = new T[v.capacity];
	for (int i = 0; i < v.size; i++)
		mcVec[i] = std::move(v[i]);
	return *this;
}
template <typename T>
T MCvector<T>::operator[](int index){
	return mcVec[index];
}
/*
template <typename T, typename F>
std::ostream & MCvector<T>::operator<<(std::ostream& os, const F& vec){
	for (int i = 0; i < size; i++){
		os << vec[i] + " ";
	}
}
*/

// VECTOR INSERTS AND DELETES
template <typename T>
void MCvector<T>::push_back(const T& val){
	if (size >= capacity)
		resize();
	mcVec[size++] = val;
}
template <typename T>
void MCvector<T>::pop_back(){
	--size;
}


template <typename T>
typename MCvector<T>::MCiterator MCvector<T>::insert(MCiterator it, const T& val){
	if (it.index < size){
		int temp = mcVec[it.index];
		mcVec[it.index] = val;
		for (int i = it.index + 1; i < getSize(); i++)
			std::swap(temp, mcVec[i]);	
		push_back(temp);
		return MCiterator(it.index, size, val);
	}
	else 
		return MCiterator();
}


// VECTOR ITERATOR FUNCTIONS
template <typename T>
typename MCvector<T>::MCiterator MCvector<T>::begin()const{
	if (size > 0){
		return MCiterator(0, size, mcVec);
	} 
	else 
		return MCiterator();
}

// returns the value of the last element
template <typename T>
typename MCvector<T>::MCiterator MCvector<T>::end()const{
	return MCiterator();
}

/*
template <typename T>
const typename MCvector<T>::MCiterator MCvector<T>::cbegin(){
	if (size > 0)
		return const_MCiterator(0, mcVec[0]);
	else 
		return const_MCiterator();
}
template <typename T>
const typename MCvector<T>::MCiterator MCvector<T>::cend(){
	if (size > 0)
		return const_MCiterator(size, mcVec[size - 1]);
	else 
		return const_MCiterator();
}
*/
// UTILITY FUNCTIONS
template <typename T>
void MCvector<T>::print()const{
	for (int i = 0; i < size; i++){
		std::cout << mcVec[i] << " ";
	}
	std::cout << '\n';
}

template <typename T>
unsigned int MCvector<T>::getSize()const{
	return size;
}


template <typename T>
void MCvector<T>::resize(){
	if (size >= capacity){
		capacity *= 2;
		T* newVec = new T[capacity];
		for (int i = 0; i < size; i++)
			newVec[i] = mcVec[i];
		delete [] mcVec;
		mcVec = newVec;
	}
}
template <typename T>
bool MCvector<T>::isEmpty()const{
	return (size == 0);
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const MCvector<T>& vector){
	if (!vector.isEmpty()){
		//for (int i = 0; i < vector.getSize(); i++){
		auto itr = vector.begin();
		while (itr != vector.end()){
			out << *itr << " ";
			++itr;
		};
		out << '\n';
	}
	else 
		out << "Empty vector\n";
}	
};
