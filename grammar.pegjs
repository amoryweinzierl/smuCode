{
  const AST = options.AST

  function rollupBinOp(head, rest) {
    return rest.reduce(
      (result, [op, right]) => new AST.BinOp(result, op, right),
      head
    )
  }
}

start
  = code

identifier       
   = id:([a-z][a-zA-Z_0-9]*)
    { return text() }

///////////////////////// blocks (lists of statements) /////////////////////////

code
  = _ state:statement+ _
  {return new AST.Statements(state)}

statement
  = "let" _ v:variable_declaration _
  {return v}
  / assign:assignment _
    {return assign}
  / expr

//////////////// variables & variable declaration /////////////////////////////

variable_declaration
  = v:variable_name "=" e:expr
    {return new AST.VarDec(v,e)}
  / v:variable_name
    {return new AST.VarDec(v, new AST.IntegerValue(0))}

variable_value             // as rvalue
  = _ id:identifier _
      {return new AST.variableVal(id)}

variable_name              // as lvalue
  = _ id:identifier _
      {return new AST.variableName(id)}

//////////////////////////////// if/then/else /////////////////////////////

if_expression
  = e:expr ifs:brace_block "else" elses:brace_block
    {return new AST.ifStatement(e, ifs, elses)}
  / e:expr ifs:brace_block
    {return new AST.ifStatement(e, ifs, [])}

//////////////////////////////// assignment /////////////////////////////

assignment
  = v:variable_name _ "=" _ e:expr
    {return new AST.Assignment(v, e)}

//////////////////////////////// expression /////////////////////////////

expr
  = _ "fn" expr:function_definition 
  {return expr}
  / _ "if" expr:if_expression 
  {return expr}
  / boolean_expression
  / arithmetic_expression


/////////////////////// boolean expression /////////////////////////////

boolean_expression
  = head:arithmetic_expression rest:(relop arithmetic_expression)*
    { return rollupBinOp(head, rest) }

//////////////////////////////// arithmetic expression /////////////////////////////

arithmetic_expression
  = head:mult_term rest:(addop mult_term)*
    { return rollupBinOp(head, rest) }

mult_term
  = head:primary rest:(mulop primary)*
    { return rollupBinOp(head, rest) }

primary
  = integer
  /function_call
  /variable_value
  / _ "(" _ expr:arithmetic_expression _ ")" _
    { return expr }


integer
  = _ number: digits _
    { return new AST.IntegerValue(number) }

addop
  = _ op:[-+] _
    { return op }

mulop
  = _ op:[*/] _
    { return op }

relop
  = '==' / '!=' / '>=' / '>' / '<=' / '<'


/////////////////////// utility NTs //////////////////////////////

function_call
  = v:variable_value "(" _ ")" _
    {return new AST.funcCall(v, [])}     // note: no parameters

//////////////////////// function definition /////////////////////////////

function_definition
  = _ p:param_list _ b:brace_block
    {return new AST.funcDef(p, b)}

param_list
   = "(" ")"

brace_block
  = _ "{" c:code "}" _
  {return c}

_ "whitespace"
  = [ \t\n\r]*

digits            
  = [-+]? [0-9]+
   { return parseInt(text(), 10) }