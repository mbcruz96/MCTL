#ifndef MCQUEUE_H
#define MCQUEUE_H
#include "MClist.h"

namespace mctl{
	template <typename T>
	class MCqueue{
		public:
			MCqueue();
			MCqueue(const MCqueue<T>& q);
			MCqueue<T>& operator=(const MCqueue<T>& q);
			MCqueue(MCqueue<T>&& q);
			MCqueue<T>& operator=(MCqueue<T>&& q);
			
			void push(const T& val);
			void pop();
			bool isEmpty()const;
			T front()const;
			T back()const;
			void empty();
			
			void print()const;
			unsigned int getSize()const;
		private:
			MClist<T> queue;
			unsigned int size;
	};
};
#include "MCqueue.hpp"
#endif
