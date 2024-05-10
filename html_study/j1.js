// var AlgorithmExercises = '我的手机号是13349983066'
// var a = AlgorithmExercises.match(/\d{11}/g)
// var b = AlgorithmExercises.replace(/(\d{3})\d{4}(\d{4})/g,'$1****$2')
// console.log(b)
// var c = 'hello'
// var d = c.search(/l/)
// console.log(d)
// slice切片 split切分 substr去掉空格 parseInt转化为整数
// var a = 'yuan'
// var b = a
// a = 'p'

// console.log(a)
// console.log(b)
// a++自增1 变量被使用后自加1
// ++a变量被使用前自加1
if(pass){pass}else{pass}
// switch语句

switch(pass){
    case(pass):
        pass
        break;
    case(pass):
        pass
        break;
    default://相当于else
        pass
        break;
}
for(var i = 0;i < 10;i++){
    console.log(i)
}
var person = {
        'name' : 'mzy'
}
console.log(person['age'])
var x = this;//this表示窗口对象
// JSON.stringify把对象转字符串 JSON.parse把字符串转对象
function a(c,d){
    e = c + d
    return e
// js返回值不能返回多个
}
var foo = function(){
    console.log('这是js的匿名函数')
}
foo()//调用匿名函数
(function (x,y){
    console.log(x+y);})(2,3)

function bar() {
    return function(){
        console.log('inner函数')
    }
}
bar()()
// bom对象
//window是js中最大的一个对象
var tag = document.getElementById('d1');
console.log(tag)

onclick //添加点击时间
document.getElementById
function Myfunction(){
        return this;
}//出现在函数内部表示函数的调用者 出现在对象内部表示对象 标签当中表示绑定的标签
 window.xx//定义全局变量
//变量提升 当使用一个未定义的变量的 默认提前定义一个 let定义变量不会进行变量提升  eval将字符串中的代码识别出来并运行  eval加密 使用eval反爬 eval实现数据加密
var fn = function(){};
var fn = () => {}
var fn = () => {let num = 10}
var fn = name => {}