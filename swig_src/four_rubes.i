/* four_rubes.i */
%module four_rubes

%include "std_string.i"
%include "exception.i" 

%{
    #include "four_rubes.h"
%}

%allowexception; 
%exception {
    try {
        $action
    } catch (InputError) {
        SWIG_exception(SWIG_ValueError, "Input is error!");
    }
}
 
extern int calculate(std::string ion);

