标准的placement new的使用方法

1）分配内存
char* buff = new char[ sizeof(Foo) * N ];
memset( buff, 0, sizeof(Foo)*N );

2）构建对象
Foo* pfoo = new (buff)Foo;

3）使用对象
pfoo->print();

4）析构对象，显式的调用类的析构函数。
pfoo->~Foo();

5）销毁内存
delete [] buff;
