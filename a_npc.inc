/*  SA-MP NPC Functions
 *
 *  (c) Copyright 2009, SA-MP Team
 *
 */

#if defined _INC_a_npc
	#endinput
#endif
#if defined _INC_a_samp
	#error Include `<a_samp>` or `<a_npc>`, not both.
#endif
#define _INC_a_npc
#define _samp_included

#define SAMP_CONST_CORRECT

// Ignores warning 217 for properly indented PAWNO code
// It's tab size is 4 and often uses 4 spaces instead, PAWNCC's is 8
#pragma tabsize 4

// --------------------------------------------------
// Defines
// --------------------------------------------------

// Limits
#if defined MAX_PLAYER_NAME
	static const __MAX_PLAYER_NAME             = MAX_PLAYER_NAME;
	#undef MAX_PLAYER_NAME
	const MAX_PLAYER_NAME                      = __MAX_PLAYER_NAME;
#else
	const MAX_PLAYER_NAME                      = 24;
#endif

#if defined MAX_PLAYERS
	static const __MAX_PLAYERS                 = MAX_PLAYERS;
	#undef MAX_PLAYERS
	const MAX_PLAYERS                          = __MAX_PLAYERS;
#else
	const MAX_PLAYERS                          = 1000;
#endif

#if defined MAX_VEHICLES
	static const __MAX_VEHICLES                = MAX_VEHICLES;
	#undef MAX_VEHICLES
	const MAX_VEHICLES                         = __MAX_VEHICLES;
#else
	const MAX_VEHICLES                         = 2000;
#endif

#if defined MAX_ACTORS
	static const __MAX_ACTORS                  = MAX_ACTORS;
	#undef MAX_ACTORS
	const MAX_ACTORS                           = __MAX_ACTORS;
#else
	const MAX_ACTORS                           = 1000;
#endif

#if defined MAX_OBJECTS
	static const __MAX_OBJECTS                 = MAX_OBJECTS;
	#undef MAX_OBJECTS
	const MAX_OBJECTS                          = __MAX_OBJECTS;
#else
	const MAX_OBJECTS                          = 2000;
#endif

#if defined MAX_GANG_ZONES
	static const __MAX_GANG_ZONES              = MAX_GANG_ZONES;
	#undef MAX_GANG_ZONES
	const MAX_GANG_ZONES                       = __MAX_GANG_ZONES;
#else
	const MAX_GANG_ZONES                       = 1024;
#endif

#if defined MAX_TEXT_DRAWS
	static const Text:__MAX_TEXT_DRAWS         = Text:MAX_TEXT_DRAWS;
	#undef MAX_TEXT_DRAWS
	const Text:MAX_TEXT_DRAWS                  = __MAX_TEXT_DRAWS;
#else
	const Text:MAX_TEXT_DRAWS                  = Text:2048;
#endif

#if defined MAX_PLAYER_TEXT_DRAWS
	static const PlayerText:__MAX_PLAYER_TEXT_DRAWS = PlayerText:MAX_PLAYER_TEXT_DRAWS;
	#undef MAX_PLAYER_TEXT_DRAWS
	const PlayerText:MAX_PLAYER_TEXT_DRAWS     = PlayerText:__MAX_PLAYER_TEXT_DRAWS;
#else
	const PlayerText:MAX_PLAYER_TEXT_DRAWS     = PlayerText:256;
#endif

#if defined MAX_MENUS
	static const Menu:__MAX_MENUS              = Menu:MAX_MENUS;
	#undef MAX_MENUS
	const Menu:MAX_MENUS                       = Menu:__MAX_MENUS;
#else
	const Menu:MAX_MENUS                       = Menu:128;
#endif

#if defined MAX_3DTEXT_GLOBAL
	static const Text3D:__MAX_3DTEXT_GLOBAL    = Text3D:MAX_3DTEXT_GLOBAL;
	#undef MAX_3DTEXT_GLOBAL
	const Text3D:MAX_3DTEXT_GLOBAL             = Text3D:__MAX_3DTEXT_GLOBAL;
#else
	const Text3D:MAX_3DTEXT_GLOBAL             = Text3D:1024;
#endif

