import Control.Monad
import Control.Applicative

main = do
  [x,y] <- map read . words <$> getLine

  putStrLn $ solve x y

solve :: Int -> Int -> String
solve x y
  | x < y = "a < b"
  | x > y = "a > b"
  | otherwise = "a == b"
