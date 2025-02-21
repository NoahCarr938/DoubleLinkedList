#include <iostream>
#include "../DoubleLinkedList/Header Files/List.h"

int main()
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushFront(10);
    list.popBack();
    return 0;
}