#if defined MAX_3DTEXT_PLAYER
	static const PlayerText3D:__MAX_3DTEXT_PLAYER = PlayerText3D:MAX_3DTEXT_PLAYER;
	#undef MAX_3DTEXT_PLAYER
	const PlayerText3D:MAX_3DTEXT_PLAYER       = PlayerText3D:__MAX_3DTEXT_PLAYER;
#else
	const PlayerText3D:MAX_3DTEXT_PLAYER       = PlayerText3D:1024;
#endif

#if defined MAX_PICKUPS
	static const __MAX_PICKUPS                 = MAX_PICKUPS;
	#undef MAX_PICKUPS
	const MAX_PICKUPS                          = __MAX_PICKUPS;
#else
	const MAX_PICKUPS                          = 4096;
#endif

#if defined NO_TAGS
	#define __TAG(%0) _
#elseif defined STRONG_TAGS
	#define __TAG(%0) E_%0
#else // if defined WEAK_TAGS
	#define __TAG(%0) e_%0
	#define WEAK_TAGS
#endif
#if defined MORE_TAGS
	#define __MORE(%0) __TAG(%0)
#else
	#define __MORE(%0) _
	#define LESS_TAGS
#endif
#define __LESS __TAG

// Invalids
const NO_TEAM = 0xFF;

const INVALID_PLAYER_ID                        = 0xFFFF;
const INVALID_VEHICLE_ID                       = 0xFFFF;
const INVALID_ACTOR_ID                         = 0xFFFF;
const INVALID_OBJECT_ID                        = 0xFFFF;
const Menu:INVALID_MENU                        = Menu:0xFF;
const Text:INVALID_TEXT_DRAW                   = Text:0xFFFF;
const PlayerText:INVALID_PLAYER_TEXT_DRAW      = PlayerText:0xFFFF;
const INVALID_GANG_ZONE                        = 0xFFFFFFFF;
const Text3D:INVALID_3DTEXT_ID                 = Text3D:0xFFFF;
const PlayerText3D:INVALID_PLAYER_3DTEXT_ID    = PlayerText3D:0xFFFF;

// States
#define PLAYER_STATE: __TAG(PLAYER_STATE):
enum PLAYER_STATE:
{
	PLAYER_STATE_NONE,
	PLAYER_STATE_ONFOOT,
	PLAYER_STATE_DRIVER,
	PLAYER_STATE_PASSENGER,
	PLAYER_STATE_WASTED                        = 7,
	PLAYER_STATE_SPAWNED,
	PLAYER_STATE_SPECTATING
}

// Weapons
#define WEAPON: __TAG(WEAPON):
enum WEAPON:
{
	WEAPON_BRASSKNUCKLE                        = 1,
	WEAPON_GOLFCLUB,
	WEAPON_NITESTICK,
	WEAPON_KNIFE,
	WEAPON_BAT,
	WEAPON_SHOVEL,
	WEAPON_POOLSTICK,
	WEAPON_KATANA,
	WEAPON_CHAINSAW,
	WEAPON_DILDO,
	WEAPON_DILDO2,
	WEAPON_VIBRATOR,
	WEAPON_VIBRATOR2,
	WEAPON_FLOWER,
	WEAPON_CANE,
	WEAPON_GRENADE,
	WEAPON_TEARGAS,
	WEAPON_MOLTOV,
	WEAPON_COLT45                              = 22,
	WEAPON_SILENCED,
	WEAPON_DEAGLE,
	WEAPON_SHOTGUN,
	WEAPON_SAWEDOFF,
	WEAPON_SHOTGSPA,
	WEAPON_UZI,
	WEAPON_MP5,
	WEAPON_AK47,
	WEAPON_M4,
	WEAPON_TEC9,
	WEAPON_RIFLE,
	WEAPON_SNIPER,
	WEAPON_ROCKETLAUNCHER,
	WEAPON_HEATSEEKER,
	WEAPON_FLAMETHROWER,
	WEAPON_MINIGUN,
	WEAPON_SATCHEL,
	WEAPON_BOMB,
	WEAPON_SPRAYCAN,
	WEAPON_FIREEXTINGUISHER,
	WEAPON_CAMERA,
	WEAPON_PARACHUTE                           = 46,
	WEAPON_VEHICLE                             = 49,
	WEAPON_DROWN                               = 53,
	WEAPON_COLLISION,
}

