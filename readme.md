## 1.玩法介绍<br> 
## 2.具体实现<br> 
## 3.墙模块<br> 
3.1 二维数组维护 游戏内容<br> 
3.2 初始化二维数据，initwall<br> 
3.3 画出墙壁 drawwall<br> 
3.4 提供对外接口setwall getwall<br> 
3.5 测试<br> 
## 4.蛇模块<br> 
4.1 初始化蛇<br> 
4.2 销毁所有节点<br> 
4.3 添加新节点<br> 
## 5.食物模块<br> 
5.1 foodX， foodY位置<br> 
5.2 setFood对外接口， 可以设置食物<br> 
5.3  随机出两个可以防止的位置<br> 
## 6.删除节点和移动蛇的封装<br> 
6.1 删除节点，通过两个临时指针，删除尾节点<br> 
6.2 移动，判断用户输入内容，进行移动操作<br> 
## 7.接受用户输入<br> 
7.1 接受一个字符，蛇移动一步<br> 
7.2 用户输入按键后，进行自动移动<br> 
## 8.解决bug	<br> 
8.1 按键冲突<br> 
8.2 180不可以转<br> 
8.3 死亡撞墙，多走一步<br> 
8.4 循环追尾，不要进入死亡<br> 
## 9.加大难度<br> 
9.1 根据蛇的身长设置移动速度<br> 
9.2 获取蛇的身段<br> 
## 10.刷屏问题<br> 
不再采用system(cls)和drawwall,而是移动光标，将原始文件中的每个setwall后面都要加上光标移动代码<br> 
## 11.改用STL(list)<br> 
 list<pair<int,int>> lSnake; or  vecto<br> 
## 12.改用STL(vector)<br> 
 vector的尾部代表蛇的头部，用vector的作用就是不用使用双指针，不用用while循环等一些复杂操作进行遍历这里使用的是vector的引用front和back而不是迭代器指针begin()和end()
