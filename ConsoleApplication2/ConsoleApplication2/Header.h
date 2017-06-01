#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <class T>
class List // 'main' class List
{
private:
	class Node //inner class to List
	{
	public:
		Node *next;   
		Node *prev;    
		T  date_birth;                 // data field

		Node(T node_val) : date_birth(node_val) { } 
		Node() {}                            
		~Node(){}                             
		void print_val() { cout << date_birth << " "; }
	};
public:
	class iterator //inner class to List
	{
	private:
		friend class List<T>;
		Node * the_node;
	public:
		iterator() : the_node(0) { }
		iterator(Node * dn) : the_node(dn) { }
		// Copy constructor
		iterator(const iterator & it) : the_node(it.the_node) { }

		iterator& iterator:: operator=(const iterator& it)
		{
			the_node = it.the_node;
			return *this;
		}
		bool operator==(const iterator& it) const
		{
			return (the_node == it.the_node);
		}
		bool operator!=(const iterator& it) const
		{
			return !(it == *this);
		}

		bool operator<(const iterator& it) const
		{
			return the_node<it.the_node;
		}


		iterator& iterator:: operator++()
			{
				if (the_node == 0)
				throw "incremented an empty iterator";
				if (the_node->next == 0)
				throw "tried to increment too far past the end";
				the_node = the_node->next;
				return *this;
				}
		iterator& iterator :: operator--()
		{
			if (the_node == 0)
				throw "decremented an empty iterator";
			if (the_node->prev == 0)
				throw "tried to decrement past the beginning";
			the_node = the_node->prev;
			return *this;
		}
		T& operator*() const 
		{
			if (the_node == 0)
				throw "tried to dereference an empty iterator";
			return the_node->date_birth;
		}
	};

private:
	Node *head;    // first element
	Node *tail;      // next to the last element
	List & operator=(const List &);
	List(const List &);

	iterator head_iterator;
	iterator tail_iterator;
	iterator tail_iterator1;
public:
	List()
		{
			head = tail = new Node;
			tail->next = 0;
			tail->prev = 0;
			head_iterator = iterator(head);
			tail_iterator = iterator(tail);
			tail_iterator1 = iterator(tail->next);
		}
			
	List(T node_val) // constructor to add one element into the list
			{
				head = tail = new Node;
				tail->next = 0;
				tail->prev = 0;
				head_iterator = iterator(head);
				tail_iterator = iterator(tail);
				tail_iterator1 = iterator(tail->next);
				add_front(node_val);
			}

	~List()
	{
		Node *node_to_delete = head;
		for (Node *sn = head; sn != tail;)
		{
			sn = sn->next;
			delete node_to_delete;
			node_to_delete = sn;
		}
		delete node_to_delete;
	}
	bool is_empty() { return head == tail; }
	iterator front() { return head_iterator; }
	iterator rear()  { return tail_iterator; }
	iterator rear1()  { return tail_iterator1; }

	void add_front(T node_val)
	{
		Node *node_to_add = new Node(node_val);
		node_to_add->next = head;
		node_to_add->prev = 0;
		head->prev = node_to_add;
		head = node_to_add;
		head_iterator = iterator(head);
	}
	
	void add_rear(T node_val)
	{
		if (is_empty())    // if list is empty
			add_front(node_val);
		else
		{
			Node *node_to_add = new Node(node_val);
			node_to_add->next = tail;
			node_to_add->prev = tail->prev;
			tail->prev->next = node_to_add;
			tail->prev = node_to_add;
			tail_iterator = iterator(tail);
		}
	}
	bool remove_it(iterator & key_i)
	{
		for (Node *dn = head; dn != tail; dn = dn->next)
			if (dn == key_i.the_node)    
			{
			dn->prev->next = dn->next;
			dn->next->prev = dn->prev;
			delete dn;                            
			key_i.the_node = 0;
			return true;
			}
		return false;
	}
	
	iterator find(T node_val) const
	{
		for (Node *dn = head; dn != tail; dn = dn->next)
			if (dn->date_birth == node_val) return iterator(dn);
		return tail_iterator;
	}
	int size() const
	{
		int count = 0;
		for (Node *dn = head; dn != tail; dn = dn->next) ++count;
		return count;
	}
	
};
