// 全局变量
//用户登入的密码
//rsa加密（保护得更好）
let bb = (function() {
    let key_b = 'abcdef'

    function fn() {
        console.log('bb写的加密程序，使用的密钥是', key_b);
    }
    return fn
})()