// Keys
#define KEY: __TAG(KEY):
enum KEY: (<<= 1)
{
	KEY_ACTION                                 = 1,
	KEY_CROUCH,
	KEY_FIRE,
	KEY_SPRINT,
	KEY_SECONDARY_ATTACK,
	KEY_JUMP,
	KEY_LOOK_RIGHT,
	KEY_HANDBRAKE,
	KEY_LOOK_LEFT,
	KEY_SUBMISSION,
	KEY_LOOK_BEHIND                            = KEY_SUBMISSION,
	KEY_WALK,
	KEY_ANALOG_UP,
	KEY_ANALOG_DOWN,
	KEY_ANALOG_LEFT,
	KEY_ANALOG_RIGHT,
	KEY_YES                                    = 65536,
	KEY_NO,
	KEY_CTRL_BACK,

	KEY_UP                                     = -128,
	KEY_DOWN                                   =  128,
	KEY_LEFT                                   = -128,
	KEY_RIGHT                                  =  128,
}

#define PLAYER_RECORDING_TYPE: __TAG(PLAYER_RECORDING_TYPE):
enum PLAYER_RECORDING_TYPE:
{
	PLAYER_RECORDING_TYPE_NONE,
	PLAYER_RECORDING_TYPE_DRIVER,
	PLAYER_RECORDING_TYPE_ONFOOT
}

// Limits
#if MAX_PLAYER_NAME < 1 || MAX_PLAYER_NAME > 24
	#error MAX_PLAYER_NAME must be >= 1 and <= 24
#endif

#if MAX_PLAYERS < 1 || MAX_PLAYERS > 1000
	#error MAX_PLAYERS must be >= 1 and <= 1000
#endif

#if MAX_VEHICLES < 1 || MAX_VEHICLES > 2000
	#error MAX_VEHICLES must be >= 1 and <= 2000
#endif

#if MAX_OBJECTS < 1 || MAX_OBJECTS > 2000
	#error MAX_OBJECTS must be >= 1 and <= 2000
#endif

#if MAX_GANG_ZONES < 1 || MAX_GANG_ZONES > 1024
	#error MAX_GANG_ZONES must be >= 1 and <= 1024
#endif

#if MAX_TEXT_DRAWS < Text:1 || MAX_TEXT_DRAWS > Text:2048
	#error MAX_TEXT_DRAWS must be >= 1 and <= 2048
#endif

#if MAX_MENUS < Menu:1 || MAX_MENUS > Menu:128
	#error MAX_MENUS must be >= 1 and <= 128
#endif

public const SAMP_INCLUDES_VERSION = 0x037030;
#pragma unused SAMP_INCLUDES_VERSION

#include <core>
#include <float>
#include <string>
#include <file>
#include <time>
#include <datagram>
#tryinclude <console>

/*

Version examples:

0.3.DL R1       - 03D010

0.3.7 R3        - 037030
0.3.7 R2-2      - 037022
0.3.7 R1-2      - 037012
0.3.7           - 037000

0.3z R4         - 030700
0.3z R3         - 030700
0.3z R2-1       - 030700
0.3z R1-2       - 030700
0.3z            - 030700
0.3x R2 patch 1 - 030621
0.3x R2         - 030620
0.3x R1-2       - 030612
0.3x            - 030600
0.3e            - 030500
0.3d            - 030400
0.3c            - 030300
0.3b            - 030200
0.3a            - 030100

0.2X            - 02A000
0.2.2 R3        - 022300

Rough rules:

Uses (roughtly) BCD.  Special versions are denoted outside 0-9.

0.1.2c R4-5
| | ||  | |
0 1 23  4 5
=
0x012345

(assuming c is the third revision)

0.2X becomes 02A000 because it is basically 0.2.3, but not, while higher than
0.2.2 so can't be 020400 (for example).  Also, its a capital letter, so doesn't
use the revision method.

P.S.  Making a consistent scheme for SA:MP versions is REALLY hard.

open.mp releases can use `A` as the first digit.

*/

// --------------------------------------------------
// Natives
// --------------------------------------------------

// Util

