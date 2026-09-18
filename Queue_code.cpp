/*
1.const: the value cannot change.An ordinary variable that can change cannot be used as the size of a built-in array inside the class.
2.static: the value belongs to the class.Without static, every MyQueue object would have its own capacity variable.With static, there is one class-level value shared by all MyQueue objects.
3.In modern C++, write:static constexpr int capacity = 10;
constexpr means that the value is a compile-time constant. This makes it clear that it can be used as an array size
*/
#include<iostream>

class MyQueue
{
    private:
        static const int size =10;
        int data[size];
        int count = 0;
    public:
        bool isEmpty()
        {
            if(count == 0)
            {
                std::cout<<"the queue is empty\n";
                return true;
            }
            else
                return false;
        }
        
        int que_size()
        {
            //std::cout<<"current size of queue is "<<count<<"\n";
            return count;
        }
        
        void enqueue(int v)
        {
            if (count == size)
            {
                return ;
            }
            data[count] = v;
            count++;
            std::cout<<"enqueue value:"<<v<<'\n';
        }
        
        void dequeue()
        {
            if (isEmpty())
            {
                return ;
            }
            for(int i = 0;i < count ;i ++)
            {
                data[i] = data[i+1];
            }
            count --;
        }
        
        int peek()
        {
            if (isEmpty())
                return -1;
            return data[0];
        }
};

int main()
{
    MyQueue q;
    bool state = q.isEmpty();
    std::cout<<"now the queue is empty:"<<state<<'\n';
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    std::cout << "Front value: " << q.peek() << '\n';
    std::cout << "Queue is empty: " << q.isEmpty() << '\n';
    std::cout << "Current size: " << q.que_size() << '\n';

    q.dequeue();
    std::cout << "Front value: " << q.peek() << '\n';
    std::cout << "Current size: " << q.que_size() << '\n';

    q.dequeue();
    std::cout << "Front value: " << q.peek() << '\n';
    std::cout << "Current size: " << q.que_size() << '\n';
    /*
    int peek = q.peek();
    std::cout<<"current peek value is:"<<peek<<'\n';
    state = q.isEmpty();
    std::cout<<"now the queue is empty:"<<state<<'\n';    
    
    q.que_size();
    q.dequeue();
    peek = q.peek();
    std::cout<<"current peek value is:"<<peek<<'\n';
    q.que_size();
    q.dequeue();
    peek = q.peek();
    std::cout<<"current peek value is:"<<peek<<'\n';
    q.que_size();
    */
    
}
