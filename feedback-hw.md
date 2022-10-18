# Feedback for Homeworks

This file contains partial feedback to homeworks for the report and will be supplemented by comments and Q&A in the Tuesday lecture. It may also contain instructions for future homeworks, so please **read carefully**, whether you got full points or not. Not following the instructions may lead to loosing points (I collect instructions from earlier weeks in a separate section at the end of the file).

See also [report.md](https://github.com/alexhkurz/programming-languages-2022/blob/main/report.md). If you don't respect the instructions below you will loose a point on the following homeworks.

Feedback will also be provided each Tuesday in the lecture. If you have any further questions to the homework, it would be great to see you in the office hours. 

## Week 7

### Free and bound variables

Don't say: "variable bounds"

https://github.com/alexhkurz/programming-languages-2022/blob/main/src/LambdaNat0/src/Interpreter-fragment.hs

line 5: `e1` and `e2` are bound on the left of `=` and the scope is to the end of line 7
line 6:  `i` and `e3` are bound on the left of `->` and the scope is to the end of the line
line 7: `e3` is bound on the left of `->` and the scope is to the end of the line
line 8: `x` is bound on the left of `=` and the scope is to the end of the line

line 18: `id`, `s`, `id1`, `e1` are bound on the left of `=` and the scope is to the end of line 22
line 20: `f` is bound on the left of `=` and the scope is to the end of line 22
line 21: `e2` is bound on the left of `=` and the scope is to the end of line 22

If you are unsure about how far the scope goes, you can write little test programs such as

```
main = do 
print $ let x = (if x == 1 then 2 else 2 )
            y = x in 
            x + y
```

predict the results under assumptions of scope and test your predictions against the actual outputs of the program. This is faster and more accurate than sifting through manuals.

### Computing `evalCBN`

The computations need to be performed on abstract syntax, showing the rewriting steps that the interpreter is taking. Again, many students did not take the time to do this. I know it is hard, but it will be a valuable skill to have in upcoming assignments.

### The homework as specified in https://hackmd.io/@alexhkurz/BJ7AoGcVK

Don't say: "valid ARS"

#### Part 1

We have drawn the pictures in class. Here is the list of properties:

1. terminating, confluent, UNF
2. terminating, confluent, UNF
3. non terminating, confluent, no UNF
4. terminating, not confluent, no UNF
5. not terminating, confluent, UNF
6. not terminating, not confluent, no UNF
7. not terminating, not confluent, no UNF

#### The Truth Table

Solution linked from the homework.

## Week 6

### Evaluating lambda terms

```
(\exp . \two . \three . exp two three)
(\m.\n. m n)
(\f.\x. f (f x))
(\f.\x. f (f (f x)))
```

The main point of this example was to practice "following the rules" which is an important skill for every programmer and computer scientist. (If you are wondering, the fact that this exercise is boring and difficult is exactly the point because "boring and difficult" is how "following the rules" feels to humans.)

But there are also interesting teaching points connected with this example.

- The example demonstrates that even in lambda calculus, which is sometimes understood as a calculus of nameless functions, one can name functions if one wants to, by binding variable names to functions. 

  (I say "variable names" instead of "variables" to emphasize that the variables of lambda calculus often resemble mere names more than what we know as variables in mathematics or programming. (What are the differences between different concepts of variables? As with other data types, the diffferences can be best explained by the operations available on the data.))

- The example demonstrates that lambda calculus can encode data types such as numbers. 

  (And we do know that once one can encode numbers, one can encode all data types. (Why? (Btw, this illustrates another important skill, namely to draw technical conclusions from general knowledge))). 
  
  For more on this see my notes on [Church Encodings](https://hackmd.io/@alexhkurz/SyowcD9XF).

### Project topics

Make sure that you build up your incrementally and document your progress by submitting regularly to git. Send me an email when you achieved a milestone.

- Lisp interpreter with parser
- Learning a new programming language.
  - Comments:
    - Include some of the history of the programming language. Try to find out something about the design decisions that went into the language. What was the motivation behind the language? Find interviews, articles etc in which the designers of the language talk about some of this background.
    - How was the language received? How did it develop? Is it used today for what it was designed to? 
    - What are the strengths and weaknesses of the language? How does the language compare to other langauges?
    - Use the software project you develop to highlight some of the questions above.
  - Some chosen examples:
    - Javascript (plus Typescript)
    - Ruby
    - Rust
    - Swift
    - Kotlin
    - ...


## Week 5

**Instruction:** `report.pdf` needs a table of contents with hyperlinks to the respective sections (see `latex-exmaple.tex` for an example of how to do this).

**General tip:** If `report.pdf` gets too big because of the pictures you include, upload pictures to github and link them from `report.pdf` (using the `href` command of LaTeX). (The smaller the number of pictures, the easier it is for me to grade though.)

#### Syntax of Lambda Calculus

To lay out the syntax trees in 2-dimenionsal notation is a requirement. If you want to draw the trees in Latex try [Quiver](https://q.uiver.app/?&q=WzAsMixbMCwwLCJcXE9tZWdhXntYXntvcH19Il0sWzIsMCwieyhcXE9tZWdhXkEpfV57b3B9Il0sWzAsMSwicF5cXHVwYXJyb3ciLDAseyJjdXJ2ZSI6LTJ9XSxbMSwwLCJwXlxcZG93bmFycm93IiwwLHsiY3VydmUiOi0yfV1d) (this makes it also easy to later make corrections). Otherwise you can draw them by hand, make a picture, upload the picture to your repo and link it from the report.

Be careful about the trees for 7 and 8. Make sure to check carefully that all the 2-dimensional trees drawn by hand match up with the linearized trees output by the parser: **After linearizing your 2d ASTs, the output must be identical to the output of the parser.**

#### Semantics of Lambda Calculus

For the evaluation of the lambda terms, observe that

`\x.\y.x` is "first projection", that is, it evaluates to the first component of a pair `a b`. Explicitely, `(\x.\y.x) a b = a`, whatever `a` and `b` are.

(At this point in the lecture I inserted a remark about the difference of variables and meta-variables.)

`(\x.\y.y)` is "second projection", that is, it evaluates to the second component of a pair `a b`. Explicitely, `(\x.\y.y) a b = b`, whatever `a` and `b` are.

Once you rephrased the problem in these terms, the answers to 3-10 should be obvious and the answers to 11 and 12 are also not difficult to find.

**I didn't deduce points if the `evalCBN` part was missing, you still need to do the work.**

## Week 4

Common mistakes:

- CSTs need to have nodes labelled `Integer`. (Why?)
- ASTs need to have nodes labelled `Num`. (Why?)
- Don't forget to answer the question about `1+2+3`.

As always, do not forget to improve and correct your homework for the final version of the report.

I showed solutions to hw4 on the whiteboard. 

## Week 3

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

When you write a formula (such as $2^N-1$) make sure that you state explicitly what the parameters ($N$ in this case) are supposed to mean.

## Week 2

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

-1 if code or explanation was missing. Also -1 if the code was not typeset properly.

In the lecture, I emphasized that 
- the [mathematical definition](resources/gcd.jpg) of gcd can be read as a functional program in pseudo code;
- the explanation can be written by rewriting equations.

## Instructions

---

Typeset code as code not as math (eg in Task 2 of HW2).

Reminder: Submit a link to your repo via Canvas. I will grade the file `report.pdf` I find your repo. 

---

Using git and latex is a requirement.

Naming conventions for files and folders are part of the assignment specification. Don't change them. Eg, it must be report.pdf, not some other name.

Put your name on the report.

Recall that it says in the latex template `report.tex` "Replace this entire Section 1 with your own short introduction."

Be careful about typesetting. Avoid "??" for missing links/references. If you need special symbols, they are easy to google.

Use a .gitignore file to avoid committing and pushing files such as .aux, .dvi, .log, .out, .toc, .DS_Store, ...

Your repo needs to be private and I need to invited as a collaborator.	


If you have latex questions, try first to find the answer on stackexchange.






