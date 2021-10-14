# A pair of compressor/decompressor tool for "square" txt  

## Algorithm:  

Whether it is a binary 0/1 square matrix (e.g., to show a picture or a picture representative of a character) recorded as a .txt file.
It will be converted to a list of char and numbers, showing number of continous same char.  

For example, the letter H, can be represented as below:  
  
5  
1 0 0 0 1  
1 0 0 0 1  
1 1 1 1 1  
1 0 0 0 1  
1 0 0 0 1  
  
After compressing, it should be:  
5 1 1 0 3 1 2 0 3 1 7 0 3 1 2 0 3 1 1  
The above numbers means it is a 5x5 matrix (first `5`), followed by one（1) `1`, and three (3) `0`'s, and two (2) `1`'s, etc.  
The decompressor will convert the above number list back to the text "picture".  

Moreover, the to be compressed text picture should be named as `test.txt`, and the to be decompressed code should be named as `test.ljcp`.  
  
## zh:   
使用。龙家压缩。必须把压缩包文件命名为‘test.ljcp’  必须把文本文件命名为‘test.txt’  ！！！  