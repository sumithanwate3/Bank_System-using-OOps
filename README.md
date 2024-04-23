# Bank Management using Object Oriented Programming

## 1. Introduction:
Bank Management System is based on a concept of recording customer’s account details.
Here the user can perform all the tasks like creating an account, deposit amount, withdraw
amount, check balance, view all account holders detail, close an account and modify an
account. There’s no login system for this project. All the main features for banking system are
set in this project.

## 2. OOPs Concepts covered:

### 1. Inline Function:
C++ provides an inline function to reduce the function call overhead. Inline function is a
function that is expanded in line when it is called. When the inline function is called whole
code of the inline function gets inserted or substituted at the point of inline function call. This
substitution is performed by the C++ compiler at compile time. Inline function may increase
efficiency if it is small.

### 2. Inheritance:
Inheritance is a feature or a process in which, new classes are created from the existing
classes. The new class created is called “derived class” or “child class” and the existing class
is known as the “base class” or “parent class”. The derived class now is said to be inherited
from the base class.

### 3. Friend function:
A friend function is a special function in C++ which in-spite of not being member function of
a class has privilege to access private and protected data of a class.
A friend function is a non-member function or ordinary function of a class, which is declared
as a friend using the keyword “friend” inside the class. By declaring a function as a friend, all
the access permissions are given to the function.

### 4. Function Overloading:
Function overloading is a feature of object-oriented programming where two or more
functions can have the same name but different parameters. When a function name is
overloaded with different jobs it is called Function Overloading. In Function Overloading
“Function” name should be the same and the arguments should be different.

### 5. Console I/O operations:
The C++ I/O system contains a hierarchy of classes that are used to define various streams to
deal with both the console and disk files. These classes are called stream classes. The
hierarchy of stream classes used for input and output operations is with the console unit.
There are mainly two types of console I/O operations:
a) Unformatted console I/O
b) Formatted console I/O
In my project I have used to take input using gets() and used to clear screen using
system(“cls”);

### 6. File Handling:
File handling in C++ is a mechanism to store the output of a program in a file and help
perform various operations on it. Files help store these data permanently on a storage device.
2

### 7. Virtual Function:
A virtual function is a member function which is declared within a base class and is redefined
(overridden) by a derived class. When you refer to a derived class object using a
pointer or a reference to the base class, you can call a virtual function for that object and
execute the derived class’s version of the function.

### 8. Abstract Base Class:
An abstract class is a class that is designed to be specifically used as a base class. An abstract
class contains at least one pure virtual function. You declare a pure virtual function by using a
pure specifier (= 0) in the declaration of a virtual member function in the class declaration.

### 9. Runtime Polymorphism:
In runtime polymorphism, the compiler resolves the object at run time and then it decides
which function call should be associated with that object. It is also known as dynamic or late
binding polymorphism. This type of polymorphism is executed through virtual functions and
function overriding.

### 10. Constructor and Destructor:
A constructor is a special member function of a class and shares the same name as of class,
which means the constructor and class have the same name.
Destructor is just the opposite function of the constructor. A destructor is called by the
compiler when the object is destroyed and its main function is to deallocate the memory of
the object.

### 11. Templates:
A template is a simple yet very powerful tool in C++. The simple idea is to pass data type as a
parameter so that we don’t need to write the same code for different data types. For example,
a software company may need to sort() for different data types. Rather than writing and
maintaining multiple codes, we can write one sort() and pass data type as a parameter.
C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second
keyword can always be replaced by the keyword ‘class’.
