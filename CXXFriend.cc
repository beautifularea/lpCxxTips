
class B;
class A
{
public:
	friend class B;

public:
	friend void friend_function(A* a) //friend function of A
	{
		a->private_function();
	}
private:
	void private_function()
	{
		printf("This is A private function\n");
	}
};

class B
{
public:
	void this_is_b_private_function(A* a)
	{
		printf("This is b private function.\n");
		a->private_function();
	}
};

int main()
{
	A* a = new A();
	friend_function(a);

	B* b = new B();
	b->this_is_b_private_function(a);

  return 0;
}
