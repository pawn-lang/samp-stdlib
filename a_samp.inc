#if defined _INC_a_samp
	#endinput
#endif

#if !defined __PawnBuild
	// Doesn't support `#warning`.
	static Using_legacy_wrapper;
	static Include_open@mp_directly;
	#include <open.mp>
	#endinput
#endif
	
// This is just a backwards-compatible wrapper.
#warning Using legacy wrapper.  Include <open.mp> directly.
#include <open.mp>

