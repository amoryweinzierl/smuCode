function bool(val) {
  return val ? 1 : 0
}

const Operations = {
  "+": (l, r) => l + r,
  "-": (l, r) => l - r,
  "*": (l, r) => l * r,
  "/": (l, r) => Math.round(l / r),
  "==": (l, r) => bool(l == r),
  "!=": (l, r) => bool(l != r),
  ">=": (l, r) => bool(l >= r),
  ">": (l, r) => bool(l > r),
  "<=": (l, r) => bool(l <= r),
  "<": (l, r) => bool(l < r),
}

export default class Interpreter {

  constructor(target, printFunction) {
    this.target = target
    this.printFunction = printFunction
    this.binding = new Map()
  }

  visit() {
    return this.target.accept(this)
  }

  BinOp(node) {
    let l = node.left.accept(this)
    let r = node.right.accept(this)
    return Operations[node.op](l, r)
  }

  IntegerValue(node) {
    return node.value
  }

  ifStatement(node) {
      let e = node.e.accept(this)
      let ifs = node.ifs
      let elses = node.elses

      if(elses == null) {
        return ifs
      }

      else if(e) {
        return ifs.accept(this)
      }

      else {
        return elses.accept(this)
      }
  }

  nullStatements(node) {
    return null;
  }

  variableName(node) {
    return node.name
  }

  variableVal(node) {
    return this.getVariable(node.name)
  }

  setVariable(name, value){
    this.binding.set(name, value)
  }

  getVariable(name){
    if(this.binding.has(name)){
      return this.binding.get(name)
    }
    throw new Error(`undefined variable ${name}`)
  }

  Assignment(node) {
    let variable = node.l.accept(this);
    let expr = node.r.accept(this);
    if(this.binding.has(variable))
        this.setVariable(variable, r);
    else{
      throw new Error(`undefined variable ${variable}`)
    }
    return expr;
  }

  VarDec(node){
    let variable = node.l.accept(this);
    let expr = node.r.accept(this);
    if(this.binding.has(variable))
        throw new Error(`already defined variable ${variable}`)
    else{
        this.setVariable(variable, expr);
    }
    return expr;
  }

  FunctionDef(node){
    return node.r
  }

  FunctionCall(node){
    let name = node.l.accept(this)
    return name.accept(this)
  }

  Statements(node) {
    let state = node.statements;
    let count = 0;
    for (let statement of state) {
      count = statement.accept(this)
    }
    return count;
  }
}
