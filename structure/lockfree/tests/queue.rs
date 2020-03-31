use lockfree::queue;

fn generate_rpn(infix: &str) -> String{
  let mut operators: Vec<char> = Vec::new();
  let mut expr: Vec<char> = Vec::new();
  for ch in infix.chars(){
      match ch{
          '(' => operators.push('('),
          ')' => {
            while let Some(op) = operators.pop(){
              if op == '('{
                  break;
              }else{
                  expr.push(op);
              }
            }
          },
          '|' | '*' => {
            loop{
              if let Some(op) = operators.last(){
                println!("{:?}", *op);
                if *op == '('{
                    operators.push(ch);
                    break;
                }else{
                    let op = operators.pop().unwrap();
                    expr.push(op);
                }
              }else{
                expr.push(ch);
                break;
              }
            }
          },
          _ => expr.push(ch)
      }
  }
  expr.iter().collect()
}
#[test]
fn test_rpn(){
  let res = generate_rpn("a(b|c)*d*(a|b)c");
  assert_eq!(res, "abc|*d*ab|c");
}