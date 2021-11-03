// ==UserScript==
// @name         Codeforces dark theme
// @version      1.0.6
// @description  dark theme for codeforces
// @author       Gaurang Tandon
// @match        https://codeforces.com/*
// @match        http://codeforces.com/*
// @match        https://calendar.google.com/calendar/embed*
// @match        https://www.facebook.com/v2.8/plugins/like.php*
// @resource     desertCSS  desert.css
// @resource     monokaiEditorTheme https://raw.githubusercontent.com/ajaxorg/ace/master/lib/ace/theme/monokai.css
// @resource     darkthemecss darktheme.css
// @grant        GM_addStyle
// @grant        GM_getResourceText
// @grant        GM_setValue
// @grant        GM_getValue
// @run-at       document-start
// ==/UserScript==

let problemPageFontSize="1.8em";
let arr=location.pathname.split('/'),n=arr.length;

function submitPage(){
    document.addEventListener('keydown', function (event) {
        if (event.key === 's') {
            document.querySelector('input[value="Submit"]').click();
        }
    });

    document.querySelector('select[name="submittedProblemIndex"]').value=GM_getValue('pid','A');
    window.scroll(0,172);
    navigator.clipboard.readText().then(clipText =>
        document.getElementById("sourceCodeTextarea").value=clipText);
}

function problemStatementPage(){
    document.querySelector('.problem-statement').style.fontSize=problemPageFontSize;
    GM_setValue('pid',arr[n-1]);
    window.scroll(0,172);
    document.addEventListener('keydown', function (event) {
        if (event.key === 's') {
            if(arr[1]=="contest"){
                window.open(`/contest/${arr[2]}/submit`);
            } else {
                window.open("/problemset/submit");
            }
        }
    });

}

function CfMod(){
    window.addEventListener('load',function(){
        if(arr[n-1]=="submit"){
            submitPage();
        } else {
            problemStatementPage();
        }
    });
}

CfMod();
