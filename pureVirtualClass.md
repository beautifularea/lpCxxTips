class Interface {
public:
	virtual void run() = 0;
	virtual void tearDown() = 0;
};

//要想实例化TestCase, 必须实现接口中的纯虚函数
class TestCase : public Interface {
public:
	void run() {}
	void tearDown() {}
};
