# README

This folder contains an interpreter for the lambda calculus as given by the grammar

    EAbs.   Exp ::= "\" Id "." Exp ;  
    EApp.   Exp ::= Exp Exp1 ; 
    EVar.   Exp1 ::= Id ;
    
To parse and run a program:

- (I assume you have Haskell and bnfc)

- Copy this directory `LambdaNat0` to your local machine.

- `cd` into `LambdaNat0`.

- Use `bnfc` to generate a parser from `grammar/LambdaNat0.cf`.

    ```bash
    cd grammar
    bnfc -m --haskell LambdaNat0.cf
    make
    cd ..
    ```

- Copy the relevant Haskell files generated by the parser generator (bnfc) into the directory containing the source files of the interpreter.

    ```bash
    `cp grammar/*.hs src`
    ```

- Build an interpreter with 
    ```bash
    stack build 
    ````

- Assuming that `myprogram.lc` is in the folder `test`, run 
    ```bash
    stack exec LambdaNat-exe test/myprogram.lc
    ```
