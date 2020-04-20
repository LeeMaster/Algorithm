//！ # Expression tree 
//! use the rust to  build a Eval tree to eval the +-*/
//! 
//! 
#[derive(Debug)]
#[allow(dead_code)]
enum Type{
    Plus = 1,
    Minus,
    Mul,
    Div
}

#[derive(Debug)]
enum Node{
    Nil,
    Cal(Type, Box<Node>, Box<Node>),
    Num(i32),
    Bracket
}

impl Default for Node{
    fn default() -> Node{
        Node::Nil
    }
}

impl Node {

    /// eval a i32 value from the Node
    fn eval(&self) -> Result<i32, &str>{
        match self{
            Node::Nil => return Err("Nil is not a i32 number"),
            Node::Bracket => return Err("Bracket is not a i32 number"),
            Node::Num(number) => return Ok(*number),
            Node::Cal(op, left, right) => {
                match op{
                    Type::Plus => return Ok(left.eval()? + right.eval()?),
                    Type::Minus => return Ok(left.eval()? - right.eval()?),
                    Type::Mul => return Ok(left.eval()? * right.eval()?),
                    Type::Div => return Ok(left.eval()? * right.eval()?)
                }
            }
            
        }
    }
}

#[cfg(test)]
mod tests{
    use crate::*;
    #[test]
    fn test_node_eval() {
        // nil node return 0
        let node = Default::default();
        assert!(node.eval().is_err());

        // 1 + 2 
        let node = Node::Cal(
            Type::Plus,
            Box::new(Node::Num(1)),
            Box::new(Node::Num(2))
        );

        assert_eq!(node.eval().unwrap(), 3);

        // 1 + nil return error
        let node = Node::Cal(
            Type::Plus,
            Box::new(Node::Num(1)),
            Box::new(Node::Nil)
        );

        assert!(node.eval().is_err());

        // 1 + 2 * 3
        let node = Node::Cal(
            Type::Plus,
            Box::new(Node::Num(1)),
            Box::new(Node::Cal(
                Type::Mul,
                Box::new(Node::Num(2)),
                Box::new(Node::Num(3))
            ))
        );

        assert_eq!(node.eval().unwrap(), 7);

    }
}
