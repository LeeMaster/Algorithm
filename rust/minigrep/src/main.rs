use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();

    let query = &args[0];
    let filename = &args[1];

    let contents = fs::read_to_string(filename).expect("Something went wrong reading the file")


    println!("The args is {:?}", args);
}
