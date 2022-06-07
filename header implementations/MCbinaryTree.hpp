#include "MCbinaryTree.h"

namespace mctl{
// CONST ITERATOR
template <typename T>
MCbinaryTree<T>::const_MCiterator::const_MCiterator(){
	current = nullptr;
	tree = nullptr;
}
template <typename T>
MCbinaryTree<T>::const_MCiterator::const_MCiterator(Node* c, Node* t){
	current = curr;
	tree = t;
}
template <typename T>
MCbinaryTree<T>::const_MCiterator::const_MCiterator(const const_MCiterator& itr){
	current = itr.current;
	tree = itr.tree;
}
template <typename T>
MCbinaryTree<T>::const_MCiterator::const_MCiterator(const_MCiterator&& itr){
	current = std::move(itr.current);
	tree = std::move(itr.tree);
}
template <typename T>
typename MCbinaryTree<T>::const_MCiterator& MCbinaryTree<T>::const_MCiterator::operator=(const const_MCiterator& itr){
	current = itr.current;
	tree = itr.tree;
}
template <typename T>
typename MCbinaryTree<T>::const_MCiterator& MCbinaryTree<T>::const_MCiterator::operator=(const_MCiterator&& itr){
	current = std::move(itr.current);
	tree = std::move(itr.tree);
}			

template <typename T>
const T& MCbinaryTree<T>::const_MCiterator::operator*()const{
	return retrieve();
}
template <typename T>
typename MCbinaryTree<T>::const_MCiterator& MCbinaryTree<T>::const_MCiterator::operator++(){
	if (current == nullptr)
		return nullptr;
	if (current->lchild == nullptr && current->rchild == nullptr){
		auto prevNode = current;
		current = current->parent;
		while (current->rchild == prevNode || current != tree){
			prevNode = current;
			current = current->parent;
		};
		if (current->rchild == prevNode && current == tree){
			current = nullptr;
			return nullptr;
		}
		if (current->rchild != prevNode)
			return (*this);
	}
	if (current->rchild != nullptr){
		current = current->rchild;
		if (current->lchild != nullptr){
			while (current->lchild != nullptr){
				current = current->lchild;
			};
		}
	}
	return (*this);
}
template <typename T>
const_MCiterator  MCbinaryTree<T>::const_MCiterator::operator++(int){
	if (current == nullptr)
		return nullptr;
	auto old = *this;
	if (current->lchild == nullptr && current->rchild == nullptr){
		auto prevNode = current;
		current = current->parent;
		while (current->rchild == prevNode || current != tree){
			prevNode = current;
			current = current->parent;
		};
		if (current->rchild == prevNode && current == tree){
			current =  nullptr;
			return old;
		}
		if (current->rchild != prevNode)
			return old;
	}
	if (current->rchild != nullptr){
		current = current->rchild;
		if (current->lchild != nullptr){
			while (current->lchild != nullptr){
				current = current->lchild;
			};
		}
	}
	return old;
}
template <typename T>
typename MCbinaryTree<T>::const_MCiterator& MCbinaryTree<T>::const_MCiterator::operator--(){
	if (current == nullptr)
		return nullptr;
	if (current->lchild == nullptr && current->rchild == nullptr){
		auto prevNode = current;
		current = current->parent;
		while (current->lchild == prevNode || current != tree){
			prevNode = current;
			current = current->parent;
		};
		if (current->lchild == prevNode && current == tree){
			current =  nullptr;
			return nullptr;
		}
		if (current->lchild != prevNode)
			return (*this);
	}
	if (current->lchild != nullptr){
		current = current->lchild;
		if (current->rchild != nullptr){
			while (current->rchild != nullptr){
				current = current->rchild;
			};
		}
	}
	return (*this);
}
template <typename T>
const_MCiterator  MCbinaryTree<T>::const_MCiterator::operator--(int){
	if (current == nullptr)
		return nullptr;
	auto old = *this;
	if (current->lchild == nullptr && current->rchild == nullptr){
		auto prevNode = current;
		current = current->parent;
		while (current->lchild == prevNode || current != tree){
			prevNode = current;
			current = current->parent;
		};
		if (current->lchild == prevNode && current == tree){
			current =  nullptr;
			return old;
		}
		if (current->lchild != prevNode)
			return old;
	}
	if (current->lchild != nullptr){
		current = current->lchild;
		if (current->rchild != nullptr){
			while (current->rchild != nullptr){
				current = current->rchild;
			};
		}
	}
	return old;
}
					
template <typename T>
bool MCbinaryTree<T>::const_MCiterator::operator==(const const_MCiterator& rhs, const const_MCiterator& lhs)const{
	if (rhs.tree == lhs.tree && rhs.current == lhs.current)
		return true;
	else
		return false;
}
template <typename T>
bool MCbinaryTree<T>::const_MCiterator::operator!=(const const_MCiterator& rhs, const const_MCiterator& lhs)const{
	return !(rhs == lhs);
}

///////////////////////////////////////////////////////////////////////////////////////////////

// ITERATOR
template <typename T>
MCbinaryTree<T>::MCiterator::MCiterator(): const_MCiterator(){}
template <typename T>
MCbinaryTree<T>::MCiterator::MCiterator(Node* c, Node* t): const_MCiterator(c, t){}
template <typename T>
MCbinaryTree<T>::MCiterator::MCiterator(const MCiterator& itr): const_MCiterator(itr){}
template <typename T>
MCbinaryTree<T>::MCiterator::MCiterator(MCiterator&& itr): const_MCiterator(itr){}
template <typename T>
typename MCbinaryTree<T>::MCiterator& MCbinaryTree<T>::MCiterator::operator=(const MCiterator& itr){
	const_MCiterator::current = itr.current;
	const_MCiterator::tree = itr.tree;
}
template <typename T>
typename MCbinaryTree<T>::MCiterator& MCbinaryTree<T>::MCiterator::operator=(MCiterator&& itr){
	const_MCiterator::current = std::move(itr.current);
	const_MCiterator::tree = std::move(itr.tree);
}

template <typename T>
const T& MCbinaryTree<T>::MCiterator::operator*()const{
	return const_MCiterator::retrieve();
}
template <typename T>
typename MCbinaryTree<T>::MCiterator& MCbinaryTree<T>::MCiterator::operator++(){
	if (const_MCiterator::current == nullptr)
		return nullptr;
	if (current->lchild == nullptr && current->rchild == nullptr){
		auto prevNode = const_MCiterator::current;
		const_MCiterator::current = const_MCiterator::current->parent;
		while (const_MCiterator::current->rchild == prevNode || const_MCiterator::current != const_MCiterator::tree){
			prevNode = const_MCiterator::current;
			const_MCiterator::current = const_MCiterator::current->parent;
		};
		if (const_MCiterator::current->rchild == prevNode && const_MCiterator::current == const_MCiterator::tree){
			const_MCiterator::current = nullptr;
			return nullptr;
		}
		if (const_MCiterator::current->rchild != prevNode)
			return (*this);
	}
	if (const_MCiterator::current->rchild != nullptr){
		const_MCiterator::current = const_MCiterator::current->rchild;
		if (const_MCiterator::current->lchild != nullptr){
			while (const_MCiterator::current->lchild != nullptr){
				const_MCiterator::current = const_MCiterator::current->lchild;
			};
		}
	}
	return (*this);
}
template <typename T>
MCiterator  MCbinaryTree<T>::MCiterator::operator++(int){
	if (const_MCiterator::current == nullptr)
		return nullptr;
	auto old = *this;
	if (const_MCiterator::current->lchild == nullptr && const_MCiterator::current->rchild == nullptr){
		auto prevNode = const_MCiterator::current;
		const_MCiterator::current = const_MCiterator::current->parent;
		while (const_MCiterator::current->rchild == prevNode || const_MCiterator::current != const_MCiterator::tree){
			prevNode = const_MCiterator::current;
			const_MCiterator::current = const_MCiterator::current->parent;
		};
		if (const_MCiterator::current->rchild == prevNode && const_MCiterator::current == const_MCiterator::tree){
			const_MCiterator::current =  nullptr;
			return old;
		}
		if (const_MCiterator::current->rchild != prevNode)
			return old;
	}
	if (const_MCiterator::current->rchild != nullptr){
		const_MCiterator::current = const_MCiterator::current->rchild;
		if (const_MCiterator::current->lchild != nullptr){
			while (const_MCiterator::current->lchild != nullptr){
				const_MCiterator::current = current->lchild;
			};
		}
	}
	return old;
}
template <typename T>
typename MCbinaryTree<T>::MCiterator& MCbinaryTree<T>::MCiterator::operator--(){
	if (const_MCiterator::current == nullptr)
		return nullptr;
	if (const_MCiterator::current->lchild == nullptr && const_MCiterator::current->rchild == nullptr){
		auto prevNode = const_MCiterator::current;
		const_MCiterator::current = const_MCiterator::current->parent;
		while (const_MCiterator::current->lchild == prevNode || const_MCiterator::current != const_MCiterator::tree){
			prevNode = const_MCiterator::current;
			const_MCiterator::current = const_MCiterator::current->parent;
		};
		if (const_MCiterator::current->lchild == prevNode && const_MCiterator::current == const_MCiterator::tree){
			const_MCiterator::current =  nullptr;
			return nullptr;
		}
		if (const_MCiterator::current->lchild != const_MCiterator::prevNode)
			return (*this);
	}
	if (const_MCiterator::current->lchild != nullptr){
		const_MCiterator::current = const_MCiterator::current->lchild;
		if (const_MCiterator::current->rchild != nullptr){
			while (const_MCiterator::current->rchild != nullptr){
				const_MCiterator::current = const_MCiterator::current->rchild;
			};
		}
	}
	return (*this);
}
template <typename T>
MCiterator  MCbinaryTree<T>::MCiterator::operator--(int){
	if (const_MCiterator::current == nullptr)
		return nullptr;
	auto old = *this;
	if (const_MCiterator::current->lchild == nullptr && const_MCiterator::current->rchild == nullptr){
		auto prevNode = const_MCiterator::current;
		const_MCiterator::current = const_MCiterator::current->parent;
		while (const_MCiterator::current->lchild == prevNode || const_MCiterator::current != const_MCiterator::tree){
			prevNode = const_MCiterator::current;
			const_MCiterator::current = const_MCiterator::current->parent;
		};
		if (const_MCiterator::current->lchild == prevNode && const_MCiterator::current == const_MCiterator::tree){
			const_MCiterator::current =  nullptr;
			return old;
		}
		if (const_MCiterator::current->lchild != prevNode)
			return old;
	}
	if (const_MCiterator::current->lchild != nullptr){
		const_MCiterator::current = const_MCiterator::current->lchild;
		if (const_MCiterator::current->rchild != nullptr){
			while (const_MCiterator::current->rchild != nullptr){
				const_MCiterator::current = const_MCiterator::current->rchild;
			};
		}
	}
	return old;
}

////////////////////////////////////////////////////////////////////////////////////////////////

// BINARY TREE
template <typename T>
MCbinaryTree<T>::MCbinaryTree(){
	root = nullptr;
	size = 0;
}
template <typename T>
MCbinaryTree<T>::MCbinaryTree(const MCbinaryTree<T>& bt){
}
template <typename T>
MCbinaryTree<T>::MCbinaryTree(MCbinaryTree<T>&& bt){}
template <typename T>
typename MCbinaryTree<T>::MCbinaryTree<T>& MCbinaryTree<T>::operator=(const MCbinaryTree<T>& bt){}
template <typename T>
typename MCbinaryTree<T>::MCbinaryTree<T>& MCbinaryTree<T>::operator=(MCbinaryTree<T>&& bt){}
template <typename T>
MCbinaryTree<T>::~MCbinaryTree(){}

template <typename T>
void MCbinaryTree<T>::push(const T& val){}
template <typename T>
void MCbinaryTree<T>::remove(const T& val){}
template <typename T>
bool MCbinaryTree<T>::search(const T& val)const{
	auto itr = begin();
	while (itr != end() || *itr != ){
		itr++;
	};
	if (itr != end)
		return true;
	else 
		return false;
}

template <typename T>
typename MCbinaryTree<T>::MCiterator&  MCbinaryTree<T>::begin()const{
	return MCiterator(findMin());
}
template <typename T>
typename MCbinaryTree<T>::MCiterator&  MCbinaryTree<T>::end() const{
	return nullptr;
}

template <typename T>
unsigned int MCbinaryTree<T>::getSize()const{}
template <typename T>
void MCbinaryTree<T>::print()const{}
template <typename T>
Node* MCbinaryTree<T>::findMin()const{
	if (root == nullptr)
		return nullptr;
	else{
		Node* node = root;
		if (node->lchild != nullptr){
			while (node->lchild != nullptr){
				node = node->lchild;
			};
			return node;
		}
		else 
			return node;
	}
}
template <typename T>
Node* MCbinaryTree<T>::findMax()const{
	if (root == nullptr)
		return nullptr;
	else {
		Node* node = root;
		if (node->rchild != nullptr){
			while (node->rchild != nullptr){
				node = node->rchild;
			};
		return node;
		}
		else 
			return node;
	}
};
