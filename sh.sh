flex limbaj.l 
bison --debug -d -v limbaj.y 
gcc lex.yy.c limbaj.tab.c  -I . -II -lm -ly