# umtsm-examples-c
The examples of Generating State Machines

**UMTSM** is a UML-based, proprietary state machine definition tool. It enables source code generation across multiple programming languages and frameworks by creating a model from state machines defined using its unique notation.

This project contains simple **C programming language** examples defined and generated using **UMTSM**. Each example resides within its own directory, with some expanded examples presenting distinct states within nested directories as individual "cases."

Each example typically consists of two main directories. The "src" directory holds manually written code, with the 'src/main' folder defining the main function for C, responsible for constructing and executing the state machines. Other sub-directories within ‘src’ contain the state machine definitions (stored in files with the .umt extension) and any function files required by the state machines, which are to be supplied by the developer.

The 'generated' folder houses code generated by **UMTSM** and the '**CGen**' C language code generator. The generated/src directory includes generated state machine code, while generated/test provides C++ files necessary for test cases written in gTest/gMock, also produced by CGen.

CMake files required for compiling the state machines are generated by **UMTSM** and **CGen**. These CMake files include dependencies among the state machines and external libraries, managed with the help of CmakeExtras.cmake files.

The sample applications provided with the project include:

* 01-paroot : Solve parabolic equations
  * case-0 : A classical example before introducing State Machines
  * case-1
  * case-2
* 02-numberguess : Play the game guessing the number between 1 and 99
  * case-1
  * case-2
  * case-3
* 03-keypress : Counting and sorting the keys pressed
* 04-calculator : A simple calculator for four operations
* 05-crossrood : Managing a four lane junction with pedestrian lane in controlled and uncontrolled mode
