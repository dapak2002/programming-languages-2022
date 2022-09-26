# Feedback for Homeworks

This file contains partial feedback to homeworks for the report and will be supplemented by comments and Q&A in the Tuesday lecture. It may also contain instructions for future homeworks, so please **read carefully**, whether you got full points or not.

See also [report.md](https://github.com/alexhkurz/programming-languages-2022/blob/main/report.md). If you don't respect the instructions below you will loose a point on the following homeworks.

Feedback will also be provided each Tuesday in the lecture. If you have any further questions to the homework, it would be great to see you in the office hours. 

## Week 4

I showed solutions to hw4 on the whiteboard.

## Week 3

### Specific comments

#### HW2

- For computations via equational reasoning (aka rewriting), in HW2 and elsewhere, make sure that in the computation of a function (see the example of `append` below)
  - every line contains ` = `,
  - every ` = ` is justified by (ie an instance of) one and only one of the equations defining the function.
  
- Also use common sense in striking the right balance between detail and readability. For example, if your program is
  ```haskell
  member _ [] = False
  member n (x:xs)
    | x == n = True
    | otherwise = member n xs
  ```
  then write computations as in
  ```haskell
  member 2 [1,2,3] =
    member 2 [2,3] = 
    True
  ```
  The idea is that you treat the vertical bar notation `|` as, in this case, creating three equations. If you think of the evaluation of the expressions `x == n` and `otherwise` as being part of the pattern matching (which determines which equation is chosen), then the evaluation of the conditions `x == n` and `otherwise` does not appear in the equational reasoning. This makes the computation easier to follow and is as unambiguous.
- Good typesetting would mean to use correct Haskell syntax in the computations, for example it is `True` and not `true`.

#### HW 3

- When you write a formula (such as $2^N-1$) make sure that you state explicitly what the parameters ($N$ in this case) are supposed to mean.

## Week 2

### General Instructions

Typeset code as code not as math (eg in Task 2 of HW2).

Reminder: Submit a link to your repo via Canvas. I will grade the file `report.pdf` I find your repo. 

### Specific Comments

In `revert` do not use `++` but your own `append`. Do not use `last`.

If you have not done Task 2, add it to your report. In any case, write out now one computation for each function in the following style, called "rewriting" or "equational reasoning" (you may make your own choice of linebreakes and indentation):

```haskell
append [1,2,3] [4,5] = 
    1 : (append [2,3] [4,5]) = 
    1 : (2 : (append [3] [4,5])) = 
    1 : (2 : (append [3] [4,5])) = 
    1 : (2 : (3 : (append [] [4,5]))) = 
    1 : (2 : (3 : [4,5])) = 
    [1,2,3,4,5]
```

Note how each equation above is an instance of one of the equations of the definition of `append` in Haskell, which, in my case, is

```haskell
append [] ys = ys
append (x:xs) ys = x : append xs ys
```

Of course, if you have a different definition of `append`, your execution sequence will be different as well.

I will take this into account when grading HW3.

## Week 1

### General Instructions

Using git and latex is a requirement.

Naming conventions for files and folders are part of the assignment specification. Don't change them. Eg, it must be report.pdf, not some other name.

Put your name on the report.

Recall that it says in the latex template `report.tex` "Replace this entire Section 1 with your own short introduction."

Be careful about typesetting. Avoid "??" for missing links/references. If you need special symbols, they are easy to google.

Use a .gitignore file to avoid committing and pushing files such as .aux, .dvi, .log, .out, .toc, .DS_Store, ...

Your repo needs to be private and I need to invited as a collaborator.	


If you have latex questions, try first to find the answer on stackexchange.

### Particular Comments

-1 if code or explanation was missing. Also -1 if the code was not typeset properly.

In the lecture, I emphasized that 
- the [mathematical definition](resources/gcd.jpg) of gcd can be read as a functional program in pseudo code;
- the explanation can be written by rewriting equations.



