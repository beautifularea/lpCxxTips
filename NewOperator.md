***operator new*** can be called explicitly as a regular function, 
but in C++, new is an operator with a very specific behavior: An expression with the ***new operator***,
first calls function operator new (i.e., this function) with the size of its type specifier as first argument,
and if this is successful, it then automatically initializes or constructs the object (if needed). 
Finally, the expression evaluates as a pointer to the appropriate type.

new operator：指我们在C++里通常用到的关键字，比如A* a = new A; </br>
operator new：它是一个操作符，并且可被重载(类似加减乘除的操作符重载)
