Mathbot For Hipchat ![Build Status](https://travis-ci.org/hanks/Mathbot_for_hipchat.svg?branch=master) ![Coverage Status](https://img.shields.io/coveralls/hanks/Mathbot_for_hipchat.svg) 
===================

A demo chatbot to do simple four operation rubes math.

## Why
Recently, I was developing a DevOps chatbot for team, easily speaking, you can send messages to chatbot in the Hipchat to do some deployment, migrate db, supervisord tasks and so on. It may be useful when you are outside with just taking your phone and some emergencies happen. And also, I added some funny features like let chatbot to tell a joke and etc.

Here is just an another simple demo to show how to use chatbot to do math.

## Demo
![demo](https://raw.githubusercontent.com/hanks/Mathbot_for_hipchat/master/demo/demo.gif "demo")  

* **calculate** is a command.  
* **@hanks** is a trigger to tell chatbot to do some commands.  
* **And I just add some easy input checks and only support string with no spaces**
  
## Implementation  
1. [Err chatbot framework](http://errbot.net/)  
    Err is a GPL3-licensed chat bot for XMPP and IRC networks, designed to be easily deployable, extensible and maintainable. Its goal is to make it easy for you to write your own plugins so you can make it do whatever you want.
    
2. [SWIG](http://www.swig.org/)  
    SWIG is an interface compiler that connects programs written in C and C++ with scripting languages such as Perl, Python, Ruby, and Tcl. It works by taking the declarations found in C/C++ header files and using them to generate the wrapper code that scripting languages need to access the underlying C/C++ code. In addition, SWIG provides a variety of customization features that let you tailor the wrapping process to suit your application.   
    
    I use SWIG to compile C++ code to dynamic library that used in python code.
    
3. A simple infix expression to reverse polish notation algorithm written by C++.  
4. Unit test and coverage test.

## Special Note  
I finally know where the icon ![Build Status](https://travis-ci.org/hanks/Mathbot_for_hipchat.svg?branch=master) is from!! It is from [Travis CI](https://travis-ci.org/), a free continuous integration service.  
   
Travis CI is very easy to use, that can let you do unit test in different envrionments at the same time with just modifing some configuration parameters. **Amazing!!**  

And also you can try [Coveralls](https://coveralls.io/), a free coverage test report service that can integrated with Travis CI and Github, and then you can get this icon ![Coverage Status](https://img.shields.io/coveralls/hanks/Mathbot_for_hipchat.svg) 
