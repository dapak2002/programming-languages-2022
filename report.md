# Report

Instead of a midterm and final exam, you will write a report. Think of it as a take home with several deadlines throughout the semester plus a final project.

- Part 1 (12x3=36 points): Homework.
- Part 2 (64 points): Final project.

The [LaTeX template](report/report.tex) and the compiled [pdf](report/report.pdf).

- You will keep both report.tex and report.pdf in your private github repository. - Give me access to your private github repo by inviting me as a collaborator (my GitHub name is alexhkurz).
- Submission info below.

**Deadlines:**
- Weekly deadlines for Part 1. Each week has 3 points upon completion.  10x3=30 points for content are awarded after the final deadline in December.
- Deadline is the Sunday at midnight. This gives me time to look over your answers on Monday. I will discuss the questions Tuesday in class and you will have an opportunity to improve your answers. (The following is preliminary, we may have to adapt it as we go along.)
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
    - Week 11: Theorem Proving. ...
    - Week 12: Hoare Logic. ...

- Part 2 
    - A specification of your project is due on the last day of September.
    - A prototype implementation (or the core section of a theoretical report) is due on the last day of October.
    - A draft of Part 2 is due on Sunday before the Thanksgiving break.

- The full report is due on the Sunday of the examination week. 

**Submissions:** 
- For now I would like you to submit both via Canvas and via [email](mailto:akurz@chapman.edu?subject=Report%20Week%20X), where you replace "X" in the subject by the relevant number of the week ... if it works out on Canvas we can drop the  email ...
- For Part 2, by [email](mailto:akurz@chapman.edu?subject=Report%20Part%202).
- For the final submission, [email](mailto:akurz@chapman.edu?subject=Report%20Final).
- In all cases, send
    - a pdf 
    - a link to your private github where you keep your .tex and .pdf as well as any accompanying code. 

(A programming project without working code on git will get no points. Get in touch early if you want to do a theory project without code.) 

Do not make different copies of report.tex or report.pdf. I will use git to verify timestamps and git's version control if I need to go back to an earlier version.

## Grading Guidelines

- **D:** Demonstrates adequate understanding of the material, with possibly some missed deadlines and some wrong solutions. No project.
- **C:** Demonstrates *good* understanding of the material. No missed deadlines. Correct solutions to the homework. A straightforward project.
- **B:** Demonstrates *very good* understanding of the material. No missed deadlines. Correct solutions to the homework. The project explores a topic related to this course and shows that the student deepened their understanding significantly.
- **A:** As for B. Moreover, the student is able to apply the concepts of this course to a challenging problem or project showing strong problem solving skills .

A way to describe when a report gets the full 100 points: You would be proud to add it to your resume and I would be proud to show it to my colleagues bragging about how good our students are.

Some further considerations:

- Spelling, typesetting, layout, and structure will also be taken into account for grading. Does the form support the understanding of (or does it distract from) the content? 
- As usual, for full points I need to be able to see a trail of your work on git. 

## Example Project Topics

I don't want to limit your creativity, so please get in touch if you have your own ideas.

- Data Analysis:
    - Github has an enormous amount of public available data. If you have experience with data analysis, you can use it to learn more about how programming languages are used. For example, look at [GHArchive](https://www.gharchive.org/).
- Programming:
    - A software package that allows us to benchmark programs in different programming languages and graph the results for comparison. (Doesn't need to be developed in Haskell.)
    - Implementing a calculator in a programming language other than Haskell. BFNC can generate abstract syntax trees in a variety of languages.
    - Writing an interpreter for LISP.
    - A Haskell project that is related to this course, for example developing software tools for the analysis of string rewriting systems.
    - Learn a new programming language.
    - Implement algorithms in LambdaFun that modify data structures on the heap. (Programming with pointers.)
    - Programming with infinite lists in Haskell.
- Theory:
    - A theorem proving project along the lines of Chapter 2 and 3 of the book [Concrete Semantics](http://concrete-semantics.org/).
    - Exploring Hoare logic in more depth.
    - A math project that explores the category theoretic foundations of programming languages. 
    - A project on computability and/or complexity: halting problem, Turing completeness, Church-Turing thesis, etc.
    - Applying the methods of the class to problems in the book Goedel, Escher, Bach.
    - Typeinference in lambda calculus, natural deduction, Curry-Howard correspondence.

## Writing Tips:

- Typeset code different from text.
- Do not always go with the first reference that comes up, try to find interesting references for each topic. Cite your references throughout the text.
- In case of doubt, put rather more references. The basic idea of scientific writing is that all claims must be justified. (Of course, every community has its common knowledge.) 
- In Latex, you can use  `\href` to link to online material.

The report is not an English assignment, but I find this classic and entertaining [advice by George Orwell](https://www.orwell.ru/library/essays/politics/english/e_polit) useful. 
- To avoid what Orwell calls "this mixture of vagueness and sheer incompetence" is particularly important in technical writing. 
- "A scrupulous writer, in every sentence that he writes, will ask himself at least four questions, thus: What am I trying to say? What words will express it? What image or idiom will make it clearer? Is this image fresh enough to have an effect? And he will probably ask himself two more: Could I put it more shortly? Have I said anything that is avoidably ugly?" Perhaps metaphors play a lesser role in our kind of technical writing, but if you replace "image" above by "example", Orwell's remarks are again exactly to the point.
- Orwell recommends to avoid writing something just because it sounds good. Instead, 
    - "put off using words as long as possible and get one's meaning as clear as one can through pictures". 
    - first "think wordlessly, and then, [...] describe the thing you have been visualising". 

