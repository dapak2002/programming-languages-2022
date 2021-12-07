-- the initial algebra for F X = 1 + X
data NN = O | S NN

-- the initial algebra for F X = 1 + A x X
data List a = Nil | Cons a (List a)
    deriving (Show, Eq)

-- List is a functor Set -> Set mapping `a` to `List a` and arrows as follows
mapList :: (a -> b) -> (List a -> List b)
mapList f Nil = Nil
mapList f (Cons x xs) = Cons (f x) (mapList f xs)

main = do 
  print $ (Cons 2 (Cons 1 Nil))
  -- print $ Nil -- gives an error since type inference cannot deduce the `a` in `List a`
  print $ (Nil :: List Int)
  