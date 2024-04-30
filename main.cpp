#include <iostream>
class Node
{
public:
    double data;
    Node* prev, * next;
public:
    Node(double data)
    {
        this->data = data;
        this->prev = this->next = NULL;
    }
};
class Linkedlist
{
public:
    Node* head, * tail;
public:
    Linkedlist()
    {
        head = tail = NULL;
    }
    ~Linkedlist()
    {
        while (head != NULL)
            pop_front();
    }
    Node* push_front(double data)
    {
        Node* ptr = new Node(data);
        ptr->next = head;
        if (head != NULL)
            head->prev = ptr;
        if (tail == NULL)
            tail = ptr;
        head = ptr;
        return ptr;
    }
    Node* push_back(double data)
    {
        Node* ptr = new Node(data);
        ptr->prev = tail;
        if (tail != NULL)
            tail->next = ptr;
        if (head == NULL)
            head = ptr;
        tail = ptr;
        return ptr;
    }
    void pop_front()
    {
        if (head == NULL) return;
        Node* ptr = head->next;
        if (ptr != NULL)
            ptr->prev = NULL;
        else
            tail = NULL;
        delete head;
        head = ptr;
    }
    void pop_back()
    {
        if (tail == NULL) return;
        Node* ptr = tail->prev;
        if (ptr != NULL)
            ptr->next = NULL;
        else
            head = NULL;
        delete tail;
        tail = ptr;
    }
    void remove_element(size_t pos)
    {
        Node* temp = head;
        for (size_t i = 0; i < pos; ++i)
        {
            temp = temp->next;
        }
        if(temp->prev!=nullptr)
            temp->prev->next = temp->next;
        else 
            head = temp->next; 
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
        delete temp;
    }  
    void delete_nums_subzero()
    {
        Node* temp = head;
        size_t counter = 0;
        bool flag = false;
        size_t first_sub =0 , last_sub = 0;
        while (temp != nullptr)
        {
            if (temp->data < 0. && flag) last_sub = counter;
            else if (temp->data < 0. && !flag) { first_sub = counter; flag = 1; };
            temp = temp->next;
            counter++;
        }
        this->remove_element(first_sub);
        this->remove_element(last_sub-1);
    }   
};
int main()
{
    Linkedlist lst;
    lst.push_back(-1.0);
    lst.push_back(2.0);
    lst.push_back(-4.0);
    lst.push_back(-3.0);
    lst.push_back(-5.0);
    lst.delete_nums_subzero();
    for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)
        std::cout << ptr->data << " ";
    std::cout << std::endl;

}