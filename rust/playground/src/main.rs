
fn print(var: i32){
    println!("Var {}", var)
}

fn print_str(s: String){
    println!("String {}", s );
}

fn main() {
    let x = 5;
    let s = String::from("Helloworld");
    // println!("Hello {}", x);
    print(x);
    print_str(s);
    // x = 6;
    println!("World {}", x);
    //println!("S {}", s);

    let p = Point{x: 1, y: 2};
    p.get_sum();
    let p2 = Point{x:0.2, y:0.3};
    p2.get_x();


    let mut a = String::from("s: &str");
    let b = &a;
    println!("{}", a);
    let c = &mut a;
    c.push_str("string: &str");


    let mut data = vec![1,2,3,4];
    let x = &data[0];
    println!("{}", x); // you have to move this ref to some comsumer , when produce a new ref there also one consumer 
    data.push(10);
    
}


struct Point<T>{
    x: T,
    y: T,
}

impl <T> Point<T>{
    fn get_x(&self) -> &T{
        &self.x
    }
}

impl Point<i32>{
    fn get_sum(&self) -> i32{
        self.x + self.y
    }
}
