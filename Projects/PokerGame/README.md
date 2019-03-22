# 斗地主游戏 main.cpp 实现
设想你在打扑克牌“斗地主”。现在，上家刚刚出完牌。给定你当前手中的牌和上家刚刚出的牌，请尝试判断能否用手中的牌压过对方的牌。如果可以，输出最小的能压过对方牌型的一组牌。为了简化问题，本问题不考虑花色。  
斗地主规则: [维基百科-斗地主](https://zh.wikipedia.org/zh-hans/%E9%AC%A5%E5%9C%B0%E4%B8%BB)
## 特殊规则说明
* 本实现不考虑三及以上飞机（如777888999，345777888999，334455777888999）的应对方式，一律视为只能以炸弹应对，也就是只能用炸弹炸掉三及以上飞机
* 本实现不考虑下一轮的可能性，只以当前轮的胜利为主  
## 输入输出格式及样例
输入第一行两个数字，以空格相隔，第一个数字表示我方牌数，第二个数字表示我方需要应对的牌数  
第二行为我方牌，从大到小排列，并用空格隔开  
第三行为对方牌，从大到小排列，并用空格隔开  
第四行为输出，用空格相隔
* 特殊输入格式说明
  ```
  三代一：3 5 5 5  
  三代二：3 3 5 5 5
  四代二：6 7 4 4 4 4
  无机翼飞机：7 7 7 6 6 6
  单机翼飞机：3 6 6 6 5 5 5 4
  双机翼飞机：3 3 6 6 6 5 5 5 4 4
  其他机翼飞机以机身开头
  ```
* 示例
```
16 6
JOKER 2 2 A Q Q Q J J 10 10 9 8 8 4 4
5 5 4 4 3 3
Q Q J J 10 10
```  
```
8 2
JOKER 2 2 A Q 9 8 8
A A
2 2
```
```
19 4
JOKER joker 2 2 K K K K J 10 9 9 9 9 8 7 7 4 4
3 5 5 5
4 9 9 9
```
## 实现方式说明  
* main.cpp: 控制命令行接受输入输出并将其提供给相应函数输出计算结果  
* Class PokerAnalysis：接收当前牌并判断牌的类型（单牌，双牌，三带一等），保存在PokerNature内  
* Class MyPoker：根据上述类所判断的结果结合当前手中的牌采用相应的策略选择打出最小能压死对方的牌  
# 斗地主游戏 shuffle_and_deal.cpp 实现  
模拟一个简易的牌局，输入一个随机数种子产生3手牌，分别对应地主和两个农民的牌，并且在尽量不出单牌的情况下循环出牌，直到某一人出牌结束  
* 输入及输出样例展示（完整牌局）  
```
输入（种子）：
5
输出：
Current Lap
Lord: JOKER 2 2 A A Q Q J J 10 10 10 9 9 8 7 6 6 5 5
Farmer1: A A K K Q Q J 10 9 8 8 8 7 5 4 4 3
Farmer2: joker 2 2 K K J 9 7 7 6 6 5 4 4 3 3 3

Lord out: 5 5
Lord remain: JOKER 2 2 A A Q Q J J 10 10 10 9 9 8 7 6 6

Farmer No.1 out: 8 8
Farmer No.1 remain: A A K K Q Q J 10 9 8 7 5 4 4 3

Farmer No.2 out: K K
Farmer No.2 remain: joker 2 2 J 9 7 7 6 6 5 4 4 3 3 3

Lord out: A A
Lord remain: JOKER 2 2 Q Q J J 10 10 10 9 9 8 7 6 6

Farmer No.1 pass

Farmer No.2 out: 2 2
Farmer No.2 remain: joker J 9 7 7 6 6 5 4 4 3 3 3

Lord pass

Farmer No.1 pass

Farmer No.2 out: 3 3
Farmer No.2 remain: joker J 9 7 7 6 6 5 4 4 3

Lord out: 6 6
Lord remain: JOKER 2 2 Q Q J J 10 10 10 9 9 8 7

Farmer No.1 out: Q Q
Farmer No.1 remain: A A K K J 10 9 8 7 5 4 4 3

Farmer No.2 pass

Lord out: 2 2
Lord remain: JOKER Q Q J J 10 10 10 9 9 8 7

Farmer No.1 pass

Farmer No.2 pass

Lord out: 9 9
Lord remain: JOKER Q Q J J 10 10 10 8 7

Farmer No.1 out: K K
Farmer No.1 remain: A A J 10 9 8 7 5 4 4 3

Farmer No.2 pass

Lord pass

Farmer No.1 out: 4 4
Farmer No.1 remain: A A J 10 9 8 7 5 3

Farmer No.2 out: 6 6
Farmer No.2 remain: joker J 9 7 7 5 4 4 3

Lord out: 10 10
Lord remain: JOKER Q Q J J 10 8 7

Farmer No.1 out: A A
Farmer No.1 remain: J 10 9 8 7 5 3

Farmer No.2 pass

Lord pass

Farmer No.1 out: 7 8 9 10 J
Farmer No.1 remain: 5 3

Farmer No.2 pass

Lord pass

Farmer No.1 out: 3
Farmer No.1 remain: 5

Farmer No.2 out: 4
Farmer No.2 remain: joker J 9 7 7 5 4 3

Lord out: 7
Lord remain: JOKER Q Q J J 10 8

Farmer No.1 pass

Farmer No.2 out: 9
Farmer No.2 remain: joker J 7 7 5 4 3

Lord out: 10
Lord remain: JOKER Q Q J J 8

Farmer No.1 pass

Farmer No.2 out: J
Farmer No.2 remain: joker 7 7 5 4 3

Lord out: Q
Lord remain: JOKER Q J J 8

Farmer No.1 pass

Farmer No.2 out: joker
Farmer No.2 remain: 7 7 5 4 3

Lord out: JOKER
Lord remain: Q J J 8

Farmer No.1 pass

Farmer No.2 pass

Lord out: J J
Lord remain: Q 8

Farmer No.1 pass

Farmer No.2 pass

Lord out: 8
Lord remain: Q

Farmer No.1 pass

Farmer No.2 pass

Lord out: Q
Lord remain:
Lord Win!!!!!!!!!!
```
