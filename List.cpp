#include "List.hpp"


List::List()
{
    head = NULL;
}
List::~List()
{
    head = destroy(head);
}
Node* List::insert(Node *nd, int value)
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
void List::print_out(Node *nd)
{
    if(nd != NULL)
    {
        std::cout << nd->value << std::endl;
        print_out(nd->next);
    }
} 
Node* List::destroy(Node *nd)
{
    if(nd != NULL)
    {
        nd->next = destroy(nd->next);
        free(nd);
        nd = NULL;
    }
    return NULL;
}
Node* List::insert_front(Node *nd, int value)
{
    if (nd != NULL)
    {
        Node *new_head = new Node{value, NULL};
        new_head->next = head;
        head = new_head;
        
    }
    else if (nd == NULL)
    {
        nd = new Node{value, NULL};
    }
    return head;
}
void List::reverse(Node *nd)
{
    Node *prev =  NULL;
    Node *next = NULL;
    Node *current = nd;
    while(current != NULL)
    {
        next = current->next;
        
        current->next = prev;

        prev = current;
        
        current = next;
    }
    head = prev;
}
void List::pop_front(Node *nd)
{
    Node *temp;
    temp = head->next;
    free(head);
    head = NULL;

    head = temp;
    
}
Node* List::pop_back(Node *nd)
{
    if (nd->next == NULL)
    {
        free(nd);
        nd = NULL;

    }
    else
    {
        nd->next = pop_back(nd->next);
    }
    return nd;
}
Node* List::find_node(Node *nd, int value)
{
    if (nd != NULL)
    {
        if(value == nd->value)
        {
            printf("found\n");
            return nd;
        }
        else
        {
            return find_node(nd->next, value);
        }
    }
    return NULL;
}
void List::insert(int value)
{
    head = insert(head, value);
}
void List::emplace_back(int value)
{
    head = insert(head, value);
}
void List::emplace_front(int value)
{
    head = insert_front(head, value);
}
void List::print_out()
{
    print_out(head);
}
void List::reverse()
{
    reverse(head);
}
bool List::is_empty()
{
    return head == NULL;
}
void List::pop_front()
{
    pop_front(head);
}
void List::pop_back()
{
    head = pop_back(head);
}
Node* List::find_node(int value)
{
    return find_node(head, value);
}