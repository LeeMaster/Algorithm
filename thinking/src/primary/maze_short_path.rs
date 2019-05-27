//! ## 迷宫最短路径
//! 
//! 给定一个大小为NxM的迷宫，迷宫由通道和墙壁组成，可以上下左右进行移动，求从起点到终点的最短路径。

use std::collections::VecDeque;

// the Maze status could be wall and the road
pub enum MazeStatus {
    Road,
    Wall,
    Start,
    End
}

/// ### BFS解决问题
/// 
/// 从起点开始进行搜索，因为图中已经标记了开始和结束位置了，如果发现下一个位置就是终点的话，直接返回就是最短路径。
#[allow(dead_code)]
pub fn maze_shortest_way_bfs_solve(map:& Vec<Vec<MazeStatus>>,start:(usize,usize),end:(usize,usize)) -> i32{
    let mut queue = VecDeque::<(usize,usize,i32)>::new();
    let right_edge = map.len() - 1;
    let bottom_edge = map[0].len() - 1;
   queue.push_back((start.0,start.1,1));

    while !queue.is_empty(){
      let position = queue.pop_front().unwrap();

      // get the top bottom left right value 
      let top = (position.0,position.1 - 1,position.2 + 1);
      let left = (position.0 - 1,position.1,position.2 + 1);
      let right = (position.0 + 1,position.1,position.2 + 1);
      let bottom = (position.0,position.1 + 1,position.2 + 1);


      for next_pos in [left,top,right,bottom].iter() {
        // this method to check the edge is messy to ease it ! 
        if (next_pos.0 >= 0 && next_pos.0 <= right_edge) && 
           (next_pos.1 >= 0 && next_pos.1 <= bottom_edge) && 
           (next_pos.0 != position.0 && next_pos.1 != position.1){

            let attr = &map[next_pos.0][next_pos.1];
            match attr {
              MazeStatus::Road => {
                queue.push_back(*next_pos);
              },
              MazeStatus::Wall | MazeStatus::Start => {
                //should do nothing
              },
              MazeStatus::End => {
                return position.2 + 1;
              }
            }
          }
      }

    }

    0
}
