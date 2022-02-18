#include <iostream>
using namespace std;

bool is_maxheap(int* data, int size, int pos) {
    // Implement function
    int child1 = 2 * pos + 1;
    int child2 = 2 * pos + 2;
    bool b1 = true, b2 = true;
    bool result = true;

    if (child1 < size)
        if (data[pos] < data[child1] || !is_maxheap(data, size, child1)) b1 = false;
    
    if (child2 < size)
        if (data[pos] < data[child2] || !is_maxheap(data, size, child2)) b2 = false;

    if (!b1 || !b2) result = false;

    return result;
}

int main(int argc, char** argv) {
    // Just some examples
    int a1[8] = { 6,8,9,2,6,3,7 };
    bool b1 = is_maxheap(a1, 8, 0);
    cout << "Example one is " << b1 << endl;

    int a2[8] = { 61,18,29,12,16,3,7 };
    bool b2 = is_maxheap(a2, 8, 0);
    cout << "Example two is " << b2 << endl;

    return 0;
}