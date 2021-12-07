/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <ctype.h>   /* isspace */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Printer.h"

#define INDENT_WIDTH 2

int _n_;
char *buf_;
int cur_;
int buf_size;

/* You may wish to change the renderC functions */
void renderC(Char c)
{
  if (c == '{')
  {
     bufAppendC('\n');
     indent();
     bufAppendC(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppendC('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppendC(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppendC(c);
     bufAppendC(' ');
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for(t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppendC(c);
     bufAppendC(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == ' ') bufAppendC(c);
  else if (c == 0) return;
  else
  {
     bufAppendC(c);
     bufAppendC(' ');
  }
}

int allIsSpace(String s)
{
  char c;
  while ((c = *s++))
    if (! isspace(c)) return 0;
  return 1;
}

void renderS(String s)
{
  if (*s) /* s[0] != '\0', string s not empty */
  {
    if (allIsSpace(s)) {
      backup();
      bufAppendS(s);
    } else {
      bufAppendS(s);
      bufAppendC(' ');
    }
  }
}
void indent(void)
{
  int n = _n_;
  while (--n >= 0)
    bufAppendC(' ');
}
void backup(void)
{
  if (cur_ && buf_[cur_ - 1] == ' ')
    buf_[--cur_] = 0;
}
char *printProgram(Program p)
{
  _n_ = 0;
  bufReset();
  ppProgram(p, 0);
  return buf_;
}
char *printListExp(ListExp p)
{
  _n_ = 0;
  bufReset();
  ppListExp(p, 0);
  return buf_;
}
char *printExp(Exp p)
{
  _n_ = 0;
  bufReset();
  ppExp(p, 0);
  return buf_;
}
char *showProgram(Program p)
{
  _n_ = 0;
  bufReset();
  shProgram(p);
  return buf_;
}
char *showListExp(ListExp p)
{
  _n_ = 0;
  bufReset();
  shListExp(p);
  return buf_;
}
char *showExp(Exp p)
{
  _n_ = 0;
  bufReset();
  shExp(p);
  return buf_;
}
void ppProgram(Program p, int _i_)
{
  switch(p->kind)
  {
  case is_Prog:
    if (_i_ > 0) renderC(_L_PAREN);
    ppListExp(p->u.prog_.listexp_, 0);
    if (_i_ > 0) renderC(_R_PAREN);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Program!\n");
    exit(1);
  }
}

void ppListExp(ListExp listexp, int i)
{
  while(listexp != 0)
  {
    if (listexp->listexp_ == 0)
    {
      ppExp(listexp->exp_, i);
      listexp = 0;
    }
    else
    {
      ppExp(listexp->exp_, i);
      renderS(";;");
      listexp = listexp->listexp_;
    }
  }
}

void ppExp(Exp p, int _i_)
{
  switch(p->kind)
  {
  case is_EAbs:
    if (_i_ > 1) renderC(_L_PAREN);
    renderC('\\');
    ppIdent(p->u.eabs_.id_, 0);
    renderC('.');
    ppExp(p->u.eabs_.exp_, 0);
    if (_i_ > 1) renderC(_R_PAREN);
    break;

  case is_EIf:
    if (_i_ > 2) renderC(_L_PAREN);
    renderS("if");
    ppExp(p->u.eif_.exp_1, 0);
    renderC('=');
    ppExp(p->u.eif_.exp_2, 0);
    renderS("then");
    ppExp(p->u.eif_.exp_3, 0);
    renderS("else");
    ppExp(p->u.eif_.exp_4, 0);
    if (_i_ > 2) renderC(_R_PAREN);
    break;

  case is_ELet:
    if (_i_ > 3) renderC(_L_PAREN);
    renderS("let");
    ppIdent(p->u.elet_.id_, 0);
    renderC('=');
    ppExp(p->u.elet_.exp_1, 0);
    renderS("in");
    ppExp(p->u.elet_.exp_2, 0);
    if (_i_ > 3) renderC(_R_PAREN);
    break;

  case is_ERec:
    if (_i_ > 4) renderC(_L_PAREN);
    renderS("let");
    renderS("rec");
    ppIdent(p->u.erec_.id_, 0);
    renderC('=');
    ppExp(p->u.erec_.exp_1, 0);
    renderS("in");
    ppExp(p->u.erec_.exp_2, 0);
    if (_i_ > 4) renderC(_R_PAREN);
    break;

  case is_EHd:
    if (_i_ > 6) renderC(_L_PAREN);
    renderS("hd");
    ppExp(p->u.ehd_.exp_, 0);
    if (_i_ > 6) renderC(_R_PAREN);
    break;

  case is_ETl:
    if (_i_ > 6) renderC(_L_PAREN);
    renderS("tl");
    ppExp(p->u.etl_.exp_, 0);
    if (_i_ > 6) renderC(_R_PAREN);
    break;

  case is_ELE:
    if (_i_ > 9) renderC(_L_PAREN);
    ppExp(p->u.ele_.exp_1, 10);
    renderS("less_equal");
    ppExp(p->u.ele_.exp_2, 10);
    if (_i_ > 9) renderC(_R_PAREN);
    break;

  case is_EPlus:
    if (_i_ > 10) renderC(_L_PAREN);
    ppExp(p->u.eplus_.exp_1, 10);
    renderC('+');
    ppExp(p->u.eplus_.exp_2, 11);
    if (_i_ > 10) renderC(_R_PAREN);
    break;

  case is_EMinus:
    if (_i_ > 10) renderC(_L_PAREN);
    ppExp(p->u.eminus_.exp_1, 10);
    renderC('-');
    ppExp(p->u.eminus_.exp_2, 11);
    if (_i_ > 10) renderC(_R_PAREN);
    break;

  case is_ETimes:
    if (_i_ > 10) renderC(_L_PAREN);
    ppExp(p->u.etimes_.exp_1, 11);
    renderC('*');
    ppExp(p->u.etimes_.exp_2, 12);
    if (_i_ > 10) renderC(_R_PAREN);
    break;

  case is_EApp:
    if (_i_ > 13) renderC(_L_PAREN);
    ppExp(p->u.eapp_.exp_1, 13);
    ppExp(p->u.eapp_.exp_2, 14);
    if (_i_ > 13) renderC(_R_PAREN);
    break;

  case is_ENil:
    if (_i_ > 15) renderC(_L_PAREN);
    renderC('#');
    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_ECons:
    if (_i_ > 15) renderC(_L_PAREN);
    ppExp(p->u.econs_.exp_1, 16);
    renderC(':');
    ppExp(p->u.econs_.exp_2, 15);
    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_EInt:
    if (_i_ > 16) renderC(_L_PAREN);
    ppInteger(p->u.eint_.integer_, 0);
    if (_i_ > 16) renderC(_R_PAREN);
    break;

  case is_EVar:
    if (_i_ > 17) renderC(_L_PAREN);
    ppIdent(p->u.evar_.id_, 0);
    if (_i_ > 17) renderC(_R_PAREN);
    break;

  case is_EFix:
    if (_i_ > 5) renderC(_L_PAREN);
    renderS("fix");
    ppExp(p->u.efix_.exp_, 0);
    if (_i_ > 5) renderC(_R_PAREN);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Exp!\n");
    exit(1);
  }
}

void ppInteger(Integer n, int i)
{
  char tmp[20];
  sprintf(tmp, "%d", n);
  renderS(tmp);
}
void ppDouble(Double d, int i)
{
  char tmp[24];
  sprintf(tmp, "%.15g", d);
  renderS(tmp);
}
void ppChar(Char c, int i)
{
  char tmp[4];
  sprintf(tmp, "'%c'", c);
  renderS(tmp);
}
void ppString(String s, int i)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
  bufAppendC(' ');
}
void ppIdent(String s, int i)
{
  renderS(s);
}

void ppId(String s, int i)
{
  renderS(s);
}


void shProgram(Program p)
{
  switch(p->kind)
  {
  case is_Prog:
    bufAppendC('(');

    bufAppendS("Prog");

    bufAppendC(' ');

    shListExp(p->u.prog_.listexp_);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Program!\n");
    exit(1);
  }
}

void shListExp(ListExp listexp)
{
  bufAppendC('[');
  while(listexp != 0)
  {
    if (listexp->listexp_)
    {
      shExp(listexp->exp_);
      bufAppendS(", ");
      listexp = listexp->listexp_;
    }
    else
    {
      shExp(listexp->exp_);
      listexp = 0;
    }
  }
  bufAppendC(']');
}

void shExp(Exp p)
{
  switch(p->kind)
  {
  case is_EAbs:
    bufAppendC('(');

    bufAppendS("EAbs");

    bufAppendC(' ');

    shIdent(p->u.eabs_.id_);
  bufAppendC(' ');
    shExp(p->u.eabs_.exp_);

    bufAppendC(')');

    break;
  case is_EIf:
    bufAppendC('(');

    bufAppendS("EIf");

    bufAppendC(' ');

    shExp(p->u.eif_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eif_.exp_2);
  bufAppendC(' ');
    shExp(p->u.eif_.exp_3);
  bufAppendC(' ');
    shExp(p->u.eif_.exp_4);

    bufAppendC(')');

    break;
  case is_ELet:
    bufAppendC('(');

    bufAppendS("ELet");

    bufAppendC(' ');

    shIdent(p->u.elet_.id_);
  bufAppendC(' ');
    shExp(p->u.elet_.exp_1);
  bufAppendC(' ');
    shExp(p->u.elet_.exp_2);

    bufAppendC(')');

    break;
  case is_ERec:
    bufAppendC('(');

    bufAppendS("ERec");

    bufAppendC(' ');

    shIdent(p->u.erec_.id_);
  bufAppendC(' ');
    shExp(p->u.erec_.exp_1);
  bufAppendC(' ');
    shExp(p->u.erec_.exp_2);

    bufAppendC(')');

    break;
  case is_EHd:
    bufAppendC('(');

    bufAppendS("EHd");

    bufAppendC(' ');

    shExp(p->u.ehd_.exp_);

    bufAppendC(')');

    break;
  case is_ETl:
    bufAppendC('(');

    bufAppendS("ETl");

    bufAppendC(' ');

    shExp(p->u.etl_.exp_);

    bufAppendC(')');

    break;
  case is_ELE:
    bufAppendC('(');

    bufAppendS("ELE");

    bufAppendC(' ');

    shExp(p->u.ele_.exp_1);
  bufAppendC(' ');
    shExp(p->u.ele_.exp_2);

    bufAppendC(')');

    break;
  case is_EPlus:
    bufAppendC('(');

    bufAppendS("EPlus");

    bufAppendC(' ');

    shExp(p->u.eplus_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eplus_.exp_2);

    bufAppendC(')');

    break;
  case is_EMinus:
    bufAppendC('(');

    bufAppendS("EMinus");

    bufAppendC(' ');

    shExp(p->u.eminus_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eminus_.exp_2);

    bufAppendC(')');

    break;
  case is_ETimes:
    bufAppendC('(');

    bufAppendS("ETimes");

    bufAppendC(' ');

    shExp(p->u.etimes_.exp_1);
  bufAppendC(' ');
    shExp(p->u.etimes_.exp_2);

    bufAppendC(')');

    break;
  case is_EApp:
    bufAppendC('(');

    bufAppendS("EApp");

    bufAppendC(' ');

    shExp(p->u.eapp_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eapp_.exp_2);

    bufAppendC(')');

    break;
  case is_ENil:

    bufAppendS("ENil");




    break;
  case is_ECons:
    bufAppendC('(');

    bufAppendS("ECons");

    bufAppendC(' ');

    shExp(p->u.econs_.exp_1);
  bufAppendC(' ');
    shExp(p->u.econs_.exp_2);

    bufAppendC(')');

    break;
  case is_EInt:
    bufAppendC('(');

    bufAppendS("EInt");

    bufAppendC(' ');

    shInteger(p->u.eint_.integer_);

    bufAppendC(')');

    break;
  case is_EVar:
    bufAppendC('(');

    bufAppendS("EVar");

    bufAppendC(' ');

    shIdent(p->u.evar_.id_);

    bufAppendC(')');

    break;
  case is_EFix:
    bufAppendC('(');

    bufAppendS("EFix");

    bufAppendC(' ');

    shExp(p->u.efix_.exp_);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Exp!\n");
    exit(1);
  }
}

void shInteger(Integer i)
{
  char tmp[20];
  sprintf(tmp, "%d", i);
  bufAppendS(tmp);
}
void shDouble(Double d)
{
  char tmp[24];
  sprintf(tmp, "%.15g", d);
  bufAppendS(tmp);
}
void shChar(Char c)
{
  bufAppendC('\'');
  bufAppendC(c);
  bufAppendC('\'');
}
void shString(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}
void shIdent(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}

void shId(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}


void bufAppendS(const char *s)
{
  int len = strlen(s);
  int n;
  while (cur_ + len >= buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  for(n = 0; n < len; n++)
  {
    buf_[cur_ + n] = s[n];
  }
  cur_ += len;
  buf_[cur_] = 0;
}
void bufAppendC(const char c)
{
  if (cur_ + 1 >= buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  buf_[cur_] = c;
  cur_++;
  buf_[cur_] = 0;
}
void bufReset(void)
{
  cur_ = 0;
  buf_size = BUFFER_INITIAL;
  resizeBuffer();
  memset(buf_, 0, buf_size);
}
void resizeBuffer(void)
{
  char *temp = (char *) malloc(buf_size);
  if (!temp)
  {
    fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
    exit(1);
  }
  if (buf_)
  {
    strncpy(temp, buf_, buf_size); /* peteg: strlcpy is safer, but not POSIX/ISO C. */
    free(buf_);
  }
  buf_ = temp;
}
char *buf_;
int cur_, buf_size;

