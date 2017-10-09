vs2017, 使用strcpy提示error，应该用strcpy_s函数。</br>
右击工程 - 属性 - 配置属性 - C/C++  - 命令行</br>
命令行增加 /D _CRT_SECURE_NO_WARNINGS</br>
