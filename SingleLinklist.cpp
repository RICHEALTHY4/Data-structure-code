#include<iostream>

class Node
{
    public:
        int value;
        Node* next;
    Node(int v)
        : value(v), next(nullptr)
    {
    }
};



class LinkedList
{
    private:
        
        //Node* head = nullptr;
        Node* head;
    
    public:
   
        LinkedList() :head(nullptr) //When a LinkedList is created, set head to nullptr.
        {
            
        }
        //have the same function with LinkedList() = default;

    
        //LinkedList() = default;  // Allow creation of an empty list
        //Do not allow LinkedList objects to be copied.
        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
        
        
        void insertFront(int v)
        {
            Node* newNode = new Node(v);
            newNode->next = head;
            head = newNode;
        }
        
        bool search(int v)
        {
            Node* current = head;
            
            while(current !=nullptr)
            {
                if(current->value == v)
                {
                    return true;
                }
                current = current->next;
            }
            
            return false;
        }
        
        bool remove_node(int v)
        {
            //three cases
            //1.the list is empty
            //2.the node to removw is the head
            //3.the node is somewhere after the head
            if (head == nullptr)
            {
                return false;
            }
            
            if (head->value == v)
            {
                Node*nodeToDelete = head;
                head = head->next;
                delete nodeToDelete;
                
                return true;
            }
            
            Node* current = head;
            while(current->next != nullptr)
            {
                if(current->next->value == v)
                {
                    Node* nodeToDelete = current->next;
                    
                    delete nodeToDelete;
                    return true;
                }
            }
            return false;
        }
        
        void print() const{
            Node* current  = head;
            while(current != nullptr)
            {
                std::cout<<current->value <<"->";
                current = current->next;
                
            }
            std::cout<<"nullptr\n";
        }
        
};


int main()
{
    LinkedList l;
    l.insertFront(10);
    l.insertFront(20);
    l.insertFront(30);
    l.insertFront(40);
    
    l.print();
    l.remove_node(40);
    l.print();
}
