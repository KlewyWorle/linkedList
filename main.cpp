#include<iostream>
#include <list>

#include "List.hpp"


int main()
{
    //pop back , pop front is empty
    
    List list;
    for(int i = 1; i <= 5; ++i)
    {
        list.insert(i * 10);
    }
    list.emplace_front(0);
    list.print_out();
    
    
    return 0;
}
