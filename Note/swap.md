# swap() in c++

## std::swap() in STL

- Syntax: swap(a, b)
- Parameters: two mandatory parameters **a** and **b** in ***any data type***
- Some datatype ex are: int, string, char, array, array[i][j], vector, ...
- Does not return anything.
- O(n) time complexity

```
// example of swap()
using namespace std;

int main() {
    int a = 1;
    int b = 2;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(a, b);
    cout << "swap a and b" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

expected output:
a = 1
b = 2
swap a and b
a = 2
b = 1
```