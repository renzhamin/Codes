// ==UserScript==
// @name         KissanimeHalalaiser
// @version      1.0
// @description  HideKissanimeAdds
// @author       Tasnim Ferdous
// @match        https://kissanime.ru/*
// @match        http://kissanime.ru/*
// @grant        GM_addStyle
// ==/UserScript==

var fast=0,clickhideonly=0,blockall=1,hideAddsOnAllPages=0; //set your chosen method to 1

/*
   Note :
   This script does not do anything to pop-ups,so if something like Hydrax/Nova server is your default than there's not much use.
   1.only blockall works on all pages of kissanime as default the rest works for the video-playback page only;
   2.the safest method is clickhideonly;
   3.fast is similar to clickhideonly but much faster and less safer but safer than blockall;

   hideAddsOnAllPages works the same way as blockall,the risk-level is the same,so why does it exist? well,the options there,you can use it or not.

   my suggestion would be:
   If your inernet speed is good(6/7Mbps+) at the time of using kissanime just use clickhideonly;
*/

(function(){

    if(blockall){
        hideframe();
    }
    else if(fast || clickhideonly){
        addhide();
    }

    if(hideAddsOnAllPages && !blockall){
        hideOnAllpages();
    }

})();



function addhide(){
    var url = location.href;
    var server = url.split("&s=");
    if(server.length<=1) {return 0;}

    GM_addStyle('.glx-teaser{display:none !important}');

    if(fast){
        cleanadframe();
    }
    clickHideButton();
}



function hideframe(){
    var url = location.href;
    var server = url.split("&s=");

    GM_addStyle('.glx-teaser{display:none !important}');

    if(server.length==1 || (server.length>1 &&(server[1].startsWith('beta') || server[1].startsWith('def')))){
        GM_addStyle('iframe{display:none !important;}');
    } else {
        return addhide();
        alert("Chose beta server if possible in case video doesn't work");
    }

    if(server.length==1) return;
    window.addEventListener(
        'load',function(){
            document.querySelector(".glx-close").click();
        },false
    )

}

function clickHideButton(){
    window.addEventListener('load', function() {
        if(document.querySelector(".glx-close")){
            document.querySelector(".glx-close").click();;
        }
        for(var i=0;i<5000;i+=100){
            setTimeout(function() {
                clickHide();
            }, i);
        }

    }, false);
}


function hideOnAllpages(){
    var url = location.href;
    var server = url.split("&s=");

    if(server.length==1){
        GM_addStyle('iframe{display:none !important;}');
    }
}

function addcssinHead(elm){
    var x=document.getElementsByTagName("head")[0];
    x.innerHTML+=`<style>${elm}</style>`;
}



function clickHide(){
    var x=document.getElementsByClassName("divCloseBut");
    for(var i=0;i<x.length;i++){
        x[i].getElementsByTagName("a")[0].onclick();
    }
}

function cleanclutter(){
    for(var i=1;i<=20;i++){
        if(document.getElementById("adsIfrme"+i)){
            document.getElementById("adsIfrme"+i).remove();
        }
    }
}

function cleanadframe(){
    for(var i=0;i<500;i+=50){
        setTimeout(function(){cleanclutter();},i);
    }
};w