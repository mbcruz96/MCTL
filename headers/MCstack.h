#ifndef MCSTACK_H
#define MCSTACK_H

#include "MCvector.h"
namespace mctl{
	template <typename T>
	class MCstack{
		public:
			MCstack();
			MCstack(const MCstack<T>& st);
			MCstack<T>& operator=(const MCstack<T>& st);
			MCstack(MCstack<T>&& st);
			MCstack<T>& operator=(MCstack<T>&& st);
			
			void push(T val);
			void pop();
			
			bool empty()const;
			T& top()const;
			
			void print()const;
			unsigned int getSize()const;
			
		private:
			MCvector<T> vec;
			unsigned int size;
	};
};
#include "MCstack.hpp"
#endif
