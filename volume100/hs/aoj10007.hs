import Control.Monad
import Control.Applicative
import Data.Char
import Data.List

main = do
  contents <- getContents
  putStr $ solve $ lines contents
  --mapM_ print $ map words $ lines contents

solve :: [String] -> String
solve ["0 0"] = ""
solve (t:ts) =
    let [x,y] = sort $ map (\xs -> read xs :: Int) $ words t
    in show x ++ " " ++ show y ++ "\n" ++ (solve ts)
