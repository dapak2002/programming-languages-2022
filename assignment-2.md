# Assignment 2 

This assignment comes in two parts.

## Introduction

The purpose of the assignment is to build a simple functional programming language that has function definitions, function application, numbers, conditionals, recursion and lists. We start from lambda calculus, which already has function definitions and application.


## Instructions

You may form groups again. This time, groups of 3 are possible. Easiest for me is if you keep working **in the same repo as before** (if that is not possible get in touch). Make folders as follows

    YourRepo
        Assignment1 -- contains your work on Assignment 1
        Assignment2
            README.md -- group members, your critical appraisal
            LambdaNat0 -- just a copy of my folder LambdaNat0
            LambdaNat1 -- your work as specified below for Part 0
            LambdaNat2 -- my solution to Part 0 (available after class)
            LambdaNat3 -- your solution to Part 1
            LambdaNat4 -- my solution to Part 1 (available after the deadline for Part 1)
            LambdaNat5 -- your solution to Part 2

**You need to keep my naming conventions as I will run scripts to test your software.** As in Assignment 1, also for this assignment my naming conventions are part of the specifications. 

## General Remarks 

### Rationale

We are aiming for the simplest possible interpreter of the simplest interesting functional programming language. Amongst many other simplifications, the language is untyped, the implementation is not optimized for efficiency, and the interpreter does not produce meaningful error messages. 

### Interpreter

For each constructor in the grammar there will be one clause in the definitions of `subst` and `evalCBN`.

`subst` just applies `subst` recursively to sub-expressions. For `evalCBN` this is often not enough. For `evalCBN e` you may want to use Haskell's `case` to make a case-distinction on the result of evaluating `e`.

### Debugging

As the interpreter and programs gets more complicated, you are likely to run into problems with debugging. One difficulty is to determine whether unexpected results are caused by the program or by the interpreter. If you run into unexpected behaviour create a [minimal interesting example (MIE)](MIE.md). 

## Part 0: From LambdaNat0 to LambdaNat1 - Getting Started With Natural Numbers

(our work in class)

