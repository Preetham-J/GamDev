// Transition to game or restart through user input
if (keyboard_check_pressed(vk_enter))
{
	switch (room)
	{
		case room_start:
			room_goto(room_game);
			break;
		
		case room_win:
		case room_gameover:
			game_restart();
			break;
	}
}

// Transition to win or game over
if (room == room_game)
{
	if (score >= 1000)
	{
		room_goto(room_win);
		audio_play_sound(sound_win, 1, false);
	}

	if (lives <= 0)
	{
		room_goto(room_gameover);
		audio_play_sound(snd_lose, 1, false);
	}
}
