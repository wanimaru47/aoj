while 1
	sdytime = gets.to_i

	if sdytime == 0
		break
	end

	sdycount = gets.to_i

	set = Array.new()
	times = 0
	1.upto(sdycount) do |i|
		num = gets
		set = num.split(" ")
		times = times + set[1].to_i - set[0].to_i
		#times = times + set[i*2-1].to_i - set[i*2-2].to_i
	end

	#puts "times=#{times}"
	if times >= sdytime
		puts "OK"
	else
		puts (sdytime - times)
	end

end