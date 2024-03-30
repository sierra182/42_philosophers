#! /bin/bash
#./philosophers 200 1 10 100 take fork after die
VALUES="4 310 200 100"

echo -e "\n\033[0;35m sanitize address:\033[0m" \
&& make fclean \
&& make address \
&& ./philosophers $VALUES

echo -e "\n\033[0;35m sanitize thread:\033[0m" \
&& make fclean \
&& make thread \
&& ./philosophers $VALUES

echo -e "\n\033[0;35m no sanitize:\033[0m" \
&& make fclean \
&& make l \
&& echo -e "\033[0;35m memory flag:\033[0m\n" \
&& valgrind --leak-check=full --show-leak-kinds=all ./philosophers $VALUES

echo -e "\n\033[0;35m helgrind flag:\033[0m\n" \
&& valgrind --tool=helgrind ./philosophers $VALUES

echo -e "\n\033[0;35m drd flag:\033[0m\n" \
&& valgrind --tool=drd ./philosophers $VALUES