#if !defined _console_included
	#define _console_included

	/// <summary>Prints a string to the server console (not in-game chat) and logs (server_log.txt).</summary>
	/// <param name="string">The string to print</param>
	/// <seealso name="printf" />
	native print(const string[]);

	/// <summary>Outputs a formatted string on the console (the server window, not the in-game chat).</summary>
	/// <param name="format">The format string</param>
	/// <param name="">Indefinite number of arguments of any tag</param>
	/// <seealso name="print" />
	/// <seealso name="format" />
	/// <remarks>The format string or its output should not exceed 1024 characters. Anything beyond that length can lead to a server to crash.</remarks>
	/// <remarks>This function doesn't support <a href="#strpack">packed</a> strings.</remarks>
	/// <remarks>
	///   <b>Format Specifiers:</b><br />
	///   <ul>
	///     <li><b><c>%i</c></b> - integer (whole number)</li>
	///     <li><b><c>%d</c></b> - integer (whole number).</li>
	///     <li><b><c>%s</c></b> - string</li>
	///     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
	///     <li><b><c>%c</c></b> - ASCII character</li>
	///     <li><b><c>%x</c></b> - hexadecimal number</li>
	///     <li><b><c>%b</c></b> - binary number</li>
	///     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
	///     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
	///   </ul>
	/// </remarks>
	/// <remarks>The values for the placeholders follow in the exact same order as parameters in the call. For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer variable, which is the person's age.</remarks>
	/// <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder code. This number indicates the field width; if the size of the parameter to print at the position of the placeholder is smaller than the field width, the field is expanded with spaces. To cut the number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
	native printf(const format[], {Float, _}:...);
#endif

/// <summary>Formats a string to include variables and other strings inside it.</summary>
/// <param name="output">The string to output the result to</param>
/// <param name="len">The maximum length output can contain</param>
/// <param name="format">The format string</param>
/// <param name="">Indefinite number of arguments of any tag</param>
/// <seealso name="print" />
/// <seealso name="printf" />
/// <remarks>This function doesn't support <a href="#strpack">packed strings</a>.</remarks>
/// <remarks>
///   <b>Format Specifiers:</b><br />
///   <ul>
///     <li><b><c>%i</c></b> - integer (whole number)</li>
///     <li><b><c>%d</c></b> - integer (whole number).</li>
///     <li><b><c>%s</c></b> - string</li>
///     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
///     <li><b><c>%c</c></b> - ASCII character</li>
///     <li><b><c>%x</c></b> - hexadecimal number</li>
///     <li><b><c>%b</c></b> - binary number</li>
///     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
///     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
///   </ul>
/// </remarks>
/// <remarks>The values for the placeholders follow in the exact same order as parameters in the call. For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer variable, which is the person's age.</remarks>
/// <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder code. This number indicates the field width; if the size of the parameter to print at the position of the placeholder is smaller than the field width, the field is expanded with spaces. To cut the number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
native format(output[], len = sizeof (output), const format[], {Float, _}:...);

/// <summary>Sets a 'timer' to call a function after some time. Can be set to repeat.</summary>
/// <param name="functionName">Name of the function to call as a string. This must be a public function (forwarded). A null string here will crash the server</param>
/// <param name="interval">Interval in milliseconds</param>
/// <param name="repeating">Whether the timer should repeat or not</param>
/// <seealso name="SetTimerEx" />
/// <seealso name="KillTimer" />
/// <remarks>Timer intervals are not accurate (roughly 25% off). There's a fix available <a href="http://forum.sa-mp.com/showthread.php?t=289675">here</a>. </remarks>
/// <remarks>Timer IDs are never used twice. You can use <a href="#KillTimer">KillTimer</a> on a timer ID and it won't matter if it's running or not. </remarks>
/// <remarks>The function that should be called must be public. </remarks>
/// <remarks>The use of many timers will result in increased memory/cpu usage. </remarks>
/// <returns>The ID of the timer that was started. Timer IDs start at <b><c>1</c></b>.</returns>
native SetTimer(const functionName[], interval, bool:repeating);

/// <summary>Kills (stops) a running timer.</summary>
/// <param name="timerid">The ID of the timer to kill (returned by <a href="#SetTimer">SetTimer</a> or <a href="#SetTimerEx">SetTimerEx</a>)</param>
/// <seealso name="SetTimer" />
/// <seealso name="SetTimerEx" />
/// <returns>This function always returns <b><c>0</c></b>.</returns>
native KillTimer(timerid);

