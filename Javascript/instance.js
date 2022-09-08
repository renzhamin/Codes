function Apple(x,color){
	this.x=x;
	this.color=color;
}

Apple.prototype = {
	sleep:function(){
		return "I can't fall asleep";
	}
}

var a=new Apple(1,"red");
var b=new Apple(2,"green");
var c=new Apple(3,"blue");

console.log(b);