	struct Data
	{
            int i;
	    float j;
	};
  
        std::list<Data*> list_;
	Data* pData = new Data();
	pData->i = 3;
	pData->j = 4.4;
	list_.push_back(pData);

	list_.remove(pData);



	for (int i = 0; i < 10; i++)
	{
		Data* pData = new Data();
		pData->i = i;
		pData->j = 1.1 + i;
		list_.push_back(pData);
	}

	/** iterator 删除是有问题的。 修改如下OK */
	for (auto it = list_.begin(); it != list_.end();)
	{
		Data* pData = *it;
		it++;

		if (pData->i == 1 || pData->i == 5)
		{
			list_.remove(pData);
		}
	}

	for (std::list<Data*>::iterator it = list_.begin(); it != list_.end(); it++)
	{
		pData = *it;
		printf("it -> i = %d\t", pData->i);
	}
