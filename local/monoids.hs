{- https://hackage.haskell.org/package/base-4.15.0.0/docs/src/GHC-Base.html
-- https://stackoverflow.com/questions/6948166/javas-interface-and-haskells-type-class-differences-and-similarities
-- https://stackoverflow.com/a/8123973/4600290
-- Phil Wadler https://www.youtube.com/watch?v=8frGknO8rIg

class Semigroup a where
    (<>) :: a -> a -> a

class Semigroup a => Monoid a where
    mempty  :: a
    mappend :: a -> a -> a
    mappend = (<>)
    mconcat :: [a] -> a
    mconcat = foldr mappend mempty

-}

-- Lists as a semigroup and a monoid

data List a = Nil | Cons a (List a)
    deriving (Show, Eq)

instance Semigroup (List a) where
    Nil <> xs = xs
    (Cons y ys) <> xs = Cons y (ys <> xs)

instance Monoid (List a) where
    mempty = Nil

instance Semigroup Integer where
    n <> m = n + m

{-- Integers with addition as a semigroup and a monoid

newtype Plus a = Plus a
        deriving (Show, Eq)

instance Semigroup (Plus Int) where
    (Plus n) <> (Plus m) = Plus (n+m)

instance Monoid (Plus Int) where
    mempty = Plus 0
-} 

main = do
    let l123 = (Cons 1 (Cons 2 (Cons 3 Nil)))
    let l234 = (Cons 2 (Cons 3 (Cons 4 Nil)))
    print $ l123
    print $ mappend l123 l234
    print $ mconcat [2::Integer,3,4]
