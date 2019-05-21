//! # 挑战程序设计竞赛第一本书
//! 
//! 整个代码仓库使用Rust实现了书中全部的算法，并做了一些解题思路的注解
//! * prepare 模块 第一章节
//! * primary 模块 第二章节
//! * intermediate 模块 第四章节
//! * advanced 模块 第四章节



pub mod prepare;
pub mod primary;
pub mod advanced;
pub mod intermediate;
pub mod common;


#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
