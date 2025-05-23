# Design_pattern

Design patterns make it easier to reuse the successful designs and architectures for OOP. Design patterns help you choose design alternatives that make a system reusable and avoid alternatives that compromise reusability. Put simply, design patterns help a designer get a design "right" faster. 

## What is a Design Pattern?
Christopher Alexander says, "Each pattern describes a problem which occurs over and over again in our environment, and then describes the core of the solution to that problem, in such a way that you can use this solution a million times over, without ever doing it the same way twice". Even though Alexander was talking about patterns in buildings and towns, what he says is true about object-oriented design patterns. Our solutions are expressed in terms of objects and interfaces instead of walls and doors, but at the core of both kinds of patterns is a solution to a problem in a context. 

## What are SOLID Design Principles?
SOLID is an acronym for five design principles that help software developers create maintainable, scalable, and flexible software systems. These principles are:
1. **Single Responsibility Principle (SRP)**: A class should have only one reason to change, meaning it should have only one job or responsibility. This makes the class easier to understand and maintain.
2. **Open/Closed Principle (OCP)**: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. This means that you should be able to add new functionality without changing existing code.
3. **Liskov Substitution Principle (LSP)**: Subtypes must be substitutable for their base types without altering the correctness of the program. This means that derived classes should extend the base class without changing its behavior.
4. **Interface Segregation Principle (ISP)**: Clients should not be forced to depend on interfaces they do not use. This means that you should create smaller, more specific interfaces rather than large, general-purpose ones.
5. **Dependency Inversion Principle (DIP)**: High-level modules should not depend on low-level modules. Both should depend on abstractions. This means that you should depend on interfaces or abstract classes rather than concrete implementations.

## Pattern has four elements to it
1. Pattern Name: so we can easily recognize the core pattern and logic behind it.
2. Problem: When to apply the pattern and what are the conditions and assumptions are there.
3. Solution: Design/template of an abstract description of a design problem and how a general arrangement of elements (classes and objects in our case) solves the problem.
4. Consequences: Results and trade-offs of applying the pattern.

## MVC (Model, View, Controller)

MVC consists of three kinds of objects. 
1. The Model is the application object.
2. The View is its screen presentation.
3. The Controller defines the way the user interface reacts to user input. 

Before MVC, user interface designs tended to lump these objects together. MVC decouples them to increase flexibility and reuse. 

MVC decouples model and view into subscriber/notify protocol between them. A view must ensure that its appearance reflects the state of models, and decoupling them allows having multiple views connected to a single model, and views can be updated without changing the model.
 
MVC also lets you update the view response to user input without changing its visual presentation. You might want to update/modify the response to keyboard/mouse. The controller object is responsible for the response mechanism. The hierarchy class of the controller will make it easier to create new variations of controllers in the existing system.

The view uses one instance of the controller class to implement a particular response logic. To use different response logic, just replace the controller class.

## Describing Design Patterns

To describe any pattern, we must show all the decisions, alternative options, and trade-offs that led to it. Also, sample examples are important too because they help you see the design in action.

## Design pattern bifurcation  

### Purpose
We can divide design based on purpose, meaning what the pattern actually does:
1. Creation pattern which design object creations
2. Structural pattern deals with composition of classes and objects
3. behavioral patterns, which describe how classes/object interact and handle roles

### Scope
Weather pattern applies mostly on classes or objects. Class patterns deal with relationships between classes and their subclasses via inheritance so they are static at compiler timer.Object patterns deal with object relationships, which can be changed at run-time and are more dynamic.

Creational class patterns defer some part of object creation to subclasses, while Creational object patterns defer it to another object. The Structural class patterns use inheritance to compose classes, while the Structural object patterns describe ways to assemble objects. The Behavioral class patterns use inheritance to describe algorithms and flow of control, whereas the Behavioral object patterns describe how a group of objects cooperate to perform a task that no single object can carry out alone. 

## Why Use interface

Class inheritance is basically just a mechanism for extending an application's functionality by reusing functionality in parent classes.It lets you get new implementations almost for free, inheriting most of what you need from existing classes. However, implementation reuse is only half the story. Inheritance's ability to define families of objects with identical interfaces (usually by inheriting from an abstract class) is also important. Why? Because polymorphism depends on it.  

When Inheritance is used ideally all classes must be derived from an abstract class. and all classes just adds or override the operation of abstract classes.

major benefit of manipulating objects using interact defined by abstract classes Client remain unaware of the specific types of objects or implementation and they use the interface as long as they agrees on type

## Inheritance versus Composition
Two most common techniques for reusing the functionality in OOP are inheritance and object composition.

Inheritance lets to you define the implementation of one class in term of another. Referencing the subclass for reusability is called white box reuse which means that internals of parent classes are often visible to subclass

In Object composition, We combine object into one large object to get it more complex object. This is called black box reuse because the internal of the composed object are hidden from the outside world. The outside world only sees the interface of the composed object.

Both have their own advantages and disadvantages. Class inheritance is defined at compile time, so it is static. Easily to modify the implementation of a subclass. but it is difficult to change the implementation of a class at run-time. but worst part is inheritance exposes the implementation of the parent class to the subclass. Any change in the parent class will affect subclass and to solve this problem you can use abstract classes.

Composition is more flexible than inheritance. You can change the implementation of a class at run-time. You can also change the implementation of a class without affecting the other classes. Because objects are solely accessed through their interface. Any object can be replaced with another object that implements the same interface. This is called polymorphism.

Composition has one more advantage over inheritance. you keep each class encapsulated and focus on a single task. This is called the single responsibility principle. It makes the code more maintainable and easier to understand.

Your classes and class hierachies will remain small and will be less likely to be grown super large but only if you use composition will have more objects and the system's behavior will be based on the composition of these objects instead of the inheritance of classes

brief about second principle of OOP is favor composition over inheritance. It means that you should prefer to use composition instead of inheritance. Inheritance is a powerful tool, but it can lead to complex and difficult-to-maintain code. Composition is a more flexible and maintainable approach to code reuse. Reuse by interfaces is a good way to make new componenets that can be composed  with old ones. It is also a good way to make new components that can be used in different contexts. This is called the open/closed principle. It means that you should design your classes to be open for extension but closed for modification. This means that you should design your classes to be easily extensible without modifying the existing code.

## Delegation

Via delegation you can make composition as powerful as inheritance. In Delegation, you have two object handling the request. A receiving object delegate operation to delegate class. it is same as subclass deferring request to parent classes in inheritance. So the receiver object passes itself to the main object to let the main object refer to the receiver operations.

For example, you passed rectangle object into windows object as member variable instead create rectangle at child pass of windows object to use rectangle operation.

Main advantage of delegation is that you can change the behavior of the object at run-time. You can also change the behavior of the object without affecting the other objects. Our windows can become circle or square at run-time.

Delegation has a disadvantage. The dynamic nature makes it difficult to understand the code. It is also difficult to debug the code. You have to keep track of the delegation chain and it can be difficult to find the source of the problem. It is also difficult to test the code. You have to test all the possible combinations of delegation chains. This can be time-consuming and error-prone.

## Inheritance vs Parameterized Type or Template

For reusing functionality, inheritance is not the only way. You can also use parameterized types or templates. Parameterized types allow you to define a class with a placeholder for a type that can be specified later. This enables you to create more flexible and reusable code by allowing different types to be used with the same class.

## Design for change
Key to maximizing reuse lies in anticipating new requirements and designing for change. This is called the open/closed principle. It means that you should design your classes to be open for extension but closed for modification and design your according so that they can be easily extended without modifying the existing code. 


