#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cstddef>
// List.hpp
template <typename T>
struct List;
template <typename T>
struct ListNode
{
ListNode():m_value() , m_prev(nullptr) ,m_next(nullptr) {}
ListNode (T const& v ,ListNode *prev ,ListNode *next):
m_value(v), m_prev(prev), m_next(next)
	{} 
	T m_value;
	ListNode * m_prev ;
	ListNode * m_next ;
};

template <typename T>
struct ListIterator
{
	friend class List <T>;
// not implemented yet
private:
	ListNode <T>* m_node = nullptr;
};

template <typename T>
struct ListConstIterator
{
	friend class List <T>;
public:
// not implemented yet
private:
	ListNode <T>* m_node = nullptr;
};

template <typename T>
class List
{
public :
	List():
		m_first{nullptr},
		m_last{nullptr},
		m_size{0}{}
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ListIterator <T> iterator;
	typedef ListConstIterator <T> const_iterator;

	void push_front(T const& x) {
		auto n = new ListNode<T>(x, nullptr, m_first);
		if(m_size == 0) {
      		m_last = n;
    	}
    	else {
      		m_first->m_prev = n;
    	}

    	m_first = n;
    	++m_size;
  	}
	
	bool empty() const{
    	if (m_size == 0)
      		{return true;}
    	else {return false;}
  	}

  	T& front() { return m_first->m_value; }
  	T& back() { return m_last->m_value; }
	
	std::size_t size() const{
		return m_size;
	}

	friend class ListIterator <T>;
	friend class ListConstIterator <T>;
	// not implemented yet
private:
	std::size_t m_size = 0;
	ListNode <T>* m_first = nullptr;
	ListNode <T>* m_last = nullptr;
};

# endif // # define BUW_LIST_HPP