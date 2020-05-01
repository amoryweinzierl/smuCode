export class BinOp {
  constructor(l, op, r) {
    this.left  = l
    this.op    = op
    this.right = r
  }
  accept(visitor) {
    return visitor.BinOp(this)
  }
}

export class IntegerValue {
  constructor(value) {
    this.value = value
  }

  accept(visitor) {
    return visitor.IntegerValue(this)
  }
}

export class ifStatement {
  constructor(e, ifs, elses) {
    this.e = e;
    this.ifs = ifs
    this.elses = elses
  }
  accept(visitor) {
    return visitor.ifStatement(this)
  }
}

export class variableName {
  constructor(name) {
      this.name = name
  }

  accept(visitor) {
      return visitor.variableName(this)
  }
}

export class variableVal {
  constructor(name) {
      this.name = name
  }

  accept(visitor) {
      return visitor.variableVal(this)
  }
}

export class Assignment {
  constructor(l, r) {
      this.l = l
      this.r = r
  }

  accept(visitor) {
      return visitor.Assignment(this)
  }
}

export class VarDec{
  constructor(l, r){
    this.l = l
    this.r = r
  }

  accept(visitor){
      return visitor.VarDec(this)
  }
}

export class Statements {
  constructor(statements){
      this.statements = statements
  }

  accept(visitor){
      return visitor.Statements(this)
  }
}

export class nullStatements {
  constructor() {}
  accept(visitor){
      return visitor.nullStatements(this)
  }
}

export class funcDef{
  constructor(l, r){
    this.l = l
    this.r = r
  }

  accept(visitor){
    return visitor.FunctionDef(this)
  }
}

export class funcCall{
  constructor(l, r){
    this.l = l
    this.r = r
  }

  accept(visitor){
    return visitor.FunctionCall(this)
  }
}