defmodule ConstModule do

  defmacro __using__(_opts) do
    quote do
      @some_const 1
    end
  end
end
