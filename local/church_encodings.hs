zero = \f -> \x -> x -- zero f x = x
one = \f -> \x -> f x -- one f x = f x
two = \f -> \x -> f (f x) -- two f x = f (f x)
three = \f -> \x -> f (f (f x)) -- etc
four = \f -> \x -> f (f (f (f x))) -- etc

add n m = \f -> \x -> n f ( m f x) 
mult n m = \f -> \x -> n (m f) x
power n m = m n

-- for printing and testing
plusone x = x + 1
print_num x = print $ x plusone 0

main = do
  print_num zero
  print_num one
  print_num two
  print_num three
  print_num $ add two three
  print_num $ mult two three
  print_num $ power two three
