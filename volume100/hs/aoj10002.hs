import Control.Monad
import Control.Applicative

main = do
  [x,y] <- map read . words <$> getLine

  putStrLn $ (men x y) ++ " " ++ (len x y)
  --putStrLn . show $ x * x

men :: Int -> Int -> String
men x y = show $ x * y

len :: Int -> Int -> String
len x y = show $ (x + y) * 2 
