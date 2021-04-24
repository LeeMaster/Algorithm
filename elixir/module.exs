defmodule Fuck do
  @some_useful_const_list [1, 2, 3, 4, 5, 6]
  use ConstModule
  IO.puts(@some_const)
end

#IO.puts(inspect(Fuck.@some_useful_const_list))
