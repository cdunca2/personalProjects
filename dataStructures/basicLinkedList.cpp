#include <iostream>


class node
{
    public:
        node(int);
        ~node();
        int get();
        void set(int);

    private:

};

node::node(int _val)
{
    this->set(_val);
}
node::~node()
{

}

class linkedList
{
    public:
        linkedList();
        ~linkedList();
        void printList();
        void insert();
        int remove();
        int find();

    private:
        void* head;
        void* tail;

};

linkedList::linkedList()
{
    head = NULL;
}
linkedList::~linkedList()
{
}




int main()
{

}