/// <summary>Returns the uptime of the actual server (not the SA-MP server) in milliseconds.</summary>
/// <seealso name="tickcount" />
/// <remarks>GetTickCount will cause problems on servers with uptime of over 24 days as GetTickCount will eventually warp past the integer size constraints. However using <a href="https://gist.github.com/ziggi/5d7d8dc42f54531feba7ae924c608e73">this</a> function fixes the problem.</remarks>
/// <remarks>One common use for GetTickCount is for benchmarking. It can be used to calculate how much time some code takes to execute.</remarks>
/// <returns>Uptime of the actual server (not the SA-MP server).</returns>
native GetTickCount();

/// <summary>Get the inversed value of a sine in degrees.</summary>
/// <param name="value">The sine for which to find the angle for</param>
/// <seealso name="floatsin" />
/// <returns>The angle in degrees.</returns>
native Float:asin(Float:value);

/// <summary>Get the inversed value of a cosine in degrees.</summary>
/// <param name="value">The cosine for which to find the angle for</param>
/// <seealso name="floatcos" />
/// <returns>The angle in degrees.</returns>
native Float:acos(Float:value);

/// <summary>Get the inversed value of a tangent in degrees.</summary>
/// <param name="value">The tangent for which to find the angle for</param>
/// <seealso name="atan2" />
/// <seealso name="floattan" />
/// <returns>The angle in degrees.</returns>
native Float:atan(Float:value);

/// <summary>Get the multi-valued inversed value of a tangent in degrees.</summary>
/// <param name="y">y size</param>
/// <param name="x">x size</param>
/// <seealso name="atan" />
/// <seealso name="floattan" />
/// <returns>The angle in degrees.</returns>
native Float:atan2(Float:y, Float:x);

/// <summary>This will send a player text by the bot, just like using <a href="#SendPlayerMessageToAll">SendPlayerMessageToAll</a>, but this function is to be used inside the NPC scripts.</summary>
/// <param name="message">The text to be sent by the NPC</param>
/// <seealso name="SendCommand" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native SendChat(const message[]);

/// <summary>This will force the NPC to write a desired command, and this way, getting the effects it would produce.</summary>
/// <param name="command">The command text to be sent by the NPC</param>
/// <seealso name="SendChat" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native SendCommand(const command[]);

/// <summary>Get a player's current state.</summary>
/// <param name="playerid">The ID of the player to get the current state of</param>
/// <seealso name="GetPlayerSpecialAction" />
/// <seealso name="SetPlayerSpecialAction" />
/// <seealso name="OnPlayerStateChange" />
/// <remarks>
///   <b>States:</b><br />
///   <ul>
///     <li><b><c>PLAYER_STATE_NONE</c></b> - empty (while initializing)</li>
///     <li><b><c>PLAYER_STATE_ONFOOT</c></b> - player is on foot</li>
///     <li><b><c>PLAYER_STATE_DRIVER</c></b> - player is the driver of a vehicle</li>
///     <li><b><c>PLAYER_STATE_PASSENGER</c></b> - player is passenger of a vehicle</li>
///     <li><b><c>PLAYER_STATE_WASTED</c></b> - player is dead or on class selection</li>
///     <li><b><c>PLAYER_STATE_SPAWNED</c></b> - player is spawned</li>
///     <li><b><c>PLAYER_STATE_SPECTATING</c></b> - player is spectating</li>
///     <li><b><c>PLAYER_STATE_EXIT_VEHICLE</c></b> - player exits a vehicle</li>
///     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_DRIVER</c></b> - player enters a vehicle as driver</li>
///     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_PASSENGER</c></b> - player enters a vehicle as passenger </li>
///   </ul>
/// </remarks>
/// <returns>The player's current state as an integer.</returns>
native GetPlayerState(playerid);

