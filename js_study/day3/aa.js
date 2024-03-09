// 局部变量
let aa = (function() {
    let key_a = '123456'
    function fn() {
        console.log('aa写的加密程序，使用的密钥是',key_a);
    }
    //给数据进行加密 -> 反爬做的加密
    //aes多
    return fn
})()