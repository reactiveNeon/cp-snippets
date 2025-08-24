# C++ boilerplate for LeetCode

Inspired by [neal](https://codeforces.com/profile/neal) from codeforces

## Features

### Debug Printing Macro (`DBG`)
- Prints the line numbers, variable names and values `[line number] (<variable names>): <values>`
- Works for basic types, STL containers, pair, and tuple
- Enabled when DEBUG is defined, otherwise compiles to no-op

```cpp
vector<int> v = {1, 2, 3};
pair<int, int> p = {4, 5};
DBG(v, p);  
// Output (line numbers may vary):
// [23] (v, p): {1, 2, 3} (4, 5)
```

### Macros
- `RANGE(x)`: expands to `(x).begin(), (x).end()`, useful for STL algorithms like sort
- `MP` → shorthand for `make_pair`
- `MT` → shorthand for `make_tuple`
- `PII` → alias for `pair<int,int>`

### Utilities

#### Min/Max utility
```cpp
int x = 5;
smax(x, 10);                                // x = 10
smin(x, 3, []() { 
    cout << "Updated!" << endl;             // x = 3, prints "Updated!"
});
```

#### Clamp utility
```cpp
int val = clamp(15, 0, 10);  // val = 10
```

### Stream operators
- for `pair<U,V>`, `tuple<T, ...>`
- containers `{x1, x2, x3, ...}`

### Type Alias
```cpp
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
```

### Fast I/O setup
```cpp
auto fastio = [](){ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    return 0; 
}();
```
- Disables sync with C I/O
- Unties `cin` from `cout`
  - Significantly speed up input/output in CP
