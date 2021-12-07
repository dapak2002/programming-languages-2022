-- A Virtual Machine (VM) for Arithmetic (solution)
-- Copyright: Richard Dedekind 1887, Alexander Kurz 2021

-----------------------
-- Data types of the VM
-----------------------

-- Natural numbers
data NN = O | S NN
  deriving (Eq,Show) -- for equality and printing

-- Integers
data II = II NN NN
  deriving (Eq,Show) -- for equality and printing

-- Positive integers (to avoid dividing by 0)
data PP = I | T PP

-- Rational numbers
data QQ =  QQ II PP

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
addI (II a b) (II c d) =  II (addN a c) (addN b d)

-- Multiplication: (a-b)*(c-d)=(ac+bd)-(ad+bc)
multI :: II -> II -> II
multI (II a b) (II c d) = II (addN (multN a c) (multN b d)) (addN (multN a d) (multN b c))

-- Subtraction: (a-b)-(c-d)=(a+d)-(b+c)
subtrI :: II -> II -> II
subtrI (II a b) (II c d) = II (addN a d) (addN b c)

-- Negation: -(a-b)=(b-a)
negI :: II -> II
negI (II a b) = II b a

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
ii_pp I =  II (S O) O
ii_pp (T p) = addI (II (S O) O) (ii_pp p)

-- Addition: (a/b)+(c/d)=(ad+bc)/(bd)
addQ :: QQ -> QQ -> QQ
addQ (QQ a b) (QQ c d) = QQ (addI (multI a (ii_pp d)) (multI (ii_pp b) c)) (multP b d)

-- Multiplication: (a/b)*(c/d)=(ac)/(bd)
multQ :: QQ -> QQ -> QQ
multQ (QQ a b) (QQ c d) = QQ (multI a c) (multP b d)

----------------
-- Normalisation
----------------

normalizeI :: II -> II
normalizeI (II n O) = II n O
normalizeI (II O m) = II O m
normalizeI (II (S n) (S m)) = normalizeI (II n m)

----------------------------------------------------
-- Converting between VM-numbers and Haskell-numbers
----------------------------------------------------

-- Precondition: Inputs are non-negative
nn_int :: Integer -> NN
nn_int 0 = O
nn_int n = S(nn_int (n-1))

int_nn :: NN->Integer
int_nn O = 0
int_nn (S n) = 1+int_nn n

ii_int :: Integer -> II
ii_int i = if i >= 0 then II (nn_int i) O else II O (nn_int (-i))

int_ii :: II -> Integer
int_ii (II a b) = int_nn a - int_nn b

-- Precondition: Inputs are positive
pp_int :: Integer -> PP
pp_int 1 = I
pp_int n = T(pp_int (n-1))

int_pp :: PP->Integer
int_pp I = 1
int_pp (T n) = 1 + int_pp n

float_qq :: QQ -> Float
float_qq (QQ i p) = fromInteger (int_ii i)/fromInteger (int_pp p)

------------------------------
-- Normalisation by Evaluation
------------------------------

nbv :: II -> II
nbv n = ii_int (int_ii n)

----------
-- Testing
----------

main = do
    -- Integers: (II i j) represents i-j, (II k l) represents k-l
    let i = 4
    let j = 2
    let k = 1
    let l = 3
    print $ int_ii (addI (II (nn_int i) (nn_int j)) (II (nn_int k) (nn_int l)))
    print $ int_ii (multI (II (nn_int i) (nn_int j)) (II (nn_int k) (nn_int l)))
    -- Fractions: (QQ i j) represents i/j, (QQ k l) represents k/l
    print $ float_qq (addQ (QQ (ii_int i) (pp_int j)) (QQ (ii_int k) (pp_int l)))
    print $ float_qq (multQ (QQ (ii_int i) (pp_int j)) (QQ (ii_int k) (pp_int l)))
    -- Normalisation (recursive definition)
    print $ normalizeI (II (nn_int i) (nn_int j))
    -- Normalisation (by evaluation)
    print $ nbv (II (nn_int i) (nn_int j))

{-
    float_qq (addQ (QQ (ii_int 4) (pp_int 2)) (QQ (ii_int 1) (pp_int 3)))
    float_qq (multQ (QQ (ii_int 4) (pp_int 2)) (QQ (ii_int 1) (pp_int 3)))

    normalizeI (II (S (S (S (S O)))) (S (S O)))
    normalizeI (II (S (S O)) (S (S (S (S O)))))
    nbv (II (S (S (S (S O)))) (S (S O)))
    nbv (II (S (S O)) (S (S (S (S O)))))

    ii_int (-4) -- II O (S (S (S (S O))))
    int_ii (II (S O) (S(S O)))

-}
