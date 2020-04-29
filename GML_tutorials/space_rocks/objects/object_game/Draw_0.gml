// Transition between rooms
switch (room)
{
	// Game
	case room_game:
		// Display score and lives
		draw_text(20, 20, "SCORE: " + string(score));
		draw_text(20, 40, "LIVES: " + string(lives));
		break;

	// Splash
	case room_start:
		draw_set_halign(fa_center);
		var colour = c_yellow;
		draw_text_transformed_color(
			room_width/2, 100,
			"SPACE ROCKS",
			3, 3, 0, 
			colour, colour, colour, colour, 1
		);
		draw_text(
			room_width/2, 200,
			@"Score 1,000 points to win!
		
			UP: move
			LEFT/RIGHT: change direction
			SPACE: shoot

			>> PRESS ENTER TO START <<
			"
		);
		draw_set_halign(fa_left);
		break;
		
	// Win
	case room_win:
		draw_set_halign(fa_center);
		var colour = c_lime;
		draw_text_transformed_color(
			room_width/2, 200,
			"YOU WON",
			3, 3, 0, 
			colour, colour, colour, colour, 1
		);
		draw_text(room_width/2, 300, "PRESS ENTER TO RESTART");
		draw_set_halign(fa_left);
		break;
	
	// Game over
	case room_gameover:
		draw_set_halign(fa_center);
		var colour = c_red;
		draw_text_transformed_color(
			room_width/2, 150,
			"GAME OVER",
			3, 3, 0, 
			colour, colour, colour, colour, 1
		);
		draw_text(room_width/2, 250, "FINAL SCORE: " + string(score));
		draw_text(room_width/2, 300, "PRESS ENTER TO RESTART");
		draw_set_halign(fa_left);
		break;
}
		