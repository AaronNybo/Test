# String Library Part 1

C++ has two common ways to represent strings, the string class or a char buffer (commonly called c-strings).  The string class actually stores strings using a char buffer but takes care of all of the underlying memory management.  It also provides several methods for working with and manipulating strings.  We will be creating are own string class StaticString. To avoid issues of dynamically allocated memory, StaticString will use a fixed-size character array of 64 bytes. The last byte of the string should always by the null character '\0' so the maximum number of actual characters that can be stored in StaticString is 63.  When implementing the String class you are **not allowed** to use the string header file, cstring header file or C++ strings.

## Goals:
The purpose of this project is to review topics covered in CS 1410 and introduce the tools and methodologies we will be using throughout the rest of the semester.

## Requirements:
The StaticString class will store strings in a fixed-size(static) character array.  Like cstrings it will always terminate the string with a null character. This allows you to find the end of the string but it also allows the character array to be used as a normal cstring.  

Starter code is provided and you will need to modify the StaticString.cpp and StaticString.h files.  The StaticString.cpp driver file does not need to be edited and any changes you make to it will be discarded.  However, many students find it useful to add their own test cases or comment out certain sections while developing their code.  This is completely acceptable but remember any changes you make to the StaticString.cpp file will not be used when grading your assignment.

## Suggested library methods:
- tolower
- toupper
- isspace
- out_of_range

## Tips and suggestions:
- Get started early.  Download and install git today.  Clone the repository and build the executable.
- Always get the latest changes before starting any new work.  This will make it easier to merger your changes back.
- Build the executable on both Windows and linux.  Make sure you know how to use the tools.
- Look at the driver file. Just because you will not be making changes to that code, you should still understand what it is doing. The tests are examples of expected results for each of the different methods. If you want to know what concat is supposed to do, look at the input and expected output.
- Read the comments in the header files.  They describe what each method is meant to do.
- Work on one thing at a time and compile and commit early and often.  For example, implement the len method, compile it, test it, commit it.  The more often you compile and test the easier it will be to pinpoint errors. 
- Use the debugger.  When you are getting unexpected results, set a breakpoint and trace exactly what is happening in the code.
- Ask for help.  Use the tutors, canvas dicussion boards and me.  Be detailed and descriptive of what problem you are having and how you have tried to solve it. When you ask me for help make sure your latest code is in your git repository.