# reverse() in c++

## std::reverse() in STl

- Syntax: reverse(BidirecationalIterator first, BidirecationalIterator last)
  - BidirecationalIterator: iterator that can be used to access any elements of a container from both forward and backward direction
- Reverse the order of the elements in the range of [first, last)
  - range [first, last) contains all elements between first and last, including elements **pointed by first but not last**
- O(n) time complexity

```
// example using reverse
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1;
    vector<int>:: iterator p;

    // Insert elements in v1
    for (int i = 0; i < 8; ++i) {
        v1.push_back(3*i);
    }

    // initial vector cout
    cout << "v1: " << endl;
    for (p = v1.begin(); p < v1.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;

    cout << "Reverse from index 5 to 7 in v1" << endl;

    reverse(v1.begin() + 5, v1.begin() + 8);

    // reversed vector
    cout << "v1: " << endl;
    for (p = v1.begin(); p < v1.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;

    cout << "Reverse full vector" << endl;
    reverse(v1.begin(), v1.end());

    // reversed full vector
    cout << "v1: " << endl;
    for (p = v1.begin(); p < v1.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}

expected output:
v1: 
0 3 6 9 12 15 18 21
Reverse from index 5 to 7 in v1
v1:
0 3 6 9 12 21 18 15
Reverse full vector
15 18 21 12 9 6 3 0
```