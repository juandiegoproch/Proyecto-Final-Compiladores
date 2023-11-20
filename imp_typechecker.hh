#ifndef IMP_TYPECHECKER
#define IMP_TYPECHECKER

#include <unordered_map>

#include "imp.hh"
#include "type_visitor.hh"
#include "environment.hh"

using namespace std;

class ImpTypeChecker : public TypeVisitor {
public:
  ImpTypeChecker();
private:
  Environment<ImpType> env;
  ImpType booltype;
  ImpType inttype;
  vector<Stm*> loopStack; // es innecesario manejar un stack entero pero podria no serlo
                          //  a futuro. No es necesario hacer memmanagement sobre el porque
                          // los objetos pertenecen al AST, solo guardo referencias.
public:
  void typecheck(Program*);
  void visit(Program*);
  void visit(Body*);
  void visit(VarDecList*);
  void visit(VarDec*);
  void visit(StatementList*);
  void visit(AssignStatement*);
  void visit(PrintStatement*);
  void visit(IfStatement*);
  void visit(WhileStatement*);
  void visit(ForStatement*);
  void visit(DoWhileStatement*);
  void visit(LoopSkipStatement*);

  ImpType visit(BinaryExp* e);
  ImpType visit(UnaryExp* e);
  ImpType visit(NumberExp* e);
  ImpType visit(BoolConstExp* e);
  ImpType visit(IdExp* e);
  ImpType visit(ParenthExp* e);
  ImpType visit(CondExp* e);
};


#endif

