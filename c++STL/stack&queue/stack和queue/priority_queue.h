#pragma once
#include<vector>
namespace yu
{
    template<class T>
    struct less
    {
        bool operator()(const T& x1, const T& x2)
        {
            return x1 < x2;
        }
    };
     
    template<class T>
    struct greater
    {
        bool operator()(const T& x1, const T& x2)
        {
            return x1 > x2;
        }
    };

    //Ĭ���Ǵ��
    template<class T, class Container = vector<T>,class Compare = less<T> >     //ע�������ϸ�ڣ�Ĭ�ϴ��
    class priority_queue
    {
    public:
        void AdjustUp(int child)
        {
            Compare com;
            int parent = (child - 1) / 2;
            while (child > 0)
            {
                //if (_con[child] > _con[parent])
                if(com(_con[parent],_con[child]))
                {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }
        void push(const T& x)
        {
            _con.push_back(x);
            AdjustUp(_con.size() - 1);
        }

        void AdjustDwon(int root)
        {
            int parent = root;
            int child = parent * 2 + 1;

            Compare com;
            while (child < _con.size())
            {
                //if (child + 1 < _con.size() && _con[child + 1] > _con[child])
                if (child + 1 < _con.size() && com(_con[child],_con[child+1]))
                {
                    ++child;
                }
                //if (_con[child] > _con[parent])
                if(com(_con[parent],_con[child]))
                {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        void pop()
        {
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();

            AdjustDwon(0);
        }

        T& top()
        {
            return _con[0];
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }
    private:
        Container _con;
    };

    void test3()
    {
        priority_queue<int, vector<int>,greater<int>> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}