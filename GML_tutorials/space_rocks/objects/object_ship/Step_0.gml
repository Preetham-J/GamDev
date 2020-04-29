// Left movement
if (keyboard_check(vk_left)) 
{
	image_angle += 5;
}
// Right movement
if (keyboard_check(vk_right)) 
{
	image_angle -= 5;
}
// Up movement
if (keyboard_check(vk_up)) 
{
	motion_add(image_angle, 0.05);
}

// Shooting bullets
if (keyboard_check_pressed(vk_space)) 
{
	var bullet = instance_create_layer(x, y, "Instances", object_bullet);
	bullet.direction = image_angle;
	audio_play_sound(snd_zap, 1, false);
}

// Border Wrap
move_wrap(true, true, sprite_width/2); 
