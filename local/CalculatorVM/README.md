compiles

parser works

Calculator even hangs on small inputs such as 0+0

... did not try to find out why ...

Another problem is that to match up the bnfc generated parser with Arithmetic.hs, the data types of Arithmetic.hs need to be produced by the context-free grammar. This forces us to use the syntax of NN, II, QQ in the concrete syntax of the calculator, which is very ugly.