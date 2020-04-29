// Destory bullet
instance_destroy();

// Increment score
score += 10;

// Play sound
audio_play_sound(snd_die, 1, false);

// Asteroid actions
with (other)
{
	// Destroy asteroid
	instance_destroy();
	
	// If asteroid is large, split into two medium ones
	if (sprite_index == sprite_asteroid_large)
	{
		repeat (2)
		{
			var asteroid = instance_create_layer(x, y, "Instances", object_asteroid);
			asteroid.sprite_index = sprite_asteroid_medium;
		}
	}
	// If asteroid is medium, split into two small ones
	else if (sprite_index == sprite_asteroid_medium)
	{
		repeat (2)
		{
			var asteroid = instance_create_layer(x, y, "Instances", object_asteroid);
			asteroid.sprite_index = sprite_asteroid_small;
		}
	}
	
	// Create debris
	repeat(10)
	{
		instance_create_layer(x, y, "Instances", object_debris);
	}
}
