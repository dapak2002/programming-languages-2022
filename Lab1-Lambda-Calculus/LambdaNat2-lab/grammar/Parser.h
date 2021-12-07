#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include "Absyn.h"

typedef union
{
  int    _int;
  char   _char;
  double _double;
  char*  _string;
  Program program_;
  ListExp listexp_;
  Exp exp_;
} YYSTYPE;

typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;

#define _ERROR_ 258
#define _SYMB_7 259
#define _SYMB_9 260
#define _SYMB_10 261
#define _SYMB_6 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_2 265
#define _SYMB_8 266
#define _SYMB_0 267
#define _SYMB_3 268
#define _SYMB_1 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _INTEGER_ 280


extern YYLTYPE yylloc;
extern YYSTYPE yylval;

Program  pProgram(FILE *inp);
Program psProgram(const char *str);
ListExp  pListExp(FILE *inp);
ListExp psListExp(const char *str);
Exp  pExp1(FILE *inp);
Exp psExp1(const char *str);
Exp  pExp2(FILE *inp);
Exp psExp2(const char *str);
Exp  pExp3(FILE *inp);
Exp psExp3(const char *str);
Exp  pExp4(FILE *inp);
Exp psExp4(const char *str);
Exp  pExp6(FILE *inp);
Exp psExp6(const char *str);
Exp  pExp9(FILE *inp);
Exp psExp9(const char *str);
Exp  pExp10(FILE *inp);
Exp psExp10(const char *str);
Exp  pExp13(FILE *inp);
Exp psExp13(const char *str);
Exp  pExp15(FILE *inp);
Exp psExp15(const char *str);
Exp  pExp16(FILE *inp);
Exp psExp16(const char *str);
Exp  pExp17(FILE *inp);
Exp psExp17(const char *str);
Exp  pExp(FILE *inp);
Exp psExp(const char *str);
Exp  pExp5(FILE *inp);
Exp psExp5(const char *str);
Exp  pExp7(FILE *inp);
Exp psExp7(const char *str);
Exp  pExp8(FILE *inp);
Exp psExp8(const char *str);
Exp  pExp11(FILE *inp);
Exp psExp11(const char *str);
Exp  pExp12(FILE *inp);
Exp psExp12(const char *str);
Exp  pExp14(FILE *inp);
Exp psExp14(const char *str);

#endif
