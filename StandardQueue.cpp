#include<iostream>
#include<queue>

int main()
{
    std::queue<int> q;
    
    // add values
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    std::cout<<"current size:"<<q.size()<<'\n';
    std::cout<<"current front:"<<q.front()<<'\n';
    std::cout<<"current back:"<<q.back()<<'\n';
    
    //remove the front element
    q.pop();
    
    std::cout << "Front after pop: " << q.front() << '\n';

    if (!q.empty())
    {
        std::cout << "The queue is not empty\n";
    }   
}

/*

Operation	                            Meaning
q.push(value)	             Adds a value to the back
q.emplace(arguments...)	     Constructs a new element at the back
q.pop()	                     Removes the front element
q.front()	                 Accesses the front element
q.back()	                 Accesses the last element
q.empty()	                 Returns whether the queue is empty
q.size()	                 Returns the number of elements
q.swap(other)	             Exchanges contents with another queue

*/
