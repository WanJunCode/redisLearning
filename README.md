# redisLearning



阅读Redis的数据结构部分

2020/3/6
sds.h  动态字符串
adlist.h 双向链表

2020/3/8
dict.h  字典
字典的操作都是计算获得hash值，再到哈希表0中查找，如果当前正在执行rehash还会到哈希表1中进行查找

2020/3/9 完成dict.c阅读
server.h t_zset.c 跳跃表部分

2020/3/12 完成跳跃表，插入，删除操作

hyperloglog.c  理论学习

2020/3/14 完成hyperloglog.c 部分

熟悉Redis的内存编码结构 
+ 整数集合数据结构 intset.h和intset.c 
+ 压缩列表数据结构 ziplist.h和ziplist.c

完成intset.c
占用极少内存的 数值集合 类型

2020/3/15
ziplist  压缩列表  快速列表 存储string和int，支持push和pop操作
完成 ziplist.c

第三阶段 熟悉Redis数据类型的实现
对象系统 object.c
字符串键 t_string.c
列表建 t_list.c
散列键 t_hash.c
集合键 t_set.c
有序集合键 t_zset.c中除 zsl 开头的函数之外的所有函数
HyperLogLog键 hyperloglog.c中所有以pf开头的函数

object.c  完成 robj
对于string对象，编码方式有三种：raw embstr int (其中encode方式是raw embstr，decode方式是int)

2020/3/22 完成quicklist.c