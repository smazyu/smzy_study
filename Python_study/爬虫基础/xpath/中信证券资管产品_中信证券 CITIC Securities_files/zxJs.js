if($('.butFun').size()>0){
$('.butFun .but').on({'mouseenter':function(){
	$(this).addClass('cur').siblings().removeClass('cur').end().parents('.butParents').find('.showPart').eq($(this).index()).show().siblings('.showPart').hide();
}}).first().mouseenter();
}


if($('#bannerBFun').size()>0){
	~function(){
		$('#bannerBFun ul').append($('#bannerBFun ul').children().clone())
		var _o = $('#bannerBFun ul'),_childSize=_o.children().size(),_timer = null,interval = 6000,_speed=600,_winW = $('#bannerBFun').width(),_step=_winW;
		_o.children().width(_winW);_o.css({'width':_childSize*_step});

		var playGo = function(){
			Math.abs(parseInt(_o.css('left'))) >= (_childSize/2) * _step ? _o.css('left',0) : '';
			_o.stop().animate({'left':parseInt(_o.css('left')) - _step},_speed,'easeInOutCirc');
		};
		playGo();
		_timer = setInterval(playGo,interval);
		$(window).resize(function(){
			clearInterval(_timer);_o.stop(true);
			_winW = $('#bannerBFun').width(),_step=_winW;
			_o.children().css({'width':_winW});_o.css({'width':_childSize*_step,'left':0});
			playGo();
			_timer = setInterval(playGo,interval);
		});
	}()
}




//控制首页-热门推荐模块gif图动效
if($('#navBaFun').size()>0){
	~function(){var _o = $('#navBaFun li'),_opacity=1;
		_o.animate({'opacity':_opacity},'fast').hover(function(){
                         var tempUrl = $(this).find('.tu').attr('dtpic');
                        $(this).find(".tu").css("background","url('"+tempUrl+"') no-repeat center center");
			$(this).stop().animate({'opacity':1},'fast').siblings().removeClass('cur');
		},function(){
                        var tempUrl = $(this).find('.tu').attr('jtpic');
                        $(this).find(".tu").css("background","url('"+tempUrl+"') no-repeat center center");
			$(this).stop().animate({'opacity':_opacity},'fast');
		});
		
	}()
}




if($('#clnlFun').size()>0){
	$('#clnlFun .nodeB').on({
		'click':function(e){e.preventDefault();
			if($(this).next('ul').children().size()>0){
				$(this).toggleClass(function(){$(this).next('ul').toggle();
					return 'open';
				})
			}else{
				window.location.href=$(this).attr('href');
			}
		}
	})
}

if($('#gpFun').size()>0){
	~function(){
		var _count=0,sk=4,_next=$('#gpFun .next'),_o=$('#gpFun ul'),_step=$('#gpFun li').outerWidth(true),_oChildSize=$('#gpFun li').size();
		_o.css({'margin-left':0,'width':_step*_oChildSize});
		var playGo=function(){
			if(_count>=(_oChildSize-sk)){
				_count=0;_o.stop().animate({'margin-left': _count});
			}else{
				_o.stop().animate({'margin-left': parseInt(_o.css('margin-left')) - _step});_count++;
			}
		};
		_next.click(function(){_oChildSize>sk?playGo():'';	});
	}()
}


if($('.animateB').size()>0){
	$('.animateB .ImgB1,.animateB .ImgB2').css('opacity',0);
	function animateBFun(o){
		var _child1 = o.find('.ImgB1'),_child2 = o.find('.ImgB2');
		_child1.animate({'bottom':0,'opacity':1},1000);
		parseInt(_child2.css('right'))<0?_child2.animate({'right':0,'opacity':1},1000):_child2.animate({'left':0,'opacity':1},1000);
		o.addClass('sign');
	}
	animateBFun($('.animateB').first());
	$(window).scroll(function(){
		$('.animateB').each(function(index, el) {
			if( $(window).scrollTop() >=($(this).offset().top - 600)  ){		
				if(!$(this).hasClass('sign')){
					animateBFun($(this));
				}
			}
		});
	})
}