class Test
{
	virtual void a() {}
	virtual void b() {}
};

class TA : public Test
{
	virtual void c() {}
};

TA ta;
int** vtable = (int**)&ta;
Fun f;
f = (Fun)vtable[0][0];
f();
f = (Fun)vtable[0][1];
f();
f = (Fun)vtable[0][2];
f();

//详细可参考：http://blog.csdn.net/fdsafwagdagadg6576/article/details/51692142
