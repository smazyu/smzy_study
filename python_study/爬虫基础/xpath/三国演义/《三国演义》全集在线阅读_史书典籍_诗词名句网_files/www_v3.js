if(device.mobile()){
    var u = window.location.href;
    u = u.replace(/:\/\/www./g,"://m.")
    if(window.location.href!==u){
        window.location = u;
    }
}

var fixBoxTop = 0;
var cate = 'all';
var COOKIES_KEY_KW = 'key_kw';
//设置cookie
function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + cvalue + "; " + expires+"; path=/;";
}
//获取cookie
function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) return c.substring(name.length, c.length);
    }
    return "";
}
function toRed(kw, word) {

    var arr = kw.split(" ");

    for(var i in arr){
        var k = arr[i];
        if(k==='')continue;
        word =  word.replace(new RegExp(k,"g"),'<em>'+k+'</em>');
    }
    return word;
}
function filter_show_more() {
    var idF =  $("#filter_show_more");
    var val =idF.html();
    if(val === '展开'){
        idF.html('收起');
        $(".filter-hide").show();
    }else{
        idF.html('展开');
        $(".filter-hide").hide();
    }
}
function toTop() {
    $('html,body').animate({scrollTop:0}, 300);
}
function doSearch() {
    var kw_url = encodeURI($("#search_input").val());
    if(!kw_url)return;
    var u = '';
    if(cate === 'book'){
        u = '/book/chaxun/?kw='+kw_url;
    }else if(cate === 'chengyu'){
        u = '/chengyu/chaxun?kw='+kw_url;
    }else{
        if(cate === 'first' || cate === 'end'){
            u = '/chaxun/shiju/'+cate+'/'+kw_url;
        }else if(cate === 'title'){
            u = '/chaxun/shici/'+kw_url;
        }else if(cate ==='zuozhe'){
            u = '/chaxun/zuozhe_list/'+kw_url;
        }else{
            u = '/chaxun/'+cate+'/'+kw_url;
        }
    }
    window.location = u;
}

var searchIndex = -1;
var maxIndex = 0;
var isEnterSearchResult = false;

