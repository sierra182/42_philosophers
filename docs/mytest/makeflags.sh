#!/bin/bash

#./philosophers 200 1 10 100 take fork after die
# 4 310 200 100 2 bloc
# 4 800 200 200 3
# 200 60 60 60 talk after die
VALUES="5 1190 200 200 1"
NAME=philo
# NAME=philo

echo -e "\n\033[0;35m sanitize address:\033[0m" \
&& make fclean \
&& make address \
&& ./$NAME $VALUES

echo -e "\n\033[0;35m sanitize thread:\033[0m" \
&& make fclean \
&& make thread \
&& ./$NAME $VALUES

echo -e "\n\033[0;35m no sanitize:\033[0m" \
&& make fclean \
&& make l \
&& echo -e "\033[0;35m memory flag:\033[0m\n" \
&& valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all ./$NAME $VALUES

echo -e "\n\033[0;35m helgrind flag:\033[0m\n" \
&& valgrind --tool=helgrind ./$NAME $VALUES

echo -e "\n\033[0;35m drd flag:\033[0m\n" \
&& valgrind --tool=drd ./$NAME $VALUES