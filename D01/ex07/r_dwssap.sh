#! /bin/sh
#Write a command line that displays the output of a cat /etc/passwd command,
 #removing comments
 #every other line starting from the second line
 #reversing each login
 #sorted in reverse alphabetical order
 #and keeping only logins between FT_LINE1 #and FT_LINE2 included
 #and they must separated by ", " (without quotation marks)
 #and the output must end with a "."
FT_LINE1="4"
FT_LINE2="5"
cat /etc/passwd | sed "s/#.*//p" | sed -n '2~2p' | cut -d : -f 1 | rev | sort -dr | sed -n -e "${FT_LINE1},~${FT_LINE2}p" | xargs | sed "s/ /, /g" | sed "s/$/./"