/// <summary>Get the position of a player, represented by x, y and z coordinates.</summary>
/// <param name="playerid">The ID of the player to get the position of</param>
/// <param name="x">A float variable in which to store the x coordinate in, passed by reference</param>
/// <param name="y">A float variable in which to store the y coordinate in, passed by reference</param>
/// <param name="z">A float variable in which to store the z coordinate in, passed by reference</param>
/// <seealso name="SetPlayerPos" />
/// <seealso name="GetVehiclePos" />
/// <seealso name="IsPlayerInRangeOfPoint" />
/// <seealso name="GetPlayerDistanceFromPoint" />
/// <remarks>This function is known to return unreliable values when used in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a> and <a href="#OnPlayerRequestClass">OnPlayerRequestClass</a>. This is because the player is not spawned.</remarks>
/// <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure (i.e. player not connected).</returns>
native GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z);

/// <summary>This function gets the ID of the vehicle the player is currently in. Note: <b>NOT</b> the model ID of the vehicle. See <a href="#GetVehicleModel">GetVehicleModel</a> for that.</summary>
/// <param name="playerid">The ID of the player in the vehicle that you want to get the ID of</param>
/// <seealso name="IsPlayerInVehicle" />
/// <seealso name="IsPlayerInAnyVehicle" />
/// <seealso name="GetPlayerVehicleSeat" />
/// <seealso name="GetVehicleModel" />
/// <returns>ID of the vehicle or <b><c>0</c></b> if not in a vehicle.</returns>
native GetPlayerVehicleid(playerid);
native GetPlayerArmedWeapon(playerid);

native GetPlayerHealth(playerid);
native GetPlayerArmour(playerid);

/// <summary>Retrieves a player's current <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a>.</summary>
/// <param name="playerid">The ID of the player to get the <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a> of</param>
/// <seealso name="SetPlayerSpecialAction" />
/// <seealso name="GetPlayerState" />
/// <returns>The <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a> of the player.</returns>
native GetPlayerSpecialAction(playerid);

/// <summary>Checks if a player is streamed in for an NPC. Only nearby players are streamed in.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="IsVehicleStreamedIn" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the player is streamed in, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerStreamedIn(playerid);

/// <summary>Checks if a vehicle is streamed in for an NPC. Only nearby vehicles are streamed in.</summary>
/// <param name="vehicleid">The ID of the vehicle to check</param>
/// <seealso name="IsPlayerStreamedIn" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the vehicle is streamed in, <b><c>0</c></b> if not.</returns>
native bool:IsVehicleStreamedIn(vehicleid);

/// <summary>Check which keys a player is pressing.</summary>
/// <param name="playerid">The ID of the player to get the keys of</param>
/// <param name="keys">Bitmask containing the player's key states. <a href="http://wiki.sa-mp.com/wiki/Keys">List of keys</a></param>
/// <param name="updown">Up/down state</param>
/// <param name="leftright">Left/right state</param>
/// <seealso name="OnPlayerKeyStateChange" />
/// <remarks>Only the FUNCTION of keys can be detected; not actual keys. For example, it is not possible to detect if a player presses <b>SPACE</b>, but you can detect if they press <b>SPRINT</b> (which can be mapped (assigned/binded) to ANY key (but is space by default)). </remarks>
/// <remarks>As of update 0.3.7, the keys "A" and "D" are not recognized when in a vehicle. However, keys "W" and "S" can be detected with the "keys" parameter. </remarks>
/// <returns>The keys are stored in the specified variables.</returns>
native GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright);

/// <summary>Gets the angle a player is facing.</summary>
/// <param name="playerid">The player you want to get the angle of</param>
/// <param name="ang">The Float to store the angle in, passed by reference</param>
/// <remarks>Angles are reversed in GTA:SA; 90 degrees would be East in the real world, but in GTA:SA 90 degrees is in fact West. North and South are still 0/360 and 180. To convert this, simply do <b>360 - angle</b>.</remarks>
/// <remarks>Angles returned when inside a vehicle is rarely correct. To get the correct facing angle while inside a vehicle, use <a href="#GetVehicleZAngle">GetVehicleZAngle</a>.</remarks>
native GetPlayerFacingAngle(playerid, &Float:ang);

/// <summary>Get the current location of the NPC.</summary>
/// <param name="x">A float to save the x coordinate, passed by reference</param>
/// <param name="y">A float to save the y coordinate, passed by reference</param>
/// <param name="z">A float to save the z coordinate, passed by reference</param>
/// <seealso name="SetMyPos" />
/// <seealso name="GetDistanceFromMeToPoint" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native GetMyPos(&Float:x, &Float:y, &Float:z);

