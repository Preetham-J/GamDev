// Apply spawning only during the game
if (room != room_game)
{
	exit;
}

// Choose whether to spawn from top or bottom
if (choose(0, 1) == 0)
{
	var asteroid_x = choose(0, room_width);
	var asteroid_y = irandom_range(0, room_height);
}
else
{
	var asteroid_x = irandom_range(0, room_width);
	var asteroid_y = choose(0, room_height);
}

// Spawn asteroid
instance_create_layer(asteroid_x, asteroid_y, "Instances", object_asteroid);

// Reset alarm
alarm[0] = 4 * room_speed;