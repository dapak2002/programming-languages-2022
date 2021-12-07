module Interpreter where

import AbsNumbers
import Arithmetic

eval :: Exp -> QQ
eval (Plus n m) = addQ (eval n) (eval m)
eval (Times n m) = multQ (eval n) (eval m)
eval (Num q) = q
