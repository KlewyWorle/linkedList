#include<iostream>

class List
{
private:
    struct Node
    {
        int value;
        Node *next;
    };
   

    Node* insert(Node *nd, int value)
    {
        if(nd == NULL)
        {
            nd = new Node{value, NULL};

        }
        else 
        {
            nd->next = insert(nd->next, value);
        }
        return nd;
    }
    void print_out(Node *nd)
    {
        if(nd != NULL)
        {
            std::cout << nd->value << std::endl;
            print_out(nd->next);
        }
    }


public:
    Node *head;
    List()
    {
        head = NULL;
    }
    void insert(int value)
    {
        head = insert(head, value);
    }
    void print_out()
    {
        print_out(head);
    }


};



int main()
{

    List list;
    list.insert(10);
    list.insert(20);

    list.print_out();


    return 0;
}
