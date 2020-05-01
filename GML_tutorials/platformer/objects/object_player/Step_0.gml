/// @description Insert description here

// Check key presses
key_left = keyboard_check(vk_left);
key_right = keyboard_check(vk_right);
key_up = keyboard_check_pressed(vk_up);

// Get movement directions and change speeds
var move = key_right - key_left;
horizontal_speed = move * walk_speed;
vertical_speed += gravity_speed;
// Only allow jumps while on the ground
if ((place_meeting(x, y + 1, object_wall)) && (key_up))
{
	vertical_speed = -7;
}

/* Horizontal Collisions */
if (place_meeting(x + horizontal_speed, y, object_wall))
{
	// Move as close to the wall in pixel increment
	while (!place_meeting(x + sign(horizontal_speed), y, object_wall))
	{
		x += sign(horizontal_speed);
	}
	horizontal_speed = 0;
}
// Move player
x += horizontal_speed;


/* Vertical Collisions */
if (place_meeting(x, y + vertical_speed, object_wall))
{
	// Move as close to the wall in pixel increment
	while (!place_meeting(x, y + sign(vertical_speed), object_wall))
	{
		y += sign(vertical_speed);
	}
	vertical_speed = 0;
}
// Move player
y += vertical_speed;