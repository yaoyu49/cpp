#pragma once
#include<vector>
#include<list>
namespace yu
{
	template<class T, class Container>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		T& front()
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
	private:
		Container _con;
	};
	void test2()
	{
		//queue<int, vector<int>> q;     //vector没有提供pop.front的接口
		queue<int, list<int>>  q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}