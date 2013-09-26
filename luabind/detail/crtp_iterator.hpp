#ifndef LUABIND_CRTP_ITERATOR_HPP_INCLUDED
#define LUABIND_CRTP_ITERATOR_HPP_INCLUDED
#include <iterator>

namespace luabind {
	namespace detail {

		template< typename CRTP, typename Category, typename ValueType, typename ReferenceType = ValueType&, typename DifferenceType = ptrdiff_t >
		class crtp_iterator :
			public std::iterator<Category, ValueType, DifferenceType, ValueType*, ReferenceType >
		{
		public:
			CRTP& operator++()
			{ 
				upcast().increment();
				return upcast();
			}

			CRTP operator++(int)
			{ 
				CRTP tmp(*this);
				upcast().increment();
				return tmp; 
			}

			bool operator==(const CRTP& rhs)
			{
				return upcast().equal(rhs);
			}

			bool operator!=(const CRTP& rhs)
			{
				return !upcast().equal(rhs);
			}
			
			reference operator*()
			{
				return upcast().dereference();
			}

			reference operator->()
			{
				return upcast().dereference();
			}

		private:
			CRTP& upcast() { return static_cast<CRTP&>(*this); }
			const CRTP& upcast() const { return static_cast<const CRTP&>(*this); }
		};

	}
}






#endif

