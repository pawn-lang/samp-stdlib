#if defined _INC_a_samp
	#endinput
#endif

#if defined _INC_a_npc
	#error Include `<a_samp>` or `<a_npc>`, not both.
#endif
#define _INC_a_samp
#define _samp_included

// This is just a backwards-compatible wrapper.
#include <open.mp>

