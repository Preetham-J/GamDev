// Destroy ship
instance_destroy();

// Decrement lives
lives -= 1;

// Play sound
audio_play_sound(snd_die, 1, false);

// Pause before restarting
with (object_game)
{
	alarm[1] = room_speed;
}

// Create debris
repeat (10)
{
	instance_create_layer(x, y, "Instances", object_debris);
}
