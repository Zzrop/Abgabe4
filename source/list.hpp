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
	typedef ListIterator<T> Self;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference ;
	typedef ptrdiff_t difference_type;
	typedef std::forward_iterator_tag iterator_category;

	friend class List <T>;

	ListIterator(): m_node(nullptr) {};
	ListIterator(ListNode <T>* n): m_node(n) {};
	reference operator*() const {return m_node->m_value;}
	pointer operator->() const {return &m_node->m_value;}
	Self & operator++() {
		if (m_node)
            m_node = m_node->m_next;
        return *this;
	}

	Self operator++(int) {
		auto old{*this};
		if (m_node)
            m_node = m_node->m_next;
        return old;
	}

	bool operator==(const Self& x ) const {return m_node == x.m_node;}
	bool operator!=(const Self& x ) const {return m_node != x.m_node;}

	Self next() const{
		if(m_node){
			return ListIterator ( m_node->m_next );
		}

		else{
			return ListIterator (nullptr);
		}
	}
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

	~List(){ clear();}

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
    void push_back(T const& x) {
    	auto n = new ListNode<T>(x, m_last, nullptr);
    	if(m_size == 0) {
      		m_first = n;
    	} 
    	else {
      		m_last->m_next = n;
    	}

    	m_last = n;
    	++m_size;
  	}
	
    void pop_front() {
      	if(m_size == 1) {
        	delete m_first;
        	m_first = nullptr;
        	m_last = nullptr;
        	--m_size;
        }


        if(m_size > 1){
        	m_first = m_first->m_next;
        //auto foo = m_first->m_next;
        //m_first = foo;
        //auto bar = m_first->m_prev;
       		delete m_first->m_prev;
        	--m_size;
        	m_first->m_prev = nullptr;
      	}
    }

    void pop_back() {
      	if(m_size == 1) {
        	delete m_last;
        	m_first = nullptr;
        	m_last = nullptr;
        	--m_size;
      	}

      	if(m_size > 1){
        	m_last = m_last->m_prev;
        //auto foo = m_first->m_next;
        //m_first = foo;
        //auto bar = m_first->m_prev;
        	delete m_last->m_next;
        	--m_size;
        	m_last->m_next = nullptr;
      	}
    }

    void clear() {
      	for(int i = m_size; i!=0; --i) {
        	pop_back();
      	}
    }


	bool empty() const{
    	return m_size == 0;
  	}

	ListIterator<T> begin() const {
    	return ListIterator<T>(m_first);
	}

    ListIterator<T> end() const {
    	return ListIterator<T>(nullptr);
    }


  	T& front() { return m_first->m_value; }
  	T& back() { return m_last->m_value; }

  	T const& front() const { return m_first->m_value; }
  	T const& back() const { return m_last->m_value; }
	
	std::size_t size() const{
		return m_size;
	}

	friend class ListIterator<T>;
	friend class ListConstIterator <T>;
	// not implemented yet
private:
	std::size_t m_size = 0;
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;
};

template<typename T>
	bool operator==(List<T> const& xs, List<T> const& ys ){
    	ListIterator<T> a = xs.begin();
    	ListIterator<T> b = ys.begin();
    	if(xs.size()!=ys.size()){
    		return false;
    	}


		while(a != xs.end()){
			if(*a != *b){
				return false;
			}
    		++a;
    		++b;
		}
		return true;
    }




template<typename T>
  	bool operator!=(List<T> const& xs , List<T> const & ys ){
      	return !(xs == ys);      
    }

# endif // # define BUW_LIST_HPP