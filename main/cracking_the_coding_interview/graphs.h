#pragma once

#include <vector>
#include <unordered_map>

namespace graphs
{

struct node
{
    node(int _data) : data(_data), num_parents{} {}

    int data;
    int num_parents;
    std::vector<node*> childs;
};

class graph
{
public:
    graph(std::vector<int> vertices, std::unordered_map<int, std::vector<int>> edges)
    {
        for (auto ver: vertices)
        {
            nodes[ver] = new node{ver};
        }

        for (auto [dependancy, dependants]: edges)
        {
            for (auto dependant: dependants)
            {
                nodes[dependancy]->childs.push_back(nodes[dependant]);
                nodes[dependant]->num_parents++;
            }
        }
    }

    void removeNode(node* v)
    {
        for (auto child: v->childs)
        {
            child->num_parents--;
        }

        nodes.erase(v->data);
        delete v;
    }

    node* getIndependantNode()
    {
        node* res{};
        for (auto child: nodes)
        {
            if (child.second->num_parents == 0)
            {
                res = child.second;
                break;
            }
        }
        return res;
    }

    bool empty()
    {
        return nodes.empty();
    }

private:
    std::unordered_map<int, node*> nodes;
};


std::vector<int> buildOrder(std::vector<int> projects, std::unordered_map<int, std::vector<int>> dependancies)
{
    std::vector<int> res;
    graph graph{projects, dependancies };

    while (!graph.empty())
    {
        if (node* curr = graph.getIndependantNode())
        {
            res.push_back(curr->data);
            graph.removeNode(curr);
        }
        else
        {
            throw new std::exception("");
        }
    }

    return res;
}




}
