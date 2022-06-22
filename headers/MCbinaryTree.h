#ifndef MCBINARYTREE_H
#define MCBINARYTREE_H
#include "MCstack.h"
namespace mctl{
	template <typename T>
	class MCbinaryTree{
		public:
			struct Node{
				T value;
				Node* lchild;
				Node* rchild;
				Node* parent;
				Node(): lchild(nullptr), rchild(nullptr), parent(nullptr){}
				Node(const T& v, Node* l, Node* r, Node* p): value(v), lchild(l), rchild(r), parent(p){}
				Node(const T& v, Node* p): value(v), lchild(nullptr), rchild(nullptr), parent(p){}
			};
			
			class const_MCiterator{
				public:
					const_MCiterator();
					const_MCiterator(Node*);
					
					const T& operator*()const;
					const_MCiterator& operator++();
					const_MCiterator  operator++(int);
					const_MCiterator& operator--();
					const_MCiterator  operator--(int);
					
					bool operator==(const const_MCiterator&, const const_MCiterator&)const;
					bool operator!=(const const_MCiterator&, const const_MCiterator&)const;
				
				protected:
					Node* current;
					
					friend class MCbinaryTree<T>;
					T& retrieve()const{return data->value;)
			};
			
			class MCiterator : public const_MCiterator{
				public:
					MCiterator();
					MCiterator(Node*);
					
					const T& operator*()const;
					MCiterator& operator++();
					MCiterator  operator++(int);
					MCiterator& operator--();
					MCiterator  operator--(int);
				
				private:
				friend class MCbinaryTree<T>;
			};
			
				MCbinaryTree();
				MCbinaryTree(const MCbinaryTree<T>&);
				MCbinaryTree(MCbinaryTree<T>&&);
				MCbinaryTree<T>& operator=(const MCbinaryTree<T>&);
				MCbinaryTree<T>& operator=(MCbinaryTree<T>&&);
				~MCbinaryTree();
				
				
				MCiterator& begin()const;
				MCiterator& end() const;
				
				unsigned int getSize()const;
				void print()const;
			
		private:
			Node* root;
			unsigned int size;
	};
	
};
#include "MCbinaryTree.hpp"
#endif