/// <summary>Set the position of the NPC.</summary>
/// <param name="x">The x coordinate to put the NPC at</param>
/// <param name="y">The y coordinate to put the NPC at</param>
/// <param name="z">The z coordinate to put the NPC at</param>
/// <seealso name="GetMyPos" />
/// <seealso name="GetDistanceFromMeToPoint" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native SetMyPos(Float:x, Float:y, Float:z);

/// <summary>Get the current facing angle of the NPC.</summary>
/// <param name="ang">A float to save the angle in, passed by reference</param>
/// <seealso name="SetMyFacingAngle" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>The facing angle is stored in the specified variable.</returns>
native GetMyFacingAngle(&Float:ang);

/// <summary>Set the NPC's facing angle.</summary>
/// <param name="ang">The new NPC's facing angle</param>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>This function does not return any specific values.</returns>
native SetMyFacingAngle(Float:ang);

/// <summary>Get the distance between the NPC and a point.</summary>
/// <param name="x">The x coordinate of the point</param>
/// <param name="y">The y coordinate of the point</param>
/// <param name="z">The z coordinate of the point</param>
/// <param name="distance">A float to save the distance in, passed by reference</param>
/// <seealso name="GetMyPos" />
/// <seealso name="SetMyPos" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>This function does not return any specific values.</returns>
native GetDistanceFromMeToPoint(Float:x, Float:y, Float:z, &Float:distance);

/// <summary>Checks if a player is in range of a point. This native function is faster than the PAWN implementation using distance formula.</summary>
/// <param name="playerid">The ID of the player</param>
/// <param name="range">The furthest distance the player can be from the point to be in range</param>
/// <param name="x">The x coordinate of the point to check the range to</param>
/// <param name="y">The y coordinate of the point to check the range to</param>
/// <param name="z">The z coordinate of the point to check the range to</param>
/// <seealso name="GetPlayerDistanceFromPoint" />
/// <seealso name="GetVehicleDistanceFromPoint" />
/// <seealso name="GetPlayerPos" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the player is in range, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z);

/// <summary>Get a player's name.</summary>
/// <param name="playerid">The ID of the player to get the name of</param>
/// <param name="name">An array into which to store the name, passed by reference</param>
/// <param name="len">The length of the string that should be stored. Recommended to be <b><c>MAX_PLAYER_NAME</c></b></param>
/// <seealso name="SetPlayerName" />
/// <seealso name="GetPlayerIp" />
/// <seealso name="GetPlayerPing" />
/// <seealso name="GetPlayerScore" />
/// <seealso name="GetPlayerVersion" />
/// <remarks>A player's name can be up to 24 characters long (as of <b>0.3d R2</b>) by using <a href="#SetPlayerName">SetPlayerName</a>. This is defined in <c>a_samp.inc</c> as <b><c>MAX_PLAYER_NAME</c></b>. However, the client can only join with a nickname between 3 and 20 characters, otherwise the connection will be rejected and the player has to quit to choose a valid name.</remarks>
/// <returns>The length of the player's name. <b><c>0</c></b> if player specified doesn't exist.</returns>
native GetPlayerName(playerid, name[], len = sizeof (name));

/// <summary>Checks if a player is connected (if an ID is taken by a connected player).</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="IsPlayerAdmin" />
/// <seealso name="OnPlayerConnect" />
/// <seealso name="OnPlayerDisconnect" />
/// <remarks>This function can be omitted in a lot of cases. Many other functions already have some sort of connection check built in.</remarks>
/// <returns><b><c>1</c></b> if the player is connected, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerConnected(playerid);

/// <summary>This will run a .rec file which has to be saved in the npcmodes/recordings folder. These files allow the NPC to follow certain actions. Their actions can be recorded manually. For more information, check the related functions.</summary>
/// <param name="playbacktype">The type of recording to be loaded</param>
/// <param name="recordFile">The filename to be loaded, without the .rec extension</param>
/// <seealso name="StopRecordingPlayback" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native StartRecordingPlayback(PLAYER_RECORDING_TYPE:playbacktype, const recordFile[]);

