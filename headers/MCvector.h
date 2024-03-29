#ifndef MCVECTOR_H
#define MCVECTOR_H

#include <iostream>
namespace mctl{
	template <typename T>
	class MCvector{
		public:
			class const_MCiterator{
				public:
					const_MCiterator();
					const_MCiterator(const const_MCiterator&);
					const_MCiterator(const_MCiterator&&);
					const_MCiterator& operator=(const const_MCiterator&);
					const_MCiterator& operator=(const_MCiterator&&);
					const T& operator*() const;	// * operator to return the element
					
					const_MCiterator& operator++();
					const_MCiterator operator++(int);
					const_MCiterator& operator--();
					const_MCiterator operator--(int);
					
					bool operator==(const const_MCiterator&);
					bool operator!=(const const_MCiterator&);
					
					
				protected:
					T* data;		// pointer to the vector
					unsigned int index;		// for index
					unsigned int vecSize;
					
					friend class MCvector<T>;
					T& retrieve(){return data[index];}
					const_MCiterator(unsigned int, unsigned int, T*);
			};
			
			class MCiterator : public const_MCiterator{
				public:
					MCiterator();
					MCiterator(const MCiterator&);
					MCiterator(MCiterator&&);
					MCiterator& operator=(const MCiterator&);
					MCiterator& operator=(MCiterator&&);
					T operator*();
					
					MCiterator& operator++();
					MCiterator operator++(int);
					MCiterator& operator--();
					MCiterator operator--(int);
					
					MCiterator(unsigned int, unsigned int, T*);
					
				protected:
					friend class MCvector<T>;
					
			};
			
		
			MCvector();
			MCvector(const MCvector&);
			MCvector(MCvector<T>&&);
			MCvector<T>& operator=(const MCvector<T>&);
			MCvector<T>& operator=(MCvector<T> &&);
			~MCvector();
			
			MCvector(const T&, int);
			MCvector(int size);
			
			T operator[](int val);
			void push_back(const T&);
			void pop_back();
			
			MCiterator begin()const;
			const MCiterator cbegin()const;
			MCiterator end()const;
			const MCiterator cend()const;
			
			MCiterator insert(MCiterator, const T&);
			void print()const;
			unsigned int getSize()const;
			bool isEmpty()const;
			
			template <typename U>
			friend std::ostream& operator<<(std::ostream&, const MCvector<U>&);
		private:
			T* mcVec;
			unsigned int capacity;
			unsigned int size;
			
			void resize();
			
		};

};
#include "MCvector.hpp" 
#endif
