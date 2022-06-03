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
			bool empty()const;
			T& front()const;
			T& back()const;
			
			void print()const;
			void getSize()const;
		private:
			MClist queue;
			unsigned int size;
	};
};
#include "MCqueue.hpp"
#endif
