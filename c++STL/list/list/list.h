#pragma once
#include <assert.h>
namespace yu
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _date;

		__list_node(const T& x=T())       //构造函数
			:_date(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>     //方便理解template<class T,class T&,class T*>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr>  itera;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		//*it
		Ref operator*()
		{
			return _node->_date;
		}

		Ptr operator->()
		{
			return &_node->_date;
		}
		//it!=end()
		bool operator!=(const itera& it)
		{
			return _node != it._node;
		}

		bool operator==(const itera& it)
		{
			return _node == it._node;
		}

		//++it;
		itera& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//it++
		itera& operator++(int)
		{
			itera tmp(*this);
			//_node = _node->_next;
			++(*this);

			return tmp;
		}
		//--it
		itera& operator--()
		{
			_node = _node->prev;
			return *this;
		}
		//it--
		itera& operator--(int)
		{
			itera tmp(*this);
			//_node=_node->_prev;
			--(*this);

			return tmp;
		}
	};
	template<class T>
	class list
	{
	public:
		typedef __list_node<T> Node;
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		//带头双向循环链表
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		

		void push_back(const T& x)
		{
			/*
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);     //创建新的结点

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			*/
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

		}

		void erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			delete cur;

			prev->_next = next;
			next->_prev = prev;
		}

		void pop_back(const T& x)     //尾删
		{
			//erase(iterator(_head->_prev));    操作的对象是迭代器
			erase(--end());
		}
		void pop_front(const T& x)
		{
			erase(begin());
		}

		//lt2(lt1)
		list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			//const_iterator it = lt.begin();
			//while(it!=lt.emd())
			//{
			//	push_back(*it);
			//	++it;
		    //}

			for (auto e : lt)
			{
				push_back(e);
			}
		}
		/*//t1=lt3        赋值表示已经存在了
		list<T>& operator=(const list<T>& lt)
		{
			if (this != lt)   //判断一下是否传给自己
			{
				clean();    //清楚lt1的所占空间
				for (auto e : lt)
				{
					push_back(x);
				}
			}
			return *this;
		}*/
		//现代的写法
		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);
			return *this;
		}
	private:
		Node* _head;
	};

	struct Date
	{
		int year = 0;
		int month = 1;
		int day = 1;
	};
	void test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test2()
	{
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << it->year << "-" << it->month << "-" << it->day << endl;
			++it;
		}
		cout << endl;
	}
	void test3()
	{
		list<int> lt;
		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);
		lt.push_back(40);

		print_list(lt);

		lt.erase(lt.begin());
		print_list(lt);
		lt.clear();
		lt.push_back(100);
		lt.push_back(200);
		lt.push_back(300);
		lt.push_back(400);
		print_list(lt);
	}
	void test4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int> lt2;
		lt2 = lt;
		print_list(lt2);
	}
}
