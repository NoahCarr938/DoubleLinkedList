#include <iostream>
#include "List.h"

int main()
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushFront(10);
    list.popBack();
    return 0;
    //// Making 5 node pointers
    //Node<int>* node1 = new Node<int>(1);
    //Node<int>* node2 = new Node<int>(2);
    //Node<int>* node3 = new Node<int>(3);
    //Node<int>* node4 = new Node<int>(4);
    //Node<int>* node5 = new Node<int>(5);

    //// Setting all the previous and next of each node
    //node1->previous = nullptr;
    //node1->next = node2;
    //node2->previous = node1;
    //node2->next = node3;
    //node3->previous = node2;
    //node3->next = node4;
    //node4->previous = node4;
    //node4->next = node5;
    //node5->previous = node4;
    //node5->next = nullptr;

    //// Making a new iterator of type int and assigning it node3
    //Iterator<int> iter(node3);

    //// Should decrement to node 2
    //std::cout << *iter << std::endl;
    //iter--;
    //std::cout << *iter << std::endl;
    //// Should decrement to node 1
    //--iter;
    //std::cout << *iter << std::endl;

    //// deleting all of the nodes
    //delete node1;
    //delete node2;
    //delete node3;
    //delete node4;
    //delete node5;
}