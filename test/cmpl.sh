#! /bin/bash

if [ -z $1 ]; then
   echo "Tell me the test file name."
   exit 1
fi

gcc -fsanitize=leak -I ../include $1 libft.a -o $(echo $1 | sed "s;\.c;\.out;g") && ./$(echo $1 | sed "s;\.c;\.out;g")