Before you start, work through this [README](https://github.com/alexhkurz/programming-languages-2022/tree/main/Lab1-Lambda-Calculus). 

The task is to add natural numbers (in successor style) to `LambdaNat1`. That is, we need cases for zero and successor in the grammar and in the interpreter.

The relevant modifications that the grammar `LambdaNat1.cf` will make to `LambdaNat0.cf` are the following.  You can also design your own grammar, but this is what I used:

```
Prog.   Program ::= Exp ; 
EAbs.   Exp1 ::= "\\" Id "." Exp ;  
EApp.   Exp2 ::= Exp2 Exp3 ; 
ENat0.  Exp3 ::= "0" ;
ENatS.  Exp3 ::= "S" Exp3 ; 
EVar.   Exp4 ::= Id ; 

coercions Exp 4 ;
```

Test the grammar in the usual way by parsing some lambda expressions such as `(\ x . S x) S 0`.

Next we look at the interpreter.

Do the computation `(\ x . S x) S 0 = S S 0` pen and paper. **Think about what you need to add to `evalCBN` and `subst` to make this computation work.** 

- Add two cases for `ENatS` and `ENat0` to `evalCBN`. 
- Add two cases for `ENatS` and `ENat0` to `subst`. 

These 4 lines of code are simpler than you may think. They are just pushing symbols around. But remember that they need to use abstract syntax (`ENatS` and `ENat0` instead of `S` and `0`). So I think it should help to first write out the 4 clauses in an informal way, possibly using concrete syntax, before translating them into the correct Haskell code. For example, the case for how `subst` should handle successor could be written in pseudo code as
```haskell
subst i e2 (S e3) = S (subst i e2 e3)
```
the idea being that to substitute in `S e3` I need to substitute in `e3` and keep the `S` around.

(Recall that we read `subst i e2 e3` as "substitute `i` by `e2` in `e3`".)

## Part 1: From LambdaNat2 to LambdaNat3 - Conditionals and Recursion

The purpose of this part is to add conditionals and recursion to Part 0, see the [lecture notes](https://hackmd.io/@alexhkurz/rJEeYqZtw) for the necessary background. Your new version will be in a folder `LambdaNat3`.

We start from the grammar (you have to make this part of your grammar `LambdaNat3.cf`.)

```
Prog.      Program ::= Exp ;  
EAbs.      Exp1 ::= "\\" Id "." Exp ;   
EIf.       Exp2 ::= "if" Exp "=" Exp "then" Exp "else" Exp ; 
ELet.      Exp2 ::= "let" Id "=" Exp "in" Exp ;               -- let x = A in B is sugar for (\x.B)A  
ERec.      Exp2 ::= "let rec" Id "=" Exp "in" Exp ;
EMinusOne. Exp2 ::= "minus_one" Exp ;                         -- because we do not have pattern matching in LambdaNat
EApp.      Exp3 ::= Exp3 Exp4 ;  
ENat0.     Exp4 ::= "0" ; 
ENatS.     Exp4 ::= "S" Exp4 ; 
EVar.      Exp5 ::= Id ;  
internal EFix. Exp2 ::= "fix" Exp ;                           -- to implement "let rec"
```

`internal` means that EFix is part of the abstract syntax but not of the concrete syntax. We need EFix to implement `let rec`.

**Task** (worth 5 points): Implement `EIf`, `ELet` and `EMinusOne` in the interpreter. (3 equations for `evalCBN` and 3 equations for `subst`.) 

Hints: For `EIf` use Haskell's if-then-else. For `ELet` use the definition of the semantics of `let` as an application of lambda-calculus. For `EMinusOne` use pattern matching (if `n` matches `ENatS m` then `m` is one less than `n`.)

**Extra Challenge:** Implement `ERec`.

## Part 2: From LambdaNat 4 to LambdaNat5 - Computing with Lists

(25 points, including 5 points for the critical appraisal.)

The purpose of this part is to add some integer arithmetic and lists. Start from my `LambdaNat4`. Your new version will be in a folder `LambdaNat5`.

### What I changed for LambdaNat4

Open the grammar in an editor.

- Instead of defining our own successor numbers we now use the data type `Integer` built into BNFC and Haskell. I also added operations `+,-,*` and `less_equal`.
- We now allow a `Prog` to be a list of expressions separated by `;;`. This allows a file to contain several expressions, see `test/test.lc` for an example.
- I determined the order of operations (precedence levels) in such a way that the rules for dropping parentheses look natural to me. In case you get parsing or run-time errors check whether more parentheses help before spending time hunting for other errors.

Open `Interpreter.hs` in an editor.
- I indicated in comments where you need to add new code. `+,-,*` are implemented and `less_equal` will be similar. Are `+,-,*` implemented using call by name or call by value? What could be a reason for this choice?


Open `text/test.lc` in an editor.
- After building LambdaNat4 (with `./build.sh`) and running `cabal exec LambdaNat-exe test/test.lc`, you should get the output `3 ;; 120 ;; true`.

### Instructions

From now on you will be working `LambdaNat5`. At the beginning your `LambdaNat5` should be a copy of my `LambdaNat4`.

You will add all your solutions to a file `test/solutions.lc`. Each solution will contain one test case that is executed when running `solutions.lc`. Put further test cases in comments. Solutions will be separated by `;;`.

You can also make additional files for further testing.

### Task 1: Extend the interpreter

Your grammar for LambdaNat5 will be the same as the grammar for LambdaNat 4. For this task, note that the grammar contains

    EHd.       Exp6 ::= "hd" Exp ;
    ETl.       Exp6 ::= "tl" Exp ;
    ELE.       Exp9 ::= Exp10 "less_equal" Exp10 ;
    ENil.      Exp15 ::= "#" ; 
    ECons.     Exp15 ::= Exp16 ":" Exp15 ;

Let us look at some of the details.

- According to the rules `ENil` and `ECons` we can build lists such as

        a:b:c:#

    The precedence levels of the grammar are engineered in such a way that `a:b:c:#` is parsed as `a:(b:(c:#))`.

    For the exercise below, recall that abstract syntax is defined in `AbsLambdaNat.hs`, which in turn is generated automatically by BNFC.

    **Exercise:** (not necessary to hand this in, but should help to implement the computation rules for `hd` and `tl` in the interpreter) What is the abstract syntax tree of `a:b:c:#`? Write the answer down on paper. Run `a:b:c:#` in the parser and compare with your pen-and-paper answer.

- `hd` and `tl` are pronounced "head" and "tail", respectively. The first task here is to adapt the interpreter of LambdaNat4 in such a way that head and tail compute as, for example,

        hd a:b:c:#   --*-->   a
        tl a:b:c:#   --*-->   b:c:#

    Note that this does not specify what will happen if your computation reaches `hd #` or `tl #`. In my solution, Haskell will raise a "Non-exhaustive patterns" exception at runtime if `hd` or `tl` are applied to data that is not a non-empty list. (This has the advantage that the interpreter is kept as simple as possible and the disadvantage that no good error messages are generated.)

    Here are some further test cases to check whether your interpreter "reduces under a `hd`". 

        hd ((\ x . x) a : #)   --*-->   a
        hd ((\ x . x) a) : #   --*-->   a

    Similarly, one should reduce under a `tl`.

    **Hint:** The code in the interpreter for `EHd e` needs to 
    - evaluate `e`
    - in case `evalCBN e` is of the form `ECons e1 e2`, evaluate `e1`.

    Also note that lists are similar to successor numbers. After all, a successor number is essentially just a list of `S`s (and `0` plays a role similar to the EndOfList symbol `#`). Taking this comparison further, `tail` corresponds to `minus_one` since both chop off the first element of their respective input. 

    **Exercise:** (not necessary to hand this in, but should help to see how to implement the two rules above in `Interpreter.hs`) Translate the computation rule `hd a:b:c:#   --->   a` from concrete syntax to abstract syntax. Also run `hd a:b:c:#` in the parser and compare.

**Task:** Implement the computation rules for `EHd`, `ETl`, `ENil`, `ECons` by adding 4 cases to the definition of `evalCBN` in `Interpreter.hs`. 

**Task:** Implement the computation rule for `less_equal` (which is similar to `+,-,*`). `n less_equal m` should evaluate to `1` if `n` is an integer less or equal to the integer `m` and should evaluate to `0` if `n` is an integer greater than the integer `m`.

### Further comments

- Lists can also be nested in order to form trees as in 

        Plus:(N1:#):(Times:(N2:#):(N3:#):#):#

    If you wonder why we need the EndOfList symbol `#` above, then the answer is that in the tree above it is redundant if we have agreed that the `N` symbols are constants (take no arguments) and that `Plus` and `Times` are binary (take exactly 2 arguments). Then we could write the above instead as 

        Plus:N1:(Times:N2:N3)

    (which, by the way, we can think of as an abstract syntax tree for `1+2*3`.) The reason we need the EndOfList symbol is that lists are meant to work in situations where we do not know at *programming time* (aka compile time) how long the lists will be at *run time*. 

- The previous remark hides a deeper duality between two different readings of `#`, one as the empty list (often written as "nil") and the other has the EndOfList symbol. This duality is known as the duality of **algebras** and **co-algebras**. In the algebraic view, we *build* or *construct* finite data from smallest data (here `ENil` with concrete syntax `#`) by inductively applying a finite number of rules (here `ECons` with concrete syntax `:`). In the co-algebraic view, data is potentially infinite and we *observe* or *deconstruct* this data (here using `hd` and `tl`) until we get to the end symbol (here `#`).

### Testing LambdaNat5

When you start writing your own `LambdaNat5` programs don't forget that unexpected results obtained from running your programs could be due to errors in the interpreter. Here are some test cases I found useful, but you need to create your own in order to gain confidence in your interpreter. Put them in a file `test/mytests.lc`.

| Program | Result |
|---|---|
| `hd one:two` | `one` |
| `hd one:two:#` | `one` |
| `hd (one:two):#` | `one : two` |
| `hd (one:two:#):#` | `one : two : #` |
| `(hd one:two:#):#` | `one : #` |

As common in functional programming I designed the grammar so that you can drop many parentheses. But this also means that you need to watch out carefully where parentheses are needed. In case of doubt you can always put them in, for example `(hd one:two:#):#` abbreviates `(hd (one:(two:#))):#`. A good way to learn where parentheses go is 
- to look at the precedence levels in the grammar,
- to put in enough parentheses so that the program runs in the expected way and then to eliminate all unnecessary parentheses two by two.

### Task 2: Write `LambdaNat5` programs

Now we have our own programming language, LambdaNat5, it is time to write some programs in that language. Remember that the syntax of the languages is defined in `grammar/LambdaNat5.cf` and the operational semantics is as defined in `src/Interpreter.hs`. For example programs see `test/test.lc`.

- You will provide in `test/solutions.lc` the functions

        is_empty
        fib
        length
        even
        reverse (with append)
        weave

    Running 
                
        cabal exec LambdaNat-exe test/solutions.lc 
    
    should produce the correct outputs as described in the test cases below. **Indicate further tests in comments.** (For example, all branches of an if-then-else should be covered by some test.)

#### `is_empty`

`is_empty l` evaluates to `1` if `l` is the empty list and to `0` if `l` is not empty.

Test case:

`is_empty a:#    --*-->    0`

(Similarly, `isempty #    --*-->    1`.)

#### `fib`

`fib n` evaluates to the `n`-th element of the Fibonacci sequence

    0,1,1,2,3,5,8,13,...'

Test case:

`fib 6    --*-->    8`

#### `length`

`length l` evaluates to the length of a list `l`.

Test case:

```
length a:b:c:#    --*-->    3
```

#### `even`

`even l` evaluates to `1` if `l` is a list of even length and evaluates to `0` if `l` is not of even length, for example

```
even a1:a2:a3:a4:#      --*-->   1    
```

(And, similarly `even a1:a2:a3:a4:a5:#   --*-->   0`)

#### `reverse`

`reverse l` reverses a list `l`. For example,

Test case:

```
reverse a:b:c:#    --*-->     c:b:a:#
```

#### `weave`

`weave ns ms` weaves together to lists of integers, respecting their order. More explicitely, 
- `weave` satisfies the invariant that the output-list is sorted if the input-lists are sorted;
- `weave` satisfies the equation

        length (weave ns ms) = (length ns) + (length ms)

Test case:

    weave (0:1:4:#) (2:3:5:#)    --*-->    0:1:2:3:4:5:#

### Task 3

Implement the functions of Task 2 also in Haskell and add them to a file `test/solutions.hs`. This file should have a `main`-function that prints the results of the same test cases specified above. 

### Critical Appraisal

(5 points, approx one page)

There are a lot of interesting questions. For example, `#:#` does not parse, but `(#):#` does. Why? Does that mean that it would make sense to change the grammar? 

As you spent quite a lot of time on this assignment, I would like to know about the questions you came up with. For full points, your critical appraisal needs to contain **personal interesting** observations and/or questions.

In addition, also discuss the following.

- Explain what changes where made in `LambdaNat4` in order to accommodate multiple test cases (separated by `;;`) in the same file.

- Reflect on the differences between LambdaNat5 and the Calculator. In LambdaNat5, why can't we implement arithmetic using the simple
    ```
    evalCBN (EPlus e1 e2) = (evalCBN e1) + (evalCBN e2)
    ```
    similar to what we have done in the calculator? Are `+,-,*` implemented using call by name or call by value? What could be a reason for this choice?

- Reflect on the differences between LambdaNat5 and Haskell. In your experience from this assignment, how does writing code in LambdaNat5 and Haskell compare? How far did we come in implementing a functional programming language? What is missing? What can you say about how one should go about extending LambdaNat5 to a more powerful functional language (such as Haskell)?

- Did you notice that `weave` satisfies the invariant "the output-list is sorted if the input-lists are sorted"? Can you use it to prove the correctness of `sort` (that is, that `sort` actually does sort)?
