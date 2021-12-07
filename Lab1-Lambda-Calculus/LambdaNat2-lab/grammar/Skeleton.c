/*** BNFC-Generated Visitor Traversal Skeleton. ***/
/* This traverses the abstract syntax tree.
   To use, copy Skeleton.h and Skeleton.c to
   new files. */

#include <stdlib.h>
#include <stdio.h>

#include "Skeleton.h"

void visitProgram(Program p)
{
  switch(p->kind)
  {
  case is_Prog:
    /* Code for Prog Goes Here */
    visitListExp(p->u.prog_.listexp_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Program!\n");
    exit(1);
  }
}

void visitListExp(ListExp listexp)
{
  while(listexp  != 0)
  {
    /* Code For ListExp Goes Here */
    visitExp(listexp->exp_);
    listexp = listexp->listexp_;
  }
}

void visitExp(Exp p)
{
  switch(p->kind)
  {
  case is_EAbs:
    /* Code for EAbs Goes Here */
    visitId(p->u.eabs_.id_);
    visitExp(p->u.eabs_.exp_);
    break;
  case is_EIf:
    /* Code for EIf Goes Here */
    visitExp(p->u.eif_.exp_1);
    visitExp(p->u.eif_.exp_2);
    visitExp(p->u.eif_.exp_3);
    visitExp(p->u.eif_.exp_4);
    break;
  case is_ELet:
    /* Code for ELet Goes Here */
    visitId(p->u.elet_.id_);
    visitExp(p->u.elet_.exp_1);
    visitExp(p->u.elet_.exp_2);
    break;
  case is_ERec:
    /* Code for ERec Goes Here */
    visitId(p->u.erec_.id_);
    visitExp(p->u.erec_.exp_1);
    visitExp(p->u.erec_.exp_2);
    break;
  case is_EHd:
    /* Code for EHd Goes Here */
    visitExp(p->u.ehd_.exp_);
    break;
  case is_ETl:
    /* Code for ETl Goes Here */
    visitExp(p->u.etl_.exp_);
    break;
  case is_ELE:
    /* Code for ELE Goes Here */
    visitExp(p->u.ele_.exp_1);
    visitExp(p->u.ele_.exp_2);
    break;
  case is_EPlus:
    /* Code for EPlus Goes Here */
    visitExp(p->u.eplus_.exp_1);
    visitExp(p->u.eplus_.exp_2);
    break;
  case is_EMinus:
    /* Code for EMinus Goes Here */
    visitExp(p->u.eminus_.exp_1);
    visitExp(p->u.eminus_.exp_2);
    break;
  case is_ETimes:
    /* Code for ETimes Goes Here */
    visitExp(p->u.etimes_.exp_1);
    visitExp(p->u.etimes_.exp_2);
    break;
  case is_EApp:
    /* Code for EApp Goes Here */
    visitExp(p->u.eapp_.exp_1);
    visitExp(p->u.eapp_.exp_2);
    break;
  case is_ENil:
    /* Code for ENil Goes Here */
    break;
  case is_ECons:
    /* Code for ECons Goes Here */
    visitExp(p->u.econs_.exp_1);
    visitExp(p->u.econs_.exp_2);
    break;
  case is_EInt:
    /* Code for EInt Goes Here */
    visitInteger(p->u.eint_.integer_);
    break;
  case is_EVar:
    /* Code for EVar Goes Here */
    visitId(p->u.evar_.id_);
    break;
  case is_EFix:
    /* Code for EFix Goes Here */
    visitExp(p->u.efix_.exp_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Exp!\n");
    exit(1);
  }
}

void visitId(Id p)
{
  /* Code for Id Goes Here */
}
void visitIdent(Ident i)
{
  /* Code for Ident Goes Here */
}
void visitInteger(Integer i)
{
  /* Code for Integer Goes Here */
}
void visitDouble(Double d)
{
  /* Code for Double Goes Here */
}
void visitChar(Char c)
{
  /* Code for Char Goes Here */
}
void visitString(String s)
{
  /* Code for String Goes Here */
}

