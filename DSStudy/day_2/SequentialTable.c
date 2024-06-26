#if 0 
//异或，相同为0，相异为1
//遇到不会的题，先思考几个小时，如果没有好好思路，去看看别人的代码
//和思路，理解以后。后面不看他的，再去自己实现一下，这样才能提高
//顺序表
//1.可动态增长的数组
//2.数据在数组中存储时必须是连续的
//
//缺点:
//1.中间或头部的插入删除很慢，需要挪动数据。时间复杂度o(n)
//2，空间不够时，增容会有一定消耗和空间浪费
//优点；
//1.随机访问。
//2.缓存利用率比较高。(相较于链式结构) (本质是物理空间连续)，预加载就有了优势

//cpu
//三级缓存 寄存器
//L1
//L2
//L3
//一般速度越慢，空间越大
//取一个数据 是拿地址在缓存中取，如果缓存中没有，则从内存中拿数据到缓存中 如果缓存中有，则叫命中
//缓存访问一个数据时，会预加载，不是加载一个数据，而是这个数据所在地址的一段数据
#endif