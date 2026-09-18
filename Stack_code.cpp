#include<iostream>



class Stack{
    private:
        static const  int size = 6;
        int count = 0;
        int data[size];
    public:
        bool isEmpty()
            {
                if (count ==0)
                    {std::cout<<"the stack is empty."<<"\n";
                    return true;
                    }
                return false;
            }
            
        void push(int v)
        {
            if (count< size )
                {
                    data[count] = v;
                    count++;
                    std::cout<<"pushed the value:"<<v<<"\n";
                }
            else
            {
                std::cout<<"stack is full";
            }
        }
        
        //to get the stack top value
        int peek()
        {
            if(!isEmpty())
            {
            return data[count - 1];
            }
            else{
                
                std::cout<<"cannot get the peek value";
                return 0;
            }
        }
        
        //top pop the stack top value,choose to reurn value
        int pop()
        {
            if(isEmpty())
            {
                std::cout<< "cannot pop value\n";
                return 0;
            }
            int value = data[count -1];
            count--;
            return value;
        }
        
};

#include<stack>

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(0);
    
    int peek;
    peek = s.peek();
    std::cout<<"get the peek value"<<peek<<'\n';
    
    
    std::cout<<"now using the c++ standard stack\n";
    std::stack<int> std_stack;
    std_stack.push(10);
    std_stack.push(20);
    std_stack.push(30);
    std_stack.push(40);
    
    std::cout<<std_stack.top()<<"\n";
    std::cout<<std_stack.size()<<"\n";
    
    std_stack.pop();
    std::cout<<std_stack.top()<<"\n";
    std::cout<<std_stack.size()<<"\n";
    
    return 1;
}
