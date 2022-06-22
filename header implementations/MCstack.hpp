#include "MCstack.h"
#include <iostream>
#include <utility>

namespace mctl{
template <typename T>
MCstack<T>::MCstack(){
	size = 0;
}
template <typename T>
MCstack<T>::MCstack(const MCstack<T>& st){
	auto itr = st.begin();
	while (itr != st.end()){
		vec.push(*itr);
		++itr;
	};
	vec.push(*itr);
}
		
template <typename T>
MCstack<T>& MCstack<T>::operator=(const MCstack<T>& st){
	if (size > 0){
		while (size > 0){
			vec.pop();
		};
	}
	auto itr = st.begin();
	while(itr != st.end()){
		vec.push(*itr);
		++itr;
	};
	vec.push(*itr);
}
template <typename T>
MCstack<T>::MCstack(MCstack<T>&& st){
	vec = std::move(st.vec);
	size = std::move(st.size);
}
template <typename T>
MCstack<T>& MCstack<T>::operator=(MCstack<T>&& st){
	if (size > 0){
		while (size > 0){
			vec.pop();
		};
	}
	vec = std::move(st.vec);
	size = std::move(st.size);
}
			
template <typename T>
void MCstack<T>::push(T val){
	vec.push_back(val);
	size++;
}
template <typename T>
void MCstack<T>::pop(){
	vec.pop_back();
	size--;
}

template <typename T>			
bool MCstack<T>::empty()const{
	if (size == 0)
		return true;
	else 
		return false;
}
template <typename T>
T& MCstack<T>::top()const{
	auto itr = vec.end();
	return *itr;
}
		
template <typename T>		
void MCstack<T>::print()const{
	auto itr = vec.end();
	while (itr != vec.begin()){
		std::cout << *itr << " ";
		--itr;
	};
	std::cout << *itr << std::endl;
}
template <typename T>
unsigned int MCstack<T>::getSize()const{
	return size;
}
};
