YAHOO.util.Event.onDOMReady(function(){YAHOO.util.Dom.getElementsByClassName("asset-image-multiple","div","pagebody",function(b){var a;YAHOO.util.Dom.getElementsByClassName("asset-image-large","div",b,function(c){a=c});YAHOO.util.Dom.getElementsByClassName("asset-thumbnail","li",b,function(c){YAHOO.util.Event.addListener(c,"click",function(f){YAHOO.util.Event.stopEvent(f);var d=c.getAttribute("tp:largeuri");var e=c.getAttribute("tp:fulluri");a.innerHTML='<a href="'+e+'"><img src="'+d+'" /></a>';YAHOO.util.Dom.getElementsByClassName("asset-thumbnail","li",b,function(g){YAHOO.util.Dom.removeClass(g,"on")});YAHOO.util.Dom.addClass(c,"on")})})})});