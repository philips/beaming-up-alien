beer_o_clock = 17
current_hour = tonumber(os.date("%H"))

if (current_hour >= beer_o_clock) then
	print("Time for a Buglight Lime")
else
	d = beer_o_clock - current_hour
	print(string.format("Back to work, %i hours until beer", d))
end
