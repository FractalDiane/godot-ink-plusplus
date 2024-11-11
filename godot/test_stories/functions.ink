CONST DAY_SECTION_MORNING = 0
CONST DAY_SECTION_AFTERNOON = 1
CONST DAY_SECTION_EVENING = 2
CONST DAY_SECTION_LATENIGHT = 3

EXTERNAL player_name()

EXTERNAL get_flag(flag)
EXTERNAL set_flag(flag, value)
EXTERNAL script_run_count()
EXTERNAL script_caller_name()
EXTERNAL play_event_after_this(event)

EXTERNAL player_is_familiar()
EXTERNAL set_player_familiar(familiar)

EXTERNAL holding_item(item)
EXTERNAL holding_any_object()
EXTERNAL kill_held_item(item)
EXTERNAL hide_held_item(item)
EXTERNAL show_held_item(item)
EXTERNAL kill_item(item)
EXTERNAL spawn_item(item)
EXTERNAL show_item(item)
EXTERNAL hide_item(item)
EXTERNAL enable_item(item)
EXTERNAL disable_item(item)
EXTERNAL enable_item_pickup(item)
EXTERNAL disable_item_pickup(item)
EXTERNAL freeze_item(item)
EXTERNAL unfreeze_item(item)
EXTERNAL unlock_cauldron_recipe(recipe)

EXTERNAL set_character_emotion(character, emotion)

EXTERNAL enable_item_volume(volume)
EXTERNAL disable_item_volume(volume)
EXTERNAL enable_trigger(trigger)
EXTERNAL disable_trigger(trigger)
EXTERNAL enable_character(character) 
EXTERNAL disable_character(character)

EXTERNAL get_current_day()
EXTERNAL get_current_day_section()
EXTERNAL get_current_timeslot()
EXTERNAL is_start_of_day_section()
EXTERNAL add_flag_change_countdown(flag, value, timeslot_count)
EXTERNAL pass_time()

EXTERNAL mute_ambience()
EXTERNAL unmute_ambience()

EXTERNAL show_tutorial(index)
EXTERNAL is_editor_hint()

EXTERNAL executive_function_challenge_start()
EXTERNAL safe_minigame_start()
EXTERNAL encoding_table_start()
EXTERNAL mail_order_minigame_start()
EXTERNAL breakout_minigame_start()
EXTERNAL catalogue_page_entry_minigame_start()
EXTERNAL enable_asshole_mobile()
EXTERNAL potion_book_start()

EXTERNAL jem_explode_cooking()
EXTERNAL close_bedroom_curtains()
EXTERNAL open_bedroom_curtains()
EXTERNAL inez_drumroll()
EXTERNAL inez_tada()

EXTERNAL enable_kettle_steam()

EXTERNAL sirpa_drop_items()

EXTERNAL display_four_fingers()
EXTERNAL hide_four_fingers()
EXTERNAL haunt_computer()
EXTERNAL exorcise_computer()
EXTERNAL haunt_center()
EXTERNAL close_bedroom_door()
EXTERNAL open_bedroom_door()
EXTERNAL spawn_plushie_pile()
EXTERNAL hide_wisps()

EXTERNAL file_out_mices()
EXTERNAL appreciate_art()
EXTERNAL yeet_mrmoney()

EXTERNAL start_picrew()
EXTERNAL end_picrew()

EXTERNAL start_ending_minigame()
