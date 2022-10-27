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
            LambdaNat4 -- my solutiont to Part 1 (available after the deadline for Part1)
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

## Part 0: Getting Started With Natural Numbers

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

## Part 1: Conditionals and Recursion

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

**Task** (worth 5 points): Implement `EIf`, `ELet` and `EMinusOne` in the interpreter. (3 lines of code for `evalCBN` and 3 lines of code for `subst`.) 

Hints: For `EIf` use Haskell's if-then-else. For `ELet` use the definition of the semantics of `let` as an application of lambda-calculus. For `EMinusOne` use pattern matching (if `n` matches `ENatS m` then `m` is one less than `n`.)

**Extra Challenge:** Implement `ERec`.

## Part 2: Computing with Lists

(25 points, including 5 points for the critical appraisal.)

... to be continued ...