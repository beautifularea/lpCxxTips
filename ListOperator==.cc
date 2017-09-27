
struct Data
{
	int i;
	float j;

	int this_is_test()
	{
		return 1;
	}

  /** 以实例的方式放到list中，需要重载== 运算符。 */
	bool operator==(const Data& d)
	{
		if (d.i == this->i && this->j == d.j)
			return true;

		return false;
	}
};


	std::list<Data> dlist;

	Data d1;
	d1.i = 1;

	Data d2;
	d2.i = 2;

	dlist.push_back(d1);

	dlist.remove(d1);
  
  
