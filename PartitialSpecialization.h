/**
特化/偏特化
（函数模板不能偏特化）
*/
//类模板
template <typename T1, typename T2>
class Base
{};

//特化
template <int, int>
class Base
{};

//偏特化
template <typename T1, int>
class Base
{};
