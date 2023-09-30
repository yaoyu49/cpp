#pragma once
#include <assert.h>

namespace yu
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
				, _finish(nullptr)
				, _endofstorage(nullptr)
		{}

		/*
		vector(const vector<int>& v)         //深拷贝
		{
			_start = new T[v.capacity()];
			_finish = _start;
			_endofstorage = _start + v.capacity();

			for (size_t i = 0; i < v.size(); ++i)
			{
				*_finish = v[i];
				++_finish;
			}
		}
		*/
		//v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
				push_back(e);
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tamp = new T[n];
				size_t sw = size();
				if (_start)
				{
					//memcpy(tamp, _start, sizeof(T) * sw);       //拷贝到新的空间  按字节拷贝，浅拷贝
					for (size_t i = 0; i < sw; ++i)            // 调用的是T的operator= 深拷贝
					{
						tamp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tamp;
				_finish = tamp + sw;
				_endofstorage = tamp + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		/*
		vector<T>& operator= (const vector<T>& x)
		{
			if (this != &x)
			{
				delete[] _start;
				_start=new T&[x.capacity()];

				memcpy(_start, x._start, sizeof(T) * x.size());

			}
			return *this;
		}
		*/
		//v3=v1;    深拷贝过程
		vector<T>& operator=(vector<T> x)
		{
			swap(x);
			return *this;
		}

		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		iterator rbegin()
		{
			return _finish;
		}

		iterator rend()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}
		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;*/
			insert(_finish, x);

		}

		void pop_back()
		{
			/*
			assert(_start < _finish);
			--_finish;
			*/
			erase(_finish - 1);
		}

		void insert(iterator position ,const T& val)
		{
			assert(position <= _finish);
			if (_finish== _endofstorage)
			{
				size_t n = position - _start;       //注意迭代器增容失效问题
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				position = _start + n;
			}
			iterator end = _finish - 1;
			while (end >= position)
			{
				*(end + 1) = *end;
				--end;
			}
			*position = val;
			++_finish;
		}

		iterator erase(iterator position)
		{
			assert(position < _finish);
			iterator it = position;
			while(it<_finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return position;      //返回了这个位置
		}

		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	

	void print_vector(const vector<int>& v)
	{
		vector<int>::const_iterator  it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}


	void test1()
	{
		vector<int>  v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			for (size_t i = 0; i < v.size(); ++i)
			{
				cout << *it << " ";
				++it;
			}
		}
		cout << endl;

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		v.pop_back();
		print_vector(v);
	}
	void test2()
	{
		vector<int> v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		v2.push_back(6);
		print_vector(v2);
		v2.insert(v2.begin(),0);
		print_vector(v2);
		vector<int>::iterator it = v2.begin();
		while (it != v2.end())
		{
			if (*it % 2 == 0)
			{
				it=v2.erase(it);         //注意这里迭代器失效问题
			}
			else
			{
				++it;
			}
		}
		print_vector(v2);
		cout << v2.capacity() << endl;
		v2.resize(9, 7);
		print_vector(v2);
		cout << v2.capacity() << endl;
		vector<int>v1(v2);
		print_vector(v1);
		vector<int>v3 = v1;
		print_vector(v3);
	}
	void test3()
	{
		vector<string> v;
		v.push_back("11111111111111");
		v.push_back("22222222222222");
		v.push_back("33333333333333");
		v.push_back("44444444444444"); 
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

	}
}
