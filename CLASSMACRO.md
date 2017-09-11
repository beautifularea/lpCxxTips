Base.h
#ifdef MANAGER
#undef MANAGER
#endif
#define MANAGER Base

class Base
{
public:
	virtual void test()
	{}
};

Derived.h
#ifdef MANAGER
#undef MANAGER
#endif
#define MANAGER Derived

class Derived : public Base
{
public:
	void test()
	{}
};

Demo.cpp
int main(int argc, char const *argv[])
{
	MANAGER->test();
	return 0;
}
