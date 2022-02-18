#include <iostream>
#include "binaryTree.h"
#include <string>

using namespace std;

int main()
{
    binaryTree<int> test;
    string s;
    cin >> s;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    test.insert(a);
    test.insert(b);
    test.insert(c);
    test.insert(d);
    test.insert(e);

    if (s == "pre")
        test.preorderTraversal();

    if (s == "post")
        test.postorderTraversal();

    return 0;
}