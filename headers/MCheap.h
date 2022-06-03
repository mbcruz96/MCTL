#ifndef MCHEAP_H
#define MCHEAP_H
#include "MCvector.h"

namespace mctl{
	class min_MCheap{
		public:
			min_MCheap();
			min_MCheap(const MCvector<int>& h);
			min_MCheap& operator=(const MCvector<int>& h);
			min_MCheap(MCvector<int>&& h);
			min_MCheap& operator=(MCvector<int>&& h);
			
			bool empty()const;
			void push(int val);
			void pop();
			
			unsigned int getSize()const;
			void print()const;
		protected:
			MCvector<int> heap;
			unsigned int size;
			
			virtual void heap();
			virtual void heapify(int i);
			int getParent(int i)const;
			int getFirstChild(int i)const;
	};
	
	template <typename T>
	class max_MCheap : public min_MCheap{
		public:
			max_MCheap();
			max_MCheap(const MCvector<int>& h);
			max_MCheap& operator=(const MCvector<int>& h);
			max_MCheap(MCvector<int>&& h);
			max_MCheap& operator=(MCvector<int>&& h);
		
		private:
			void heap();
			void heapify(int i);
	};
};
#endif