// ==UserScript==
// @name         HideKissanimeAdds
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  LoadAdds->Click Hide(Auto)
// @author       Tasnim Ferdous
// @match        https://kissanime.ru/*
// @match        http://kissanime.ru/*
// @match        http://kissanime.ru/Anime/*
// @run-at       document-start
// @grant        remove
// ==/UserScript==


function doWork(){
    var x=document.getElementsByClassName("divCloseBut");
    for(var i=0;i<x.length;i++){
        x[i].getElementsByTagName("a")[0].onclick();
    }
}

function cleanclutter(){
    for(var i=0;i<=20;i++){
        if(document.getElementById("adsIfrme"+i)!=null){
            document.getElementById("adsIfrme"+i).remove();
        }
    }
}
window.addEventListener('load', function() {
    'use strict';
    document.getElementsByClassName("glx-close")[0].click();
    for(var i=0;i<=10000;i+=500){
        setTimeout(function() {
            cleanclutter();
            doWork();
        }, i);
    }

}, false);

