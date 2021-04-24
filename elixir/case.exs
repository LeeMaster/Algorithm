
tuple_condition = {'search_engine', nil}

group_by = case tuple_condition do
  {_, second} -> second
  {first, nil} -> first
  {nil, nil} -> 'traffic_type'

end

# IO.puts(group_by)


condition = ["hello", "demo1"]

second_group_by = case condition do
  [_, second] -> second
  [first] -> first
  _ -> 'demo'

end

IO.puts(second_group_by)


defmodule DataModule do
  @name_map %{
    1 => "one",
    2 => "two",
    3 => "three",
    4 => "four",
    5 => "five"
  }

  def number_to_name(type) do
    @name_map[type]
  end

end

records = [
  %{
    "hour" => "2021-04-19 22:00:00",
    "traffic_type" => 5,
    "visitor_cnt" => 1,
    "visit_cnt" =>  11,
    "visit_page_cnt" => 14,
    "conv_cnt" => 0,
    "effective_cnt" => 12
  },
  %{
    "hour" => "2021-04-19 22:00:00",
    "traffic_type" => 5,
    "visitor_cnt" => 1,
    "visit_cnt" =>  11,
    "visit_page_cnt" => 14,
    "conv_cnt" => 0,
    "effective_cnt" => 12
  },
  %{
    "hour" => "2021-04-19 22:00:00",
    "traffic_type" => 2,
    "visitor_cnt" => 1,
    "visit_cnt" =>  11,
    "visit_page_cnt" => 14,
    "conv_cnt" => 0,
    "effective_cnt" => 12
  },
  %{
    "hour" => "2021-04-19 22:00:00",
    "traffic_type" => 3,
    "visitor_cnt" => 1,
    "visit_cnt" =>  11,
    "visit_page_cnt" => 14,
    "conv_cnt" => 0,
    "effective_cnt" => 12
  },
  %{
    "hour" => "2021-04-19 22:00:00",
    "traffic_type" => 4,
    "visitor_cnt" => 1,
    "visit_cnt" =>  11,
    "visit_page_cnt" => 14,
    "conv_cnt" => 0,
    "effective_cnt" => 12
  },
] |> Enum.map(
  fn record -> Map.put(
    record,
    "traffic_type",
    DataModule.number_to_name(record["traffic_type"])
    )
  end
  )

IO.puts(inspect(records))



query_conditions = []
