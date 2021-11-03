function addcssinHead(elm){
	let x=document.getElementsByTagName("head")[0];
	x.innerHTML+=`<style>${elm}</style>`;
}

var newStyle=`
		.don1{
			color:yellow;
		}
		.don2{
			color:yellow;
		}
		.don3{
			color:yellow;
		}
		.don4{
			color:yellow;
		}
		.don5{
			color:yellow;
		}
		.don{
			color:yellow !important;
		}
`



addcssinHead(newStyle);