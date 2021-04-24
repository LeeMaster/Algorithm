defmodule Time do
  def analytics_to_iso8601(time) do
    <<year::binary-size(4), _, month::binary-size(2), _, day::binary-size(2), _, hour::binary-size(2)>> = time
    NaiveDateTime.new!(String.to_integer(year), String.to_integer(month), String.to_integer(day), String.to_integer(hour), 0, 0)
    |> NaiveDateTime.to_iso8601()
  end
end


IO.puts(Time.analytics_to_iso8601("2021-04-20 16"))
IO.puts(Time.analytics_to_iso8601("2021-04-21 15"))
