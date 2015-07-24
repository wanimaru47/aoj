import Control.Monad
import Control.Applicative
import Data.Char

main = do
  contents <- getContents
  putStrLn $ solve 1 $ lines contents

solve :: Int -> [String] -> String
solve n (x:nx)
      | head nx == "0" = "Case " ++ (show n) ++ ": " ++ x
      | otherwise = "Case " ++ (show n) ++ ": " ++ x ++ "\n" ++ solve (n+1) nx

