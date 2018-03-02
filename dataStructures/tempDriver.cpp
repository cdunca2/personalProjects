#include <iostream>
#include "singlyLinkedList.h"

int main(int argc, char* argv[])
{
    // This is just a generic driver to test other code.

    // Dummy test input data.
    int myarray[] = {1,6,3,7,2,8,5,4};

    LinkedList thetestlist;

    for(int i=0; i<8; i++)
        thetestlist.Insert(myarray[i]);
    
    int* testoutputarray = thetestlist.ListToArray();

    for(int i=0; i<8; i++)
        std::cout << testoutputarray[i] << std::endl;

    std::cout << std::endl;
    std::cout << "find node w/ value 1 (should be present): ";
    std::cout << thetestlist.Find(1) << std::endl;
    std::cout << "find node w/ value 2 (should be present): ";
    std::cout << thetestlist.Find(2) << std::endl;

    thetestlist.Remove(2);
    thetestlist.Remove(1);
    thetestlist.Remove(4);

    std::cout << "find node w/ value 1 (should not be present): ";
    std::cout << thetestlist.Find(1) << std::endl;
    std::cout << "find node w/ value 2 (should not be present): ";
    std::cout << thetestlist.Find(2) << std::endl;
    std::cout << std::endl;

    testoutputarray = thetestlist.ListToArray();

    for(int i=0; i<5; i++)
        std::cout << testoutputarray[i] << std::endl;
}
