

defmodule Startup do

  def add_function(a, b) do
    if b >= 0 do
      {:ok, a + b}
    else
      {:error, "b is less than zero"}
    end
  end

end

Startup.add_function(1, 2)

# use the map function like &() to wrap and the &number is ref the parameters
# in the function
1..100 |> Stream.map(&(&1*3)) |> Enum.sum


# every match arms should be match not only the data but also the data structure
pattern_match = fn
  [first, second] -> {first, second}
  [first] -> {first, nil}
  _ -> {nil, nil}
end



# IO.puts()
