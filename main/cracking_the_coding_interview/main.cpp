
#include <iostream>

#include "graphs.h"
#include "linked_list.h"
#include "sort_algo.h"
#include "stack.h"
#include "trees.h"

void run_tree_and_graph()
{
    trees::node n22{ 1 };
    trees::node n23{ 1 , &n22 };
    trees::node n1{ 1, &n23 }, n3{ 3 }, n6{ 6 }, n8{ 8 };
    trees::node n2{ 2, &n1, &n3 }, n7{ 7, &n6, &n8 };
    trees::node root{ 5, &n2, &n7 };


    int arr[10]{3, 50, 200, 100, 300, 400};
    int arr[10]{ 1, 2 ,3 ,4 ,5 ,6 ,7, 8, 9, 10 };

    trees::node* res_tree = trees::binarySearchTreeFromSortedArray(arr, 10);


    trees::node* res = trees::commonAncestor(res_tree, res_tree->left->left, res_tree->left->left->left);
}

int main(int argc, char** argv)
{
    run_tree_and_graph();

    return 0;
}