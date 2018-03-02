// Name: Christopher Duncan
//
// This code was produced as an exercise for myself to reacquaint myself with
//  pointers and lists before coding up some of the more complex structures.
//
// This simple code is not designed in accordance with OOP practices, just a
//  attempt at getting it up and running.
//
// Additionally, this is an iterative implementation rather than a recursive
//  one for no particular reason whatsoever, that's just how it is.s

class ListNode
{
    public:
        ListNode(int);

        // The value of the node.
        int value;
        // The next node in the list, initially null.
        ListNode* next = nullptr;
};

class LinkedList
{
    public:
        LinkedList();
        // Delete all nodes in the list.
        ~LinkedList();

        // Insert a node with a given value.
        void Insert(int);
        // Remove a node with a given value.
        void Remove(int);
        // Determine if a node with a given value is in the list
        bool Find(int);
        // Print the whole list.
        int* ListToArray();

        // First node in the list, initially null.
        ListNode* head = nullptr;
};

ListNode::ListNode(int _value)
{
    value = _value;
}

LinkedList::LinkedList()
{
    // Nothing to do here I guess, could probably delete this constructor.
}

LinkedList::~LinkedList()
{
    // Temporary variable to use in deletions.
    ListNode* tempnode;

    // While we still have nodes in the list,
    while(head) {
        // save the current head node,
        tempnode = head;
        // move the head forward,
        head = head->next;
        // then delete the saved node.
        delete tempnode;
    }
}

// Note: I was somewhat torn on what default functionality to go with here.
//  I chose to just insert at end of the list to preserve insertion order, but
//  it would be far more optimal in terms of time complexity to insert at the
//  beginning of the list.
void LinkedList::Insert(int _value)
{
    // If the list is empty, make the new node the head.
    if(!head)
        head = new ListNode(_value);
    // Otherwise, put it on the end of the list.
    else {
        ListNode* tempnode = head;

        // Traverse to the end of the list
        while(tempnode->next) {
            tempnode = tempnode->next;
        }

        // Insert the new node.
        tempnode->next = new ListNode(_value);
    }
}

void LinkedList::Remove(int _value)
{
    ListNode* tempnode = head;

    // If head node is the target value, we need to update to the new head.
    if(head->value == _value) {
        head = head->next;
        delete tempnode;
    }
    else {
        while(tempnode->next && tempnode->next->value != _value) {
            tempnode = tempnode->next;
        }

        if(tempnode->next) {
            ListNode* tempnode2 = tempnode->next;
            tempnode->next = tempnode2->next;
            delete tempnode2;
        }
    }
}

bool LinkedList::Find(int _value)
{
    ListNode* tempnode = head;

    // Search until we find the end of the list or run out of nodes.
    while(tempnode && tempnode->value != _value) {
        tempnode = tempnode->next;
    }

    // Kind of hack-y, but works and doesn't require another if-statement.
    return tempnode;
}

// Because we've maintained minimal memory usage and dependencies until now,
//  I decided to continue that trend and ruin the time complexity instead.
//  #stillLinearTho
int* LinkedList::ListToArray()
{
    ListNode* tempnode = head;
    int size = 0;

    while(tempnode) {
        size++;
        tempnode = tempnode->next;
    }

    tempnode = head;
    int *outarray = new int[size];
    
    for(int i=0; i<size; i++) {
        outarray[i] = tempnode->value;
        tempnode = tempnode->next;
    }

    return outarray;
}
