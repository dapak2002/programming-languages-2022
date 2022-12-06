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

- Build the interpreter (can take a while) and start the REPL as explained in the [README.md](https://github.com/alexhkurz/programming-languages-2022/blob/master/Lab2-Lambda-Calculus/LambdaFun/README.md).

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

    - We distinguish now definitions and expressions. At the level of definitions, `let` and `let rec` are now replaced by `val` and `rec`. The keyword `in` is not needed anymore. Definitions are known globally throughout the file. The expression `let ... in ...` is mostly used to declare local variables inside a function.

    - There is now a syntax for pattern matching using `case`.

    - The notation for lists changed, for example, `#` is now `[]`.

- **(5 points)**: Write the programs of Assignment 2:

        is_empty
        fib
        length
        even
        reverse (with append)
        weave

    **You may have to change the names of the functions.** For example, if you look at the entry for `<id>`, you will see that `_` is not allowed in names.

    For this talk you should use the built-in lists of LambdaFun. Your programs will look similar to those you wrote for Assignment 2.

- Let me know if there are any problems, questions, etc

## Part 2 

If you want to have a look already how we will use the new features of the language, read the discussion on the [Memory Model](Lab2-Lambda-Calculus/LambdaFun/memory-model.md) and study the examples in [linked-list.lc](https://github.com/alexhkurz/programming-languages-2022/blob/master/Lab2-Lambda-Calculus/LambdaFun/test/linked-list.lc), which are the starting point for Part 2 of this assignment.

### Programming with Linked Lists

(**20 points**)

It is important for this task to be memory efficient in the sense of not creating unnecessary copies of data on the heap. In particular, you should be able to write the functions below almost without using `new`. You also should avoid the built-in lists (but using built-in lists to form pairs (or tuples) as in `[a,b]` to make elements of a linked list is allowed.)

- Implement a function `insert n list` that inserts a number `n` into a linked list `list` of numbers.
    - Invariant: If `list` is sorted (in ascending order) before `insert` then it must be sorted after `insert`.
    - Use a pointer to walk along the linked list `list` in order to insert an element at the right position. 
    - `insert` returns an address, the content of which is the first element of  `list` (after insertion).
    - See also Lecture 13.2.
    - For example, `insert 3 (insert 1 (insert 4 (insert 2 (insert 5 nil))));;` should build a sorted list on the heap. (Also test `insert` in cases where not all elements are different.)
    - Similarly,
        ```
        print (insert 5 (insert 4 (insert 3 (insert 2 (insert 1 nil)))));;
        [1, 2, 3, 4, 5]
        ```

- Implement insertion sort. That is, implement a function `sort list` that sorts a linked list `list` of numbers by repeatedly using `insert`. 
    - For example, `sort (cons 3 (cons 1 (cons 4 (cons 2 (cons 5 nil)))))` should result in a sorted list on the heap. 
    - Simlarly, 
        ```
        print (sort (cons 6 (cons 4 (cons 2 nil))));;
        [2,4,6]
        ```


**Remark:** The code of the solution is not too long, but to get there requires a large amount of problem solving. Do not be surprised if you have to write more code for testing and debugging than will be contained in the actual solution. 

**Extra challenge:** (10 extra points) Insertion sort is easy to implement, but has time complexity O(n^2), which is significantly worse than the known optimum of O(n log n). A well-known sorting algorithm with time complexity O(n log n) is merge sort. 

- Implement a function `merge list1 list2` that merges two lists into one. 
    - Invariant: If `list1` and `list2` are sorted than the merged list is sorted.
    - Merging must be done "in place", that is, no allocations should be necessary.
    - `merge list1 list2` returns an address, the content of which is the first element of the merged list.
- Implement a function `mergesort` that uses `merge` above to sort in-place a linked list. For some general background on mergesort for linked lists see [here](https://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.html), but this is not required reading for the assignment.


### Critical Appraisal

(**5 points**)

Write the functions in pseudo code that is independent of the particular programming language used to implement the algorithm.

Make drawings that contain pictures of the heap illustrating your algorithms.

As usual, make some **interesting** observations about this assignment. For example, show me the most interesting work you did on testing and debugging. Maybe inspecting the heap while debugging made you think of garbage collection, a topic that would be worth exploring.

