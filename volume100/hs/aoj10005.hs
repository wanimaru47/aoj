main = do
  putStr $ solve 1000

solve :: Int -> String;
solve 1 = "Hello World\n"
solve n = "Hello World\n" ++ (solve $ n - 1)
