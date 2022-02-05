#include "solution.h"

#include <functional>
#include <queue>
using namespace sol1612;
using namespace std;

/* takeaways
   - you have two bins positive (P) and negative
     (N) for each tree

   - put the variable into the bin based on
     the following:
     - example a - b
       - put a into P; put b into N as b is behind a '-'
     - example (a+b)-(c-d)
       - put a,b,d in P and c in N
       - c is a left child so it should be positive
         - however its grandparent is '-', so it
           just inherits that and become negative
       - d is behind a '-' so it should be negative
         - however its grandparent is '-', so it
           needs reverse that as two negatives
           become one positive

   - compare if tree1 and tree2 have identical bins
*/

/* C++ notes
   - we can check if two unordered maps
     are equal easily
   - check test_map() in main.cpp
*/
bool Solution::isEqual(Node *tree1, Node *tree2)
{
    unordered_map<char, int> t1P, t1N, t2P, t2N;

    function<void(Node *, unordered_map<char, int> &, unordered_map<char, int> &, bool)> visit =
        [&visit](Node *node, unordered_map<char, int> &plus, unordered_map<char, int> &minus, bool isMinus)
    {
        if (node == nullptr)
            return;
        if (node->val != '+' && node->val != '-')
        {
            if (!isMinus)
                plus[node->val]++;
            else
                minus[node->val]++;
        }

        /*
          - by default left should be positive
          - but it can be overridden to negative
            like c in the following case:
            (a+b)-(c-d)
        */
        auto left = isMinus;
        /*
          - by default left should be negative
          - but it can be overridden to positive
            like d in the following case:
            (a+b)-(c-d)
          - so what we are saying here is that
            if the right is behind a '-', revert
            what the grandparent (node's parent)
            says as two negatives become one positive
        */
        auto right = node->val == '+' ? isMinus : !isMinus;

        visit(node->left, plus, minus, left);
        visit(node->right, plus, minus, right);
    };

    visit(tree1, t1P, t1N, false);
    visit(tree2, t2P, t2N, false);

    return t1P == t2P && t1N == t2N;
}
