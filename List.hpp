#pragma once

#include<iostream>


struct Node
{
    int value;
    Node *next;
};
   
class List
{
private:
    

    Node* insert(Node *nd, int value);
    
    void print_out(Node *nd);

    Node* destroy(Node *nd);

    Node* insert_front(Node *nd, int value);

    void reverse(Node *nd);

    void pop_front(Node *nd);

    Node* pop_back(Node *nd);


    Node* find_node(Node *nd, int value);
    Node *head;
public:
    
    List();
    ~List();
    void insert(int value);
    void emplace_back(int value);
    void emplace_front(int value);
    void print_out();
    void reverse();
    bool is_empty();
    void pop_front();
    void pop_back();
    Node* find_node(int value);


};
