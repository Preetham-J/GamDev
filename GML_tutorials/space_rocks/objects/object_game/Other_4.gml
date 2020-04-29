// Spawn initial asteroids
if (room == room_game)
{
	if (audio_is_playing(msc_song))
	{
		audio_stop_sound(msc_song);
	}
	audio_play_sound(msc_song, 2, true);
	repeat(6)
	{
		var asteroid_x = choose(irandom_range(0, room_width * 0.3),
								irandom_range(room_width * 0.7, room_width));
		var asteroid_y = choose(irandom_range(0, room_height * 0.3),
								irandom_range(room_height * 0.7, room_height));
		instance_create_layer(asteroid_x, asteroid_y, "Instances", object_asteroid);
	}
	
	// Set alarm to trigger on 60 steps
	alarm[0] = 60;
}