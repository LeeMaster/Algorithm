//! # 命令行读取
//! 用于读取一些命令行数据，可以用来支持以后的其他样例数据
//! 

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
