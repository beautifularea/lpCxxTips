class Interface { </br>
public:</br>
	virtual void run() = 0;</br>
	virtual void tearDown() = 0;</br>
};</br>

//要想实例化TestCase, 必须实现接口中的纯虚函数</br>
class TestCase : public Interface {</br>
public:</br>
	void run() {}</br>
	void tearDown() {}</br>
};</br>
