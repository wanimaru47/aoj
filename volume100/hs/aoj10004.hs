import Data.List
import Control.Monad
import Control.Applicative

main = do
  xs <- map read . words <$> getLine

  putStrLn $ solve xs

solve :: [Int] -> String
solve xs = 
  let [x,y,z] = take 3 $ sort xs
  in show x ++ " " ++ show y ++ " " ++ show z