$(document).ready(function () {
    //搜索框
    var idSearchInput = $("#search_input");
    var idTipResultUl = $("#tip_result ul");
    var idTipResult = $("#tip_result");
    var idTipContent = $("#tip_content");
    function hideResult(){
        idTipResult.hide()
    }
    function searchIndexMinus(){
        searchIndex--;
        if(searchIndex<0)searchIndex = maxIndex;
        refreshSearchIndexUi();
    }

    function searchIndexAdd(){
        searchIndex++;
        if(searchIndex>maxIndex)searchIndex=0;
        refreshSearchIndexUi();
    }


    function listen() {
        $('#tip_result ul li a').hover(function () {
            var me = this;
            $('#tip_result ul li a').each(function (index,e) {
                if(e === me){
                    if(searchIndex === index){
                        return;
                    }
                    searchIndex = index;
                    refreshSearchIndexUi();
                    return;
                }
            });
        },function () {

        });
    }
    function refreshSearchIndexUi(){
        isEnterSearchResult = true;
        var hh = undefined;
        $("#tip_result ul li a").each(function (index,e) {
            if(index === searchIndex){
                $(this).addClass('search_tip_current');
                hh = this;
            }else{
                $(this).removeClass('search_tip_current');
            }
        });
        if($(hh).attr("data-scid")){
            var scid = $(hh).attr("data-scid");
            idTipContent.show();
            idTipContent.html('加载中...');
            idTipContent.css("top",$(hh).position().top+"px");
            var subAjaxScid = scid;
            var sj = $(hh).attr("data-sj");
            $.ajax({
                method:'GET',
                url:'/webApi/itemContent?scid='+scid,
                cache:true,
                success:function (res){

                    if(subAjaxScid !== scid)return;
                    if(res!==undefined && res!==''){
                        var content = res.content;

                        if(sj){
                            content = toRed(sj,content);
                        }
                        idTipContent.html(content);
                    }
                }
            });
        }else if($(hh).attr('data-jieshi')){
            idTipContent.show();
            idTipContent.css("top",$(hh).position().top+"px");
            var jieshi = $(hh).attr("data-jieshi");
            if(jieshi){
                idTipContent.html(jieshi);
            }
        }else{
            idTipContent.hide();
        }

    }



    function init(){
        cate = getCookie("key_cate");
        if(!cate){
            cate = "all";
        }
        $('#top_right_nav ul li a').each(function (e) {
            var c = $(this).attr('data-cate');
            if(c === cate){
                $(this).addClass('cate_selected');
            }
        });

        var k = getCookie(COOKIES_KEY_KW);
        if(k){
            idSearchInput.val(k);
        }
    }
    init();
    $('#top_right_nav ul li a').on('click',function () {
        $('#top_right_nav ul li a').removeClass('cate_selected');
        $(this).addClass('cate_selected');
        cate = $(this).attr('data-cate');
        setCookie("key_cate",cate,100);
    });
    idTipResult.hover(function () {
        isEnterSearchResult = true;
    },function () {
        isEnterSearchResult = false;
        idSearchInput.focus();
    });
    idSearchInput.blur(function () {
        if(!isEnterSearchResult){
            hideResult();
        }
    });
    $(window).scroll(function () {

        //窗口滚动高度
        var topScroll = $(window).scrollTop();

        if(topScroll>100){
            $("#toTop").show();
        }else{
            $("#toTop").hide();
        }



        //右侧固定
        var fixBox = $("#fixBox");
        if(fixBox&&fixBox.position()){
            if(fixBoxTop === 0){
                fixBoxTop = fixBox.position().top;
            }
            if(topScroll>fixBoxTop){
                fixBox.css({position:"fixed",top:"60px"});
            }else {
                fixBox.css({position:"static",top:"0px"});
            }
        }

        if($("#flag")&&$("#flag").position()){
            var h = $("#flag").position().top-document.documentElement.clientHeight;
            if(topScroll>=h){
                $("#list_nav").css("position","static");
            }else{
                $("#list_nav").css("position","fixed");
            }
        }
    });

    idSearchInput.on('input focus',function(e){
        var kw = $(this).val();
        if(kw===undefined)kw = '';
        setCookie(COOKIES_KEY_KW,kw,3);
        var kw_url = encodeURI(kw);
        if(kw.length>0){
            $.ajax({
                method:'POST',
                data:{
                    kw:kw,
                    cate:cate,
                    from:"web"
                },
                url:'/app_api/searchTips',
                success:function (res) {
                    var html = "";
                    var preCate = '';
                    if(res.length===0){
                        idTipResult.hide();
                        return;
                    }
                    for(var v in res){
                        var item = res[v];
                        var c = item.cate;
                        if(preCate!==''&&preCate!==c){
                            html+='<li class="li_line"></li>';
                        }
                        if(c === 'shici'){
                            html+='<li><a href="/chaxun/list/'+item.scid+'.html" data-scid="'+item.scid+'">《'+toRed(kw,item.title)+'》<span>['+item.niandai+']'+item.zuozhe+'</span></a></li>';
                        }else if(c === 'shiju'){
                            html+='<li><a href="/chaxun/list/'+item.scid+'.html" data-scid="'+item.scid+'" data-sj="'+item.shiju+'">'+toRed(kw,item.shiju)+'<span>['+item.niandai+']'+item.zuozhe+'《'+item.title+'》</span></a></li>';
                        }else if(c === 'zuozhe'){
                            html+='<li><a href="/chaxun/zuozhe/'+item.id+'.html">'+toRed(kw,item.title)+'<span>['+item.niandai+'] '+item.num+'首</span></a> </li>';
                        }else if(c === 'hc'){
                            html +='<li><a href="/hecheng/'+item.id+'.html">'+toRed(kw,item.title)+'</a></li>';
                        }else if(c === 'mark'){
                            html +='<li><a href="/shicimark/'+item.urlname+'.html">'+toRed(kw,item.title)+'</a></li>';
                        }else if(c === 'book_name'){
                            html += '<li><a href="/book/'+item.urlname+'.html">《'+toRed(kw,item.title)+'》<span>'+item.info+'</span></a> </li>';
                        }else if(c === 'book_chapter'){
                            html += '<li><a href="/book/chaxun/?kw='+kw_url+'&book_id='+item.id+'">《'+item.title+'》<span>'+item.info+'</span></a></li>';

                        }else if(c === 'chengyu'){
                            html += '<li><a href="/chengyu/'+item.py+'-'+item.id+'.html" data-jieshi="'+item.jieshi+'">'+toRed(kw,item.name)+'<span>['+item.pinyin+']</span></a></li>';
                        }
                        preCate = c;
                    }


                    html = '<ul>'+html+'</ul>';
                    searchIndex = -1;
                    maxIndex = res.length-1;
                    idTipResultUl.html(html);
                    idTipResult.show();
                    idTipContent.hide();
                    listen();
                }

            });
        }

    });
    idSearchInput.keydown(function (e) {
        if(e.keyCode === 38){
            searchIndexMinus();
        }else if(e.keyCode === 40){
            searchIndexAdd();
        }else if(e.keyCode === 27){
            hideResult();
        }else if(e.keyCode === 13){
            if(searchIndex!==-1){
                var url = $("#tip_result ul li a:eq("+searchIndex+")").attr('href');
                if(url){
                    window.location = url;
                }
            }else{
                doSearch();
            }
        }
    });






    $(".shici_content .show_more_shici").on('click',function () {
        $(this).next().show();
        $(this).hide();
        $(this).next().next().show();
    });
    $(".shici_content .hide_more_shici").on('click',function () {
        $(this).prev().hide();
        $(this).hide();
        $(this).prev().prev().show();
    });

    $("#show_all_nav").on('click',function () {

        $("#list_nav_part").hide();
        $("#list_nav_all").show();
        $("#list_nav_title").show();
    });
    $("#hide_all_nav").on('click',function () {
        $("#list_nav_part").show();
        $("#list_nav_all").hide();
        $("#list_nav_title").hide();
    });


    //章节页面高亮

    if(/\/book\/[a-zA-Z0-9]+\/[0-9]+\.html/.test(location.pathname)){
        if(/^\?kw=[^&]+$/.test(location.search)){
            var kw = decodeURI(location.search).replace('?kw=','');

            var kwArr = kw.split(" ");

            var content = $(".chapter_content").html();
            if(kw.length>0){

                for(var i in kwArr){
                    var reg = new RegExp(kwArr[i],'g');
                    content = content.replace(reg,'<span class="highlight">'+kwArr[i]+'</span>');
                }
                $(".chapter_content").html(content);

                var first = $('.highlight:first');
                if(first.length){


                    var ch = $(first).position().top-100;
                    $('html,body').animate({scrollTop:ch}, 300);
                }
            }
        }
    }


    $(".book-chaxun-more").on('click',function () {

        if($(this).html() === '收起'){
            $(this).html("展开");
            $(this).parent().next().hide();
        }else{
            $(this).html("收起");
            $(this).parent().next().show();
        }

    });
});