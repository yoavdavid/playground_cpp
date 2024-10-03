
#include "basic/array_excercises.h"
#include "basic/math_exc.h"
#include "basic/simple_unique_ptr.h"
#include "interview_questions/IBM.h"
#include "largebucket.h"
#include "sort_algo.h"
#include "linked_list_exercises.h"
#include "stack_excercises.h"
#include "trees.h"
#include "graphs.h"

#include <map>

// 301
// Sieve of Erastothenes
int main(int argc, char** argv)
{
    //trees::node n22{ 1 };
    //trees::node n23{ 1 , &n22 };
    //trees::node n1{ 1, &n23 }, n3{ 3 }, n6{ 6 }, n8{ 8 };
    //trees::node n2{ 2, &n1, &n3 }, n7{ 7, &n6, &n8 };
    //trees::node root{ 5, &n2, &n7 };

    //trees::vertex v4{ 4 }, v5{ 5 }, v3{ 3 }, v2{ 2 };
    //trees::vertex root{ 1 };
    //root.vertices.push_back(&v2);
    //root.vertices.push_back(&v3);
    //v2.vertices.push_back(&root);
    //v3.vertices.push_back(&v4);
    //v3.vertices.push_back(&v5);

    //int arr[10]{3, 50, 200, 100, 300, 400};
    int arr[10]{ 1, 2 ,3 ,4 ,5 ,6 ,7, 8, 9, 10 };

    trees::node* res_tree = trees::binarySearchTreeFromSortedArray(arr, 10);
    
    
    trees::node* res =  trees::commonAncestor(res_tree, res_tree->left->left, res_tree->left->left->left);

    return 0;
}

//https://www.codingame.com/work/cpp-interview-questions/   