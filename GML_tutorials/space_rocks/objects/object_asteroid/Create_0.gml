// Randomize asteroid size
sprite_index = choose (
	sprite_asteroid_small,
	sprite_asteroid_medium,
	sprite_asteroid_large
);

// Randomize initial direction, angle, and speed
direction = irandom_range(0, 359);
image_angle = irandom_range(0, 359);
speed = 1;
