


defmodule Loop do

  # implmentation the below logic

  # for(int i = 0; i < 10; i++){
  #   for(int j = 0; j < 10; j++){
  #     cout << "i " << i << " j " << j;
  #   }
  # }
  def outer_loop(n, j) when n <= 1 do
    inner_loop(n, j)
  end

  def outer_loop(n, j) do
    inner_loop(n, j)
    outer_loop(n - 1, j)
  end

  def inner_loop(i, j) when j <= 1 do
    IO.puts("i #{i} j #{j}")
  end

  def inner_loop(i, j) do
    IO.puts("i #{i} j #{j}")
    inner_loop(i, j - 1)
  end

end

Loop.outer_loop(2, 2)
