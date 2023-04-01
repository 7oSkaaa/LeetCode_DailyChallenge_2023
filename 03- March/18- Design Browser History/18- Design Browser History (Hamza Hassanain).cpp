// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;

/*
       Approach:
            Use a doublay linked list (linked list where each node points to its next and its previous)
*/

struct CustomListNode // our listnode will be using
{
    string val;
    CustomListNode *next;
    CustomListNode *prev;
    CustomListNode(string val) : val{val}, next{nullptr}, prev{nullptr} {}
};
class BrowserHistory
{
public:
    CustomListNode *head; // the homepage
    CustomListNode *ptr;  // the pointer to the page we are currently in
    BrowserHistory(string homepage)
    {
        this->head = new CustomListNode(homepage);
        this->ptr = this->head;
    }

    void visit(string url)
    {
        if (this->ptr->next)
            delete this->ptr->next;

        auto node = new CustomListNode(url);
        node->prev = this->ptr;

        this->ptr->next = node;
        this->ptr = this->ptr->next;
    }

    string back(int steps)
    {
        while (this->ptr->prev && steps--)
        {
            this->ptr = this->ptr->prev;
        }
        return this->ptr->val;
    }

    string forward(int steps)
    {
        while (this->ptr->next && steps--)
        {
            this->ptr = this->ptr->next;
        }
        return this->ptr->val;
    }
};
