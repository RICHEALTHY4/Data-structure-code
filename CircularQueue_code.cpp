/*
1.a circular queue isa fixe_size queue where te end of thearay cnnects back to the beginning
this avoid shiftting every element duig dequeue()
2.front : position f the first element
3.rear: position where the next element will be inserted
4.count: current number of elements
5.just calculate the next position,before this,check wheather the que is full;
  also replace the old value with the new one
6.When the queue is full, front and rear can be equal.They can also be equal when the queue is empty.
*/

#include<iostream>

class CircularQueue
{
    private:
        static const int capacity = 10;
        int data[capacity]{};
        int count = 0;
        int front = 0;
        int rear = 0;
    public:
        bool isEmpty()
        {
            if(count == 0)
                return true;
            return false;
        }
        
        bool isFull()
        {
            if (count == capacity)
                return true;
            return false;
        }
        
        int size()
        
        {
            return count;
        }
        
        void enqueue(int v)
        {
            if(isFull())
            {
                std::cout<<"current queue is full,cannot enqueue"<<'\n';
                return;
            }
            data[rear] = v;
            rear = (rear + 1)%capacity;
            count ++;
            std::cout<<"enqueue value :"<<v<<'\n';
        }
        
        void dequeue()
        {
            if (isEmpty())
            {
                std::cout<<"current queue is empty,cannot dequeue"<<'\n';
                return;
            }
            front = (front + 1) % capacity;
            count --;
        }
        
        int peek()
        {
            if (isEmpty())
            {
                return -1;
            }
            return data[front];
        }
};

int main()
{
    CircularQueue q;
    for(int i =0;i < 10;i++)
    {
        q.enqueue(i);
    }
    std::cout<<"current queue size is "<<q.size()<<'\n';
    std::cout<<"current peek "<<q.peek()<<'\n';
    
    q.dequeue();
    std::cout<<"current queue size is "<<q.size()<<'\n';
    std::cout<<"current peek "<<q.peek()<<'\n';  
  
    q.enqueue(100);
    std::cout<<"current queue size is "<<q.size()<<'\n';
    std::cout<<"current peek "<<q.peek()<<'\n';  
  
  /*  
    q.dequeue();
    std::cout<<"current queue size is "<<q.size()<<'\n';
    std::cout<<"current peek "<<q.peek()<<'\n';  
  
    q.dequeue();
    std::cout<<"current queue size is "<<q.size()<<'\n';
    std::cout<<"current peek "<<q.peek()<<'\n';
*/
}



