
# Course Materials

**Quick Links**: [Installing Haskell](https://hackmd.io/@alexhkurz/Hk86XnCzD) ...  [Videos](videos.md) ... [BNFC](BNFC-installation.md) ... [Feedback for HWs](feedback-hw.md)

<!-- [Haskell projects](haskell-projects.md) ...-->

## Functional Programming (Haskell)

We need a programming language that makes it as simple as possible to implement interpreters. Choice of language always is a compromise. In my view, Haskell is the best choice for what we want to do in this course (I would welcome any challenge on this).

- [First Haskell Steps](https://hackmd.io/@alexhkurz/SJgHGZ_nw).

- L1.1: *In which I argue that, in a specific sense, functional programming is simpler (not necessarily easier) than imperative programming.* [Imperative vs functional programming](https://hackmd.io/@alexhkurz/SJKWvna6U). Homework 1 in [Greatest Common Divisor in Different Languages](https://hackmd.io/@alexhkurz/SkqMtH0sK). Don't forget to install Haskell on your laptop/desktop.


- L1.2: *In which we learn about recursion over recursively defined data types.* [Recursive programming in Haskell](https://hackmd.io/@alexhkurz/H1jUka4Gv). For a summary on what we said about Haskell watch the [videos](videos.md) entitled [The computational model of functional programming](https://youtu.be/u_OMwv8tDVg) and [Haskell Tips I](https://youtu.be/wj0j2HjMw6w).

- L2.1: *In which we look at how recursive rewriting of equations is implemented using a call stack and at how to use recursion as a powerful problem solving technique.* We started with [Rewriting and the Call Stack](https://hackmd.io/@alexhkurz/HJiulVg0U) and then looked at [Recursion as a Problem Solving Technique](https://hackmd.io/@alexhkurz/Sy7M_6yMF), in particular at [Towers of Hanoi](https://hackmd.io/@alexhkurz/rJQwvpyMY) (which contains HW 3 for the report).

    Here are some further resources that may help. I made a video on [Euclid's algorithm](https://youtu.be/ZcJMj0antos). Read Chapter V of [Goedel, Escher, Bach](https://www.physixfan.com/wp-content/files/GEBen.pdf) and make sure to start with the dialogue "Little Harmonic Labyrinth" (it is not a coincidence that this dialogue has a similar structure to the one described in my note on "Rewriting and the Call Stack").

    We started this lecture with [feedback](feedback-hw.md) for [Homework 1](https://hackmd.io/@alexhkurz/SkqMtH0sK).


## Parsers and Interpreters (A Calculator)

Arithmetic can be seen as a programming language (not Turing complete) and a calculator as an interpreter. This is where we are going to start. Importantly, the methods we learn will scale to proper real world programming languages.

- L 2.2: *In which we learn how to write our first interpreter.* A calculator: [Overview](https://hackmd.io/@alexhkurz/HkpdXJ1fK) and [Interpreter](https://hackmd.io/@alexhkurz/rJX-i1kzY) and [Virtual Machine](https://hackmd.io/@alexhkurz/H12igXkzK). 

    For Haskell programming techniques have a look at the videos [Haskell Tips II](https://youtu.be/naNLE4GLrTo)
and [Recursion over algebraic data types](https://youtu.be/2YLfJvOtLwA).

- L 3.1: *In which we learn to parse small arithmetic expressions pen-and-paper.* A [Short Introduction to Parsing](https://hackmd.io/@alexhkurz/BkSgRX1GF). 

    We started with Q&A and [feedback for HW2](feedback-hw.md). This also contains additional homework for Week 3.

    We also went back to the interpreter using the [virtual machine](https://hackmd.io/@alexhkurz/H12igXkzK), which will be relevant for Programming Assignment 1.

 
- Videos: [Order of Operations in CFGs](https://youtu.be/jf1xhZSpCvg) and [Uniqueness of Parse Trees](https://youtu.be/3ZLkPwB_c9g).

- L 3.2: *In which we combine the parser and interpreter to obtain a calculator.* [A Calculator: Parser](https://hackmd.io/@alexhkurz/BkqOWbgMF). Introducing [Assignment 1](https://github.com/alexhkurz/programming-languages-2022/blob/main/assignment-1.md).


## Lambda Calculus

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

## Rewriting Theory

- L 6.2: Rewriting: [Examples](https://hackmd.io/@alexhkurz/rkzITG4nD) and [Introduction](https://hackmd.io/@alexhkurz/BJ7AoGcVK).

- Read Chapter 1 of [Goedel Escher Bach](GEB.md) and use the tools from rewriting to analyze the MU puzzle.

- L 7.1: [Confluence and Normal Forms](https://hackmd.io/@alexhkurz/B1wB3rT4F). 

    [Feedback for HW6](feedback-hw.md). [Church Encodings](https://hackmd.io/@alexhkurz/SyowcD9XF).

- L 7.2: 
    Continued from last lecture. [String rewriting exercises](https://hackmd.io/@alexhkurz/Syn23oMHF).

- L 8.1: [Termination](https://hackmd.io/@alexhkurz/H1O4bLBHK) and [Invariants](https://hackmd.io/@alexhkurz/r1dp-LBBt).

    [Feedback for HW7](feedback-hw.md).

- L 8.2: Continued from L 8.1.

## An Interpreter for a Functional Programming Language

- L 9.1: [Extensions of lambda-calculus](https://hackmd.io/@alexhkurz/rJEeYqZtw), video review of the [fixed point combinator](https://youtu.be/XvDOwbSh3xE).

    [Feedback for Assignment 1](feedback-hw.md).

- L 9.2: Starting [Assignment 2](assignment-2.md).

## Operational and Denotational Semantics

- L 10.1: [Operational and Denotational Semantics](https://hackmd.io/@alexhkurz/Hkf6BTL6P).

## Design of a Domain Specific Language

- L 10.2: We will discuss the article [Composing contracts: an adventure in financial engineering](https://www.cs.tufts.edu/~nr/cs257/archive/simon-peyton-jones/contracts.pdf). A link to an implementation can be found [here](https://github.com/cmahon/composing-contracts), but I did not take a closer look yet, get in touch if you are interested.

## Interlude

- L 11.1: Comments on [Assignment 2, Part 2](assignment-2.md) and [Feedback for Homework](feedback-hw.md).

## Logic

- L 11.2: *In which we introduce the area of Program Verification.* [Hoare Logic](https://hackmd.io/@alexhkurz/Hy135C2tH), a summary of the [Rules of Hoare Logic](https://hackmd.io/@alexhkurz/BJyjAXGoB). 
- L 12.1 *In which we discover that proving is programming.* [Termination of Finitely Branching Systems](https://hackmd.io/@alexhkurz/BkNlJ07IY).  
- L 12.2 *In which we learn the rules of logical reasoning.* [Natural Deduction](https://hackmd.io/xJ8NOiK4S5qnYvEI85bHig) ... [Induction and Equational Reasoning](https://hackmd.io/@alexhkurz/BkHZL3jFS).

## Interlude

- L 13.1: Introducing [LambdaFun](Lab2-Lambda-Calculus/LambdaFun/README.md) and starting on [Assignment 2](assignment-3.md). The [memory model](Lab2-Lambda-Calculus/LambdaFun/memory-model.md) of LamFun.

<!-- L 12.1: The [memory model](memory-model.md) of LambdaFun, version LamMem.-->


---

... more to come ... An Interpreter for an Imperative Programming Language ...

<!--  [Typed Lambda Calculus](https://hackmd.io/@alexhkurz/S1Sopqo6w)

- [Normalisation by Evaluation](https://hackmd.io/w9RLzXmcS86U4HVAQi5Lqg)
- [Theorem Proving](https://hackmd.io/JrBBURefROGD1xMN44Zivw)