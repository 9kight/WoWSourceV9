ALTER TABLE `character_currency`
ADD COLUMN `new_cap` int(10) DEFAULT '0' NOT NULL AFTER `week_cap`;

-- some  of server it might need  clean table or run this query 
-- UPDATE  character_currency SET week_cap=0;
-- but  i warning you this makes  characters  with 0 honor to start from 0 because if remain with thoose numbers it will still be error
