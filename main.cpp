#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1612;

tuple<Node *, Node *> testFixture1()
{
  auto tree1 = new Node('+');
  tree1->left = new Node('a');
  tree1->right = new Node('+');
  tree1->right->left = new Node('b');
  tree1->right->right = new Node('c');

  auto tree2 = new Node('+');
  tree2->left = new Node('+');
  tree2->left->left = new Node('b');
  tree2->left->right = new Node('c');
  tree2->right = new Node('a');

  return make_tuple(tree1, tree2);
}

tuple<Node *, Node *> testFixture2()
{
  auto tree1 = new Node('+');
  tree1->left = new Node('a');
  tree1->right = new Node('+');
  tree1->right->left = new Node('b');
  tree1->right->right = new Node('c');

  auto tree2 = new Node('+');
  tree2->left = new Node('+');
  tree2->left->left = new Node('b');
  tree2->left->right = new Node('d');
  tree2->right = new Node('a');

  return make_tuple(tree1, tree2);
}

tuple<Node *, Node *> testFixture3()
{
  auto tree1 = new Node('+');
  tree1->left = new Node('a');
  tree1->right = new Node('-');
  tree1->right->left = new Node('b');
  tree1->right->right = new Node('c');

  auto tree2 = new Node('+');
  tree2->left = new Node('-');
  tree2->left->left = new Node('b');
  tree2->left->right = new Node('c');
  tree2->right = new Node('a');

  return make_tuple(tree1, tree2);
}

tuple<Node *, Node *> testFixture4()
{
  auto tree1 = new Node('-');
  tree1->left = new Node('+');
  tree1->left->left = new Node('a');
  tree1->left->right = new Node('b');
  tree1->right = new Node('+');
  tree1->right->left = new Node('c');
  tree1->right->right = new Node('d');

  auto tree2 = new Node('-');
  tree2->left = new Node('+');
  tree2->left->left = new Node('c');
  tree2->left->right = new Node('d');
  tree2->right = new Node('+');
  tree2->right->left = new Node('a');
  tree2->right->right = new Node('b');
  return make_tuple(tree1, tree2);
}

tuple<Node *, Node *> testFixture5()
{
  auto tree1 = new Node('-');
  tree1->left = new Node('+');
  tree1->left->left = new Node('a');
  tree1->left->right = new Node('b');
  tree1->right = new Node('-');
  tree1->right->left = new Node('c');
  tree1->right->right = new Node('d');

  auto tree2 = new Node('-');
  tree2->left = new Node('+');
  tree2->left->left = new Node('c');
  tree2->left->right = new Node('d');
  tree2->right = new Node('-');
  tree2->right->left = new Node('a');
  tree2->right->right = new Node('b');
  return make_tuple(tree1, tree2);
}

void test1()
{
  auto fixture = testFixture1();

  Solution sol;
  auto equal = sol.isEqual(get<0>(fixture), get<1>(fixture));

  string result = equal ? "true" : "false";

  cout << "Test 1 - expect to see true" << endl;

  cout << "result: " << result << endl;
}

void test2()
{
  auto fixture = testFixture2();

  Solution sol;
  auto equal = sol.isEqual(get<0>(fixture), get<1>(fixture));

  string result = equal ? "true" : "false";

  cout << "Test 2 - expect to see false" << endl;

  cout << "result: " << result << endl;
}

void test3()
{
  auto fixture = testFixture3();

  Solution sol;
  auto equal = sol.isEqual(get<0>(fixture), get<1>(fixture));

  string result = equal ? "true" : "false";

  cout << "Test 3 - expect to see true" << endl;

  cout << "result: " << result << endl;
}

void test4()
{
  auto fixture = testFixture4();

  Solution sol;
  auto equal = sol.isEqual(get<0>(fixture), get<1>(fixture));

  string result = equal ? "true" : "false";

  cout << "Test 4 - expect to see false" << endl;

  cout << "result: " << result << endl;
}

void test5()
{
  auto fixture = testFixture5();

  Solution sol;
  auto equal = sol.isEqual(get<0>(fixture), get<1>(fixture));

  string result = equal ? "true" : "false";

  cout << "Test 5 - expect to see false" << endl;

  cout << "result: " << result << endl;
}

void test_map()
{
  unordered_map<char, int> map1;
  unordered_map<char, int> map2;

  map1['a'] = 5;
  map1['c'] = 6;

  map2['c'] = 3;
  map2['c'] += 3;
  map2['a'] = 5;

  auto same = map1 == map2;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  test5();

  // test_map();
  return 0;
}