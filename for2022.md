# for 2022

# Report

Instead of a midterm and final exam, you will write a report. Part 1 of the report focuses on the exercises and homework from the lectures. Part 2 of the report is a mini project in which you can explore some aspect of the course that you like to explore more deeply.

- Part 1 (10x6=60 points): Homework.
- Part 2 (40 points): Mini-project.

The [LaTeX template](report.tex) and the compiled [pdf](report.pdf) (needs to be adapted to 2022).

You will keep both report.tex and report.pdf in your private github repository.

**Deadlines:**
- Weekly deadlines for Part 1. Each week has 3 points upon completion.  10x3=30 points for content are awarded after the final deadline in December.
    - Week 1: Writing a report in LaTeX.
    - Week 2: Executing functional programs pen-and-paper.
    - Week 3: Parsing arithmetic expressions pen-and-paper.
    - Week 4: Parsing lambda calculus expressions pen-and-paper.
    - Week 5: Variable Binding and Church encodings.
    - Week 6: Rewriting 1: Transitive Closure and Equivalence Relations.
    - Week 7: Rewriting 2. Confluence, Normal Forms, Termination.
    - Week 8: Fixed point combinator.
    - Week 9: Rewriting 3. ...
    - Week 10: Rewriting 4. ...
    - Week 11: (Optional) Theorem Proving.
    - Week 12: (Optional) Hoare Logic.

- Part 2 is due at the end of the examination week in December.

**Submissions:** 
- For Part 1, by [email](mailto:akurz@chapman.edu?subject=Report%20Week%20X), where X denotes the number of the deadline;
- For Part 2, by [email](mailto:akurz@chapman.edu?subject=Report%20Part%202)
- In all cases, send a link to the pdf in your private github where you keep your .tex and .pdf as well as any accompanying code for Part 2. (Get in touch if you want to do a theory project without Haskell code.) 


## Grading Guidelines

Programming Languages is a vast subject. At the core of this course are three interpreters of increasing complexity. They are assessed in three assignments. This is supplemented by some theory on lambda calculus and rewriting. But there are many topics we can only touch upon.  Most obviously, there is much more to Haskell than we strictly need for the course. Similarly, there are many theoretical topics we mention only in passing. The overarching rationale for the grading guidelines below is to assess how much you master of the practice of Haskell and the theory of programming languages and how far you engage with some of the ramifications of Programming Languages that go beyond the material of the course.

- **D:** Demonstrates *basic* familiarity with Haskell and the theory of Programming Languages as presented in this course.
- **C:** Demonstrates *adequate* familiarity with Haskell and the theory of Programming Languages as presented in this course. Discusses interesting features of Haskell and illustrates them with their own project. Reviews the theoretical concepts treated in the course and illustrates them with a selection of homework and own examples.
- **B:** Demonstrates *good* understanding of Haskell and the theory of Programming Languages as presented in this course. In addition to the previous item: Develops material that goes beyond what has been treated in class. Can be recommended to next year's students as a learning resource. Makes connections between the practical and theoretical parts of the course. 

A grade of B can be achieved with a report that contains a *Haskell tutorial* for beginners in Part 1 and demonstrates in Part 2 that the techniques needed to solve the *theory homeworks* have been mastered.  

- **A:** Demonstrates *excellent* understanding of the area of Programming Languages as presented in this course. Is inspired by the course material but takes an independent perspective and *stands on its own*. Develops material that goes significantly beyond what has been treated in class. Can be highly recommended to next year's students as a learning resource. Makes interesting connections between the practical and theoretical aspects. 

A grade of A can be achieved by adding more challenging material to the Haskell tutorial and the theory homeworks. But, typically, I expect a grade A report to be project based. Here are some examples of projects:
- A Haskell project that is related to this course, for example developing software tools for the analysis of string rewriting systems.
- A theorem proving project along the lines of Chapter 2 and 3 of the book [Concrete Semantics](http://concrete-semantics.org/).
- A math project that explores the category theoretic foundations of programming languages. 

A way to describe when a report gets the full 100 points: You would be proud to add it to your resume and I would be proud to show it to my colleagues bragging about how good our students are.

## Tips on Writing

- Spelling, typesetting, layout, and structure will also be taken into account for grading. Does the form support the understanding of (or does it distract from) the content? 
- Every section should have something interesting to say and be built around a central idea. If a section reads just like a lists of items without a connecting narrative something is missing.
- As usual, for full points I need to be able to see a trail of your work on git (if you don't want to use git get in touch early ... overleaf could be an alternative). 

- Typeset code differently from text (eg using `\texttt`).
- Do not always go with the first reference that comes up, try to find interesting references for each topic. Cite your references throughout the text.
- In case of doubt, put rather more references. The basic idea of scientific writing is that all claims must be justified. (Of course, every community has its common knowledge.) 
- In Latex, you can use  `\href` to link to online material.

## Tips on Content

Make the report interesting to a readers including myself. Do not simply repeat material that is already in the lecture notes.  Explore on your own. If you write about material we have covered in the lectures, make your own examples and add your own angle. Your report can build on homework if you integrate them into your own narrative.

### Haskell Tutorial

Some example topics:

- What do you think you should have known when you started with Haskell?
- Make your own examples that you think would help a beginning Haskeller to understand Haskell better.
- Benchmark the same algorithms in Haskell, Python, etc. You can use [gnomon](https://github.com/paypal/gnomon) to measure the time that programs take to run.
- I collected some ideas for [Haskell projects](haskell-projects.md) you might want to try.
- Write about some features of Haskell that only appear on the sidelines in this course:
    - Haskell is lazy
    - Haskell has type classes
    - Haskell has monads 
    If you decide on such a topic, do not treat it too superficially. Always add code examples of your own.
- You may decide to write on topics we didn't have time for at all, for example:
    - History of Haskell  
    - Application of Haskell in industry

### Theory Homework

A good starting point is the homework in the lecture notes. Topics of revelance are (choose some of them):
- **Parsing.** Example topics: Give your own examples of ambiguous and non-ambiguous grammars. Explain, at the hand of an example, how to make a grammart non-ambiguous. Modify the grammar of your calculator by changing precedence levels and explain how different precedence levels correspond to different conventions about which parentheses can be dropped.
- **Lambda Calculus.** Examples: Make your own examples and exercises on variable binding and scope. Show sample reductions that explain how computations with the fixed point combinator or with Church numerals work. Implement Church numerals in Haskell (you need to think about how to print them). What is the type of the Haskell Church numerals? Can you explain them?
- **String Rewriting.** Confluence, normal forms, termination, invariants and exercises. (Recommended.) For more challenges have a look at the Baader-Nipkow book. You could for example take some other proof of the book and treat in the way we have done [here](https://hackmd.io/@alexhkurz/BkNlJ07IY).
- Curry Howard Isomorphism and Type Inference. Take some simple lambda terms and type them. Interpret the types as logical formulas and show that they are tautologies. Conversely, choose some tautologies and find lambda expressions of that type.
- Operational and Denotational Semantics. The lecture on operational semantics contains a number of exercises that could be fun for the mathematically inclined student. Get in touch if you want to do this.
- **Hoare Logic.** Have a look at the exercises. I can also provide more.

The topics which we look at in more depth are in boldface. Whatever topics you choose, I want to see that you can solve some concrete exercises and also that you can connect the theory with other aspects of  the course.

