#ifndef MCLIST_H
#define MCLIST_H 
#include<iostream>

namespace mctl{
	template<typename T>
	class MClist{
		public:
			struct Node{
				T value;
				Node* prev;
				Node* next;
				Node():  value(), prev(nullptr), next(nullptr){}
				Node(const Node& n): value(n.value), prev(n.prev), next(n.next){}
				Node(T v, Node* p, Node* n): value(v), prev(p), next(n){}
			};
			
			class const_MCiterator{
				public:
					const_MCiterator();
					const_MCiterator(Node*);
					const_MCiterator(const const_MCiterator&);
					const_MCiterator(const_MCiterator&&);
					const T operator*()const;
					
					const_MCiterator& operator++();
					const_MCiterator  operator++(int);
					const_MCiterator& operator--();
					const_MCiterator  operator--(int);
					
					bool operator==(const const_MCiterator& rhs)const;
					bool operator!=(const const_MCiterator& rhs)const;
				protected:
					Node* data;
					
					friend class MClist<T>;
					T retrieve()const{return data->value;}
			};
			
			class MCiterator : public const_MCiterator{
				public:
					MCiterator();
					MCiterator(Node*);
					MCiterator(const MCiterator&);
					MCiterator(MCiterator&&);
					T operator*()const;
					
					MCiterator& operator++();
					MCiterator  operator++(int);
					MCiterator& operator--();
					MCiterator  operator--(int);
				protected:
					friend class MClist<T>;
			};
			
			MClist();
			MClist(const MClist<T>&);
			MClist(MClist<T>&& l);
			MClist<T>& operator=(const MClist<T>& l);
			MClist<T>& operator=(MClist<T>&& l);
			~MClist();
			
			MClist(T val, int copies);
			
			// added push_front and pop_front
			MCiterator push_back(T val);
			MCiterator push_front(T val);
			bool pop_back();
			bool pop_front();
			
			// didn't include cbegin and cend 
			MCiterator begin()const;
			MCiterator end()const;
			
			// didn't include insert with copies parameter
			MCiterator insert(MCiterator it, T val);
			void print()const;
			unsigned int getSize()const;
			void empty();
			bool isEmpty()const;
			
			template <typename U>
			friend std::ostream& operator<<(std::ostream&, const MClist<U>&);
		private:
			Node* head;
			Node* tail;
			unsigned int size;
	};
};
#include "MClist.hpp"
#endif
