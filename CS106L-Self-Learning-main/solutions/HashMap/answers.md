
# 1.Templates and Template Classes
Q: In the rehash() function, the for-each loop contains an auto&. What is the deduced type of that auto, and why the ampersand necessary?

A1: The deduced type of auto is (Node *);

A2: The ampersand is necessary because we need to modify the content stored in the _bucket_array.

# 2.HashMap Pair Type

Q: STL containers store elements of type value_type, and for your HashMap this value_type is a std::pair<const K, M>. What would be the problem in the HashMap class if value_type were instead std::pair<K, M>? Hint: think about the following lines of code:
```c++
HashMap<std::string, int> map;
map.insert({"Avery", 3});
auto iter = map.begin();
iter->first = "Anna";
auto anna_iter = map.find("Anna");
```

A: The key should not be modified because we use the hash value of the key to find the correct bucket.

# 3.Find vs find
Q : In addition to the HashMap::find member function, there is also a std::find function in the STL algorithms library.
If you were searching for key k in HashMap m, is it preferable to call m.find(k) or std::find(m.begin(), m.end(), k)?
A : It is preferable to call m.find(k) because the amortized complexity is O(1) while std::find is O(N).

# 4.RAII?
Q : This HashMap class is RAII-compliant. Explain why.
A : Because the destructor function will call the HashMap::clear() which free all the resources which HashMap acquires.

# 5.Privacy
Q : Why is the HashMapIterator's constructor private? How do HashMapIterators get constructed if the constructor is private?
A : Because to construct a HashMapIterator, you need to have access to the private attribute of the HashMap. Since HashMapIterator is
the friend class of HashMap, so HashMap has access to the private constructor of HashMapIterator.

# 6.Increments
Q : Briefly explain the implementation of HashMapIterator's operator++, which we provide for you. How does it work and what checks does it have?
A : For the prefix ++, we first check the next node, if it is nullptr, which means the end of this bucket is reached, we find the next bucket which contains value.
Otherwise, the next node is returned. For the postfix ++, we first copy the current iterator, then call the prefix ++ to increment the iterator and return the copied iterator.

# 7.Did We Make A Mistake?
Q : Why is there both a const and non-const version of at(), but only a non-const version of operator[]?
    (unlike in Vector where operator[] also had a const version).
A : Because a key/mapped value pair will be added to the HashMap if no such key exists, which means will modify the HashMap.
So the operator[] does not need a const version.

# 8.Now Streaming on iTunes
Q : Look at the function signature for the stream insertion (operator<<) in hashmap.cpp.
Briefly explain the syntax for this function signature and how this works.
A : The two arguments are both const to avoid copying. Ostream argument should not be constant because we will modify it.
We return the reference to the modified ostream to support ostream chaining.

# 9.Attachment Issues
Q : Why is it that we need to implement the special member functions in the HashMap class,
but we can default all the special member functions in the HashMapIterator class?
A : For HashMapIterator, all its attributes are values, we can use the default SMF to copy value directly. However, for HashMap,
we need to manage pointers to allocated to memory, so we implement the SMF ourselves;

# 10.Move Semantics
Q : In your move constructor or move assignment operator, why did you have to std::move each member,
even though the parameter (named rhs) is already an r-value reference?
A : Because the attributes of the rhs may not be r-value, and assign it to the lhs's corresponding attribute may trigger copy instead of move, so we need to use std::move.

