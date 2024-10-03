#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <deque>

namespace trees
{

using namespace std;

struct node
{
    node(int val, node* l = nullptr, node* r = nullptr): data { val }, left{l}, right{r}{}

    int data;
    node* left;
    node* right;
};

struct vertex
{
    vertex(int val) : data{ val }, vertices{}{}

    int data;
    vector<vertex*> vertices;
};

void inOrder(node* n)
{
    if (!n)
    {
        return;
    }

    inOrder(n->left);
    cout << n->data;
    inOrder(n->right);
}

void preOrder(node* n)
{
    if (!n)
    {
        return;
    }

    cout << n->data;
    preOrder(n->left);
    preOrder(n->right);
}

void postOrder(node* n)
{
    if (!n)
    {
        return;
    }

    postOrder(n->left);
    postOrder(n->right);
    cout << n->data;
}

bool findPathBFS(vertex* start, vertex* end)
{
    if (start == end)
    {
        return true;
    }

    set<vertex*> visited;
    deque<vertex*> queue;
    
    queue.push_front(start);

    while (!queue.empty())
    {
        vertex* v = queue.back();
        queue.pop_back();
        visited.insert(v);
        
        for (auto adj : v->vertices)
        {
            if (adj == end)
            {
                return true;
            }

            if (visited.find(adj) == visited.end())
            {
                queue.push_front(adj);
            }
        }
    }

    return false;
}

bool findPathDFSHelper(vertex* start, vertex* end, set<vertex*>& visited)
{
    if (start == end)
    {
        return true;
    }

    visited.insert(start);
    for (auto adj : start->vertices)
    {
        if (visited.find(adj) == visited.end())
        {
            if (findPathDFSHelper(adj, end, visited))
            {
                return true;
            }
        }
    }

    return false;
}

bool findPathDFS(vertex* start, vertex* end)
{
    set<vertex*> visited;
    return findPathDFSHelper(start, end, visited);
}

node* binarySearchTreeFromSortedArray(int arr[], int size)
{
    if (!arr || size <= 0)
    {
        return nullptr;
    }

    int middle = size / 2;
    node* left = binarySearchTreeFromSortedArray(arr, middle);
    node* right = binarySearchTreeFromSortedArray(arr + middle + 1, size - middle - 1);
    return new node{arr[middle], left, right};
}

void getDepthsHelper(node* vertex, std::vector<std::list<node*>>& list, int level)
{
    if (vertex == nullptr)
    {
        return;
    }

    if (list.size() == level)
    {
        list.push_back({});
    }

    list[level].push_back(vertex);
    getDepthsHelper(vertex->left, list, level + 1);
    getDepthsHelper(vertex->right, list, level + 1);
}

std::vector<std::list<node*>> getDepths(node* root)
{
    std::vector<std::list<node*>> res;
    getDepthsHelper(root, res, 0);
    return res;
}

list<vector<node*>> getDepthsBFS(node* vertex)
{
    list<vector<node*>> res;
    deque<node*> queue1, queue2;
    

    queue1.push_front(vertex);
    while (!queue1.empty() || !queue2.empty())
    {
        res.push_back({});
        vector<node*>& vec = res.back();

        deque<node*>& from = queue1.empty() ? queue2 : queue1;
        deque<node*>& to = queue1.empty() ? queue1 : queue2;

        while (!from.empty())
        {
            node* curr = from.back();
            from.pop_back();
            vec.push_back(curr);

            if (curr->left)
            {
                to.push_front(curr->left);
            }
            if (curr->right)
            {
                to.push_front(curr->right);
            }
        }
    }

    return res;
}

bool isBalanced(node* vertex, int& height)
{
    if (!vertex)
    {
        return true;
    }

    int right_height{}, left_height{};
    bool left_balance = isBalanced(vertex->left, left_height);
    bool right_balance = isBalanced(vertex->right, right_height);

    if (!left_balance || !right_balance)
    {
        return false;
    }

    height = (left_height > right_height ? left_height : right_height) + 1;
    return (left_height - right_height > -1) && (left_height - right_height < 1);

}

bool isBSTHelper(node* vertex, node* parent, node* max_node)
{
    if (!vertex) return true;

    bool left = vertex->left ? vertex->data >= vertex->left->data : true;
    bool right = vertex->right ? vertex->data < vertex->right->data : true;
    bool max{ true };
    if (max_node && (vertex->data >= max_node->data) && (max_node != parent))
    {
        max = false;
    }
    
    if (!left || !right || !max)
    {
        return false;
    }
    
    return isBSTHelper(vertex->left, vertex, vertex) &&
        isBSTHelper(vertex->right, vertex, max_node);
}

bool isBST(node* vertex)
{
    if (!vertex) return false;
    return isBSTHelper(vertex, nullptr , nullptr);
}

node* commonAncestorHelper(node* curr, node* n1, node* n2, node** f1, node** f2)
{
    if (!curr)
    {
        return nullptr;
    }

    *f1 = (curr == n1) ? curr : *f1;
    *f2 = (curr == n2) ? curr : *f2;

    if (*f1 && *f2)
    {
        return nullptr;
    }

    node* res1 = commonAncestorHelper(curr->left, n1, n2, f1, f2);
    node* res2 = commonAncestorHelper(curr->right, n1, n2, f1, f2);

    if (*f1 && *f2)
    {
        if (res1 || res2)
        {
            return res1 ? res1 : res2;
        }
        return curr;
    }

    return nullptr;
}

node* commonAncestor(node* curr, node* n1, node* n2)
{
    node* temp1{};
    node* temp2{};

    return commonAncestorHelper(curr, n1, n2, &temp1, &temp2);
}

}

