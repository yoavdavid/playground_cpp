#pragma once

#include <stack>
#include <vector>

#include "linked_list_exercises.h"

namespace stacks
{

using namespace lists;

class stackOfstack;

struct stack_node
{
    int val;
    stack_node* next;
};

class custom_stack
{
public:
    void push(int data)
    {
        node* res = new node{ data };
        if (!head)
        {
            head = res;
        }
        else
        {
            res->next = head;
            head = res;
        }
    }

    void pop()
    {
        if (head)
        {
            node* new_head = head->next;
            delete head;
            head = new_head;
        }
    }

    int top()
    {
        return head->data;
    }

    bool empty()
    {
        return !head;
    }

private:
    node* head{};

friend stackOfstack;
};

class minStack
{
public:
    void push(int data)
    {
        stack.push(data);

        if (smin.empty() || data <= smin.top())
        {
            smin.push(data);
        }
    }

    void pop()
    {
        if (!stack.empty())
        {
            int val = stack.top();
            stack.pop();

            if (val == smin.top())
            {
                smin.pop();
            }
        }
    }

    int top()
    {
        return stack.top();
    }

    int min()
    {
        return smin.top();
    }

    bool empty()
    {
        return stack.empty();
    }

private:
    std::stack<int> stack;
    std::stack<int> smin;
};

class stack_wrapper
{
public:

    void push(int data)
    {
        stack.push(data);
        count++;
    }

    void pop()
    {
        if (!stack.empty())
        {
            stack.pop();
            count--;
        }
    }

    custom_stack stack;
    int count;

    
};

class stackOfstack
{
public:

    void push(int data)
    {
        if (stacks.empty() || stacks[stacks.size() - 1].count == max)
        {
            stacks.push_back(stack_wrapper{});
        }
        stack_wrapper& stack = stacks.back();
        stack.push(data);
    }

    int top()
    {
        if (!stacks.empty())
        {
            return stacks.back().stack.top();
        }
    }

    void pop()
    {
        if (!stacks.empty())
        {
            stack_wrapper& stack = stacks.back();
            stack.pop();
            if (stack.stack.empty())
            {
                stacks.pop_back();
            }
        }
    }

    void popAt(int idx)
    {
        stacks[idx].pop();
        for (int i=idx; i < stacks.size() - 1; i++)
        {
            stack_wrapper& from = stacks[i + 1];
            stack_wrapper& to = stacks[i];

            int data = getButtomOfStack(from.stack.head);
            to.push(data);
        }

        if (stacks[stacks.size() - 1].stack.empty())
        {
            stacks.pop_back();
        }
    }

    bool empty()
    {
        return stacks.empty();
    }

    

private:

    int getButtomOfStack(node* list)
    {
        while (list->next)
        {
            list = list->next;
        }
        return list->data;
    }

    int max{2};
    vector<stack_wrapper> stacks;
};

class Animal
{
    virtual void mock() {};
};
class Dog : public Animal {};
class Cat : public Animal {};

class animalQueue
{
public:
    void enQueue(Animal animal)
    {
        if (auto cat = dynamic_cast<Cat*>(&animal))
        {
            cats.push_back(*cat);
        }
        else if (auto dog = dynamic_cast<Dog*>(&animal))
        {
            dogs.push_back(*dog);
        }

        any.push_back(animal);
    }

    void deQueueAny()
    {
        Animal animal = any.front();
        any.pop_front();

        if (dynamic_cast<Cat*>(&animal))
        {
            cats.pop_front();
        }
        else
        {
            dogs.pop_front();
        }
    }

    void deQueueDog()
    {
        dogs.pop_front();
        any.pop_front();
    }

    void deQueueCat()
    {
        cats.pop_front();
        any.pop_front();
    }


private:
    std::list<Cat> cats;
    std::list<Dog> dogs;
    std::list<Animal> any;
};

}