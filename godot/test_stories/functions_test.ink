INCLUDE test_stories/functions.ink
//INCLUDE test_stories/include.ink

VAR day = DAY_SECTION_AFTERNOON

It is currently <>
{ day:
	- DAY_SECTION_MORNING: morning
	- DAY_SECTION_AFTERNOON: afternoon
	- DAY_SECTION_EVENING: evening
	- else: night
}
<>.
