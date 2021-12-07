CC = gcc -g
CCFLAGS = --ansi -W -Wall -Wno-unused-parameter -Wno-unused-function -Wno-unneeded-internal-declaration ${CC_OPTS}

FLEX = flex
FLEX_OPTS = -Plambda_nat_

BISON = bison
BISON_OPTS = -t -plambda_nat_

OBJS = Absyn.o Buffer.o Lexer.o Parser.o Printer.o

.PHONY : clean distclean

all : TestLambdaNat4

clean :
	rm -f *.o TestLambdaNat4 LambdaNat4.aux LambdaNat4.log LambdaNat4.pdf LambdaNat4.dvi LambdaNat4.ps LambdaNat4

distclean : clean
	rm -f Absyn.h Absyn.c Buffer.h Buffer.c LambdaNat4.l Lexer.c LambdaNat4.y Parser.h Parser.c Printer.c Printer.h Skeleton.c Skeleton.h Test.c Makefile LambdaNat4.tex

TestLambdaNat4 : ${OBJS} Test.o
	@echo "Linking TestLambdaNat4..."
	${CC} ${OBJS} Test.o -o TestLambdaNat4

Absyn.o : Absyn.c Absyn.h
	${CC} ${CCFLAGS} -c Absyn.c

Buffer.o : Buffer.c Buffer.h
	${CC} ${CCFLAGS} -c Buffer.c

Lexer.c : LambdaNat4.l
	${FLEX} ${FLEX_OPTS} -oLexer.c LambdaNat4.l

Parser.c : LambdaNat4.y
	${BISON} ${BISON_OPTS} LambdaNat4.y -o Parser.c

Lexer.o : Lexer.c Parser.h
	${CC} ${CCFLAGS} -c Lexer.c

Parser.o : Parser.c Absyn.h
	${CC} ${CCFLAGS} -c Parser.c

Printer.o : Printer.c Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Printer.c

Test.o : Test.c Parser.h Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Test.c
