# Pointer Problems — 目录索引

> 30 道 C++ 指针练习题，按学习路径排序。
> 原命名 `ex1.cpp` ~ `ex30.cpp` → 已重命名为语义化名称（`ptr_*_exN.cpp`）。

---

## 第 1 组：指针基础 (ex1–ex3)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_dereference_basic_ex1.cpp` | `ptr_dereference_basic_ex1` | 声明指针 → 取地址 → 解引用 |
| `ptr_modify_via_ptr_ex2.cpp`   | `ptr_modify_via_ptr_ex2`   | 通过指针修改变量值 |
| `ptr_double_pointer_ex3.cpp`   | `ptr_double_pointer_ex3`   | 双重指针（pointer to pointer） |

## 第 2 组：指针与数组 (ex4–ex6, ex10–ex11, ex13, ex16)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_array_traversal_ex4.cpp`   | `ptr_array_traversal_ex4`   | 指针递增遍历数组 |
| `ptr_array_element_ex5.cpp`     | `ptr_array_element_ex5`     | 指针偏移访问第 3 个元素 |
| `ptr_char_array_ex6.cpp`        | `ptr_char_array_ex6`        | 字符数组 + 指针偏移 |
| `ptr_array_sum_ex10.cpp`        | `ptr_array_sum_ex10`        | 指针遍历求数组和 |
| `ptr_array_reverse_ex11.cpp`    | `ptr_array_reverse_ex11`    | 指针逆向遍历数组 |
| `ptr_matrix_traversal_ex13.cpp` | `ptr_matrix_traversal_ex13` | 2D 矩阵 → 一维指针扁平遍历 |
| `ptr_subarray_slice_ex16.cpp`   | `ptr_subarray_slice_ex16`   | 指针截取子数组切片 |

## 第 3 组：指针作函数参数 (ex8, ex14, ex17)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_func_param_ex8.cpp`     | `ptr_func_param_ex8`     | 传指针修改外部变量 |
| `ptr_array_copy_ex14.cpp`    | `ptr_array_copy_ex14`    | 指针遍历复制数组 |
| `ptr_swap_ex17.cpp`          | `ptr_swap_ex17`          | 指针参数实现 swap |

## 第 4 组：指针作函数返回值 (ex12)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_find_min_ex12.cpp` | `ptr_find_min_ex12` | 函数返回指针 → 找最小元素 |

## 第 5 组：const 指针 (ex21–ex22)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_const_param_ex21.cpp` | `ptr_const_param_ex21` | const 指针参数（只读不写）|
| `ptr_const_ptr_ex22.cpp`   | `ptr_const_ptr_ex22`   | 常量指针（地址不可变，值可变）|

## 第 6 组：函数指针 (ex19–ex20)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_func_ptr_basic_ex19.cpp`   | `ptr_func_ptr_basic_ex19`   | 函数指针声明与调用 |
| `ptr_func_ptr_callback_ex20.cpp`| `ptr_func_ptr_callback_ex20`| 函数指针作回调参数 |

## 第 7 组：结构体与指针 (ex23)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_struct_ex23.cpp` | `ptr_struct_ex23` | 结构体指针（Rectangle）|

## 第 8 组：动态内存 (ex24–ex25, ex29)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_dynamic_alloc_ex24.cpp`   | `ptr_dynamic_alloc_ex24`   | `new`/`delete` 单个对象 |
| `ptr_dynamic_array_ex25.cpp`  | `ptr_dynamic_array_ex25`  | `new[]`/`delete[]` 动态数组 |
| `ptr_dynamic_resize_ex29.cpp` | `ptr_dynamic_resize_ex29` | 引用传指针 → 动态扩容 |

## 第 9 组：指针数组 (ex26)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_array_of_ptrs_ex26.cpp` | `ptr_array_of_ptrs_ex26` | 指针数组（每个元素是指针）|

## 第 10 组：字符串操作 (ex18, ex27)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_string_toupper_ex18.cpp`  | `ptr_string_toupper_ex18`  | 指针遍历字符串转大写 |
| `ptr_substring_find_ex27.cpp`  | `ptr_substring_find_ex27`  | 指针实现子串查找（strstr）|

## 第 11 组：链表 (ex30)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_linked_list_ex30.cpp` | `ptr_linked_list_ex30` | 简单的单向循环链表遍历 |

## 第 12 组：其他 (ex9, ex15)

| 文件名 | 二进制 | 功能 |
|--------|--------|------|
| `ptr_sizeof_compare_ex9.cpp` | `ptr_sizeof_compare_ex9` | `sizeof(int)` vs `sizeof(int*)` 对比 |
| `array_compare_ex15.cpp`     | `array_compare_ex15`     | 模板引用比较数组（**无指针**）|

---

## 快速查找

想练习某个知识点，搜文件名前缀或阅读 INDEX.md：

```bash
# 列出所有指针练习
ls ptr_*.cpp

# 按主题查找（grep）
ls | grep dyncmic       # 动态内存
ls | grep func_ptr      # 函数指针
ls | grep const         # const 指针
ls | grep struct        # 结构体指针
ls | grep string        # 字符串

# 编译运行
g++ -o ptr_xxx ptr_xxx_exN.cpp && ./ptr_xxx
```

> ⚠️ 注意：ex28 不存在（编号从 ex27 直接跳到 ex29）。
