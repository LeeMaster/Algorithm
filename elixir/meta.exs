defmodule Macros do
  defmacro intercept_expr({:+, _, [lhs, rhs]}) do
    quote do
      lhs = unquote(lhs)
      rhs = unquote(rhs)
      result = lhs + rhs
      IO.puts "#{lhs} + #{rhs} = #{result}"
      result
    end
  end

  defmacro intercept_expr({:*, _, [lhs, rhs]}) do
    quote do
      lhs = unquote(lhs)
      rhs = unquote(rhs)
      result = lhs * rhs
      IO.puts "#{lhs} * #{rhs} = #{result}"
      result
    end
  end


end
