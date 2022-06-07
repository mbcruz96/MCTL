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
					const_MCiterator(Node*, Node*);
					const_MCiterator(const const_MCiterator&);
					const_MCiterator(const_MCiterator&&);
					const_MCiterator& operator=(const const_MCiterator&);
					const_MCiterator& operator=(const_MCiterator&&);
					
					const T& operator*()const;
					const_MCiterator& operator++();
					const_MCiterator  operator++(int);
					const_MCiterator& operator--();
					const_MCiterator  operator--(int);
					
					bool operator==(const const_MCiterator&, const const_MCiterator&)const;
					bool operator!=(const const_MCiterator&, const const_MCiterator&)const;
				
				protected:
					Node* current;
					Node* tree;
					
					friend class MCbinaryTree<T>;
					T& retrieve()const{return data->value;)
			};
			
			class MCiterator : public const_MCiterator{
				public:
					MCiterator();
					MCiterator(Node*, Node*);
					MCiterator(const MCiterator&);
					MCiterator(MCiterator&&);
					MCiterator& operator=(const MCiterator&);
					MCiterator& operator=(MCiterator&&);
		
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
				
				void push(const T&);
				void remove(const T&);
				bool search(const T&)const;
				
				MCiterator& begin()const;
				MCiterator& end() const;
				
				unsigned int getSize()const;
				void print()const;
			
		private:
			Node* root;
			unsigned int size;
			
			Node* findMin()const;
			Node* findMax()const;
	};
	
};
#include "MCbinaryTree.hpp"
#endif