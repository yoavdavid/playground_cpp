#pragma once


template<typename T>
class list
{
private:
    struct node
    {
    public:

    private:

        node(const T& new_data) : data{ new_data } {}

        node* next{ nullptr };
        node* prev{ nullptr };
        T data;

        friend list;
    };

public:
    ~list()
    {
        clear();
    }

    struct iterator
    {
    public:

        iterator& operator++()
        {
            curr = curr->next;
            return *this;
        }

        iterator& operator++(int)
        {
            return ++(*this);
        }

        iterator& operator--()
        {
            curr = curr->prev;
            return *this;
        }

        iterator& operator--(int)
        {
            return --(*this);
        }

        T& operator*()
        {
            return curr->data;
        }

        bool operator==(const iterator& other) const
        {
            return curr == other.curr;
        }

        bool operator!=(const iterator& other) const
        {
            return !(curr == other.curr);
        }

    private:
        iterator() = default;
        iterator(node* _curr) : curr(_curr) {}

        node* curr{ nullptr };

        friend list;
    };

    void push_back(const T& new_data)
    {
        node* new_node{ new node(new_data) };
        if (!root)
        {
            root = last = new_node;
        }
        else
        {
            new_node->prev = last;
            last->next = new_node;
            last = new_node;
        }
        new_node->next = nullptr;
    }

    void push_front(const T& new_data)
    {
        node* new_node{ new node(new_data) };
        if (!root)
        {
            root = last = new_node;
            new_node->next = nullptr;
        }
        else
        {
            root->prev = new_node;
            new_node->next = root;
            root = new_node;
        }
    }
    
    void pop_front()
    {
        if (!empty())
        {
            if (root == last)
            {
                delete(root);
                root = last = nullptr;
            }
            else
            {
                node* to_remove = root;
                root->next->prev = nullptr;
                root = root->next;
                delete(to_remove);
            }
        }
    }

    void pop_back()
    {
        if (!empty())
        {
            if (root == last)
            {
                delete(root);
                root = last = nullptr;
            }
            else
            {
                node* to_remove = last;
                last->prev->next = nullptr;
                last = last->prev;
                delete(to_remove);
            }
        }
    }

    bool empty()
    {
        return root == nullptr;
    }

    void clear()
    {
        while (!empty())
        {
            pop_back();
        }
    }

    iterator end() const
    {
        return _end;
    }

    iterator begin() const
    {
        return root == nullptr ? end() : iterator{ root };
    }

private:
    node* root;
    node* last;
    iterator _end{};
};