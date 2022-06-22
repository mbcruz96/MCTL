#include "MCbinaryTree.h"

namespace mctl{
// CONST ITERATOR
template <typename T>
MCbinaryTree<T>::const_MCiterator::const_MCiterator(){
	data = nullptr;
}
template <typename T>
MCbinaryTree<T>::const_MCiterator::const_MCiterator(Node* curr){
	current = curr;
}
					
template <typename T>
const T& MCbinaryTree<T>::const_MCiterator::operator*()const{
	Node* node = retrieve();
	return *node;
}
template <typename T>
typename MCbinaryTree<T>::const_MCiterator& MCbinaryTree<T>::const_MCiterator::operator++(){
	if (data->rchild != nullptr)
		current = current->rchild;
	else 
		return const_MCiterator();
}
template <typename T>
const_MCiterator  MCbinaryTree<T>::const_MCiterator::operator++(int){
	auto old = *this;
	if(data->lchild != nullptr)
		data = data->lchild)
	else if (data->rchild != nullptr)
		data = data->rchild;
	else 
		data = nullptr;
	return old;
}
template <typename T>
typename MCbinaryTree<T>::const_MCiterator& MCbinaryTree<T>::const_MCiterator::operator--(){
	if(data->lchild != nullptr)
		return const_MCiterator(data->lchild);
	else if (data->rchild != nullptr)
		return const_MCiterator(data->rchild);
	else 
		return const_MCiterator();
}
template <typename T>
const_MCiterator  MCbinaryTree<T>::const_MCiterator::operator--(int){}
					
template <typename T>
bool MCbinaryTree<T>::const_MCiterator::operator==(const const_MCiterator&, const const_MCiterator&)const{}
template <typename T>
bool MCbinaryTree<T>::const_MCiterator::operator!=(const const_MCiterator&, const const_MCiterator&)const{}

///////////////////////////////////////////////////////////////////////////////////////////////

// ITERATOR
template <typename T>
MCbinaryTree<T>::MCiterator::MCiterator(){}
template <typename T>
MCbinaryTree<T>::MCiterator::MCiterator(Node*){}
					
template <typename T>
const T& MCbinaryTree<T>::MCiterator::operator*()const{}
template <typename T>
typename MCbinaryTree<T>::MCiterator& MCbinaryTree<T>::MCiterator::operator++(){}
template <typename T>
MCiterator  MCbinaryTree<T>::MCiterator::operator++(int){}
template <typename T>
typename MCbinaryTree<T>::MCiterator& MCbinaryTree<T>::MCiterator::operator--(){}
template <typename T>
MCiterator  MCbinaryTree<T>::MCiterator::operator--(int){}

////////////////////////////////////////////////////////////////////////////////////////////////

// BINARY TREE
template <typename T>
MCbinaryTree<T>::MCbinaryTree(){}
template <typename T>
MCbinaryTree<T>::MCbinaryTree(const MCbinaryTree<T>& bt){}
template <typename T>
MCbinaryTree<T>::MCbinaryTree(MCbinaryTree<T>&& bt){}
template <typename T>
MCbinaryTree<T>& MCbinaryTree<T>::operator=(const MCbinaryTree<T>& bt){}
template <typename T>
MCbinaryTree<T>& MCbinaryTree<T>::operator=(MCbinaryTree<T>&& bt){}
template <typename T>
MCbinaryTree<T>::~MCbinaryTree(){}

template <typename T>
unsigned int MCbinaryTree<T>::getSize()const{}
template <typename T>
void MCbinaryTree<T>::print()const{}
};