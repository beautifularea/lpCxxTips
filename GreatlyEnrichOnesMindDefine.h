/**
看下面代码，如果 #define XXX 2, 定义在别处，调用Add方法，怎么看怎么别扭，就因为#define的时候多写了一个,
*/
const int ww = 1;
#define XXX 2,
Add(XXX ww);

类似的/*诡异*/用法还有很多。
