#pragma once

#include <list>
#include <stack>

namespace lists
{


class node
{
public:
    node(int x = 0) : data{ x } {}
    int data;
    node* next{ nullptr };
};

void deleteDuplicates(std::list<int>& _list)
{
    auto curr = _list.begin();
    while (curr != _list.end())
    {
        auto next = curr;
        next++;
        while (next != _list.end())
        {
            auto temp = next++;
            if (*temp == *curr)
            {
                _list.erase(temp);
            }
        }
        curr++;
    }
}

// return the kth from last element in a signled ll
auto kthToLast(std::list<int>& list, int kth)
{
    auto curr = list.begin();
    auto res = list.begin();
    int offset{};
    while (curr != list.end())
    {
        if (offset > kth)
        {
            res++;
        }
        else
        {
            offset++;
        }
        curr++;
    }

    if (offset > kth)
    {
        return res;
    }
    else
    {
        return list.end();
    }
}

void kthToLast2(std::list<int>::iterator& curr, std::list<int>::iterator& res, std::list<int>::iterator& end, int pos, int kth)
{
    if (curr == end)
    {
        if (pos < kth)
        {
            res = end;
        }
        return;
    }

    if (pos > kth)
    {
        res++;
    }

    kthToLast2(++curr, res, end, ++pos, kth);
}

auto getMiddleNode(std::list<int>& list, int& index)
{
    index = 0;
    std::list<int>::iterator it1 = list.begin(), it2 = list.begin();

    if (it1 == list.end())
    {
        return it1;
    }

    while (++it2 != list.end())
    {
        if ((++index % 2) == 0)
        {
            it1++;
        }
    }

    index = index / 2;
    return it1;
}

// rearrange list as follow all nodes with where data < partition wll be before oter nodes
node* partitionList(node* curr, int partition)
{
    node* head = curr;
    node* tail = curr;

    if (!curr)
    {
        return nullptr;
    }

    while (curr != nullptr)
    {
        node* next = curr->next;
        if (curr->data <= partition)
        {
            curr->next = head;
            head = curr;
        }
        else
        {
            tail->next = curr;
            tail = curr;
        }
        curr = next;
    }

    tail->next = nullptr;
    return head;
}

// each list represent a number 1->2-3 == 321
node* sumLists(node* l1, node* l2)
{
    if (!l1 && !l2)
    {
        return nullptr;
    }
    node* head{};
    node* tail{};

    int carry{};
    while (true)
    {
        node* curr = new node{ 0 };
        if (l1)
        {
            carry += l1->data;
            l1 = l1->next;
        }

        if (l2)
        {
            carry += l2->data;
            l2 = l2->next;
        }

        curr->data = carry % 10;
        carry /= 10;

        if (!head)
        {
            head = tail = curr;
        }
        else
        {
            tail->next = curr;
            tail = curr;
        }

        if (!l1 && !l2 && !carry)
        {
            break;
        }
    }

    return head;
}

// each list represent a number 1->2-3 == 123
node* sumLists2helper(node* l1, node* l2, int& carry)
{
    node* res{};
    if (l1 && l2)
    {
        node* head = sumLists2helper(l1->next, l2->next, carry);
        res = new node{ 0 };
        int val = l1->data + l2->data + carry;
        res->data = val % 10;
        carry = val / 10;
        res->next = head;
    }
    return res;
}

int llength(node* l1)
{
    int res{};
    while (l1)
    {
        res++;
        l1 = l1->next;
    }
    return res;
}

node* padlist(node* head, int numpads)
{
    node* res{};
    while (numpads--)
    {
        res = new node{ 0 };
        res->next = head;
        head = res;
    }
    return res;
}

node* sumLists2(node* l1, node* l2)
{
    int size1 = llength(l1);
    int size2 = llength(l2);

    if (size1 > size2)
    {
        l2 = padlist(l2, size1 - size2);
    }
    else if (size2 > size1)
    {
        l1 = padlist(l1, size2 - size1);
    }

    int carry{};
    node* res = sumLists2helper(l1, l2, carry);

    if (carry)
    {
        node* head = new node{ carry };
        head->next = res;
        res = head;
    }

    return res;
}

bool isPalidrome(std::list<char> list)
{
    bool res{ true };
    std::stack<char> stack;

    std::list<char>::iterator it = list.begin();

    int size{};
    while (it != list.end())
    {
        size++;
        stack.push(*it);
        it++;
    }

    it = list.begin();
    for (int i{}; i < size / 2; i++, it++)
    {
        if (*it != stack.top())
        {
            res = false;
            break;
        }
        stack.pop();
    }

    return res;
}

struct ListContainer
{
    std::list<char>::iterator it;
};

bool isPalidrome(ListContainer& list, int size, int idx)
{
    bool res{ false };

    if ((size / 2) <= idx)
    {
        if (size % 2)
        {
            list.it++;
        }
        return true;
    }

    char ch = *(list.it);
    list.it++;
    res = isPalidrome(list, size, idx + 1);

    if (res)
    {
        res = ch == *(list.it);
        list.it++;
    }

    return res;
}

node* moveForward(node* list, int steps)
{
    for (int i = 0; i < steps; i++)
    {
        list = list->next;
    }
    return list;
}

node* intersection(node* l1, node* l2)
{
    int size1 = llength(l1);
    int size2 = llength(l2);

    if (size1 > size2)
    {
        l1 = moveForward(l1, size1 - size2);
    }
    else if (size2 > size1)
    {
        l2 = moveForward(l2, size2 - size1);
    }

    while (true)
    {
        if (l1 == l2)
        {
            return l1;
        }

        l1 = l1->next;
        l2 = l2->next;
    }
}

}