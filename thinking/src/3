use std::io;
use std::io::prelude::*;

pub struct DataReader<'a> {
    reader:&'a mut Read,
}

impl<'a> DataReader<'a> {
    pub fn new(read:&'a mut Read) -> DataReader{
        DataReader{
            // use the BufRead to replace the Read
            reader:read
        }
    }
}
