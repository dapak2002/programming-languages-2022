-- https://apfelmus.nfshost.com/articles/monoid-fingertree.html

data Tree v a = Leaf v a | Branch v (Tree v a) (Tree v a)
    deriving (Show,Eq)

toList :: Tree v a -> [a]
toList (Leaf _ a)     = [a]
toList (Branch _ x y) = toList x ++ toList y

tag :: Tree v a -> v
tag (Leaf v _)     = v
tag (Branch v _ _) = v

first :: Tree v a -> a
first (Leaf _ a)     = a
first (Branch _ x _) = first x

type Size = Int

tag (Leaf  ..)       = 1
tag (Branch .. x y)  = tag x + tag y


main = do
    let tree = Branch "a" (Branch "b" (Leaf "c" 1) (Leaf "d" 2)) (Branch "e" (Leaf "f" 3) (Leaf "g" 4))
    print $ toList tree
    print $ tag tree
    print $ first tree

