//! ## 迷宫最短路径
//! 
//! 给定一个大小为NxM的迷宫，迷宫由通道和墙壁组成，可以上下左右进行移动，求从起点到终点的最短路径。


// the Maze status could be wall and the road
pub enum MazeStatus {
    Road,
    Wall
}


#[allow(dead_code)]
pub fn maze_shortest_way_bfs_solve(map:& Vec<Vec<MazeStatus>>) -> i32{
    0
}
