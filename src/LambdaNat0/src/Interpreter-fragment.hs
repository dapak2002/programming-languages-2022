# The heart of the interpreter ... all else is "boilerplate"

-- evaluate using the strategy call-by-name
evalCBN :: Exp -> Exp  
evalCBN (EApp e1 e2) = case (evalCBN e1) of
    (EAbs i e3) -> evalCBN (subst i e2 e3)
    e3 -> EApp e3 e2
evalCBN x = x 

-- generate a fresh name
fresh :: Exp -> String

-- subst id s e performs capture avoiding substitution of id by s in e
subst :: Id -> Exp -> Exp -> Exp
subst id s (EVar id1) | id == id1 = s
                      | otherwise = EVar id1
subst id s (EApp e1 e2) = EApp (subst id s e1) (subst id s e2)
subst id s (EAbs id1 e1) = 
    -- to avoid variable capture, we first substitute id1 with a fresh name inside the body of the λ-abstraction, obtaining e2. Only then do we proceed to apply substitution of the original s for id in the body e2.
    let f = fresh (EAbs id1 e1)
        e2 = subst id1 (EVar f) e1 in 
        EAbs f (subst id s e2)
