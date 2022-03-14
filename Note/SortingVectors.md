# Sorting a vector in c++

## qsort() int c++ STL

- used for sorting an array
- uses QuickSort algorithm to sort the given array
- prototype for qsort()

  ```
  void qsort(void* base, size_t num, size_t size, int (*comparator)) (const void*, const coid* ));
  ```
- comparator function *comparator*
  - take two pointers as arguments -- const void* 
  - contain logic of relative order
  - provide flexibility to sort any type(include user define type)
  - obtain any desired order (increasing, decreasing, or others) 

```
int comparator(const void* p1, const void* p2);
Return value meaning
<0 The element pointed to p1 goes before p2
0  The element pointed to p1 is equivalent to p2
>0 The element pointed to p1 goes after p2
```

## std::sort in c++ STL

