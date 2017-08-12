# container

* vector </br>
vector is a container of elements of some type T: build-in numeric / user-defined types / pointers(const char *, Shape*...)
When you insert a new element, its value is copied into the container.
If you have a class hierachy that relies on [virtual] functions to get polymorphic behavior, do not store objects directly in a 
container. INSTEAD store a pointer For example: </br>
std::vector<Shape *> vps; </br>
or </br>
std::vector<std::unique_ptr<Share>> vups;

* list </br>
list is a doubly-linked list. </br>
[Insertion] and [deletion] without moving other elements. </br>

*** Unless you have a reason not to , use a vector. A vector performs better for traversal and for sorting and searching.

* map </br>
A search tree(a red-black tree) . </br>
lookup is O(logn).

* unordered_map </br>
A hash function is often provided as a [function object]. </br>

# Advice
* User vector as default container. 
* A map is implemented as a red-black tree.
* An unordered_map is a hash table.
* Pass a container by reference and return a container by value.
* A list is relatively expensive to traverse.
