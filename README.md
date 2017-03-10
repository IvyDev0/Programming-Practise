## Learn How to Write Good Code





## 算法复杂度 / Big-O / 渐进分析法





## 数据结构

- ### 数组（Arrays）

  - 介绍：
    - [数组（视频）](https://www.coursera.org/learn/data-structures/lecture/OsBSF/arrays)
      - [数组的基础知识（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Basic-arrays/149042/177104-4.html)
      - [多维数组（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Multidimensional-arrays/149042/177105-4.html)
      - [动态数组（视频）](https://www.coursera.org/learn/data-structures/lecture/EwbnV/dynamic-arrays)
      - [不规则数组（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Jagged-arrays/149042/177106-4.html)
      - [调整数组的大小（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Resizable-arrays/149042/177108-4.html)
  - 实现一个动态数组（可自动调整大小的可变数组）：
    - [ ] 练习使用数组和指针去编码，并且指针是通过计算去跳转而不是使用索引
          - [ ] 通过分配内存来新建一个原生数据型数组
                - 可以使用 int 类型的数组，但不能使用其语法特性
                - 从大小为16或更大的数（使用2的倍数 —— 16、32、64、128）开始编写
          - [ ] size() —— 数组元素的个数
          - [ ] capacity() —— 可容纳元素的个数
          - [ ] is_empty()
          - [ ] at(index) —— 返回对应索引的元素，且若索引越界则愤然报错
          - [ ] push(item)
          - [ ] insert(index, item) —— 在指定索引中插入元素，并把后面的元素依次后移
          - [ ] prepend(item) —— 可以使用上面的 insert 函数，传参 index 为 0
          - [ ] pop() —— 删除在数组末端的元素，并返回其值
          - [ ] delete(index) —— 删除指定索引的元素，并把后面的元素依次前移
          - [ ] remove(item) —— 删除指定值的元素，并返回其索引（即使有多个元素）
          - [ ] find(item) —— 寻找指定值的元素并返回其中第一个出现的元素其索引，若未找到则返回 -1
          - [ ] resize(new_capacity) // 私有函数
                - 若数组的大小到达其容积，则变大一倍
                - 获取元素后，若数组大小为其容积的1/4，则缩小一半
  - [ ] 时间复杂度
    - 在数组末端增加/删除、定位、更新元素，只允许占 O(1) 的时间复杂度（平摊（amortized）去分配内存以获取更多空间）
      - 在数组任何地方插入/移除元素，只允许 O(n) 的时间复杂度
  - [ ] 空间复杂度
    - 因为在内存中分配的空间邻近，所以有助于提高性能
      - 空间需求 = （大于或等于 n 的数组容积）* 元素的大小。即便空间需求为 2n，其空间复杂度仍然是 O(n)

        ​

- ### 链表（Linked Lists）

  - [ ] 介绍：
        - [ ] [单向链表（视频）](https://www.coursera.org/learn/data-structures/lecture/kHhgK/singly-linked-lists)
        - [ ] [CS 61B —— 链表（视频）](https://www.youtube.com/watch?v=sJtJOtXCW_M&list=PL-XXv-cvA_iAlnI-BQr9hjqADPBtujFJd&index=5)
  - [ ] [C 代码（视频）](https://www.youtube.com/watch?v=QN6FPiD0Gzo)
        - 并非看完整个视频，只需要看关于节点结果和内存分配那一部分即可
  - [ ] 链表 vs 数组：
        - [基本链表 Vs 数组（视频）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/rjBs9/core-linked-lists-vs-arrays)
        - [在现实中，链表 Vs 数组（视频）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/QUaUd/in-the-real-world-lists-vs-arrays)
  - [ ] [为什么你需要避免使用链表（视频）](https://www.youtube.com/watch?v=YQs6IC-vgmo)
  - [ ] 的确：你需要关于“指向指针的指针”的相关知识：（因为当你传递一个指针到一个函数时，该函数可能会改变指针所指向的地址）该页只是为了让你了解“指向指针的指针”这一概念。但我并不推荐这种链式遍历的风格。因为，这种风格的代码，其可读性和可维护性太低。
        - [指向指针的指针](https://www.eskimo.com/~scs/cclass/int/sx8.html)
  - [ ] 实现（我实现了使用尾指针以及没有使用尾指针这两种情况）：
        - [ ] size() —— 返回链表中数据元素的个数
        - [ ] empty() —— 若链表为空则返回一个布尔值 true
        - [ ] value_at(index) —— 返回第 n 个元素的值（从0开始计算）
        - [ ] push_front(value) —— 添加元素到链表的首部
        - [ ] pop_front() —— 删除首部元素并返回其值
        - [ ] push_back(value) —— 添加元素到链表的尾部
        - [ ] pop_back() —— 删除尾部元素并返回其值
        - [ ] front() —— 返回首部元素的值
        - [ ] back() —— 返回尾部元素的值
        - [ ] insert(index, value) —— 插入值到指定的索引，并把当前索引的元素指向到新的元素
        - [ ] erase(index) —— 删除指定索引的节点
        - [ ] value_n_from_end(n) —— 返回倒数第 n 个节点的值
        - [ ] reverse() —— 逆序链表
        - [ ] remove_value(value) —— 删除链表中指定值的第一个元素
  - [ ] 双向链表
        - [介绍（视频）](https://www.coursera.org/learn/data-structures/lecture/jpGKD/doubly-linked-lists)
        - 并不需要实现

- ### 堆栈（Stack）

  - [ ] [堆栈（视频）](https://www.coursera.org/learn/data-structures/lecture/UdKzQ/stacks)
  - [ ] [使用堆栈 —— 后进先出（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Using-stacks-last-first-out/149042/177120-4.html)
  - [ ] 可以不实现，因为使用数组来实现并不重要

- ### 队列（Queue）

  - [ ] [使用队列 —— 先进先出（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Using-queues-first-first-out/149042/177122-4.html)
  - [ ] [队列（视频）](https://www.coursera.org/learn/data-structures/lecture/EShpq/queue)
  - [ ] [原型队列/先进先出（FIFO）](https://en.wikipedia.org/wiki/Circular_buffer)
  - [ ] [优先级队列（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Priority-queues-deques/149042/177123-4.html)
  - [ ] 使用含有尾部指针的链表来实现:
        - enqueue(value) —— 在尾部添加值
        - dequeue() —— 删除最早添加的元素并返回其值（首部元素）
        - empty()
  - [ ] 使用固定大小的数组实现：
        - enqueue(value) —— 在可容的情况下添加元素到尾部
        - dequeue() —— 删除最早添加的元素并返回其值
        - empty()
        - full()
  - [ ] 花销：
        - 在糟糕的实现情况下，使用链表所实现的队列，其入列和出列的时间复杂度将会是 O(n)。因为，你需要找到下一个元素，以致循环整个队列
        - enqueue：O(1)（平摊（amortized）、链表和数组 [探测（probing）]）
        - dequeue：O(1)（链表和数组）
        - empty：O(1)（链表和数组）

- ### 哈希表（Hash table）

  - [ ] 视频：
        - [ ] [链式哈希表（视频）](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8)
        - [ ] [Table Doubling 和 Karp-Rabin（视频）](https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
        - [ ] [Open Addressing 和密码型哈希（Cryptographic Hashing）（视频）](https://www.youtube.com/watch?v=rvdJDijO2Ro&index=10&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
        - [ ] [PyCon 2010：The Mighty Dictionary（视频）](https://www.youtube.com/watch?v=C4Kc8xzcA68)
        - [ ] [（进阶）随机取样（Randomization）：全域哈希（Universal Hashing）& 完美哈希（Perfect Hashing）（视频）](https://www.youtube.com/watch?v=z0lJ2k0sl1g&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11)
        - [ ] [（进阶）完美哈希（Perfect hashing）（视频）](https://www.youtube.com/watch?v=N0COwN14gt0&list=PL2B4EEwhKD-NbwZ4ezj7gyc_3yNrojKM9&index=4)
  - [ ] 在线课程：
        - [ ] [哈希函数的掌握（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Understanding-hash-functions/149042/177126-4.html)
        - [ ] [使用哈希表（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Using-hash-tables/149042/177127-4.html)
        - [ ] [哈希表的支持（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Supporting-hashing/149042/177128-4.html)
        - [ ] [哈希表的语言支持（视频）](https://www.lynda.com/Developer-Programming-Foundations-tutorials/Language-support-hash-tables/149042/177129-4.html)
        - [ ] [基本哈希表（视频）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/m7UuP/core-hash-tables)
        - [ ] [数据结构（视频）](https://www.coursera.org/learn/data-structures/home/week/3)
        - [ ] [电话薄问题（Phone Book Problem）（视频）](https://www.coursera.org/learn/data-structures/lecture/NYZZP/phone-book-problem)
        - [ ] 分布式哈希表：
              - [Dropbox 中的瞬时上传及存储优化（视频）](https://www.coursera.org/learn/data-structures/lecture/DvaIb/instant-uploads-and-storage-optimization-in-dropbox)
              - [分布式哈希表（视频）](https://www.coursera.org/learn/data-structures/lecture/tvH8H/distributed-hash-tables)
  - [ ] 使用线性探测的数组去实现
        - hash(k, m) —— m 是哈希表的大小
        - add(key, value) —— 如果 key 已存在则更新值
        - exists(key)
        - get(key)
        - remove(key)









