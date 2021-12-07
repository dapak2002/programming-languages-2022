-- A Virtual Machine (VM) for Arithmetic (solution)
-- Copyright: Richard Dedekind 1887, Alexander Kurz 2021

-----------------------
-- Data types of the VM
-----------------------

-- Natural numbers
data NN = O | S NN
  deriving (Eq,Show) -- for testing equality and printing

-- Integers
type II = (NN, NN)

-- Positive integers (to avoid dividing by 0)
data PP = I | T PP

-- Rational numbers
type QQ = (II,PP)

------------------------
-- Arithmetic on the  VM
------------------------

----------------
-- NN Arithmetic
----------------

-- add natural numbers
addN :: NN -> NN -> NN
addN O m = m
addN (S n) m = S (addN n m)

-- multiply natural numbers
multN :: NN -> NN -> NN
multN O m = O
multN (S n) m = addN (multN n m) m

----------------
-- II Arithmetic
----------------

-- Addition: (a-b)+(c-d)=(a+c)-(b+d)
addI :: II -> II -> II
addI (a,b) (c,d) = (addN a c,addN b d)

-- Multiplication: (a-b)*(c-d)=(ac+bd)-(ad+bc)
multI :: II -> II -> II
multI (a,b) (c,d) = (addN (multN a c) (multN b d), addN (multN a d) (multN b c))

-- Subtraction: (a-b)-(c-d)=(a+d)-(b+c)
subtrI :: II -> II -> II
subtrI (a,b) (c,d) = (addN a d,addN b c)

-- Negation: -(a-b)=(b-a)
negI :: II -> II
negI (a,b) = (b,a)

----------------
-- QQ Arithmetic
----------------

-- add positive numbers
addP :: PP -> PP -> PP
addP I p = T p
addP (T p) q = T (addP p q)

-- multiply positive numbers
multP :: PP -> PP -> PP
multP I p = p
multP (T p) q = addP (multP p q) q

-- convert numbers of type PP to numbers of type II
ii_pp :: PP -> II
ii_pp I = (S O,O)
ii_pp (T p) = addI (S O,O) (ii_pp p)

-- Addition: (a/b)+(c/d)=(ad+bc)/(bd)
addQ :: QQ -> QQ -> QQ
addQ (a,b) (c,d) = (addI (multI a (ii_pp d)) (multI (ii_pp b) c),multP b d)

-- Multiplication: (a/b)*(c/d)=(ac)/(bd)
multQ :: QQ -> QQ -> QQ
multQ (a,b) (c,d) = (multI a c,multP b d)

----------------
-- Normalisation
----------------

normalizeI :: II -> II
normalizeI (n,O) = (n,O)
normalizeI (O,m) = (O,m)
normalizeI (S n, S m) = normalizeI (n,m)

----------------------------------------------------
-- Converting between VM-numbers and Haskell-numbers
----------------------------------------------------

-- Precondition: Inputs are non-negative
nn_int :: Integer -> NN
nn_int 0 = O
nn_int n = S(nn_int (n-1))

int_nn :: NN->Integer
int_nn O = 0
int_nn (S n) = 1+(int_nn n)

ii_int :: Integer -> II
ii_int i = if (i >= 0) then (nn_int i,O) else (O,nn_int (-i))

int_ii :: II -> Integer
int_ii (a,b) = (int_nn a) - (int_nn b)

-- Precondition: Inputs are positive
pp_int :: Integer -> PP
pp_int 1 = I
pp_int n = T(pp_int (n-1))

int_pp :: PP->Integer
int_pp I = 1
int_pp (T n) = 1+(int_pp n)

float_qq :: QQ -> Float
float_qq (i,p) = fromInteger (int_ii i)/fromInteger (int_pp p)

------------------------------
-- Normalisation by Evaluation
------------------------------

nbv :: II -> II
nbv n = ii_int (int_ii n)

----------
-- Testing
----------

main = do
    -- Integers: (i,j) represents i-j, (k,l) represents k-l
    let i = 4
    let j = 2
    let k = 1
    let l = 3
    print $ int_ii (addI (nn_int i,nn_int j) (nn_int k,nn_int l))
    print $ int_ii (multI (nn_int i,nn_int j) (nn_int k,nn_int l))
    -- Fractions: (i,j) represents i/j, (k,l) represents k/l
    print $ float_qq (addQ (ii_int i,pp_int j) (ii_int k,pp_int l))
    print $ float_qq (multQ (ii_int i,pp_int j) (ii_int k,pp_int l))
    -- Normalisation (recursive definition)
    print $ normalizeI (nn_int i,nn_int j)
    -- Normalisation (by evaluation)
    print $ nbv (nn_int i,nn_int j)




