# Assignment 3

#### Deadlines: 

- Part 1: **Sunday, Dec 4**. 
- Part 2: **Sunday, Dec 11**.

## Introduction

The purpose of the assignment is to learn how a functional programming languages can be extended to an imperative programming language. 

- Part 1 introduces only a small amount of more convenient syntax: Better notation for lists, pattern matching, separate definitions. Nothing serious, so apart from getting used to the new syntax, you should be able to carry over everything you learned from Assignment 2.

- Part 2 will add sequential composition, assignment, while loops and pointers. 

## Instructions

You may form groups of up to 3 students. 

Use the same private github repository as for Assignment 2. If you think that this is not possible/appropriate get in touch. 

Put a copy of [LambdaFun](https://github.com/alexhkurz/programming-languages-2022/tree/main/Lab2-Lambda-Calculus/LambdaFun) in your repository. The file structure should look as follows.

    Assignment1
    Assignment2
    Assignment3
        README.md -- name of students, critical appraisal
        LambdaFun -- copy of LambdaFun plus your solutions
            test/solutions.lc -- solution for Part 1
            test/sort.lc -- solution for Part 2

## Part 1

(5 points)


#### Instructions

- Start from [Lab2-Lambda-Calculus/LambdaFun](https://github.com/alexhkurz/programming-languages-2022/tree/master/Lab2-Lambda-Calculus/LambdaFun).

- Build the interpreter (can take a while) and start the REPL as explained in the [README.md](https://github.com/alexhkurz/programming-languages-2021/blob/master/Lab2-Lambda-Calculus/LambdaFun/README.md).

- Study the grammar at [README.md](https://github.com/alexhkurz/programming-languages-2022/blob/master/Lab2-Lambda-Calculus/LambdaFun/README.md). The syntax is slightly different and there are new features, most prominently, sequential composition, while loops, assignment. (You do not need the new features for Part 1).

- Study the example programs in [test/examples.lc](https://github.com/alexhkurz/programming-languages-2022/blob/master/Lab2-Lambda-Calculus/LambdaFun/test/examples.lc).

- Run in a terminal

        cabal exec lamfun

    That should open the REPL. Run

        λ :help

    to get an overview of the available commands. There are some built in functions. Run (and, as always, predict the expected results before hitting return/enter):

        λ head [2,3];;
        λ tail [2,3];;
        λ head [];;
        λ tail [];;

    Beware of the difference between `,` and `:` and throw in some parentheses if you get unexpected results: 

        λ [1,[2,3]];;
        λ 1:[2,3];;
        λ head [1]:[2,3];;
        λ (head [1]):[2,3];;
        λ [head [1],[2,3]];;

    Run 

        λ :load test/examples.lc 

    to load the examples. You can now call the defined functions as in

        λ plusone 4;;
        λ member 2 [3,2,3] ;;


- Experiment with your own examples. 

- Looking at the grammar and the example programs side by side, note the following.

    - `let` and `let rec` are now replaced by a list of definitions introduced by keywords `val` and `rec`. The keyword `in` is not needed anymore.

    - There is now a syntax for pattern matching using `case`.

    - The notation for lists changed, for example, `#` is now `[]`.

- **(5 points)**: Write the programs of Assignment 2.

- Let me know if there are any problems, questions, etc

## Part 2 

If you want to have a look already how we will use the new features of the language, read the discussion on the [Memory Model](Lab2-Lambda-Calculus/LambdaFun/memory-model.md) and study the examples in [linked-list.lc](https://github.com/alexhkurz/programming-languages-2021/blob/master/Lab2-Lambda-Calculus/LambdaFun/test/linked-list.lc). 

### Programming with Linked Lists

(**20 points**)

... to be continued ...

### Critical Appraisal

(**5 points**)

...