# Feedback for Homeworks

This file contains partial feedback to homeworks for the report and will be supplemented by comments and Q&A in the Tuesday lecture. It may also contain instructions for future homeworks, so please **read carefully**, whether you got full points or not. Not following the instructions may lead to loosing points (I collect instructions from earlier weeks in a separate section at the end of the file).

See also [report.md](https://github.com/alexhkurz/programming-languages-2022/blob/main/report.md). If you don't respect the instructions below you will loose a point on the following homeworks.

Feedback will also be provided each Tuesday in the lecture. If you have any further questions to the homework, it would be great to see you in the office hours. 

## Week 12 

[On Canvas](https://canvas.chapman.edu/courses/44405/assignments/495722) ... in [my notes](https://hackmd.io/@alexhkurz/Hy135C2tH#-Homework)

**Reminder:** The purpose of this exercise is to better understand verification tools that are widely used in software engineering. For a software tool to implement reasoning, it is important that every reasoning step can be justified by a precise rule.

I subtracted a point if there was no serious attempt at using the rules of Hoare logic to prove the correctness of the program. I also subtracted a point if the invariant was not correct. (But I only deduced 2 points if the proposed invariant was way off.)

The homework was to adapt to the program

```
while (x!=0) do z:=z*y;  x:= x-1 done
```

the work we have done in class on 

```
while (x != 0) do z:=z+y;  x:= x-1 done
```

I summarized all elements that need to go into the proof in [this picture](resources/hoare-logic-proof.jpeg). (The homework has essentially the same steps, but you need to adapt it because the program is slightly different.) 

Such a picture is called a proof tree and shows all the reasoning steps. In the report you don't have to give it the form of a proof tree, but all the reasoning steps need to be there. Note that the picture is only a summary and needs additional justification, in particular, **make sure that you indicate clearly which reasoning steps use which rules of Hoare logic.**

**Remark:** A table is a good method to test and debug your proposed invariant, but it does not serve as a proof that the invariant is correct.

**Remark:** One of the most common mistakes was to propose an invariant, that is not an invariant. Make sure to test and debug your invariant. 

Another common mistake was to propose an invariant such as `z=m*k^n`. This cannot work, because `z` changes during execution but `k,m,m` do not.



## Week 11

I think we had a good discussion.

One point I want to address, is that a much discussed question, whether such a DSL would be adopted by financial experts, is, while interesting, not the question that will, in my opinion, decide about the success of DSLs in that area. Here are some points to consider:
- Finance is increasingly driven by algorithms.
- DSLs bring value to the engineering of software tools for finance. 
- The rise of smart contracts happens largely outside of traditional finance.

**For the final report, instead of your questions, for Week 11, write a 500 word essay on the topic.**

In case you want further food for thought I link an [aritcle](https://canvas.chapman.edu/courses/44405/files/4192603?module_item_id=1507721) by Chapman law professor Tom Bell that contains many thought-provoking questions about how digital contracts, machine learning and the law will interact in the future. This shifts the topic somewhat from financial contracts to smart contracts, but touches on the same big questions.

And feel free to continue the discussion, even after the deadline.


## Week 10

**General Remark on the Final Report:** Your final report should be written in such a way that it is not just a loose collection of answers to homework. It should make sense on its own terms. It should be nicely typeset. Typically, a short summary of the problem should precede the solution. The notation you use should be explained. Of course, you don't need to repeat everything we did in the lectures. In case of doubt ask me. 

From my experience of writing reports, this kind of polishing takes a lot of time ... so better start now and spend 10 min on it every day.

**Remark on Notation:** If you use a font that does not allow subscripts I suggest to write `fix F`. This makes sense because `fix` is a combinator (program) which takes `F` as an argument and 'returns' the fixed point of `F` as a result. According to our rules for dropping parentheses we can then write `fix F 2` (which is also `(fix F)(2)` if you want to put in some parentheses) for the result of applying the fixed point of `F` (which is the factorial function in our example) to the argument `2`.

After this remark on notation, we can now say that the answer must be in the format

```
fix F 2 =           -- def of fix
F (fix F) 2 =       -- def of F
... =               
...                 
... =               
2
```

and each `=` must be justified by one of the equations defining the operational semantics of the extended lambda calculus, which are (for this homework) the equations for

- beta reduction (capture avoiding substitution)
- if then else
- `fix`
- arithmetic
- `F`

(Consult the lecture notes for details on these equations.)

**For the final report version of this homework, make sure to write out these equations in the report and annotate each step in the equational reasoning with the corresponding equation.**

## [Week 9](https://canvas.chapman.edu/courses/44405/assignments/491336)

### Milestones

```
Describe (at least) 3 milestones (other than final submission). Milestones must be verifiable, that is, the description of your milestones must contain enough detail so that by the time the milestone is due, you and I can verify whether it has been achieved. In particular, each milestone must come with a due date and a list of requirements.
```

Add the description of your milestones as section 3.2 in your report.

When your a milestone arrives do the following.
- Send me an email to akurz@chapman.edu with "Milestone" in the subject.
- Quote the description of your milestone in the email.
- Detail what you have achieved, adding any relevant evidence, such as links to code and other documentation. 
- If you milestone includes code, it must be on git in a folder that has a README telling me how to compile and run the code.

General advice: Do not delay starting to code after you finished Milestone 2. Also recall that documenting your work by regularly committing your work to git is a requirement.

General advice: Milestones are similar to a legal contract between the software developer (you) and their client (me). Describe the milestones in a language that reflects this. Avoid phrases such as "I hope to have this part done by ...". Be precise and detailed.

### The ARS

For those who have not solved the ARS

```
ba -> ab
ab -> ba
ac -> ca
ca -> ac
bc -> cb
cb -> bc
 
aa -> b
ab -> c
ac ->  
bb ->
cb -> a
cc -> b
```

I don't want to include spoilers here. Go carefully through my notes, including the feedback for the ARS of Week 8, and give it another try. As always, come to office hours for more feedback and advice.

*Hint:* Work with encoding letters as digits, use $+$ to combine digits. Also modulo arithmetic may help.

**Make sure that you justify your claims.** For example, if you write
- "There are no unique normal forms" you should exhibit an example that either has no NF or that has two different NFs. 
- "There are (exactly) four equivalence classes" you need to show (i) there are four equivalence classes and they are all different and (ii) there are no other equivalence classes. To show that all equivalence classes you identified are different use an invariant. 

More generally, a statement of the form "there is P" is justified by showing an example that satisfies the property P. And a statement of the form "for all P" is shown either by giving a proof that everything has to satsify P or that the existence of a thing with property P leads to a contradiction.

**Make sure that your justifications use the maths we learned in the lectures** (including, but not limited to, measure functions and invariants).

Also read the updated introduction to the [string rewriting exercises](https://hackmd.io/@alexhkurz/Syn23oMHF).

## [Week 8](https://canvas.chapman.edu/courses/44405/assignments/490555)

**Relevant material from the lectures:**  
- https://hackmd.io/@alexhkurz/BJ7AoGcVK  
- https://hackmd.io/@alexhkurz/B1wB3rT4F  
- https://hackmd.io/@alexhkurz/H1O4bLBHK  
- https://hackmd.io/@alexhkurz/r1dp-LBBt  
- https://hackmd.io/@alexhkurz/Syn23oMHF  
- Below I will emphasize how important it is to justify your claims. Often the justification will refer back to the material above (eg the [truth table of counter-examples](https://hackmd.io/@alexhkurz/BJ7AoGcVK) and the [theorems about the existence of UNFs](https://hackmd.io/@alexhkurz/B1wB3rT4F) and the [measure function](https://hackmd.io/@alexhkurz/H1O4bLBHK) to prove termination and [invariants](https://hackmd.io/@alexhkurz/r1dp-LBBt).)

The rewrite rules of the ARS in question are
```
aa -> a  
bb -> b  
ba -> ab  
ab -> ba  
```
I will go through this step by step, but **see also the footnotes I added to the [roadmap](https://hackmd.io/@alexhkurz/Syn23oMHF).**

- Why does the ARS not terminate?

`ab->ba->ab ...` is an infinite computation

- What are the normal forms?

`a, b, []` are normal forms (but see also below). 

- Modify the ARS so that it is terminating, has unique normal forms (and still the same equivalence relation).

A full answer is explicit about what the new rewrite system is. Termination needs to be justified (see what we learned about measure functions in the lectures).

It also needs to be shown that the modified system and the original system have the same equivalence classes. To this end you need to show that in the modified system w reduces to v if an only if in the original system w reduces v. (Hint: Use that equivalence relations, by definition, are symmteric (that is, intutively, allow us to compute backwards.)

Also you should go back to the question about the normal forms. The normal forms of the modified system could be different from the normal forms of the original system.  

(At this point I have four normal forms in my modified system: `[],a,b,ab`.)

- Describe the specification implemented by the ARS.

To answer this question, one typically finds a (complete) invariant. The best method to find an invariant is to "guess and verify". 

For example, the rule

`aa->a`

keeps the statement *at least one `a`* invariant. To verify that this is indeed an invariant, you need to check that *at least one `a`* is kept invariant also by all the other rules.

After finding this invariant, another invariant suggests itself (the observation is that the rules are symmetric under swapping `a` and `b`).

We have now two invariants:

- at least on `a`  
- at least on `b`  

which combine to the following 4 possibilities.

|Normal Form | Invariant |
|:---:|:---:|
| `[]` | no `a`, no `b` |
| `a` | at least one `a`, no `b` |
| `b` | at least one `b`, no `a` |
| `ab` | at least one `a`, at least one `b` |

At this point, the correspondence between normal forms and equivalence classes suggested by the table is only a conjecture. There are still things to verify:

- Every normal form in the first column satisfies the corresponding property in the second column.   
- (Since these properties are invariants, it follows that all the NFs are in different equivalence classes. Hence there are at least four equivalence classes.)
- Every word reduces to one of the four NFs.
- (Hence there are at most four equivalence classes.)

By this point, we know that the table gives us a full characterisation of the equivalence classes.  There are exactly four of them and we have both a computational and a mathematical characterisation. 
- Computationally, each equivalence class is characterised by its normal form. To know in which equivalence class a word is, we can reduce it to its normal form. In particular, the ARS has UNFs.
- Mathematically, the equivalence classes can be specified, using the second column, without referring to the computation rules `->`. 

The **specification of the algorithm** reconstructed from this analysis is a reformulation of the invariants:

For any word, decide whether it
- is empty
- contains `a`s but no `b`s
- contains `b`s but no `a`s
- contains `a`s and `b`s

**Make sure to include improvements along these lines in the final version of the report and to justify all the claims you make.**


## [Assignment 1](https://canvas.chapman.edu/courses/44405/assignments/484480)

(I graded this carefully, but if you feel there are questions come to my office hours to discuss.)

Make sure that your software runs "out of the box". Otherwise, you may loose points, even all points. If in doubt what I mean by this, come to my office hours. (In case I could fix the problem myself quickly, I tended to be lenient, but, to be honest, I do not think that I should do this.)

It is a general principle in software engineering that when you are asked to implement an interface, you are not allowed to change the interface. In our case that means: **Do not change the names of the functions.** Similarly, **you are not allowed to change the type of the functions**. If you change either names or types, your functions will not implement the given interface. For example, your implementation will fail my tests.

Testing is an important aspect of software engineering. I deducted a point for ignoring the following requirement from `main` in `arithmetic-specification.hs:

```haskell
-- design your own tests and add them to main 
-- make sure that all relevant functionality is tested
-- add expected test results as comments
-- do not change the names of the functions in the specification, I will use them for testing
```

I also deducted a point for 

- ignoring in the critical appraisal to "be upfront about any requirements not implemented, or any remaining bugs you know of" (not knowing about bugs due to a lack of testing on your side is not an argument that is likely to convince me, but you can come to office hours and discuss this with me ... I dont want to deduce a point here for accidentally missing a subtle bug)
- not keeping the naming conventions such as `Assignment1/Part1` ... I hate doing this, but if I don't, I send the signal that I don't care.



### Critical Appraisal

-2 if computations were missing.

I did not deduce points for missing **interesting observations** but I will next time. 

Many points were lost due to lack of testing. Often `arithmetic.hs` did only contain a few tests in `main`. **You need at least one test for each line of code.** (This is a rule of thumb that applies to programs like `arithmetic.hs` ... I will say more about it in class.)

When you work in a team, in your writing, use "we" instead of "I" (or specify the author). 

Always spell-check. Write with care. If the form is sloppy, readers will doubt the content as well. 

### Part 1

- `addN` and `addP` are recursive. Note how these recursive definitions reflect the recursive definition of the datatypes `NN` and `PP.

- `addI` and `addQ` are not recursive. In fact, they are given by a single equation. This reflects that `II` and `QQ` are not recursive datatypes.

- Equality: There is a built-in equality that is available via `deriving Eq`. This equality is defined "componentwise". The componentwise definition works for `NN` and for `PP`, but not for `II` and `QQ`. To see this let us look at some examples:
  -  Integers: We have `(1,2)=(2,3)` even though the first components (1 and 2) and the second components (2 and 3) are different.
  -  Fractions: We have `(1,2)=(2,4)` even though the components are different again.

### Part 2

I expected input such as `2*--3` and `2--3` to be legal. If your calculator did not accept such input and you did not explain why you made this decision, you lost points.

I expected `2^3^2` where `^` is exponentiation to evaluate to `512`. If your calculuator evaluated to a different number and you did not explain why you made this decision, you lost a point. 


## [Week 7](https://canvas.chapman.edu/courses/44405/assignments/488837)

*Introductory Question:* How are the 3 topics of this HW (scope, computing `evalCBN', rewriting) related?

*One Possible Answer:* 
- Haskell uses the defining equations of `evalCBN` to rewrite to normal form, which is then the result of the computation. Ideally, functional programming is confluent, non-terminating (because of recursion) and has unique normal forms, but real existing languages may deviate from this ideal in exceptional circumstances.
- In our string rewriting exercises, we simplify by not considering rewriting of ASTs with variables and binders. This is good enough to learn basic concepts such as normal form, confluence, termination, having unique normal forms, invariants, etc.
- To understand Haskell rewriting (and the meaning of any other programming language for that matter) one needs to understand the scope of variables and other names.

### Free and bound variables

Don't say: "variable bounds" (use technical language carefully).

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

https://hackmd.io/@alexhkurz/ByIktUq-i

The computations need to be performed on abstract syntax, showing the rewriting steps that the interpreter is taking. Again, many students did not take the time to do this. I know it is hard, but it will be a valuable skill to have in upcoming assignments.

To help you, I write out the computations by mixing Haskell syntax and concrete lambda-calculus syntax. Your remaining task would be to write this out in the abstract lambda-calculus syntax used by Haskell and annotate each `=` by the appropriate line number from [this file](https://github.com/alexhkurz/programming-languages-2022/blob/main/src/LambdaNat0/src/Interpreter-fragment.hs).

We first compute

```haskell
evalCBN ((\x.\y.x) y) =
evalCBN (subst x y (\y.x)) = 
evalCBN (\a.y)
```

and use this in the computation

```haskell
evalCBN ((\x.\y.x) y z) = 
evalCBN ((\a.y) z) = 
evalCBN (subst a z y) = 
evalCBN z
```

### The homework as specified in https://hackmd.io/@alexhkurz/BJ7AoGcVK

Don't say: "valid ARS"

#### Part 1

We have drawn the pictures in class. Here is the list of properties of the 7 examples (check against your solution and come to my office hours in case there are any questions remaining).

1. terminating, confluent, UNF
2. terminating, confluent, UNF
3. non terminating, confluent, no UNF
4. terminating, not confluent, no UNF
5. not terminating, confluent, UNF
6. not terminating, not confluent, no UNF
7. not terminating, not confluent, no UNF

#### Part 2

The truth table of ARS properties is linked from the homework.

For each row in the truth table that doesn't have an example, there must be a corresponding theorem (explaining why no such example can exist). Which theorems best explain the missing examples of the ARS truth table?

(The answer was discussed in class and can be found in the lecture notes. Come to the office hours if you have any doubts.)

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


## [Week 5](https://canvas.chapman.edu/courses/44405/assignments/485938)

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

#### Computing `evalCBN`

(I didn't deduce points if the `evalCBN` part was missing, you still need to do the work.)

https://hackmd.io/@alexhkurz/ByIktUq-i

The computations need to be performed on abstract syntax, showing the rewriting steps that the interpreter is taking. Again, many students did not take the time to do this. I know it is hard, but it will be a valuable skill to have in upcoming assignments.

To help you, I write out the computations by mixing Haskell syntax and concrete lambda-calculus syntax. Your remaining task would be to write this out in the abstract lambda-calculus syntax used by Haskell and annotate each `=` by the appropriate line number from [this file](https://github.com/alexhkurz/programming-languages-2022/blob/main/src/LambdaNat0/src/Interpreter-fragment.hs).

```haskell
evalCBN ((\x.x)((\y.y)a)) = 
evalCBN (subst x (\y.y)a) x) = 
evalCBN ((\y.y)a) = 
evalCBN (subst y a y) = 
evalCBN a = 
a
```

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

Your repo needs to be private and I need to be invited as a collaborator.	

If you have latex questions, try first to find the answer on stackexchange.