/// <summary>This will stop the current .rec file which is being ran by the NPC, making it stay idle until some other order is given.</summary>
/// <seealso name="StartRecordingPlayback" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native StopRecordingPlayback();

/// <summary>This will pause playing back the recording.</summary>
/// <seealso name="ResumeRecordingPlayback" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native PauseRecordingPlayback();

/// <summary>This will resume the paused recording.</summary>
/// <seealso name="PauseRecordingPlayback" />
/// <remarks>This NPC function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native ResumeRecordingPlayback();

// --------------------------------------------------
// Forwards (Callback declarations)
// --------------------------------------------------

/// <summary>Gets called when a NPC script is loaded.</summary>
/// <seealso name="OnNPCModeExit" />
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnNPCModeInit();

/// <summary>Gets called when a NPC-script unloaded.</summary>
/// <seealso name="OnNPCModeInit" />
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnNPCModeExit();

/// <summary>Gets called when a NPC successfully connects to the server.</summary>
/// <param name="myplayerid">The playerid the NPC has been given</param>
/// <seealso name="OnNPCDisconnect" />
/// <seealso name="OnPlayerConnect" />
/// <seealso name="OnPlayerDisconnect" />
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnNPCConnect(myplayerid);

/// <summary>Gets called when the NPC gets disconnected from the server.</summary>
/// <param name="reason">The reason why the bot has disconnected from the server</param>
/// <seealso name="OnNPCConnect" />
/// <seealso name="OnPlayerDisconnect" />
/// <seealso name="OnPlayerConnect" />
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnNPCDisconnect(reason[]);

/// <summary>Gets called when a NPC spawned.</summary>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnNPCSpawn();

/// <summary>Gets called when a NPC enters a vehicle.</summary>
/// <param name="vehicleid">The vehicleid from the Vehicle the NPC enters</param>
/// <param name="seatid">The seatid the NPC uses</param>
/// <seealso name="OnNPCExitVehicle" />
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnNPCEnterVehicle(vehicleid, seatid);

/// <summary>Gets called when a NPC leaves a vehicle.</summary>
/// <seealso name="OnNPCEnterVehicle" />
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnNPCExitVehicle();

/// <summary>This callback gets called whenever the NPC sees a ClientMessage. This will be everytime a <a href="#SendClientMessageToAll">SendClientMessageToAll</a> function is used and everytime a <a href="#SendClientMessage">SendClientMessage</a> function is sent towards the NPC. This callback won't be called when someone says something. For a version of this with player text, see <a href="#OnPlayerText">OnPlayerText</a>.</summary>
/// <param name="colour">The colour the ClientMessage is</param>
/// <param name="text">The actual message</param>
/// <seealso name="OnPlayerText" />
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnClientMessage(colour, text[]);

/// <summary>Just as the player version of the callback, this callback is called when any player dies.</summary>
/// <param name="playerid">The player who has died</param>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnPlayerDeath(playerid);

/// <summary>Opposed to the player version of this callback, this callback is called everytime anyone says anything in the chat. This includes any player, any other NPC, or the same NPC himself.</summary>
/// <param name="playerid">The player who has written something in the chat</param>
/// <param name="text">The text written by playerid</param>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnPlayerText(playerid, text[]);

/// <summary>This callback is called when a player is streamed in for an NPC. Only nearby players are streamed in.</summary>
/// <param name="playerid">The ID of the player that is now streamed in for the NPC</param>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnPlayerStreamIn(playerid);

/// <summary>This callback is called when a player is streamed out the NPC.</summary>
/// <param name="playerid">The player who has been destreamed</param>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnPlayerStreamOut(playerid);

/// <summary>This callback is called when a vehicle is streamed by the NPC. A simpler definition would be when the NPC sees the grey vehicle icon appear on his map.</summary>
/// <param name="vehicleid">The vehicle that has been streamed</param>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnVehicleStreamIn(vehicleid);

/// <summary>This callback is called when a vehicle is streamed out for an NPC.</summary>
/// <param name="vehicleid">The vehicle that was streamed out</param>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnVehicleStreamOut(vehicleid);

/// <summary>This callback is called when a recorded file being reproduced with <a href="#StartRecordingPlayback">StartRecordingPlayback</a> has reached to its end.</summary>
/// <remarks>This NPC callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
forward OnRecordingPlaybackEnd();

