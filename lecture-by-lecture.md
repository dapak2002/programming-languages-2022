
# Course Materials

**Quick Links**: [Installing Haskell](https://hackmd.io/@alexhkurz/Hk86XnCzD) ...  [Videos](videos.md) ... [BNFC](BNFC-installation.md) ... [Feedback for HWs](feedback-hw.md)

<!-- [Haskell projects](haskell-projects.md) ...-->

## Part 0: Functional Programming in Haskell

We need a programming language that makes it as simple as possible to implement interpreters. Choice of language always is a compromise. In my view, Haskell is the best choice for what we want to do in this course (I would welcome any challenge on this).

- [First Haskell Steps](https://hackmd.io/@alexhkurz/SJgHGZ_nw).

- L1.1: *In which I argue that, in a specific sense, functional programming is simpler (not necessarily easier) than imperative programming.* [Imperative vs functional programming](https://hackmd.io/@alexhkurz/SJKWvna6U). Homework 1 in [Greatest Common Divisor in Different Languages](https://hackmd.io/@alexhkurz/SkqMtH0sK). Don't forget to install Haskell on your laptop/desktop.


- L1.2: *In which we learn about recursion over recursively defined data types.* [Recursive programming in Haskell](https://hackmd.io/@alexhkurz/H1jUka4Gv). For a summary on what we said about Haskell watch the [videos](videos.md) entitled [The computational model of functional programming](https://youtu.be/u_OMwv8tDVg) and [Haskell Tips I](https://youtu.be/wj0j2HjMw6w).

- L2.1: *In which we look at how recursive rewriting of equations is implemented using a call stack and at how to use recursion as a powerful problem solving technique.* We started with [Rewriting and the Call Stack](https://hackmd.io/@alexhkurz/HJiulVg0U) and then looked at [Recursion as a Problem Solving Technique](https://hackmd.io/@alexhkurz/Sy7M_6yMF), in particular at [Towers of Hanoi](https://hackmd.io/@alexhkurz/rJQwvpyMY) (which contains HW 3 for the report).

    Here are some further resources that may help. I made a video on [Euclid's algorithm](https://youtu.be/ZcJMj0antos). Read Chapter V of [Goedel, Escher, Bach](https://www.physixfan.com/wp-content/files/GEBen.pdf) and make sure to start with the dialogue "Little Harmonic Labyrinth" (it is not a coincidence that this dialogue has a similar structure to the one described in my note on "Rewriting and the Call Stack").

    We started this lecture with [feedback](feedback-hw.md) for [Homework 1](https://hackmd.io/@alexhkurz/SkqMtH0sK).


## Part 1: A Calculator

Arithmetic can be seen as a programming language (not Turing complete) and a calculator as an interpreter. This is where we are going to start. Importantly, the methods we learn will scale to proper real world programming languages.

- L 2.2: *In which we learn how to write our first interpreter.* A calculator: [Overview](https://hackmd.io/@alexhkurz/HkpdXJ1fK) and [Interpreter](https://hackmd.io/@alexhkurz/rJX-i1kzY) and [Virtual Machine](https://hackmd.io/@alexhkurz/H12igXkzK). 

    For Haskell programming techniques have a look at the videos [Haskell Tips II](https://youtu.be/naNLE4GLrTo)
and [Recursion over algebraic data types](https://youtu.be/2YLfJvOtLwA).

- L 3.1: *In which we learn to parse small arithmetic expressions pen-and-paper.* A [Short Introduction to Parsing](https://hackmd.io/@alexhkurz/BkSgRX1GF). 

    We started with Q&A and [feedback for HW2](feedback-hw.md). This also contains additional homework for Week 3.

    We also went back to the interpreter using the [virtual machine](https://hackmd.io/@alexhkurz/H12igXkzK), which will be relevant for Programming Assignment 1.

 
- Videos: [Order of Operations in CFGs](https://youtu.be/jf1xhZSpCvg) and [Uniqueness of Parse Trees](https://youtu.be/3ZLkPwB_c9g).

- L 3.2: *In which we combine the parser and interpreter to obtain a calculator.* [A Calculator: Parser](https://hackmd.io/@alexhkurz/BkqOWbgMF). Introducing [Assignment 1](https://github.com/alexhkurz/programming-languages-2022/blob/main/assignment-1.md).


## Part 2: Lambda Calculus

The lambda calculus plays a foundational role in Programming Languages because it is the smallest programming language that has variables and functions (and, as an aside, is Turing complete).

- L 4.1: **In which we meet lambda calculus for the first time.** [Syntax of Lambda Calculus](https://hackmd.io/@alexhkurz/S1D0yP8Bw).

    We started with Q&A and [feedback for HW3](feedback-hw.md).

- Videos: 
    - [Syntax of Lambda Calculus](https://youtu.be/D0kH1BpNr14).
    - Parsing lambda-calculus expressions:  [one](https://youtu.be/eYstx7uuE6c) and [two](https://youtu.be/yls1NEUlzZA).
    - [Semantics of Lambda Calculus](https://www.youtube.com/watch?v=h4aT42t7v9c#t=0m).

- L 4.2: *In which we learn the meaning of lambda calculus programs.* [Semantics of Lambda Calculus](https://hackmd.io/@alexhkurz/H1e4Nv8Bv).  

- L 5.1: *In which we learn how run our lambda-calculus interpreter by hand.* A lab like interactive session, the notes of which will be [here](https://hackmd.io/@alexhkurz/ByIktUq-i). 

    We started with [Feedback for HW4](feedback-hw.md) and then briefly discussed [Math Puzzles and Debugging](https://hackmd.io/@alexhkurz/rkwDAjAZj).

- L 5.2: Continued from the previous lecture.

- L 6.1: [Variables, Binding, Scope and Substitution](https://hackmd.io/@alexhkurz/SkQzDC6n7).  

---

... more to come ...

<!--
- L 5.1: [Variables, Binding, Scope and Substitution](https://hackmd.io/@alexhkurz/SkQzDC6n7).  

- L 5.2: [Church Encodings](https://hackmd.io/@alexhkurz/SyowcD9XF).  
-->


## Part 3: Rewriting

## Part 4: An Interpreter for a Functional Programming Language

## Part 5: Advanced Topics 1

## Part 6: An Interpreter for an Imperative Programming Language

## Part 7: Advanced Topics 2
