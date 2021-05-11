/*  SA-MP Player Functions
 *
 *  (c) Copyright 2005-2017, SA-MP Team
 *
 */

#if defined _INC_a_players
	#endinput
#endif
#define _INC_a_players
#define _players_included

#define SAMP_CONST_CORRECT

#pragma tabsize 4

// Limits
#if !defined MAX_PLAYER_ATTACHED_OBJECTS
	#define MAX_PLAYER_ATTACHED_OBJECTS        (10)
#endif

#if !defined MAX_CHATBUBBLE_LENGTH
	#define MAX_CHATBUBBLE_LENGTH              (144)
#endif

#define SPECIAL_ACTION: __TAG(SPECIAL_ACTION):
enum SPECIAL_ACTION:
{
	SPECIAL_ACTION_NONE,
	SPECIAL_ACTION_DUCK,
	SPECIAL_ACTION_USEJETPACK,
	SPECIAL_ACTION_ENTER_VEHICLE,
	SPECIAL_ACTION_EXIT_VEHICLE,
	SPECIAL_ACTION_DANCE1,
	SPECIAL_ACTION_DANCE2,
	SPECIAL_ACTION_DANCE3,
	SPECIAL_ACTION_DANCE4,
	SPECIAL_ACTION_HANDSUP                     = 10,
	SPECIAL_ACTION_USECELLPHONE,
	SPECIAL_ACTION_SITTING,
	SPECIAL_ACTION_STOPUSECELLPHONE,
	SPECIAL_ACTION_DRINK_BEER                  = 20,
	SPECIAL_ACTION_SMOKE_CIGGY,
	SPECIAL_ACTION_DRINK_WINE,
	SPECIAL_ACTION_DRINK_SPRUNK,
	SPECIAL_ACTION_CUFFED,
	SPECIAL_ACTION_CARRY,
	SPECIAL_ACTION_PISSING                     = 68
}

#define FIGHT_STYLE: __TAG(FIGHT_STYLE):
enum FIGHT_STYLE:
{
	FIGHT_STYLE_NORMAL                         = 4,
	FIGHT_STYLE_BOXING,
	FIGHT_STYLE_KUNGFU,
	FIGHT_STYLE_KNEEHEAD,
	FIGHT_STYLE_GRABKICK                       = 15,
	FIGHT_STYLE_ELBOW
}

#define WEAPONSKILL: __TAG(WEAPONSKILL):
enum WEAPONSKILL:
{
	WEAPONSKILL_PISTOL,
	WEAPONSKILL_PISTOL_SILENCED,
	WEAPONSKILL_DESERT_EAGLE,
	WEAPONSKILL_SHOTGUN,
	WEAPONSKILL_SAWNOFF_SHOTGUN,
	WEAPONSKILL_SPAS12_SHOTGUN,
	WEAPONSKILL_MICRO_UZI,
	WEAPONSKILL_MP5,
	WEAPONSKILL_AK47,
	WEAPONSKILL_M4,
	WEAPONSKILL_SNIPERRIFLE,
}

#define WEAPONSTATE: __TAG(WEAPONSTATE):
enum WEAPONSTATE:
{
	WEAPONSTATE_UNKNOWN                        = -1,
	WEAPONSTATE_NO_BULLETS,
	WEAPONSTATE_LAST_BULLET,
	WEAPONSTATE_MORE_BULLETS,
	WEAPONSTATE_RELOADING
}

// PVar enumeration
#define PLAYER_VARTYPE: __TAG(PLAYER_VARTYPE):
enum PLAYER_VARTYPE:
{
	PLAYER_VARTYPE_NONE,
	PLAYER_VARTYPE_INT,
	PLAYER_VARTYPE_STRING,
	PLAYER_VARTYPE_FLOAT
}

#define MAPICON: __TAG(MAPICON):
enum MAPICON:
{
	MAPICON_LOCAL,                             // Displays in the player's local area
	MAPICON_GLOBAL,                            // Displays always
	MAPICON_LOCAL_CHECKPOINT,                  // Displays in the player's local area and has a checkpoint marker
	MAPICON_GLOBAL_CHECKPOINT                  // Displays always and has a checkpoint marker
}

#define CAMERA: __TAG(CAMERA):
enum CAMERA:
{
	CAMERA_MOVE                                = 1,
	CAMERA_CUT
}

// Spectating
#define SPECTATE_MODE: __TAG(SPECTATE_MODE):
enum SPECTATE_MODE:
{
	SPECTATE_MODE_NORMAL                       = 1,
	SPECTATE_MODE_FIXED,
	SPECTATE_MODE_SIDE
}

// Recording for NPC playback
#define PLAYER_RECORDING_TYPE: __TAG(PLAYER_RECORDING_TYPE):
enum PLAYER_RECORDING_TYPE:
{
	PLAYER_RECORDING_TYPE_NONE,
	PLAYER_RECORDING_TYPE_DRIVER,
	PLAYER_RECORDING_TYPE_ONFOOT
}

// Player

/// <summary>This function can be used to change the spawn information of a specific player. It allows you to automatically set someone's spawn weapons, their team, skin and spawn position, normally used in case of minigames or automatic-spawn systems. This function is more crash-safe then using <a href="#SetPlayerSkin">SetPlayerSkin</a> in <a href="#OnPlayerSpawn">OnPlayerSpawn</a> and/or <a href="#OnPlayerRequestClass">OnPlayerRequestClass</a>, even though this has been fixed in 0.2.</summary>
/// <param name="playerid">The Playerid of who you want to set the spawn information</param>
/// <param name="team">The Team-ID of the chosen player</param>
/// <param name="skin">The skin which the player will spawn with</param>
/// <param name="x">The x-coordinate of the player's spawn position</param>
/// <param name="y">The y-coordinate of the player's spawn position</param>
/// <param name="z">The z-coordinate of the player's spawn position</param>
/// <param name="rotation">The direction in which the player needs to be facing after spawning</param>
/// <param name="weapon1">The first spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="ammo1">The amount of ammunition for the primary spawnweapon</param>
/// <param name="weapon2">The second spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="ammo2">The amount of ammunition for the second spawnweapon</param>
/// <param name="weapon3">The third spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="ammo3">The amount of ammunition for the third spawnweapon</param>
/// <seealso name="SetPlayerSkin" />
/// <seealso name="SetPlayerTeam" />
/// <seealso name="SpawnPlayer" />
native SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, ammo1, weapon2, ammo2, weapon3, ammo3);

/// <summary>(Re)Spawns a player.</summary>
/// <param name="playerid">The ID of the player to spawn</param>
/// <seealso name="SetSpawnInfo" />
/// <seealso name="AddPlayerClass" />
/// <seealso name="OnPlayerSpawn" />
/// <remarks>Kills the player if they are in a vehicle and then they spawn with a bottle in their hand.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native SpawnPlayer(playerid);

// Player info

/// <summary>Set a player's position.</summary>
/// <param name="playerid">The ID of the player to set the position of</param>
/// <param name="x">The x coordinate to position the player at</param>
/// <param name="y">The y coordinate to position the player at</param>
/// <param name="z">The z coordinate to position the player at</param>
/// <seealso name="SetPlayerPosFindZ" />
/// <seealso name="SetPlayerFacingAngle" />
/// <seealso name="GetPlayerPos" />
/// <seealso name="SetVehiclePos" />
/// <seealso name="GetVehiclePos" />
/// <remarks>Using this function on a player in a vehicle will instantly remove them from the vehicle. Useful for quickly ejecting players.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native SetPlayerPos(playerid, Float:x, Float:y, Float:z);

/// <summary>This sets the players position then adjusts the players z-coordinate to the nearest solid ground under the position.</summary>
/// <param name="playerid">The ID of the player to set the position of</param>
/// <param name="x">The x coordinate to position the player at</param>
/// <param name="y">The x coordinate to position the player at</param>
/// <param name="z">The z coordinate to position the player at</param>
/// <seealso name="SetPlayerPos" />
/// <seealso name="OnPlayerClickMap" />
/// <remarks>This function does not work if the new coordinates are far away from where the player currently is. The z height will be <b><c>0</c></b>, which will likely put them underground. It is highly recommended that the <a href="http://forum.sa-mp.com/showthread.php?t=275492">MapAndreas plugin</a> be used instead.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z);

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

/// <summary>Set a player's facing angle (z rotation).</summary>
/// <param name="playerid">The ID of the player to set the facing angle of</param>
/// <param name="ang">The angle the player should face</param>
/// <seealso name="GetPlayerFacingAngle" />
/// <seealso name="SetPlayerPos" />
/// <remarks>Angles are reversed in GTA:SA; 90 degrees would be East in the real world, but in GTA:SA 90 degrees is in fact West. North and South are still 0/360 and 180. To convert this, simply do <b>360 - angle</b>.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native SetPlayerFacingAngle(playerid, Float:ang);

/// <summary>Gets the angle a player is facing.</summary>
/// <param name="playerid">The player you want to get the angle of</param>
/// <param name="ang">The Float to store the angle in, passed by reference</param>
/// <seealso name="GetVehicleZAngle" />
/// <seealso name="SetPlayerFacingAngle" />
/// <remarks>Angles are reversed in GTA:SA; 90 degrees would be East in the real world, but in GTA:SA 90 degrees is in fact West. North and South are still 0/360 and 180. To convert this, simply do <b>360 - angle</b>.</remarks>
/// <remarks>Angles returned when inside a vehicle is rarely correct. To get the correct facing angle while inside a vehicle, use <a href="#GetVehicleZAngle">GetVehicleZAngle</a>.</remarks>
native GetPlayerFacingAngle(playerid, &Float:ang);

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

/// <summary>Calculate the distance between a player and a map coordinate.</summary>
/// <param name="playerid">The ID of the player to calculate the distance from</param>
/// <param name="x">The x map coordinate</param>
/// <param name="y">The y map coordinate</param>
/// <param name="z">The z map coordinate</param>
/// <seealso name="IsPlayerInRangeOfPoint" />
/// <seealso name="GetVehicleDistanceFromPoint" />
/// <seealso name="GetPlayerPos" />
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns>The distance between the player and the point as a float.</returns>
native Float:GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z);

/// <summary>Checks if a player is streamed in another player's client.</summary>
/// <param name="targetid">The ID of the player to check is streamed in</param>
/// <param name="playerid">The ID of the player to check if playerid is streamed in for</param>
/// <seealso name="IsActorStreamedIn" />
/// <seealso name="IsVehicleStreamedIn" />
/// <seealso name="OnPlayerStreamIn" />
/// <seealso name="OnPlayerStreamOut" />
/// <seealso name="OnVehicleStreamIn" />
/// <seealso name="OnVehicleStreamOut" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>Players aren't streamed in on their own client, so if playerid is the same as targetid it will return false!</remarks>
/// <remarks>Players stream out if they are more than <b><c>150</c></b> meters away (see <c>server.cfg</c> - <c>stream_distance</c>)</remarks>
/// <returns><b><c>1</c></b> if the player is streamed in, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerStreamedIn(targetid, playerid);

/// <summary>Set a player's interior. A list of currently known interiors and their positions can be found <a href="http://wiki.sa-mp.com/wiki/Interiorids">here</a>.</summary>
/// <param name="playerid">The ID of the player to set the interior of</param>
/// <param name="interiorid">The <a href="http://wiki.sa-mp.com/wiki/Interiorids">interior ID</a> to set the player in</param>
/// <seealso name="GetPlayerInterior" />
/// <seealso name="LinkVehicleToInterior" />
/// <seealso name="OnPlayerInteriorChange" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native SetPlayerInterior(playerid, interiorid);

/// <summary>Retrieves the player's current interior. A list of currently known interiors with their positions can be found on <a href="http://wiki.sa-mp.com/wiki/Interiorids">this</a> page.</summary>
/// <param name="playerid">The player to get the interior ID of</param>
/// <seealso name="SetPlayerInterior" />
/// <seealso name="GetPlayerVirtualWorld" />
/// <remarks>Always returns <b><c>0</c></b> for NPCs.</remarks>
/// <returns>The interior ID the player is currently in.</returns>
native GetPlayerInterior(playerid);

/// <summary>Set the health of a player.</summary>
/// <param name="playerid">The ID of the player to set the health of</param>
/// <param name="health">The value to set the player's health to. Max health that can be displayed in the HUD is <b><c>100</c></b>, though higher values are valid</param>
/// <seealso name="GetPlayerHealth" />
/// <seealso name="GetPlayerArmour" />
/// <seealso name="SetPlayerArmour" />
/// <remarks>Health is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b></remarks>
/// <remarks>If a player's health is set to <b><c>0</c></b> or a minus value, they will die instantly.</remarks>
/// <remarks>If a player's health is below <b><c>10</c></b> or above <b><c>98303</c></b>, their health bar will flash. </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native SetPlayerHealth(playerid, Float:health);

/// <summary>The function GetPlayerHealth allows you to retrieve the health of a player. Useful for cheat detection, among other things.</summary>
/// <param name="playerid">The ID of the player</param>
/// <param name="health">Float to store health, passed by reference</param>
/// <seealso name="SetPlayerHealth" />
/// <seealso name="GetVehicleHealth" />
/// <seealso name="GetPlayerArmour" />
/// <remarks>
///   Even though the health can be set to near infinite values on the server side, the individual clients will only report values up to <b><c>255</c></b>. Anything higher will wrap around; <b><c>256</c></b> becomes <b><c>0</c></b>, <b><c>257</c></b> becomes <b><c>1</c></b>, etc.<br />
///   Health is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b>
/// </remarks>
/// <returns>
///   <b><c>1</c></b> - success.<br />
///   <b><c>0</c></b> - failure (i.e. player not connected).<br />
/// </returns>
native GetPlayerHealth(playerid, &Float:health);

/// <summary>Set a player's armor level.</summary>
/// <param name="playerid">The ID of the player to set the armour of</param>
/// <param name="armour">The amount of armour to set, as a percentage (float). Values larger than <b><c>100</c></b> are valid, but won't be displayed in the HUD's armour bar</param>
/// <seealso name="GetPlayerArmour" />
/// <seealso name="SetPlayerHealth" />
/// <seealso name="GetPlayerHealth" />
/// <remarks>Armour is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b></remarks>
/// <remarks>The function's name is armour, not armor (Americanized). This is inconsistent with the rest of SA-MP, so remember that.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native SetPlayerArmour(playerid, Float:armour);

/// <summary>This function stores the armour of a player into a variable.</summary>
/// <param name="playerid">The ID of the player that you want to get the armour of</param>
/// <param name="armour">The float to to store the armour in, passed by reference</param>
/// <seealso name="SetPlayerArmour" />
/// <seealso name="GetPlayerHealth" />
/// <seealso name="GetVehicleHealth" />
/// <remarks>Even though the armour can be set to near infinite values on the server side, the individual clients will only report values up to <b><c>255</c></b>. Anything higher will wrap around; <b><c>256</c></b> becomes <b><c>0</c></b>, <b><c>257</c></b> becomes <b><c>1</c></b>, etc. </remarks>
/// <remarks>Armour is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b> </remarks>
/// <remarks>The function's name is armour, not armor (Americanized). This is inconsistent with the rest of SA-MP, so remember that.</remarks>
/// <returns>
///   <b><c>1</c></b> - success.<br />
///   <b><c>0</c></b> - failure (i.e. player not connected).<br />
/// </returns>
native GetPlayerArmour(playerid, &Float:armour);

/// <summary>Set the ammo of a player's weapon.</summary>
/// <param name="playerid">The ID of the player to set the weapon ammo of</param>
/// <param name="weaponslot">The ID of the <a href="http://wiki.sa-mp.com/wiki/Weapons">weapon slot</a> to set the ammo of.</param>
/// <param name="ammo">The amount of ammo to set</param>
/// <seealso name="GetPlayerAmmo" />
/// <seealso name="GivePlayerWeapon" />
/// <seealso name="SetPlayerArmedWeapon" />
/// <remarks>Set the ammo to <b><c>0</c></b> to remove a weapon from a player's inventory. Note that the weapon will still show up in <a href="#GetPlayerWeaponData">GetPlayerWeaponData</a>, albeit with <b><c>0</c></b> ammo.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is also returned when the weapon slot specified is invalid (not 0-12).<br />
///   <b><c>0</c></b>: The function failed to execute. The player isn't connected.<br />
/// </returns>
native SetPlayerAmmo(playerid, weaponslot, ammo);

/// <summary>Gets the amount of ammo in a player's current weapon.</summary>
/// <param name="playerid">The ID of the player whose ammo to get</param>
/// <seealso name="SetPlayerAmmo" />
/// <seealso name="GetPlayerWeaponData" />
/// <remarks>The ammo can hold 16-bit values, therefore values over <b><c>32767</c></b> will return erroneous values.</remarks>
/// <returns>The amount of ammo in the player's current weapon.</returns>
native GetPlayerAmmo(playerid);

/// <summary>Check the state of a player's weapon.</summary>
/// <param name="playerid">The ID of the player to obtain the weapon state of</param>
/// <seealso name="GivePlayerWeapon" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Weapon states:</b><br />
///   <ul>
///     <li><b><c>WEAPONSTATE_UNKNOWN</c></b> - unknown (Set when in a vehicle)</li>
///     <li><b><c>WEAPONSTATE_NO_BULLETS</c></b> - The weapon has no remaining ammo</li>
///     <li><b><c>WEAPONSTATE_LAST_BULLET</c></b> - the weapon has one remaining bullet</li>
///     <li><b><c>WEAPONSTATE_MORE_BULLETS</c></b> - the weapon has multiple bullets</li>
///     <li><b><c>WEAPONSTATE_RELOADING</c></b> - the player is reloading their weapon </li>
///   </ul>
/// </remarks>
/// <returns>The state of the player's weapon. <b><c>0</c></b> if player specified does not exist.</returns>
native WEAPONSTATE:GetPlayerWeaponState(playerid);

/// <summary>Check who a player is aiming at.</summary>
/// <param name="playerid">The ID of the player to get the target of</param>
/// <seealso name="GetPlayerCameraFrontVector" />
/// <seealso name="OnPlayerGiveDamage" />
/// <seealso name="OnPlayerTakeDamage" />
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions! </remarks>
/// <remarks>Does not work for joypads/controllers, and after a certain distance. </remarks>
/// <remarks>Does not work for the sniper rifle, as it doesn't lock on to anything and as such can't and won't return a player. </remarks>
/// <returns>The ID of the target player, or <b><c>INVALID_PLAYER_ID</c></b> if none.</returns>
native GetPlayerTargetPlayer(playerid);

/// <summary>Gets ID of an actor which is aimed by certain player.</summary>
/// <param name="playerid">The ID of the player to get the target of</param>
/// <seealso name="GetPlayerCameraTargetActor" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <seealso name="OnPlayerGiveDamageActor" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>Does not work for joypads/controllers, and after a certain distance. </remarks>
/// <remarks>Does not work for the sniper rifle, as it doesn't lock on to anything and as such can't and won't return a player. </remarks>
/// <returns>The ID of the targeted actor, or <b><c>INVALID_ACTOR_ID</c></b> if none.</returns>
native GetPlayerTargetActor(playerid);

/// <summary>Set the team of a player.</summary>
/// <param name="playerid">The ID of the player you want to set the team of</param>
/// <param name="teamid">The team to put the player in. Use <b><c>NO_TEAM</c></b> to remove the player from any team</param>
/// <seealso name="GetPlayerTeam" />
/// <seealso name="SetTeamCount" />
/// <seealso name="EnableVehicleFriendlyFire" />
/// <remarks>Players can not damage/kill players on the same team unless they use a knife to slit their throat. As of <b>SA-MP 0.3x</b>, players are also unable to damage vehicles driven by a player from the same team. This can be enabled with <a href="#EnableVehicleFriendlyFire">EnableVehicleFriendlyFire</a>.</remarks>
/// <remarks><b><c>255</c></b> (or <b><c>NO_TEAM</c></b>) is the default team to be able to shoot other players, not <b><c>0</c></b>.</remarks>
native SetPlayerTeam(playerid, teamid);

/// <summary>Get the ID of the team the player is on.</summary>
/// <param name="playerid">The ID of the player to get the team of</param>
/// <seealso name="SetPlayerTeam" />
/// <seealso name="SetTeamCount" />
/// <returns>
///   <b><c>0-254</c></b>: The player's team. (<b><c>0</c></b> is a valid team).<br />
///   <b><c>255</c></b>: Defined as <b><c>NO_TEAM</c></b>. The player is not on any team.<br />
///   <b><c>-1</c></b>: The function failed to execute. Player is not connected.
/// </returns>
native GetPlayerTeam(playerid);

/// <summary>Set a player's score. Players' scores are shown in the scoreboard (shown by holding the TAB key).</summary>
/// <param name="playerid">The ID of the player to set the score of</param>
/// <param name="score">The value to set the player's score to</param>
/// <seealso name="GetPlayerScore" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native SetPlayerScore(playerid, score);

/// <summary>This function returns a player's score as it was set using <a href="#SetPlayerScore">SetPlayerScore</a>.</summary>
/// <param name="playerid">The player to get the score of</param>
/// <seealso name="SetPlayerScore" />
/// <seealso name="GetPlayerPing" />
/// <returns>The player's score.</returns>
native GetPlayerScore(playerid);

/// <summary>
///   Checks the player's level of drunkenness. If the level is less than <b><c>2000</c></b>, the player is sober. The player's level of drunkness goes down slowly automatically (1 level per frame) but will always reach <b><c>2000</c></b> at the end (in <b>0.3b</b> it will stop at <b><c>0</c></b>).
///   The higher drunkenness levels affect the player's camera, and the car driving handling. The level of drunkenness increases when the player drinks from a bottle (You can use <a href="#SetPlayerSpecialAction">SetPlayerSpecialAction</a> to give them bottles).
/// </summary>
/// <param name="playerid">The player you want to check the drunkenness level of</param>
/// <seealso name="SetPlayerDrunkLevel" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>An integer with the level of drunkenness of the player.</returns>
native GetPlayerDrunkLevel(playerid);

/// <summary>Sets the drunk level of a player which makes the player's camera sway and vehicles hard to control.</summary>
/// <param name="playerid">The ID of the player to set the drunkenness of</param>
/// <param name="level">The level of drunkenness to set</param>
/// <seealso name="GetPlayerDrunkLevel" />
/// <remarks>
///   Players' drunk level will automatically decrease over time, based on their FPS (players with <b><c>50</c></b> FPS will lose <b><c>50</c></b> 'levels' per second. This is useful for determining a player's FPS!).<br />
///   In <b>0.3a</b> the drunk level will decrement and stop at <b><c>2000</c></b>. In <b>0.3b+</b> the drunk level decrements to <b><c>0</c></b>)<br />
///   Levels over <b><c>2000</c></b> make the player drunk (camera swaying and vehicles difficult to control).<br />
///   Max drunk level is <b><c>50000</c></b>.<br />
///   While the drunk level is above <b><c>5000</c></b>, the player's HUD (radar etc.) will be hidden.
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native SetPlayerDrunkLevel(playerid, level);

/// <summary>Set the colour of a player's nametag and marker (radar blip).</summary>
/// <param name="playerid">The ID of the player whose colour to set</param>
/// <param name="colour">The colour to set. Supports alpha values (<b>RGBA</b>)</param>
/// <seealso name="SetPlayerMarkerForPlayer" />
/// <seealso name="GetPlayerColor" />
/// <seealso name="ChangeVehicleColor" />
/// <remarks>This function will change player's colour for everyone, even if player's colour was changed with <a href="#SetPlayerMarkerForPlayer">SetPlayerMarkerForPlayer</a> for any other player. </remarks>
/// <remarks>If used under <a href="#OnPlayerConnect">OnPlayerConnect</a>, the affecting player will not see the colour in the TAB menu. </remarks>
native SetPlayerColor(playerid, colour);

/// <summary>Gets the colour of the player's name and radar marker. Only works after <a href="#SetPlayerColor">SetPlayerColor</a>.</summary>
/// <param name="playerid">The ID of the player to get the colour of</param>
/// <seealso name="SetPlayerColor" />
/// <seealso name="ChangeVehicleColor" />
/// <remarks>GetPlayerColor will return <b><c>0</c></b> unless <a href="#SetPlayerColor">SetPlayerColor</a> has been used first.</remarks>
/// <returns>The player's colour. <b><c>0</c></b> if no colour set or player not connected.</returns>
native GetPlayerColor(playerid);

/// <summary>Set the skin of a player. A player's skin is their character model.</summary>
/// <param name="playerid">The ID of the player to set the skin of</param>
/// <param name="skinid">The <a href="http://wiki.sa-mp.com/wiki/Skins">skin</a> the player should use</param>
/// <seealso name="GetPlayerSkin" />
/// <seealso name="SetSpawnInfo" />
/// <remarks>If a player's skin is set when they are crouching, in a vehicle, or performing certain animations, they will become frozen or otherwise glitched. This can be fixed by using <a href="#TogglePlayerControllable">TogglePlayerControllable</a>. Players can be detected as being crouched through <a href="#GetPlayerSpecialAction">GetPlayerSpecialAction</a> (<b><c>SPECIAL_ACTION_DUCK</c></b>).</remarks>
/// <remarks>Setting a player's skin when he is dead may crash players around him.</remarks>
/// <remarks>Note that 'success' is reported even when skin ID is invalid (not <b><c>0</c></b>-<b><c>311</c></b>, or <b><c>74</c></b>), but the skin will be set to ID <b><c>0</c></b> (CJ).</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.<br />
/// </returns>
native SetPlayerSkin(playerid, skinid);

/// <summary>Returns the class of the players skin.</summary>
/// <param name="playerid">The player you want to get the skin from</param>
/// <seealso name="SetPlayerSkin" />
/// <remarks>Returns the new skin after <a href="#SetSpawnInfo">SetSpawnInfo</a> is called but before the player actually respawns to get the new skin. </remarks>
/// <remarks>Returns the old skin if the player was spawned through <a href="#SpawnPlayer">SpawnPlayer</a> function. </remarks>
/// <returns>The skin ID (<b><c>0</c></b> if invalid).</returns>
native GetPlayerSkin(playerid);

/// <summary>Returns the class of the players skin.</summary>
/// <param name="playerid">The player you want to get the skin from</param>
/// <seealso name="SetPlayerSkin" />
/// <remarks>Returns the new skin after <a href="#SetSpawnInfo">SetSpawnInfo</a> is called but before the player actually respawns to get the new skin. </remarks>
/// <remarks>Returns the old skin if the player was spawned through <a href="#SpawnPlayer">SpawnPlayer</a> function. </remarks>
/// <returns>The skin id (<b><c>0</c></b> if invalid).</returns>
native GetPlayerCustomSkin(playerid);

/// <summary>Give a player a weapon with a specified amount of ammo.</summary>
/// <param name="playerid">The ID of the player to give a weapon to</param>
/// <param name="weaponid">The ID of the weapon to give to the player</param>
/// <param name="ammo">The amount of ammo to give to the player</param>
/// <seealso name="SetPlayerArmedWeapon" />
/// <seealso name="GetPlayerWeapon" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.<br />
/// </returns>
native GivePlayerWeapon(playerid, weaponid, ammo);

/// <summary>Removes all weapons from a player.</summary>
/// <param name="playerid">The ID of the player whose weapons to remove</param>
/// <seealso name="GivePlayerWeapon" />
/// <seealso name="GetPlayerWeapon" />
/// <remarks>To remove individual weapons from a player, set their ammo to <b><c>0</c></b> using <a href="#SetPlayerAmmo">SetPlayerAmmo</a>.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native ResetPlayerWeapons(playerid);

/// <summary>Sets which weapon (that a player already has) the player is holding.</summary>
/// <param name="playerid">The ID of the player to arm with a weapon</param>
/// <param name="weaponid">The ID of the weapon that the player should be armed with</param>
/// <seealso name="GivePlayerWeapon" />
/// <seealso name="GetPlayerWeapon" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>This function arms a player with a weapon they <b>already have</b>; it does not give them a new weapon. See <a href="#GivePlayerWeapon">GivePlayerWeapon</a>.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is returned even when the function fails to execute (the player doesn't have the weapon specified, or it is an invalid weapon).<br />
///   <b><c>0</c></b>: The function failed to execute. The player is not connected.
/// </returns>
native SetPlayerArmedWeapon(playerid, weaponid);

/// <summary>Get the weapon and ammo in a specific player's weapon slot (e.g. the weapon in the 'SMG' slot).</summary>
/// <param name="playerid">The ID of the player whose weapon data to retrieve</param>
/// <param name="slot">The weapon slot to get data for (<b><c>0-12</c></b>)</param>
/// <param name="weapons">A variable in which to store the weapon ID, passed by reference</param>
/// <param name="ammo">A variable in which to store the ammo, passed by reference</param>
/// <seealso name="GetPlayerWeapon" />
/// <seealso name="GivePlayerWeapon" />
/// <remarks>Old weapons with no ammo left are still returned.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player isn't connected and/or the weapon slot specified is invalid (valid is <b><c>0-12</c></b>).
/// </returns>
native GetPlayerWeaponData(playerid, slot, &weapons, &ammo);

/// <summary>Give money to or take money from a player.</summary>
/// <param name="playerid">The ID of the player to give money to or take money from</param>
/// <param name="money">The amount of money to give the player. Use a minus value to take money</param>
/// <seealso name="ResetPlayerMoney" />
/// <seealso name="GetPlayerMoney" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native GivePlayerMoney(playerid, money);

/// <summary>Reset a player's money to $0.</summary>
/// <param name="playerid">The ID of the player to reset the money of</param>
/// <seealso name="GetPlayerMoney" />
/// <seealso name="GivePlayerMoney" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native ResetPlayerMoney(playerid);

/// <summary>Sets the name of a player.</summary>
/// <param name="playerid">The ID of the player to set the name of</param>
/// <param name="name">The name to set. Must be 1-24 characters long and only contain valid characters (<b>0-9</b>, <b>a-z</b>, <b>A-z</b>, <b>[]</b>, <b>()</b>, <b>$</b>, <b>@</b>, <b>.</b>, <b>_</b>, <b>=</b>)</param>
/// <seealso name="GetPlayerName" />
/// <remarks>Changing the players' name to the same name but with different character cases (e.g. "John" to "JOHN") will not work. </remarks>
/// <remarks>If used in <a href="#OnPlayerConnect">OnPlayerConnect</a>, the new name will <b>not</b> be shown for the connecting player. </remarks>
/// <remarks>Passing a null string as the new name will crash the server. </remarks>
/// <remarks>Player names can be up to 24 characters when using this function, but when joining the server from the SA-MP server browser, players' names must be no more than 20 and less than 3 characters (the server will deny entry). This allows for 4 characters extra when using <a href="#SetPlayerName">SetPlayerName</a>. </remarks>
/// <returns>
///   <b><c>1</c></b> The name was changed successfully.<br />
///   <b><c>0</c></b> The player already has that name.<br />
///   <b><c>-1</c></b> The name can not be changed (it's already in use, too long or has invalid characters).
/// </returns>
native SetPlayerName(playerid, const name[]);

/// <summary>Retrieves the amount of money a player has.</summary>
/// <param name="playerid">The ID of the player to get the money of</param>
/// <seealso name="GivePlayerMoney" />
/// <seealso name="ResetPlayerMoney" />
/// <returns>The amount of money the player has.</returns>
native GetPlayerMoney(playerid);

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
native PLAYER_STATE:GetPlayerState(playerid);

/// <summary>Get the specified player's IP address and store it in a string.</summary>
/// <param name="playerid">The ID of the player to get the IP address of</param>
/// <param name="ip">An array into which to store the player's IP address, passed by reference</param>
/// <param name="len">The maximum length of the IP address (recommended 16)</param>
/// <seealso name="NetStats_GetIpPort" />
/// <seealso name="GetPlayerName" />
/// <seealso name="GetPlayerPing" />
/// <seealso name="GetPlayerVersion" />
/// <seealso name="OnIncomingConnection" />
/// <seealso name="OnPlayerConnect" />
/// <seealso name="OnPlayerDisconnect" />
/// <remarks>This function does not work when used in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a> because the player is already disconnected. It will return an invalid IP (<b><c>255.255.255.255</c></b>). Save players' IPs under <a href="#OnPlayerConnect">OnPlayerConnect</a> if they need to be used under <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>. </remarks>
/// <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure.</returns>
native GetPlayerIp(playerid, ip[], len = sizeof (ip));

/// <summary>Get the ping of a player. The ping measures the amount of time it takes for the server to 'ping' the client and for the client to send the message back.</summary>
/// <param name="playerid">The ID of the player to get the ping of</param>
/// <seealso name="GetPlayerIp" />
/// <seealso name="GetPlayerName" />
/// <seealso name="GetPlayerVersion" />
/// <remarks>Player's ping may be <b><c>65535</c></b> for a while after a player connects</remarks>
/// <returns>The current ping of the player (expressed in milliseconds).</returns>
native GetPlayerPing(playerid);

/// <summary>Returns the ID of the weapon a player is currently holding.</summary>
/// <param name="playerid">The ID of the player to get the currently held weapon of</param>
/// <seealso name="GetPlayerWeaponData" />
/// <seealso name="GivePlayerWeapon" />
/// <seealso name="ResetPlayerWeapons" />
/// <remarks>Prior to version <b>0.3z R1-2</b>, when the player state is <b>PLAYER_STATE_PASSENGER</b> this function returns the weapon held by the player before they entered the vehicle. If a cheat is used to spawn a weapon inside a vehicle, this function will not report it.</remarks>
/// <returns>The ID of the player's current weapon. Returns <b><c>-1</c></b> if the player specified does not exist.</returns>
native GetPlayerWeapon(playerid);

/// <summary>Check which keys a player is pressing.</summary>
/// <param name="playerid">The ID of the player to get the keys of</param>
/// <param name="keys">Bitmask containing the player's key states. <a href="http://wiki.sa-mp.com/wiki/Keys">List of keys</a></param>
/// <param name="updown">Up/down state</param>
/// <param name="leftright">Left/right state</param>
/// <seealso name="OnPlayerKeyStateChange" />
/// <remarks>Only the FUNCTION of keys can be detected; not actual keys. For example, it is not possible to detect if a player presses <b>SPACE</b>, but you can detect if they press <b>SPRINT</b> (which can be mapped (assigned/binded) to ANY key (but is space by default)). </remarks>
/// <remarks>As of update <b>0.3.7</b>, the keys "A" and "D" are not recognized when in a vehicle. However, keys "W" and "S" can be detected with the "keys" parameter. </remarks>
/// <returns>The keys are stored in the specified variables.</returns>
native GetPlayerKeys(playerid, &KEY:keys, &KEY:updown, &KEY:leftright);

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

/// <summary>Sets the game time for a player. If a player's clock is enabled (<a href="#TogglePlayerClock">TogglePlayerClock</a>) the time displayed by it will update automatically.</summary>
/// <param name="playerid">The ID of the player to set the game time of</param>
/// <param name="hour">Hour to set (0-23)</param>
/// <param name="minute">Minutes to set (0-59)</param>
/// <seealso name="SetWorldTime" />
/// <seealso name="GetPlayerTime" />
/// <seealso name="TogglePlayerClock" />
/// <remarks>Using this function under <a href="#OnPlayerConnect">OnPlayerConnect</a> doesn't work.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native SetPlayerTime(playerid, hour, minute);

/// <summary>Get the player's current game time. Set by <a href="#SetWorldTime">SetWorldTime</a> or <a href="#SetPlayerTime">SetPlayerTime</a>, or by the game automatically if <a href="#TogglePlayerClock">TogglePlayerClock</a> is used.</summary>
/// <param name="playerid">The ID of the player to get the game time of</param>
/// <param name="hour">A variable in which to store the hour, passed by reference</param>
/// <param name="minute">A variable in which to store the minutes, passed by reference</param>
/// <seealso name="SetPlayerTime" />
/// <seealso name="SetWorldTime" />
/// <seealso name="TogglePlayerClock" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.<br />
/// </returns>
native GetPlayerTime(playerid, &hour, &minute);

/// <summary>Toggle the in-game clock (top-right corner) for a specific player. When this is enabled, time will progress at 1 minute per second. Weather will also interpolate (slowly change over time) when set using <a href="#SetWeather">SetWeather</a>/<a href="#SetPlayerWeather">SetPlayerWeather</a>.</summary>
/// <param name="playerid">The player whose clock you want to enable/disable</param>
/// <param name="toggle"><b><c>1</c></b> to show and <b><c>0</c></b> to hide. Hidden by default</param>
/// <remarks>Time is not synced with other players! Time can be synced using <a href="#SetPlayerTime">SetPlayerTime</a>.</remarks>
/// <remarks>Time will automatically advance 6 hours when the player dies.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The specified player does not exist.
/// </returns>
native TogglePlayerClock(playerid, bool:toggle);

/// <summary>Set a player's weather.</summary>
/// <param name="playerid">The ID of the player whose weather to set</param>
/// <param name="weather">The <a href="http://wiki.sa-mp.com/wiki/Weatherid">weather</a> to set</param>
/// <seealso name="SetWeather" />
/// <seealso name="SetGravity" />
/// <remarks>If <a href="#TogglePlayerClock">TogglePlayerClock</a> is enabled, weather will slowly change over time, instead of changing instantly.</remarks>
native SetPlayerWeather(playerid, weather);

/// <summary>Forces a player to go back to class selection.</summary>
/// <param name="playerid">The player to send back to class selection</param>
/// <seealso name="AddPlayerClass" />
/// <seealso name="SetPlayerSkin" />
/// <seealso name="GetPlayerSkin" />
/// <seealso name="OnPlayerRequestClass" />
/// <remarks>The player will not return to class selection until they re-spawn. This can be achieved with <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a>, as seen in the below example.</remarks>
native ForceClassSelection(playerid);

/// <summary>Set a player's wanted level (6 brown stars under HUD).</summary>
/// <param name="playerid">The ID of the player to set the wanted level of</param>
/// <param name="level">The wanted level to set for the player (0-6)</param>
/// <seealso name="GetPlayerWantedLevel" />
/// <seealso name="PlayCrimeReportForPlayer" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native SetPlayerWantedLevel(playerid, level);

/// <summary>Gets the wanted level of a player.</summary>
/// <param name="playerid">The ID of the player that you want to get the wanted level of</param>
/// <seealso name="SetPlayerWantedLevel" />
/// <seealso name="PlayCrimeReportForPlayer" />
/// <returns>The player's wanted level.</returns>
native GetPlayerWantedLevel(playerid);

/// <summary>Set a player's special fighting style. To use in-game, aim and press the 'secondary attack' key (<b>ENTER</b> by default).</summary>
/// <param name="playerid">The ID of player to set the fighting style of</param>
/// <param name="style">The fighting style that should be set</param>
/// <seealso name="GetPlayerFightingStyle" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>This does not affect normal fist attacks - only special/secondary attacks (aim + press 'secondary attack' key).</remarks>
/// <remarks>
///   <b>Fighting styles:</b><br />
///   <ul>
///     <li><b><c>FIGHT_STYLE_NORMAL</c></b></li>
///     <li><b><c>FIGHT_STYLE_BOXING</c></b></li>
///     <li><b><c>FIGHT_STYLE_KUNGFU</c></b></li>
///     <li><b><c>FIGHT_STYLE_KNEEHEAD</c></b></li>
///     <li><b><c>FIGHT_STYLE_GRABKICK</c></b></li>
///     <li><b><c>FIGHT_STYLE_ELBOW</c></b></li>
///   </ul>
/// </remarks>
native SetPlayerFightingStyle(playerid, FIGHT_STYLE:style);

/// <summary>Get the fighting style the player currently using.</summary>
/// <param name="playerid">The ID of the player to get the fighting style of</param>
/// <seealso name="SetPlayerFightingStyle" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Fighting styles:</b><br />
///   <ul>
///     <li><b><c>FIGHT_STYLE_NORMAL</c></b></li>
///     <li><b><c>FIGHT_STYLE_BOXING</c></b></li>
///     <li><b><c>FIGHT_STYLE_KUNGFU</c></b></li>
///     <li><b><c>FIGHT_STYLE_KNEEHEAD</c></b></li>
///     <li><b><c>FIGHT_STYLE_GRABKICK</c></b></li>
///     <li><b><c>FIGHT_STYLE_ELBOW</c></b></li>
///   </ul>
/// </remarks>
/// <returns>The ID of the fighting style of the player.</returns>
native FIGHT_STYLE:GetPlayerFightingStyle(playerid);

/// <summary>Set a player's velocity on the x, y and z axes.</summary>
/// <param name="playerid">The player to apply the speed to</param>
/// <param name="x">The velocity (speed) on the x axis</param>
/// <param name="y">The velocity (speed) on the y axis</param>
/// <param name="z">The velocity (speed) on the z axis</param>
/// <seealso name="GetPlayerVelocity" />
/// <seealso name="SetVehicleVelocity" />
/// <seealso name="GetVehicleVelocity" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native SetPlayerVelocity(playerid, Float:x, Float:y, Float:z);

/// <summary>Get the velocity (speed) of a player on the x, y and z axes.</summary>
/// <param name="playerid">The player to get the speed from</param>
/// <param name="x">A float variable in which to store the velocity on the x axis, passed by reference</param>
/// <param name="y">A float variable in which to store the velocity on the y axis, passed by reference</param>
/// <param name="z">A float variable in which to store the velocity on the z axis, passed by reference</param>
/// <seealso name="SetPlayerVelocity" />
/// <seealso name="SetVehicleVelocity" />
/// <seealso name="GetVehicleVelocity" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z);

/// <summary>This function plays a crime report for a player - just like in single-player when CJ commits a crime.</summary>
/// <param name="playerid">The ID of the player that will hear the crime report</param>
/// <param name="suspectid">The ID of the suspect player whom will be described in the crime report</param>
/// <param name="crime">The crime ID, which will be reported as a 10-code (i.e. 10-16 if 16 was passed as the crime)</param>
/// <seealso name="PlayerPlaySound" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Crime list:</b><br />
///   <ul>
///     <li><b><c>3</c></b> 10-71 Advise nature of fire (size, type, contents of building)</li>
///     <li><b><c>4</c></b> 10-47 Emergency road repairs needed</li>
///     <li><b><c>5</c></b> 10-81 Breatherlizer Report</li>
///     <li><b><c>6</c></b> 10-24 Assignment Completed</li>
///     <li><b><c>7</c></b> 10-21 Call () by phone</li>
///     <li><b><c>8</c></b> 10-21 Call () by phone</li>
///     <li><b><c>9</c></b> 10-21 Call () by phone</li>
///     <li><b><c>10</c></b> 10-17 Meet Complainant</li>
///     <li><b><c>11</c></b> 10-81 Breatherlizer Report</li>
///     <li><b><c>12</c></b> 10-91 Pick up prisoner/subject</li>
///     <li><b><c>13</c></b> 10-28 Vehicle registration information</li>
///     <li><b><c>14</c></b> 10-81 Breathalyzer</li>
///     <li><b><c>15</c></b> 10-28 Vehicle registration information</li>
///     <li><b><c>16</c></b> 10-91 Pick up prisoner/subject</li>
///     <li><b><c>17</c></b> 10-34 Riot</li>
///     <li><b><c>18</c></b> 10-37 (Investigate) suspicious vehicle</li>
///     <li><b><c>19</c></b> 10-81 Breathalyzer</li>
///     <li><b><c>21</c></b> 10-7 Out of service</li>
///     <li><b><c>22</c></b> 10-7 Out of service </li>
///   </ul>
/// </remarks>
native PlayCrimeReportForPlayer(playerid, suspectid, crime);

/// <summary>Play an 'audio stream' for a player. Normal audio files also work (e.g. MP3).</summary>
/// <param name="playerid">The ID of the player to play the audio for</param>
/// <param name="url">The url to play. Valid formats are mp3 and ogg/vorbis. A link to a .pls (playlist) file will play that playlist</param>
/// <param name="posX">The x position at which to play the audio. Has no effect unless usepos is set to 1 (optional=<b><c>0.0</c></b>)</param>
/// <param name="posY">The y position at which to play the audio. Has no effect unless usepos is set to 1 (optional=<b><c>0.0</c></b>)</param>
/// <param name="posZ">The z position at which to play the audio. Has no effect unless usepos is set to 1 (optional=<b><c>0.0</c></b>)</param>
/// <param name="distance">The distance over which the audio will be heard. Has no effect unless usepos is set to 1 (optional=<b><c>50.0</c></b>)</param>
/// <param name="usepos">Use the positions and distance specified. (optional=<b><c>0</c></b>)</param>
/// <seealso name="StopAudioStreamForPlayer" />
/// <seealso name="PlayerPlaySound" />
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native PlayAudioStreamForPlayer(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, bool:usepos = false);

/// <summary>Stops the current audio stream for a player.</summary>
/// <param name="playerid">The player you want to stop the audio stream for</param>
/// <seealso name="PlayAudioStreamForPlayer" />
/// <seealso name="PlayerPlaySound" />
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions!</remarks>
native StopAudioStreamForPlayer(playerid);

/// <summary>Loads or unloads an interior script for a player (for example the ammunation menu).</summary>
/// <param name="playerid">The ID of the player to load the interior script for</param>
/// <param name="shopname">The shop script to load. Leave blank ("") to unload scripts</param>
/// <seealso name="DisableInteriorEnterExits" />
/// <seealso name="SetPlayerInterior" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>This function does not support casino scripts.</remarks>
/// <remarks>
///   <b>Shop names:</b><br />
///   <ul>
///     <li><b><c>"FDPIZA"</c></b> Pizza Stack</li>
///     <li><b><c>"FDBURG"</c></b> Burger Shot</li>
///     <li><b><c>"FDCHICK"</c></b>Cluckin' Bell</li>
///     <li><b><c>"AMMUN1"</c></b> Ammunation 1</li>
///     <li><b><c>"AMMUN2"</c></b> Ammunation 2</li>
///     <li><b><c>"AMMUN3"</c></b> Ammunation 3</li>
///     <li><b><c>"AMMUN4"</c></b> Ammunation 4</li>
///     <li><b><c>"AMMUN5"</c></b> Ammunation 5</li>
///   </ul>
/// </remarks>
native SetPlayerShopName(playerid, const shopname[]);

/// <summary>Set the skill level of a certain weapon type for a player.</summary>
/// <param name="playerid">The ID of the player to set the weapon skill of</param>
/// <param name="skill">The weapon to set the skill of</param>
/// <param name="level">The skill level to set for that weapon, ranging from <b><c>0</c></b> to <b><c>999</c></b>. A level out of range will max it out</param>
/// <seealso name="SetPlayerArmedWeapon" />
/// <seealso name="GivePlayerWeapon" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Weapon skills:</b><br />
///   <ul>
///     <li><b><c>WEAPONSKILL_PISTOL(0)</c></b></li>
///     <li><b><c>WEAPONSKILL_PISTOL_SILENCED(1)</c></b></li>
///     <li><b><c>WEAPONSKILL_DESERT_EAGLE(2)</c></b></li>
///     <li><b><c>WEAPONSKILL_SHOTGUN(3)</c></b></li>
///     <li><b><c>WEAPONSKILL_SAWNOFF_SHOTGUN(4)</c></b></li>
///     <li><b><c>WEAPONSKILL_SPAS12_SHOTGUN(5)</c></b></li>
///     <li><b><c>WEAPONSKILL_MICRO_UZI(6)</c></b></li>
///     <li><b><c>WEAPONSKILL_MP5(7)</c></b></li>
///     <li><b><c>WEAPONSKILL_AK47(8)</c></b></li>
///     <li><b><c>WEAPONSKILL_M4(9)</c></b></li>
///     <li><b><c>WEAPONSKILL_SNIPERRIFLE(10)</c></b></li>
///   </ul>
/// </remarks>
native SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level);

/// <summary>Get the ID of the vehicle that the player is surfing (stuck to the roof of).</summary>
/// <param name="playerid">The ID of the player you want to know the surfing vehicle ID of</param>
/// <seealso name="GetPlayerVehicleid" />
/// <seealso name="GetPlayerVehicleSeat" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>The ID of the vehicle that the player is surfing. If they are not surfing a vehicle or the vehicle they are surfing has no driver, <b><c>INVALID_VEHICLE_ID</c></b>. If the player specified is not connected, <b><c>INVALID_VEHICLE_ID</c></b> also.</returns>
native GetPlayerSurfingVehicleID(playerid);

/// <summary>Returns the ID of the object the player is surfing on.</summary>
/// <param name="playerid">The ID of the player surfing the object</param>
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns>The ID of the <b>moving</b> object the player is surfing. If the player isn't surfing a <b>moving</b> object, it will return <b><c>INVALID_OBJECT_ID</c></b>.</returns>
native GetPlayerSurfingObjectID(playerid);

/// <summary>Removes a standard San Andreas model for a single player within a specified range.</summary>
/// <param name="playerid">The ID of the player to remove the objects for</param>
/// <param name="modelid">The model to remove</param>
/// <param name="centerX">The x coordinate around which the objects will be removed</param>
/// <param name="centerY">The y coordinate around which the objects will be removed</param>
/// <param name="centerZ">The z coordinate around which the objects will be removed</param>
/// <param name="radius">The radius around the specified point to remove objects with the specified model</param>
/// <seealso name="DestroyObject" />
/// <seealso name="DestroyPlayerObject" />
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions!</remarks>
/// <remarks>There appears to be a limit of around <b><c>1000</c></b> lines/objects. There is no workaround. </remarks>
/// <remarks>When removing the same object for a player, they will crash. Commonly, players crash when reconnecting to the server because the server removes buildings on <a href="#OnPlayerConnect">OnPlayerConnect</a>. </remarks>
/// <remarks>In <b>SA-MP 0.3.7</b> you can use <b><c>-1</c></b> for the modelid to remove all objects within the specified radius.</remarks>
native RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius);

/// <summary>Retrieves the start and end (hit) position of the last bullet a player fired.</summary>
/// <param name="playerid">The ID of the player to get the last bullet shot information of</param>
/// <param name="originX">A float variable in which to save the x coordinate of where the bullet originated from</param>
/// <param name="originY">A float variable in which to save the y coordinate of where the bullet originated from</param>
/// <param name="originZ">A float variable in which to save the z coordinate of where the bullet originated from</param>
/// <param name="hitPosX">A float variable in which to save the x coordinate of where the bullet hit</param>
/// <param name="hitPosY">A float variable in which to save the y coordinate of where the bullet hit</param>
/// <param name="hitPosZ">A float variable in which to save the z coordinate of where the bullet hit</param>
/// <seealso name="GetPlayerWeaponData" />
/// <seealso name="GetPlayerWeapon" />
/// <seealso name="VectorSize" />
/// <seealso name="OnPlayerWeaponShot" />
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <remarks>This function will only work when <a href="http://wiki.sa-mp.com/wiki/Lag_Compensation">lag compensation</a> is <b>enabled</b>. </remarks>
/// <remarks>If the player hit nothing, the hit positions will be <b><c>0</c></b>. This means you can't currently calculate how far a bullet travels through open air. </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.<br />
/// </returns>
native GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ);

// Attached to bone objects
#if MAX_PLAYER_ATTACHED_OBJECTS < 1 || MAX_PLAYER_ATTACHED_OBJECTS > 10
	#error MAX_PLAYER_ATTACHED_OBJECTS must be >= 1 and <= 10
#endif

/// <summary>Attach an object to a specific bone on a player.</summary>
/// <param name="playerid">The ID of the player to attach the object to</param>
/// <param name="index">The index (slot) to assign the object to (0-9 since 0.3d, 0-4 in previous versions)</param>
/// <param name="modelid">The <a href="http://wiki.sa-mp.com/wiki/Objects">model</a> to attach</param>
/// <param name="bone">The bone to attach the object to</param>
/// <param name="offsetX">x axis offset for the object position (optional=<b><c>0.0</c></b>)</param>
/// <param name="offsetY">y axis offset for the object position (optional=<b><c>0.0</c></b>)</param>
/// <param name="offsetZ">z axis offset for the object position (optional=<b><c>0.0</c></b>)</param>
/// <param name="rotX">x axis rotation of the object (optional=<b><c>0.0</c></b>)</param>
/// <param name="rotY">y axis rotation of the object (optional=<b><c>0.0</c></b>)</param>
/// <param name="rotZ">z axis rotation of the object (optional=<b><c>0.0</c></b>)</param>
/// <param name="scaleX">x axis scale of the object (optional=<b><c>1.0</c></b>)</param>
/// <param name="scaleY">y axis scale of the object (optional=<b><c>1.0</c></b>)</param>
/// <param name="scaleZ">z axis scale of the object (optional=<b><c>1.0</c></b>)</param>
/// <param name="materialColour1">The first object colour to set <b>ARGB</b> (optional=<b><c>0</c></b>)</param>
/// <param name="materialColour2">The second object colour to set <b>ARGB</b> (optional=<b><c>0</c></b>)</param>
/// <seealso name="RemovePlayerAttachedObject" />
/// <seealso name="IsPlayerAttachedObjectSlotUsed" />
/// <seealso name="EditAttachedObject" />
/// <remarks>This function was added in <b>SA-MP 0.3c</b> and will not work in earlier versions!</remarks>
/// <remarks>In version <b>0.3d</b> and onwards, <b><c>10</c></b> objects can be attached to a single player (index <b><c>0</c></b>-<b><c>9</c></b>). In earlier versions, the limit is <b><c>5</c></b> (index <b><c>0</c></b>-<b><c>4</c></b>).</remarks>
/// <remarks>This function is separate from the <a href="#CreateObject">CreateObject</a> / <a href="#CreatePlayerObject">CreatePlayerObject</a> pools.</remarks>
/// <remarks>
///   <b>Bone IDs:</b><br />
///   <ul>
///     <li><b><c>1</c></b> - spine</li>
///     <li><b><c>2</c></b> - head</li>
///     <li><b><c>3</c></b> - left upper arm</li>
///     <li><b><c>4</c></b> - right upper arm</li>
///     <li><b><c>5</c></b> - left hand</li>
///     <li><b><c>6</c></b> - right hand</li>
///     <li><b><c>7</c></b> - left thigh</li>
///     <li><b><c>8</c></b> - right thigh</li>
///     <li><b><c>9</c></b> - left foot</li>
///     <li><b><c>10</c></b> - right foot</li>
///     <li><b><c>11</c></b> - right calf</li>
///     <li><b><c>12</c></b> - left calf</li>
///     <li><b><c>13</c></b> - left forearm</li>
///     <li><b><c>14</c></b> - right forearm</li>
///     <li><b><c>15</c></b> - left clavicle (shoulder)</li>
///     <li><b><c>16</c></b> - right clavicle (shoulder)</li>
///     <li><b><c>17</c></b> - neck</li>
///     <li><b><c>18</c></b> - jaw </li>
///   </ul>
/// </remarks>
/// <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
native SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0);

/// <summary>Remove an attached object from a player.</summary>
/// <param name="playerid">The ID of the player to remove the object from</param>
/// <param name="index">The index of the object to remove (set with <a href="#SetPlayerAttachedObject">SetPlayerAttachedObject</a>)</param>
/// <seealso name="SetPlayerAttachedObject" />
/// <seealso name="IsPlayerAttachedObjectSlotUsed" />
/// <remarks>This function was added in <b>SA-MP 0.3c</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
native RemovePlayerAttachedObject(playerid, index);

/// <summary>Check if a player has an object attached in the specified index (slot).</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <param name="index">The index (slot) to check</param>
/// <seealso name="SetPlayerAttachedObject" />
/// <seealso name="RemovePlayerAttachedObject" />
/// <remarks>This function was added in <b>SA-MP 0.3c</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if used, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerAttachedObjectSlotUsed(playerid, index);

/// <summary>Enter edition mode for an attached object.</summary>
/// <param name="playerid">The ID of the player to enter in to edition mode</param>
/// <param name="index">The index (slot) of the attached object to edit</param>
/// <seealso name="SetPlayerAttachedObject" />
/// <seealso name="RemovePlayerAttachedObject" />
/// <seealso name="IsPlayerAttachedObjectSlotUsed" />
/// <seealso name="EditObject" />
/// <seealso name="EditPlayerObject" />
/// <seealso name="SelectObject" />
/// <seealso name="CancelEdit" />
/// <seealso name="OnPlayerEditAttachedObject" />
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b> in vehicle) and moving your mouse.</remarks>
/// <remarks>
///   There are 7 clickable buttons in edition mode.<br />
///   The three single icons that have x/y/z on them can be dragged to edit position/rotation/scale.<br />
///   The four buttons in a row are to select the edition mode and save edition: [Move] [Rotate] [Scale] [Save].<br />
///   Clicking save will call <a href="#OnPlayerEditAttachedObject">OnPlayerEditAttachedObject</a>.
/// </remarks>
/// <remarks>Players will be able to scale objects up to a very large or negative value size. Limits should be put in place using <a href="#OnPlayerEditAttachedObject">OnPlayerEditAttachedObject</a> to abort the edit.</remarks>
/// <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure.</returns>
native EditAttachedObject(playerid, index);

// Per-player TextDraws

/// <summary>Creates a textdraw for a single player. This can be used as a way around the <a href="#TextDrawCreate">global</a> text-draw limit.</summary>
/// <param name="playerid">The ID of the player to create the textdraw for</param>
/// <param name="x">x-Coordinate</param>
/// <param name="y">y-Coordinate</param>
/// <param name="text">The text in the textdraw</param>
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   If you choose values for y that are less than 1, the first text row will be invisible and only the shadow is visible.<br />
///   <paramref name="text" /> must <b>NOT</b> be empty or the server will crash! If you need a textdraw that shows nothing, use " " (a space) or _ (underscore)<br />
///   If the last character in the text is a space (" "), the text will all be blank.<br />
///   If part of the text is off-screen, the colour of the text will not show, only the shadow (if enabled) will. <br />
/// </remarks>
/// <remarks>
///   This applies ONLY to sa-mp versions before <b>0.3z</b>:<br /><br />
///   Maximum length of textdraw is <b><c>800</c></b> characters. Longer text will crash the client in older versions.<br />
///   If you use colour codes (such as <b><c>~R~ ~G~</c></b>) beyond 255th character the client will crash trying to display the textdraw. <br />
/// </remarks>
/// <remarks>Keyboard key mapping codes (such as <b><c>~k~~VEHICLE_ENTER_EXIT~</c></b> Doesn't work beyond 255th character. </remarks>
/// <remarks>
///   The x, y coordinate is the top left coordinate for the text draw area based on a <b><c>640x480</c></b> "canvas" (irrespective of screen resolution). If you plan on using <a href="#PlayerTextDrawAlignment">PlayerTextDrawAlignment</a> with alignment <b><c>3</c></b> (right), the x, y coordinate is the top right coordinate for the text draw.<br />
///   This function merely CREATES the textdraw, you must use <a href="#PlayerTextDrawShow">PlayerTextDrawShow</a> to show it to a player.<br />
///   It is recommended to use WHOLE numbers instead of decimal positions when creating player textdraws to ensure resolution friendly design. <br />
/// </remarks>
/// <remarks>Player-textdraws are automatically destroyed when a player disconnects.</remarks>
/// <returns>The ID of the created textdraw.</returns>
native PlayerText:CreatePlayerTextDraw(playerid, Float:x, Float:y, const text[]);

/// <summary>Destroy a player-textdraw.</summary>
/// <param name="playerid">The ID of the player who's player-textdraw to destroy</param>
/// <param name="text">The ID of the textdraw to destroy</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawDestroy(playerid, PlayerText:text);

/// <summary>Sets the width and height of the letters in a player-textdraw.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to set the letter size of</param>
/// <param name="text">The ID of the player-textdraw to change the letter size of</param>
/// <param name="width">Width of a char</param>
/// <param name="height">Height of a char</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>When using this function purely for the benefit of affecting the textdraw box, multiply 'y' by <b><c>0.135</c></b> to convert to <a href="#TextDrawTextSize">TextDrawTextSize</a>-like measurements</remarks>
/// <remarks>Fonts appear to look the best with an x to y ratio of <b><c>1</c></b> to <b><c>4</c></b> (e.g. if x is <b><c>0.5</c></b> then y should be <b><c>2</c></b>).</remarks>
native PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:width, Float:height);

/// <summary>Change the size of a player-textdraw (box if <a href="#PlayerTextDrawUseBox">PlayerTextDrawUseBox</a> is enabled and/or clickable area for use with <a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a>).</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to set the size of</param>
/// <param name="text">The ID of the player-textdraw to set the size of</param>
/// <param name="width">The size on the x axis (left/right) following the same 640x480 grid as <a href="#TextDrawCreate">TextDrawCreate</a></param>
/// <param name="height">The size on the y axis (up/down) following the same 640x480 grid as <a href="#TextDrawCreate">TextDrawCreate</a></param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   The x and y have different meanings with different PlayerTextDrawAlignment values:<br />
///   <ul>
///     <li><b><c>1</c></b> (left): they are the right-most corner of the box, absolute coordinates.</li>
///     <li><b><c>2</c></b> (center): they need to inverted (switch the two) and the x value is the overall width of the box.</li>
///     <li><b><c>3</c></b> (right): the x and y are the coordinates of the left-most corner of the box </li>
///   </ul>
/// </remarks>
/// <remarks>
///   Using font type <b><c>4</c></b> (sprite) and <b><c>5</c></b> (model preview) converts x and y of this function from corner coordinates to WIDTH and HEIGHT (offsets).<br />
///   The TextDraw box starts <b><c>10.0</c></b> units up and <b><c>5.0</c></b> to the left as the origin (<a href="#TextDrawCreate">TextDrawCreate</a> coordinate).<br />
///   This function defines the clickable area for use with <a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a>, whether a box is shown or not.
/// </remarks>
native PlayerTextDrawTextSize(playerid, PlayerText:text, Float:width, Float:height);

/// <summary>Set the text alignment of a player-textdraw.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to set the alignment of</param>
/// <param name="text">The ID of the player-textdraw to set the alignment of</param>
/// <param name="alignment"><b><c>1</c></b>-left <b><c>2</c></b>-centered <b><c>3</c></b>-right</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>For alignment <b><c>2</c></b> (center) the x and y values of TextSize need to be swapped, see notes at <a href="#PlayerTextDrawTextSize">PlayerTextDrawTextSize</a>. </remarks>
native PlayerTextDrawAlignment(playerid, PlayerText:text, TEXT_DRAW_ALIGN:alignment);

/// <summary>Sets the text colour of a player-textdraw.</summary>
/// <param name="playerid">The ID of the player who's textdraw to set the colour of</param>
/// <param name="text">The TextDraw to change</param>
/// <param name="colour">The colour in hexadecimal format</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You can also use Gametext colours in textdraws.</remarks>
/// <remarks>The textdraw must be re-shown to the player in order to update the colour.</remarks>
native PlayerTextDrawColor(playerid, PlayerText:text, colour);

/// <summary>Toggle the box on a player-textdraw.</summary>
/// <param name="playerid">The ID of the player whose textdraw to toggle the box of</param>
/// <param name="text">The ID of the player-textdraw to toggle the box of</param>
/// <param name="use"><b><c>1</c></b> to use a box or <b><c>0</c></b> to not use a box</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawUseBox(playerid, PlayerText:text, bool:use);

/// <summary>Sets the colour of a textdraw's box (<a href="#PlayerTextDrawUseBox">PlayerTextDrawUseBox</a>).</summary>
/// <param name="playerid">The ID of the player whose textdraw to set the box colour of</param>
/// <param name="text">The ID of the player textdraw to set the box colour of</param>
/// <param name="colour">The colour to set. Alpha (transparency) is supported</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawBoxColor(playerid, PlayerText:text, colour);

/// <summary>Show a player-textdraw to the player it was created for.</summary>
/// <param name="playerid">The ID of the player to show the textdraw for</param>
/// <param name="text">The ID of the textdraw to show</param>
/// <param name="size">The size of the shadow. <b><c>0</c></b> will hide the shadow</param>
/// <seealso name="PlayerTextDrawHide" />
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawSetShadow(playerid, PlayerText:text, size);

/// <summary>Set the outline of a player-textdraw. The outline colour cannot be changed unless <a href="#PlayerTextDrawBackgroundColor">PlayerTextDrawBackgroundColor</a> is used.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to set the outline of</param>
/// <param name="text">The ID of the player-textdraw to set the outline of</param>
/// <param name="size">The thickness of the outline</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawSetOutline(playerid, PlayerText:text, size);

/// <summary>Adjust the background colour of a player-textdraw.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to set the background colour of</param>
/// <param name="text">The ID of the player-textdraw to set the background colour of</param>
/// <param name="colour">The colour that the textdraw should be set to</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>If <a href="#PlayerTextDrawSetOutline">PlayerTextDrawSetOutline</a> is used with size &gt; 0, the outline colour will match the colour used in <a href="#PlayerTextDrawBackgroundColor">PlayerTextDrawBackgroundColor</a>. Changing the value of colour seems to alter the colour used in <a href="#PlayerTextDrawColor">PlayerTextDrawColor</a></remarks>
native PlayerTextDrawBackgroundColor(playerid, PlayerText:text, colour);

/// <summary>Change the font of a player-textdraw.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to change the font of</param>
/// <param name="text">The ID of the player-textdraw to change the font of</param>
/// <param name="font">There are four font styles. A font value greater than <b><c>3</c></b> does not display, and anything greater than <b><c>16</c></b> crashes the client. See <a href="http://wiki.sa-mp.com/wiki/PlayerTextDrawFont">http://wiki.sa-mp.com/wiki/PlayerTextDrawFont</a></param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawFont(playerid, PlayerText:text, font);

/// <summary>Appears to scale text spacing to a proportional ratio. Useful when using <a href="#PlayerTextDrawLetterSize">PlayerTextDrawLetterSize</a> to ensure the text has even character spacing.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to set the proportionality of</param>
/// <param name="text">The ID of the player-textdraw to set the proportionality of</param>
/// <param name="set"><b><c>1</c></b> to enable proportionality, <b><c>0</c></b> to disable</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawSetProportional(playerid, PlayerText:text, bool:set);

/// <summary>Toggles whether a player-textdraw can be selected or not.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to set the selectability of</param>
/// <param name="text">The ID of the player-textdraw to set the selectability of</param>
/// <param name="set">Set the player-textdraw selectable (<b><c>1</c></b>) or non-selectable (<b><c>0</c></b>). By default this is <b><c>0</c></b></param>
/// <seealso name="SelectTextDraw" />
/// <seealso name="CancelSelectTextDraw" />
/// <seealso name="OnPlayerClickPlayerTextDraw" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks><a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a> MUST be used BEFORE the textdraw is shown to the player.</remarks>
/// <remarks>Use <a href="#PlayerTextDrawTextSize">PlayerTextDrawTextSize</a> to define the clickable area.</remarks>
native PlayerTextDrawSetSelectable(playerid, PlayerText:text, bool:set);

/// <summary>Show a player-textdraw to the player it was created for.</summary>
/// <param name="playerid">The ID of the player to show the textdraw for</param>
/// <param name="text">The ID of the textdraw to show</param>
/// <seealso name="PlayerTextDrawHide" />
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawShow(playerid, PlayerText:text);

/// <summary>Hide a player-textdraw from the player it was created for.</summary>
/// <param name="playerid">The ID of the player to hide the textdraw for</param>
/// <param name="text">The ID of the textdraw to hide</param>
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawSetString" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native PlayerTextDrawHide(playerid, PlayerText:text);

/// <summary>Change the text of a player-textdraw.</summary>
/// <param name="playerid">The ID of the player who's textdraw string to set</param>
/// <param name="text">The ID of the textdraw to change</param>
/// <param name="string">The new string for the TextDraw</param>
/// <seealso name="CreatePlayerTextDraw" />
/// <seealso name="PlayerTextDrawDestroy" />
/// <seealso name="PlayerTextDrawColor" />
/// <seealso name="PlayerTextDrawBoxColor" />
/// <seealso name="PlayerTextDrawBackgroundColor" />
/// <seealso name="PlayerTextDrawAlignment" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="PlayerTextDrawLetterSize" />
/// <seealso name="PlayerTextDrawTextSize" />
/// <seealso name="PlayerTextDrawSetOutline" />
/// <seealso name="PlayerTextDrawSetShadow" />
/// <seealso name="PlayerTextDrawSetProportional" />
/// <seealso name="PlayerTextDrawUseBox" />
/// <seealso name="PlayerTextDrawShow" />
/// <seealso name="PlayerTextDrawHide" />
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>There are limits to the length of textdraw strings! See <a href="http://wiki.sa-mp.com/wiki/Limits">Limits</a> for more info.</remarks>
/// <remarks>You don't have to show the TextDraw again in order to apply the changes.</remarks>
native PlayerTextDrawSetString(playerid, PlayerText:text, const string[]);

/// <summary>Sets a player textdraw 2D preview sprite of a specified model ID.</summary>
/// <param name="playerid">The PlayerTextDraw player ID</param>
/// <param name="text">The textdraw ID that will display the 3D preview</param>
/// <param name="modelIndex">The GTA SA or SA:MP model ID to display</param>
/// <seealso name="PlayerTextDrawSetPreviewRot" />
/// <seealso name="PlayerTextDrawSetPreviewVehCol" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="OnPlayerClickPlayerTextDraw" />
/// <remarks>This function was added in <b>SA-MP 0.3x</b> and will not work in earlier versions!</remarks>
/// <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> in order for this function to have effect.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. If an invalid model is passed 'success' is reported, but the model will appear as a yellow/black question mark.<br />
///   <b><c>0</c></b>: The function failed to execute. Player and/or textdraw do not exist.
/// </returns>
native PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelIndex);

/// <summary>Sets the rotation and zoom of a 3D model preview player-textdraw.</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to change</param>
/// <param name="text">The ID of the player-textdraw to change</param>
/// <param name="rotX">The x rotation value</param>
/// <param name="rotY">The y rotation value</param>
/// <param name="rotZ">The z rotation value</param>
/// <param name="zoom">The zoom value, smaller values make the camera closer and larger values make the camera further away (optional=<b><c>1.0</c></b>)</param>
/// <seealso name="TextDrawSetPreviewRot" />
/// <seealso name="PlayerTextDrawSetPreviewModel" />
/// <seealso name="PlayerTextDrawSetPreviewVehCol" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="OnPlayerClickPlayerTextDraw" />
/// <remarks>This function was added in <b>SA-MP 0.3x</b> and will not work in earlier versions!</remarks>
/// <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> and already have a model set in order for this function to have effect.</remarks>
native PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0);

/// <summary>Set the colour of a vehicle in a player-textdraw model preview (if a vehicle is shown).</summary>
/// <param name="playerid">The ID of the player whose player-textdraw to change</param>
/// <param name="text">The ID of the player's player-textdraw to change</param>
/// <param name="colour1">The <a href="http://wiki.sa-mp.com/wiki/Vehicle_Color_IDs">colour</a> to set the vehicle's primary colour to</param>
/// <param name="colour2">The <a href="http://wiki.sa-mp.com/wiki/Vehicle_Color_IDs">colour</a> to set the vehicle's secondary colour to</param>
/// <seealso name="PlayerTextDrawSetPreviewModel" />
/// <seealso name="PlayerTextDrawSetPreviewRot" />
/// <seealso name="PlayerTextDrawFont" />
/// <seealso name="OnPlayerClickPlayerTextDraw" />
/// <remarks>This function was added in <b>SA-MP 0.3x</b> and will not work in earlier versions!</remarks>
/// <remarks>The textdraw MUST use the font <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> and be showing a vehicle in order for this function to have effect.</remarks>
native PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, colour1, colour2);

// Per-player variable system (PVars)

/// <summary>Set an integer player variable.</summary>
/// <param name="playerid">The ID of the player whose player variable will be set</param>
/// <param name="pvar">The name of the player variable</param>
/// <param name="value">The integer to be set</param>
/// <seealso name="GetPVarInt" />
/// <seealso name="SetPVarString" />
/// <seealso name="GetPVarString" />
/// <seealso name="SetPVarFloat" />
/// <seealso name="GetPVarFloat" />
/// <seealso name="DeletePVar" />
/// <remarks>Variables aren't reset until after <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a> is called, so the values are still accessible in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. Either the player specified is not connected, or the variable name is null or over 40 characters.
/// </returns>
native SetPVarInt(playerid, const pvar[], value);

/// <summary>Gets an integer player variable's value.</summary>
/// <param name="playerid">The ID of the player whose player variable to get</param>
/// <param name="pvar">The name of the player variable (case-insensitive). Assigned in SetPVarInt</param>
/// <seealso name="SetPVarInt" />
/// <seealso name="SetPVarString" />
/// <seealso name="GetPVarString" />
/// <seealso name="SetPVarFloat" />
/// <seealso name="GetPVarFloat" />
/// <seealso name="DeletePVar" />
/// <returns>The integer value of the specified player variable. It will still return <b><c>0</c></b> if the variable is not set, or the player does not exist.</returns>
native GetPVarInt(playerid, const pvar[]);

/// <summary>Saves a string into a player variable.</summary>
/// <param name="playerid">The ID of the player whose player variable will be set</param>
/// <param name="pvar">The name of the player variable</param>
/// <param name="value">The string you want to save in the player variable</param>
/// <seealso name="SetPVarInt" />
/// <seealso name="GetPVarInt" />
/// <seealso name="GetPVarString" />
/// <seealso name="SetPVarFloat" />
/// <seealso name="GetPVarFloat" />
/// <seealso name="DeletePVar" />
native SetPVarString(playerid, const pvar[], const value[]);

/// <summary>Gets a player variable as a string.</summary>
/// <param name="playerid">The ID of the player whose player variable to get</param>
/// <param name="pvar">The name of the player variable, set by <a href="#SetPVarString">SetPVarString</a></param>
/// <param name="output">The array in which to store the string value in, passed by reference</param>
/// <param name="len">The maximum length of the returned string</param>
/// <seealso name="SetPVarString" />
/// <seealso name="SetPVarInt" />
/// <seealso name="GetPVarInt" />
/// <seealso name="SetPVarFloat" />
/// <seealso name="GetPVarFloat" />
/// <seealso name="DeletePVar" />
/// <remarks>If length of string is zero (value not set), output text will not be updated or set to anything and will remain with old data, neccesying that you clear the variable to blank value if <a href="#GetPVarString">GetPVarString</a> returns <b><c>0</c></b> if that behavior is undesired </remarks>
/// <returns>The length of the string.</returns>
native GetPVarString(playerid, const pvar[], output[], len = sizeof (output));

/// <summary>Set a float player variable's value.</summary>
/// <param name="playerid">The ID of the player whose player variable will be set</param>
/// <param name="pvar">The name of the player variable</param>
/// <param name="value">The float you want to save in the player variable</param>
/// <seealso name="SetPVarInt" />
/// <seealso name="GetPVarInt" />
/// <seealso name="SetPVarString" />
/// <seealso name="GetPVarString" />
/// <seealso name="GetPVarFloat" />
/// <seealso name="DeletePVar" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. Either the player specified is not connected, or the variable name is null or over 40 characters.
/// </returns>
native SetPVarFloat(playerid, const pvar[], Float:value);

/// <summary>Gets a player variable as a float.</summary>
/// <param name="playerid">The ID of the player whose player variable you want to get</param>
/// <param name="pvar">The name of the player variable</param>
/// <seealso name="SetPVarInt" />
/// <seealso name="GetPVarInt" />
/// <seealso name="SetPVarString" />
/// <seealso name="GetPVarString" />
/// <seealso name="SetPVarFloat" />
/// <seealso name="DeletePVar" />
/// <returns>The float from the specified player variable.</returns>
native Float:GetPVarFloat(playerid, const pvar[]);

/// <summary>Deletes a previously set player variable.</summary>
/// <param name="playerid">The ID of the player whose player variable to delete</param>
/// <param name="pvar">The name of the player variable to delete</param>
/// <seealso name="SetPVarInt" />
/// <seealso name="GetPVarInt" />
/// <seealso name="SetPVarString" />
/// <seealso name="GetPVarString" />
/// <seealso name="SetPVarFloat" />
/// <seealso name="GetPVarFloat" />
/// <remarks>Once a variable is deleted, attempts to retrieve the value will return <b><c>0</c></b> (for integers and floats and <b><c>NULL</c></b> for strings).</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. Either the player specified isn't connected or there is no variable set with the given name.
/// </returns>
native DeletePVar(playerid, const pvar[]);

/// <summary>Each PVar (player-variable) has its own unique identification number for lookup, this function returns the highest ID set for a player.</summary>
/// <param name="playerid">The ID of the player to get the upper PVar index of</param>
/// <seealso name="GetPVarNameAtIndex" />
/// <seealso name="GetPVarType" />
/// <returns>The highest set PVar ID.</returns>
native GetPVarsUpperIndex(playerid);

/// <summary>Retrieve the name of a player's pVar via the index.</summary>
/// <param name="playerid">The ID of the player whose player variable to get the name of</param>
/// <param name="index">The index of the player's pVar</param>
/// <param name="output">A string to store the pVar's name in, passed by reference</param>
/// <param name="size">The max length of the returned string</param>
/// <seealso name="GetPVarType" />
/// <seealso name="GetPVarInt" />
/// <seealso name="GetPVarFloat" />
/// <seealso name="GetPVarString" />
native GetPVarNameAtIndex(playerid, index, output[], size = sizeof (output));

/// <summary>Gets the type (integer, float or string) of a player variable.</summary>
/// <param name="playerid">The ID of the player whose player variable to get the type of</param>
/// <param name="pvar">The name of the player variable to get the type of</param>
/// <seealso name="SetPVarInt" />
/// <seealso name="GetPVarInt" />
/// <seealso name="SetPVarString" />
/// <seealso name="GetPVarString" />
/// <seealso name="SetPVarFloat" />
/// <seealso name="GetPVarFloat" />
/// <seealso name="DeletePVar" />
/// <remarks>
///   <b>Variable types:</b><br />
///   <ul>
///     <li><b><c>PLAYER_VARTYPE_NONE</c></b> (pVar with name given does not exist)</li>
///     <li><b><c>PLAYER_VARTYPE_INT</c></b></li>
///     <li><b><c>PLAYER_VARTYPE_STRING</c></b></li>
///     <li><b><c>PLAYER_VARTYPE_FLOAT</c></b></li>
///   </ul>
/// </remarks>
/// <returns>Returns the type of the PVar. See table below.</returns>
native PLAYER_VARTYPE:GetPVarType(playerid, const pvar[]);

#if MAX_CHATBUBBLE_LENGTH < 1 || MAX_CHATBUBBLE_LENGTH > 144
	#error MAX_CHATBUBBLE_LENGTH must be >= 1 and <= 144
#endif

/// <summary>Creates a chat bubble above a player's name tag.</summary>
/// <param name="playerid">The player which should have the chat bubble</param>
/// <param name="text">The text to display</param>
/// <param name="colour">The text colour</param>
/// <param name="drawdistance">The distance from where players are able to see the chat bubble</param>
/// <param name="expiretime">The time in miliseconds the bubble should be displayed for</param>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>You can't see your own chatbubbles. The same applies to attached 3D text labels.</remarks>
/// <remarks>You can use colour embedding for multiple colours in the message.</remarks>
native SetPlayerChatBubble(playerid, const text[], colour, Float:drawdistance, expiretime);

// Player control

/// <summary>Puts a player in a vehicle.</summary>
/// <param name="playerid">The ID of the player to put in a vehicle</param>
/// <param name="vehicleid">The ID of the vehicle to put the player in</param>
/// <param name="seatid">The ID of the seat to put the player in</param>
/// <seealso name="RemovePlayerFromVehicle" />
/// <seealso name="GetPlayerVehicleid" />
/// <seealso name="GetPlayerVehicleSeat" />
/// <seealso name="OnPlayerEnterVehicle" />
/// <remarks>If this function is used on a player that is already in a vehicle, other players will still see them in their previous vehicle. To fix this, first remove the player from the vehicle.</remarks>
/// <remarks>If the seat is invalid or is taken, will cause a crash when they EXIT the vehicle.</remarks>
/// <remarks>You can use <a href="#GetPlayerVehicleSeat">GetPlayerVehicleSeat</a> in a loop to check if a seat is occupied by any players.</remarks>
/// <remarks>
///   <b>Seats:</b><br />
///   <ul>
///     <li><b><c>0</c></b> - driver.</li>
///     <li><b><c>1</c></b> - front passenger.</li>
///     <li><b><c>2</c></b> - back-left passenger.</li>
///     <li><b><c>3</c></b> - back-right passenger.</li>
///     <li><b><c>4+</c></b> - passenger seats (coach etc.).</li>
///   </ul>
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player or vehicle don't exist.
/// </returns>
native PutPlayerInVehicle(playerid, vehicleid, seatid);

/// <summary>This function gets the ID of the vehicle the player is currently in. Note: <b>NOT</b> the model ID of the vehicle. See <a href="#GetVehicleModel">GetVehicleModel</a> for that.</summary>
/// <param name="playerid">The ID of the player in the vehicle that you want to get the ID of</param>
/// <seealso name="IsPlayerInVehicle" />
/// <seealso name="IsPlayerInAnyVehicle" />
/// <seealso name="GetPlayerVehicleSeat" />
/// <seealso name="GetVehicleModel" />
/// <returns>ID of the vehicle or <b><c>0</c></b> if not in a vehicle.</returns>
native GetPlayerVehicleID(playerid);

/// <summary>Find out which seat a player is in.</summary>
/// <param name="playerid">The ID of the player you want to get the seat of</param>
/// <seealso name="GetPlayerVehicleid" />
/// <seealso name="PutPlayerInVehicle" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>Sometimes the result can be <b><c>128</c></b> which is an invalid seat ID. Circumstances of this are not yet known, but it is best to discard information when returned seat number is <b><c>128</c></b>.</remarks>
/// <returns>The ID of the seat the player is in. <b><c>-1</c></b> is not in vehicle, <b><c>0</c></b> is the driver, <b><c>1</c></b> is the front passenger, and <b><c>2</c></b> &amp; <b><c>3</c></b> are the rear passengers.</returns>
native GetPlayerVehicleSeat(playerid);

/// <summary>Removes/ejects a player from their vehicle.</summary>
/// <param name="playerid">The ID of the player to remove from their vehicle</param>
/// <seealso name="PutPlayerInVehicle" />
/// <remarks>
///   The exiting animation is not synced for other players.<br />
///   This function will not work when used in <a href="#OnPlayerEnterVehicle">OnPlayerEnterVehicle</a>, because the player isn't in the vehicle when the callback is called. Use <a href="#OnPlayerStateChange">OnPlayerStateChange</a> instead.<br />
///   The player isn't removed if he is in a RC Vehicle.
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native RemovePlayerFromVehicle(playerid);

/// <summary>Toggles whether a player can control their character or not. The player will also be unable to move their camera.</summary>
/// <param name="playerid">The ID of the player to toggle the controllability of</param>
/// <param name="toggle"><b><c>0</c></b> to make them uncontrollable, <b><c>1</c></b> to make them controllable</param>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native TogglePlayerControllable(playerid, bool:toggle);

/// <summary>Plays the specified sound for a player.</summary>
/// <param name="playerid">The ID of the player for whom to play the sound</param>
/// <param name="soundid">The sound to play</param>
/// <param name="x">x coordinate for the sound to play at. (0 for no position)</param>
/// <param name="y">y coordinate for the sound to play at. (0 for no position)</param>
/// <param name="z">z coordinate for the sound to play at. (0 for no position)</param>
/// <seealso name="PlayCrimeReportForPlayer" />
/// <seealso name="PlayAudioStreamForPlayer" />
/// <seealso name="StopAudioStreamForPlayer" />
/// <remarks>Only use the coordinates if you want the sound to be played at a certain position. Set coordinates all to 0 to just play the sound.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z);

/// <summary>Apply an animation to a player.</summary>
/// <param name="playerid">The ID of the player to apply the animation to</param>
/// <param name="animationLibrary">The animation library from which to apply an animation</param>
/// <param name="animationName">The name of the animation to apply, within the specified library</param>
/// <param name="delta">The speed to play the animation (use 4.1)</param>
/// <param name="loop">If set to <b><c>1</c></b>, the animation will loop. If set to <b><c>0</c></b>, the animation will play once</param>
/// <param name="lockX">If set to <b><c>0</c></b>, the player is returned to their old x coordinate once the animation is complete (for animations that move the player such as walking). <b><c>1</c></b> will not return them to their old position</param>
/// <param name="lockY">Same as above but for the y axis. Should be kept the same as the previous parameter</param>
/// <param name="freeze">Setting this to <b><c>1</c></b> will freeze the player at the end of the animation. <b><c>0</c></b> will not</param>
/// <param name="time">Timer in milliseconds. For a never-ending loop it should be <b><c>0</c></b></param>
/// <param name="forceSync">Set to <b><c>1</c></b> to make server sync the animation with all other players in streaming radius. <b><c>2</c></b> works same as <b><c>1</c></b>, but will ONLY apply the animation to streamed-in players, but NOT the actual player being animated (useful for npc animations and persistent animations when players are being streamed) (optional=<b><c>0</c></b>)</param>
/// <seealso name="ClearAnimations" />
/// <seealso name="SetPlayerSpecialAction" />
/// <remarks>The <paramref name="forceSync" /> optional parameter, which defaults to <b><c>0</c></b>, in most cases is not needed since players sync animations themselves. The <paramref name="forceSync" /> parameter can force all players who can see <paramref name="playerid" /> to play the animation regardless of whether the player is performing that animation. This is useful in circumstances where the player can't sync the animation themselves. For example, they may be paused.</remarks>
/// <remarks>An invalid animation library will crash the player's game.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the player specified does not exist, or any of the parameters are invalid (e.g. invalid library).</returns>
native ApplyAnimation(playerid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time, bool:forceSync = false);

/// <summary>Clears all animations for the given player (it also cancels all current tasks such as jetpacking,parachuting,entering vehicles, driving (removes player out of vehicle), swimming, etc.. ).</summary>
/// <param name="playerid">The ID of the player to clear the animations of</param>
/// <param name="forceSync">Set to <b><c>1</c></b> to force playerid to sync the animation with other players in streaming radius (optional=<b><c>0</c></b>)</param>
/// <seealso name="ApplyAnimation" />
/// <remarks>ClearAnimations doesn't do anything when the animation ends if we pass 1 for the freeze parameter in <a href="#ApplyAnimation">ApplyAnimation</a>.</remarks>
/// <remarks>Unlike some other ways to remove player from a vehicle, this will also reset the vehicle's velocity to zero, instantly stopping the car. Player will appear on top of the vehicle with the same location as he was in his car seat.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even when the player specified is not connected.</returns>
native ClearAnimations(playerid, bool:forceSync = false);

/// <summary>Returns the index of any running applied animations.</summary>
/// <param name="playerid">ID of the player of whom you want to get the animation index of</param>
/// <seealso name="GetAnimationName" />
/// <remarks>This function was added in <b>SA-MP 0.3b</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>0</c></b> if there is no animation applied.</returns>
native GetPlayerAnimationIndex(playerid); // return the index of any running applied animations (0 if none are running)

/// <summary>Get the animation library/name for the index.</summary>
/// <param name="index">The animation index, returned by <a href="#GetPlayerAnimationIndex">GetPlayerAnimationIndex</a></param>
/// <param name="animationLibrary">String variable that stores the animation library</param>
/// <param name="len1">Size of the string that stores the animation library</param>
/// <param name="animationName">String variable that stores the animation name</param>
/// <param name="len2">Size of the string that stores the animation name</param>
/// <seealso name="GetPlayerAnimationIndex" />
/// <remarks>This function was added in <b>SA-MP 0.3b</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
native GetAnimationName(index, animationLibrary[], len1 = sizeof (animationLibrary), animationName[], len2 = sizeof (animationName)); // get the animation lib/name for the index

/// <summary>Retrieves a player's current <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a>.</summary>
/// <param name="playerid">The ID of the player to get the <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a> of</param>
/// <seealso name="SetPlayerSpecialAction" />
/// <seealso name="GetPlayerState" />
/// <remarks>
///   <b>Special actions: (marked with * cannot be set)</b><br />
///   <ul>
///     <li><b><c>0 - SPECIAL_ACTION_NONE</c></b></li>
///     <li><b><c>2 - SPECIAL_ACTION_USEJETPACK</c></b></li>
///     <li><b><c>5 - SPECIAL_ACTION_DANCE1</c></b></li>
///     <li><b><c>6 - SPECIAL_ACTION_DANCE2</c></b></li>
///     <li><b><c>7 - SPECIAL_ACTION_DANCE3</c></b></li>
///     <li><b><c>8 - SPECIAL_ACTION_DANCE4</c></b></li>
///     <li><b><c>10 - SPECIAL_ACTION_HANDSUP</c></b></li>
///     <li><b><c>11 - SPECIAL_ACTION_USECELLPHONE</c></b></li>
///     <li><b><c>12 - SPECIAL_ACTION_SITTING *</c></b></li>
///     <li><b><c>13 - SPECIAL_ACTION_STOPUSECELLPHONE</c></b></li>
///   </ul>
///   <b>added in SA-MP 0.3:</b><br />
///   <ul>
///     <li><b><c>1 - SPECIAL_ACTION_DUCK *</c></b> - Detect if the player is crouching.</li>
///     <li><b><c>3 - SPECIAL_ACTION_ENTER_VEHICLE *</c></b> - Detect if the player is entering a vehicle via an animation.</li>
///     <li><b><c>4 - SPECIAL_ACTION_EXIT_VEHICLE *</c></b> - Detect if the player is exiting a vehicle via an animation.</li>
///     <li><b><c>20 - SPECIAL_ACTION_DRINK_BEER</c></b> - Will increase the player's drunk level when used</li>
///     <li><b><c>21 - SPECIAL_ACTION_SMOKE_CIGGY</c></b> - Will give the player a cigar</li>
///     <li><b><c>22 - SPECIAL_ACTION_DRINK_WINE</c></b> - Will give the player a wine bottle to get drunk from</li>
///     <li><b><c>23 - SPECIAL_ACTION_DRINK_SPRUNK</c></b> - Will give the player a sprunk bottle to drink from</li>
///     <li><b><c>68 - SPECIAL_ACTION_PISSING</c></b> - Will make make the player perform the pissing animation with visible pee.</li>
///   </ul>
///   <b>added in SA-MP 0.3e:</b><br />
///   <ul>
///     <li><b><c>24 - SPECIAL_ACTION_CUFFED</c></b> - Will force the player in to cuffs (hands are behind their back) (<b>does not work on CJ skin</b>)</li>
///   </ul>
///   <b>added in SA-MP 0.3x:</b><br />
///   <ul>
///     <li><b><c>25 - SPECIAL_ACTION_CARRY</c></b>         - Will apply a 'carrying' animation to the player and make them unable to sprint, jump or punch (<b>does not work on CJ skin</b>)</li>
///   </ul>
/// </remarks>
/// <returns>The <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a> of the player.</returns>
native SPECIAL_ACTION:GetPlayerSpecialAction(playerid);

/// <summary>This function allows to set players special action.</summary>
/// <param name="playerid">The player that should perform the action</param>
/// <param name="actionid">The action that should be performed</param>
/// <seealso name="GetPlayerSpecialAction" />
/// <seealso name="ApplyAnimation" />
/// <remarks>Removing jetpacks from players by setting their special action to <b><c>0</c></b> causes the sound to stay until death.</remarks>
/// <remarks>
///   <b>Special actions: (marked with * cannot be set)</b><br />
///   <ul>
///     <li><b><c>0 - SPECIAL_ACTION_NONE</c></b></li>
///     <li><b><c>2 - SPECIAL_ACTION_USEJETPACK</c></b></li>
///     <li><b><c>5 - SPECIAL_ACTION_DANCE1</c></b></li>
///     <li><b><c>6 - SPECIAL_ACTION_DANCE2</c></b></li>
///     <li><b><c>7 - SPECIAL_ACTION_DANCE3</c></b></li>
///     <li><b><c>8 - SPECIAL_ACTION_DANCE4</c></b></li>
///     <li><b><c>10 - SPECIAL_ACTION_HANDSUP</c></b></li>
///     <li><b><c>11 - SPECIAL_ACTION_USECELLPHONE</c></b></li>
///     <li><b><c>12 - SPECIAL_ACTION_SITTING *</c></b></li>
///     <li><b><c>13 - SPECIAL_ACTION_STOPUSECELLPHONE</c></b></li>
///   </ul>
///   <b>added in SA-MP 0.3:</b><br />
///   <ul>
///     <li><b><c>1 - SPECIAL_ACTION_DUCK *</c></b> - Detect if the player is crouching.</li>
///     <li><b><c>3 - SPECIAL_ACTION_ENTER_VEHICLE *</c></b> - Detect if the player is entering a vehicle via an animation.</li>
///     <li><b><c>4 - SPECIAL_ACTION_EXIT_VEHICLE *</c></b> - Detect if the player is exiting a vehicle via an animation.</li>
///     <li><b><c>20 - SPECIAL_ACTION_DRINK_BEER</c></b> - Will increase the player's drunk level when used</li>
///     <li><b><c>21 - SPECIAL_ACTION_SMOKE_CIGGY</c></b> - Will give the player a cigar</li>
///     <li><b><c>22 - SPECIAL_ACTION_DRINK_WINE</c></b> - Will give the player a wine bottle to get drunk from</li>
///     <li><b><c>23 - SPECIAL_ACTION_DRINK_SPRUNK</c></b> - Will give the player a sprunk bottle to drink from</li>
///     <li><b><c>68 - SPECIAL_ACTION_PISSING</c></b> - Will make make the player perform the pissing animation with visible pee.</li>
///   </ul>
///   <b>added in SA-MP 0.3e:</b><br />
///   <ul>
///     <li><b><c>24 - SPECIAL_ACTION_CUFFED</c></b> - Will force the player in to cuffs (hands are behind their back) (<b>does not work on CJ skin</b>)</li>
///   </ul>
///   <b>added in SA-MP 0.3x:</b><br />
///   <ul>
///     <li><b><c>25 - SPECIAL_ACTION_CARRY</c></b>         - Will apply a 'carrying' animation to the player and make them unable to sprint, jump or punch (<b>does not work on CJ skin</b>)</li>
///   </ul>
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid);

/// <summary>Disables collisions between occupied vehicles for a player.</summary>
/// <param name="playerid">The ID of the player for whom you want to disable collisions</param>
/// <param name="disable"><b><c>1</c></b> to disable collisions, <b><c>0</c></b> to enable collisions</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native DisableRemoteVehicleCollisions(playerid, bool:disable);

// Player world/map related

/// <summary>Sets a checkpoint (red cylinder) for a player. Also shows a red blip on the radar. When players enter a checkpoint, <a href="#OnPlayerEnterCheckpoint">OnPlayerEnterCheckpoint</a> is called and actions can be performed.</summary>
/// <param name="playerid">The ID of the player for whom to set a checkpoint</param>
/// <param name="x">The x coordinate to set the checkpoint at</param>
/// <param name="y">The y coordinate to set the checkpoint at</param>
/// <param name="z">The z coordinate to set the checkpoint at</param>
/// <param name="size">The size of the checkpoint</param>
/// <remarks>
///   If a checkpoint is already set it will use the size of that checkpoint instead of the new one.<br />
///   Checkpoints created on server-created objects (<a href="#CreateObject">CreateObject</a>/<a href="#CreatePlayerObject">CreatePlayerObject</a>) will appear down on the 'real' ground, but will still function correctly. A pickup can be used instead.
/// </remarks>
/// <remarks>Checkpoints are asynchronous, meaning only one can be shown at a time. To 'stream' checkpoints (only show them when players are close enough), use a checkpoint streamer.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size);

/// <summary>Disables (hides/destroys) a player's set checkpoint. Players can only have a single checkpoint set at a time. Checkpoints don't need to be disabled before setting another one.</summary>
/// <param name="playerid">The ID of the player whose checkpoint to disable</param>
/// <seealso name="SetPlayerCheckpoint" />
/// <seealso name="IsPlayerInCheckpoint" />
/// <seealso name="SetPlayerRaceCheckpoint" />
/// <seealso name="DisablePlayerRaceCheckpoint" />
/// <seealso name="IsPlayerInRaceCheckpoint" />
/// <seealso name="OnPlayerEnterCheckpoint" />
/// <seealso name="OnPlayerLeaveCheckpoint" />
/// <seealso name="OnPlayerEnterRaceCheckpoint" />
/// <seealso name="OnPlayerLeaveRaceCheckpoint" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is also returned if the player doesn't have a checkpoint shown already.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native DisablePlayerCheckpoint(playerid);

/// <summary>Creates a race checkpoint. When the player enters it, the <a href="#OnPlayerEnterRaceCheckpoint">OnPlayerEnterRaceCheckpoint</a> callback is called.</summary>
/// <param name="playerid">The ID of the player to set the checkpoint for</param>
/// <param name="type">Type of checkpoint. <b><c>0</c></b>-Normal, <b><c>1</c></b>-Finish, <b><c>2</c></b>-Nothing(Only the checkpoint without anything on it), <b><c>3</c></b>-Air normal, <b><c>4</c></b>-Air finish, <b><c>5</c></b>-Air (rotates and stops), <b><c>6</c></b>-Air (increases, decreases and disappears), <b><c>7</c></b>-Air (swings down and up), <b><c>8</c></b>-Air (swings up and down)</param>
/// <param name="centerX">x-Coordinate</param>
/// <param name="centerY">y-Coordinate</param>
/// <param name="centerZ">z-Coordinate</param>
/// <param name="nextX">x-Coordinate of the next point, for the arrow facing direction</param>
/// <param name="nextY">y-Coordinate of the next point, for the arrow facing direction</param>
/// <param name="nextZ">z-Coordinate of the next point, for the arrow facing direction</param>
/// <param name="size">Size (diameter) of the checkpoint</param>
/// <seealso name="SetPlayerCheckpoint" />
/// <seealso name="DisablePlayerCheckpoint" />
/// <seealso name="IsPlayerInCheckpoint" />
/// <seealso name="DisablePlayerRaceCheckpoint" />
/// <seealso name="IsPlayerInRaceCheckpoint" />
/// <seealso name="OnPlayerEnterCheckpoint" />
/// <seealso name="OnPlayerLeaveCheckpoint" />
/// <seealso name="OnPlayerEnterRaceCheckpoint" />
/// <seealso name="OnPlayerLeaveRaceCheckpoint" />
/// <remarks>If a race checkpoint is already set it will use the size of that checkpoint instead of the new one. </remarks>
/// <remarks>
///   Race checkpoints created on server-created objects (<a href="#CreateObject">CreateObject</a>/<a href="#CreatePlayerObject">CreatePlayerObject</a>) will appear down on the 'real' ground, but will still function correctly.<br />
///   Race checkpoints are asynchronous, meaning only one can be shown at a time. To 'stream' race checkpoints (only show them when players are close enough), use a race checkpoint streamer.
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
/// </returns>
native SetPlayerRaceCheckpoint(playerid, type, Float:centerX, Float:centerY, Float:centerZ, Float:nextX, Float:nextY, Float:nextZ, Float:size);

/// <summary>Disable any initialized race checkpoints for a specific player, since you can only have one at any given time.</summary>
/// <param name="playerid">The player to disable the current checkpoint for</param>
/// <seealso name="SetPlayerCheckpoint" />
/// <seealso name="DisablePlayerCheckpoint" />
/// <seealso name="IsPlayerInCheckpoint" />
/// <seealso name="SetPlayerRaceCheckpoint" />
/// <seealso name="IsPlayerInRaceCheckpoint" />
/// <seealso name="OnPlayerEnterCheckpoint" />
/// <seealso name="OnPlayerLeaveCheckpoint" />
/// <seealso name="OnPlayerEnterRaceCheckpoint" />
/// <seealso name="OnPlayerLeaveRaceCheckpoint" />
native DisablePlayerRaceCheckpoint(playerid);

/// <summary>Set the world boundaries for a player. Players can not go out of the boundaries (they will be pushed back in).</summary>
/// <param name="playerid">The ID of the player to set the world boundaries of</param>
/// <param name="maxX">The maximum x coordinate the player can go to</param>
/// <param name="minX">The minimum x coordinate the player can go to</param>
/// <param name="maxY">The maximum y coordinate the player can go to</param>
/// <param name="minY">The minimum y coordinate the player can go to</param>
/// <seealso name="GangZoneCreate" />
/// <remarks>This function does not work if used in <a href="#OnPlayerConnect">OnPlayerConnect</a></remarks>
/// <remarks>A player's world boundaries can be reset by setting them to <b><c>20000.0</c></b>, <b><c>-20000.0</c></b>, <b><c>20000.0</c></b>, <b><c>-20000.0</c></b>. These are the default values.</remarks>
/// <remarks>This function doesn't work in interiors!</remarks>
native SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY);

/// <summary>Change the colour of a player's <b>nametag</b> and <b>radar blip</b> for another player.</summary>
/// <param name="playerid">The player that will see the player's changed blip/nametag colour</param>
/// <param name="targetid">The player whose colour will be changed</param>
/// <param name="colour">New colour. (<b>RGBA</b>)</param>
/// <seealso name="ShowPlayerMarkers" />
/// <seealso name="LimitPlayerMarkerRadius" />
/// <seealso name="SetPlayerColor" />
/// <seealso name="ShowPlayerNameTagForPlayer" />
native SetPlayerMarkerForPlayer(playerid, targetid, colour);

/// <summary>This functions allows you to toggle the drawing of player nametags, healthbars and armor bars which display above their head. For use of a similar function like this on a global level, <a href="#ShowNameTags">ShowNameTags</a> function.</summary>
/// <param name="playerid">Player who will see the results of this function</param>
/// <param name="targetid">Player whose name tag will be shown or hidden</param>
/// <param name="show"><b><c>1</c></b>-show name tag, <b><c>0</c></b>-hide name tag</param>
/// <seealso name="ShowNameTags" />
/// <seealso name="DisableNameTagLOS" />
/// <seealso name="SetPlayerMarkerForPlayer" />
/// <remarks><a href="#ShowNameTags">ShowNameTags</a> must be set to <b><c>1</c></b> to be able to show name tags with ShowPlayerNameTagForPlayer, that means that in order to be effective you need to <c>ShowPlayerNameTagForPlayer(forplayerid, playerid, 0)</c> ahead of time(<a href="#OnPlayerStreamIn">OnPlayerStreamIn</a> is a good spot).</remarks>
native ShowPlayerNameTagForPlayer(playerid, targetid, bool:show);

/// <summary>Place an icon/marker on a player's map. Can be used to mark locations such as banks and hospitals to players.</summary>
/// <param name="playerid">The ID of the player to set the map icon for</param>
/// <param name="iconid">The player's icon ID, ranging from <b><c>0</c></b> to <b><c>99</c></b>. This means there is a maximum of <b><c>100</c></b> map icons. ID can be used in <a href="#RemovePlayerMapIcon">RemovePlayerMapIcon</a></param>
/// <param name="x">The x coordinate to place the map icon at</param>
/// <param name="y">The y coordinate to place the map icon at</param>
/// <param name="z">The z coordinate to place the map icon at</param>
/// <param name="markerType">The icon to set</param>
/// <param name="colour">The colour of the icon (<b>RGBA</b>). This should only be used with the square icon (ID: <b><c>0</c></b>)</param>
/// <param name="style">The style of icon (optional=<b><c>MAPICON_LOCAL</c></b>)</param>
/// <seealso name="RemovePlayerMapIcon" />
/// <seealso name="SetPlayerMarkerForPlayer" />
/// <remarks>If you use an invalid marker type, it will create ID <b><c>1</c></b> (White Square). </remarks>
/// <remarks>If you use an icon ID that is already in use, it will replace the current map icon using that ID. </remarks>
/// <remarks>Marker type <b><c>1</c></b> (square), <b><c>2</c></b> (player blip), <b><c>4</c></b> (north), and <b><c>56</c></b> (single airstrip blip) will cause your game to crash if you have map legends enabled while viewing the map.</remarks>
/// <remarks>
///   <b>Map icon styles:</b><br />
///   <ul>
///     <li><b><c>0 MAPICON_LOCAL</c></b> - close proximity only</li>
///     <li><b><c>1 MAPICON_GLOBAL</c></b> - show on radar edge as long as in range</li>
///     <li><b><c>2 MAPICON_LOCAL_CHECKPOINT</c></b> - Close proximity only (with checkpoint)</li>
///     <li><b><c>3 MAPICON_GLOBAL_CHECKPOINT</c></b> - Show on radar edge as long as in range (with checkpoint)</li>
///   </ul>
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. Player is not connected.
/// </returns>
native SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL);

/// <summary>Removes a map icon that was set earlier for a player using <a href="#SetPlayerMapIcon">SetPlayerMapIcon</a>.</summary>
/// <param name="playerid">The ID of the player whose icon to remove</param>
/// <param name="iconid">The ID of the icon to remove. This is the second parameter of <a href="#SetPlayerMapIcon">SetPlayerMapIcon</a></param>
/// <seealso name="SetPlayerMapIcon" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute.
/// </returns>
native RemovePlayerMapIcon(playerid, iconid);

/// <summary>Enable/Disable the teleporting ability for a player by right-clicking on the map.</summary>
/// <param name="playerid">The ID of the player to allow teleport</param>
/// <param name="allow"><b><c>1</c></b> to allow, <b><c>0</c></b> to disallow</param>
/// <remarks><b>This function, as of 0.3d, is deprecated. Check <a href="#OnPlayerClickMap">OnPlayerClickMap</a>.</b></remarks>
/// <remarks>This function will work only if <a href="#AllowAdminTeleport">AllowAdminTeleport</a> is enabled, and you have to be an admin.</remarks>
/// <seealso name="AllowAdminTeleport" />
#pragma deprecated Use `OnPlayerClickMap`.
native AllowPlayerTeleport(playerid, bool:allow);

// Player camera

/// <summary>Sets the camera to a specific position for a player.</summary>
/// <param name="playerid">ID of the player</param>
/// <param name="x">The x coordinate to place the camera at</param>
/// <param name="y">The y coordinate to place the camera at</param>
/// <param name="z">The z coordinate to place the camera at</param>
/// <seealso name="SetPlayerCameraLookAt" />
/// <seealso name="SetCameraBehindPlayer" />
/// <remarks>You may also have to use <a href="#SetPlayerCameraLookAt">SetPlayerCameraLookAt</a> with this function in order to work properly.</remarks>
/// <remarks>Use <a href="#SetCameraBehindPlayer">SetCameraBehindPlayer</a> to reset the camera to behind the player.</remarks>
/// <remarks>Using the camera functions directly after enabling spectator mode doesn't work.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified doesn't exist.
/// </returns>
native SetPlayerCameraPos(playerid,Float:x, Float:y, Float:z);

/// <summary>Set the direction a player's camera looks at. Generally meant to be used in combination with <a href="#SetPlayerCameraPos">SetPlayerCameraPos</a>.</summary>
/// <param name="playerid">The ID of the player whose camera to set</param>
/// <param name="x">The x coordinate for the player's camera to look at</param>
/// <param name="y">The y coordinate for the player's camera to look at</param>
/// <param name="z">The z coordinate for the player's camera to look at</param>
/// <param name="cut">The style of the change. Can be used to interpolate (change slowly) from old pos to new pos using <b><c>CAMERA_MOVE</c></b>. Added in <b>0.3e</b>. Leave out for older versions (optional=<b><c>CAMERA_CUT</c></b>)</param>
/// <seealso name="SetPlayerCameraPos" />
/// <seealso name="SetCameraBehindPlayer" />
/// <seealso name="GetPlayerCameraPos" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>Using the camera functions directly after enabling spectator mode doesn't work.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAMERA:cut = CAMERA_CUT);

/// <summary>Restore the camera to a place behind the player, after using a function like <a href="#SetPlayerCameraPos">SetPlayerCameraPos</a>.</summary>
/// <param name="playerid">The player you want to restore the camera for</param>
/// <seealso name="SetPlayerCameraPos" />
/// <seealso name="SetPlayerCameraLookAt" />
native SetCameraBehindPlayer(playerid);

/// <summary>Get the position of the player's camera.</summary>
/// <param name="playerid">The ID of the player to get the camera position of</param>
/// <param name="x">A float variable to store the x coordinate in, passed by reference</param>
/// <param name="y">A float variable to store the y coordinate in, passed by reference</param>
/// <param name="z">A float variable to store the z coordinate in, passed by reference</param>
/// <seealso name="SetPlayerCameraPos" />
/// <seealso name="GetPlayerCameraZoom" />
/// <seealso name="GetPlayerCameraAspectRatio" />
/// <seealso name="GetPlayerCameraMode" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>Player's camera positions are only updated once a second, <b>unless aiming</b>.</remarks>
/// <remarks>It is recommended to set a 1 second timer if you wish to take action that relies on a player's camera position.</remarks>
native GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z);

/// <summary>This function will return the current direction of player's aiming in 3-D space, the coords are relative to the camera position, see <a href="#GetPlayerCameraPos">GetPlayerCameraPos</a>.</summary>
/// <param name="playerid">The ID of the player you want to obtain the camera front vector of</param>
/// <param name="x">A float to store the x coordinate, passed by reference</param>
/// <param name="y">A float to store the y coordinate, passed by reference</param>
/// <param name="z">A float to store the z coordinate, passed by reference</param>
/// <seealso name="GetPlayerCameraPos" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>In <b>0.3a</b> the camera front vector is only obtainable when player is inside a rhino, S.W.A.T tank, fire truck, or on foot. </remarks>
/// <remarks>Since <b>0.3b</b> the camera data can be obtained when the player is in any vehicle or on foot. </remarks>
/// <returns>The position is stored in the specified variables.</returns>
native GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z);

/// <summary>Returns the current GTA camera mode for the requested player. The camera modes are useful in determining whether a player is aiming, doing a passenger driveby etc.</summary>
/// <param name="playerid">The ID of the player whose camera mode to retrieve</param>
/// <seealso name="GetPlayerCameraPos" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <seealso name="SetPlayerCameraPos" />
/// <seealso name="SetPlayerCameraLookAt" />
/// <seealso name="SetCameraBehindPlayer" />
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns>The camera mode as an integer (or <b><c>-1</c></b> if player is not connected).</returns>
native GetPlayerCameraMode(playerid);

/// <summary>Toggle camera targeting functions for a player. Disabled by default to save bandwidth.</summary>
/// <param name="playerid">The ID of the player to toggle camera targeting functions for</param>
/// <param name="enable"><b><c>1</c></b> to enable camera targeting functions and <b><c>0</c></b> to disable them</param>
/// <seealso name="GetPlayerCameraTargetVehicle" />
/// <seealso name="GetPlayerCameraTargetPlayer" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player is not connected.
/// </returns>
native EnablePlayerCameraTarget(playerid, bool:enable);

/// <summary>Allows you to retrieve the ID of the object the player is looking at.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="GetPlayerCameraTargetVehicle" />
/// <seealso name="GetPlayerCameraTargetPlayer" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <returns>The ID of the object playerid is looking at. If <b><c>INVALID_OBJECT_ID (65535)</c></b> is returned, playerid isn't looking at any object.</returns>
native GetPlayerCameraTargetObject(playerid);

/// <summary>Get the ID of the vehicle the player is looking at.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="GetPlayerCameraTargetPlayer" />
/// <seealso name="GetPlayerCameraTargetObject" />
/// <seealso name="EnablePlayerCameraTarget" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <remarks>This function can (obviously) only return one vehicle ID at a time, while the player may be looking at multiple. It generally seems to detect the closest vehicle first.</remarks>
/// <returns>The vehicle ID of the vehicle the player is looking at. <b><c>INVALID_VEHICLE_ID</c></b> if none.</returns>
native GetPlayerCameraTargetVehicle(playerid);

/// <summary>Allows you to retrieve the ID of the player the playerid is looking at.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="GetPlayerCameraTargetActor" />
/// <seealso name="GetPlayerCameraTargetVehicle" />
/// <seealso name="GetPlayerCameraTargetObject" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <remarks>Do not confuse this function with <a href="#GetPlayerTargetPlayer">GetPlayerTargetPlayer</a>. <a href="#GetPlayerTargetPlayer">GetPlayerTargetPlayer</a> returns the ID of the player playerid is aming at (with a weapon). <a href="#GetPlayerCameraTargetPlayer">GetPlayerCameraTargetPlayer</a> returns the ID of the player playerid is looking at (reference point is the <b>center of the screen</b>).</remarks>
/// <returns>The ID of the player the playerid is looking at.</returns>
native GetPlayerCameraTargetPlayer(playerid);

/// <summary>Allows you to retrieve the ID of the actor the player is looking at (if any).</summary>
/// <param name="playerid">The ID of the player to get the target actor of</param>
/// <seealso name="GetPlayerTargetActor" />
/// <seealso name="GetPlayerCameraTargetPlayer" />
/// <seealso name="GetPlayerCameraTargetVehicle" />
/// <seealso name="GetPlayerCameraTargetObject" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <remarks>This function only tells you which actor (if any) the player is <b>looking</b> at. To find out if they are <b>aiming</b> at them, you need to use <a href="#GetPlayerTargetActor">GetPlayerTargetActor</a>.</remarks>
/// <returns>The ID of the actor the player is looking at.</returns>
native GetPlayerCameraTargetActor(playerid);

/// <summary>Retrieves the aspect ratio of a player's camera.</summary>
/// <param name="playerid">The ID of the player to get the camera aspect ratio of</param>
/// <seealso name="GetPlayerCameraZoom" />
/// <seealso name="GetPlayerCameraPos" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions! </remarks>
/// <remarks>The return value of this function represents the value of the "widescreen" option in the game's display settings, not the actual aspect ratio of the player's display.</remarks>
/// <returns>The aspect ratio of the player's camera, as a float. The aspect ratio can be one of three values: 4:3 (<b><c>1.3333334</c></b>, <b><c>Float:0x3FAAAAAB</c></b>) when widescreen is turned off, 5:4 (<b><c>1.2470589</c></b>, <b><c>Float:0x3F9F9FA0</c></b>) when letterbox mode is turned on, and 16:9 (<b><c>1.7764707</c></b>, <b><c>Float:0x3FE36364</c></b>) when widescreen is turned on regardless of the letterbox mode.</returns>
native Float:GetPlayerCameraAspectRatio(playerid);

/// <summary>Retrieves the game camera zoom level for a given player.</summary>
/// <param name="playerid">The ID of the player to get the camera zoom level of</param>
/// <seealso name="GetPlayerCameraAspectRatio" />
/// <seealso name="GetPlayerCameraPos" />
/// <seealso name="GetPlayerCameraFrontVector" />
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <remarks>This retrieves the zoom level of the GAME camera, not the camera WEAPON.</remarks>
/// <returns>The player's camera zoom level (camera, sniper etc.), a float.</returns>
native Float:GetPlayerCameraZoom(playerid);

/// <summary>You can use this function to attach the player camera to objects.</summary>
/// <param name="playerid">The ID of the player which will have your camera attached on object</param>
/// <param name="objectid">The object ID which you want to attach the player camera</param>
/// <seealso name="AttachCameraToPlayerObject" />
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You need to create the object first, before attempting to attach a player camera for that.</remarks>
native AttachCameraToObject(playerid, objectid);

/// <summary>Attaches a player's camera to a player-object. The player is able to move their camera while it is attached to an object. Can be used with MovePlayerObject and AttachPlayerObjectToVehicle.</summary>
/// <param name="playerid">The ID of the player which will have their camera attached to a player-object</param>
/// <param name="objectid">The ID of the player-object to which the player's camera will be attached</param>
/// <seealso name="AttachCameraToObject" />
/// <seealso name="SetPlayerCameraPos" />
/// <seealso name="SetPlayerCameraLookAt" />
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>The player-object must be created before attempting to attach the player's camera to it.</remarks>
native AttachCameraToPlayerObject(playerid, objectid);

/// <summary>Move a player's camera from one position to another, within the set time. Useful for scripted cut scenes.</summary>
/// <param name="playerid">The ID of the player the camera should be moved for</param>
/// <param name="fromX">The x position the camera should start to move from</param>
/// <param name="fromY">The y position the camera should start to move from</param>
/// <param name="fromZ">The z position the camera should start to move from</param>
/// <param name="toX">The x position the camera should move to</param>
/// <param name="toY">The y position the camera should move to</param>
/// <param name="toZ">The z position the camera should move to</param>
/// <param name="time">Time in milliseconds</param>
/// <param name="cut">The jumpcut to use. Set to <b><c>CAMERA_MOVE</c></b> for a smooth movement (optional=<b><c>CAMERA_CUT</c></b>)</param>
/// <seealso name="InterpolateCameraLookAt" />
/// <seealso name="SetPlayerCameraPos" />
/// <seealso name="SetPlayerCameraLookAt" />
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>Use <b><c>TogglePlayerSpectating</c></b> to make objects stream in for the player while the camera is moving. You can reset the camera behind the player with <b><c>SetCameraBehindPlayer</c></b>.</remarks>
native InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAMERA:cut = CAMERA_CUT);

/// <summary>Interpolate a player's camera's 'look at' point between two coordinates with a set speed. Can be be used with <a href="#InterpolateCameraPos">InterpolateCameraPos</a>.</summary>
/// <param name="playerid">The ID of the player the camera should be moved for</param>
/// <param name="fromX">The x position the camera should start to move from</param>
/// <param name="fromY">The y position the camera should start to move from</param>
/// <param name="fromZ">The z position the camera should start to move from</param>
/// <param name="toX">The x position the camera should move to</param>
/// <param name="toY">The y position the camera should move to</param>
/// <param name="toZ">The z position the camera should move to</param>
/// <param name="time">Time in milliseconds to complete interpolation</param>
/// <param name="cut">The 'jumpcut' to use. Set to <b><c>CAMERA_MOVE</c></b> for interpolation (optional=<b><c>CAMERA_CUT</c></b>)</param>
/// <seealso name="InterpolateCameraPos" />
/// <seealso name="SetPlayerCameraLookAt" />
/// <seealso name="SetPlayerCameraPos" />
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>Use <b><c>TogglePlayerSpectating</c></b> to make objects stream in for the player while the camera is moving. You can reset the camera behind the player with <b><c>SetCameraBehindPlayer</c></b>.</remarks>
native InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAMERA:cut = CAMERA_CUT);

// Player conditionals

/// <summary>Checks if a player is connected (if an ID is taken by a connected player).</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="IsPlayerAdmin" />
/// <seealso name="OnPlayerConnect" />
/// <seealso name="OnPlayerDisconnect" />
/// <remarks>This function can be omitted in a lot of cases. Many other functions already have some sort of connection check built in.</remarks>
/// <returns><b><c>1</c></b> if the player is connected, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerConnected(playerid);

/// <summary>Checks if a player is in a specific vehicle.</summary>
/// <param name="playerid">ID of the player</param>
/// <param name="vehicleid">ID of the vehicle</param>
/// <seealso name="IsPlayerInAnyVehicle" />
/// <seealso name="GetPlayerVehicleSeat" />
/// <returns><b><c>1</c></b> if the player is in the vehicle, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerInVehicle(playerid, vehicleid);

/// <summary>Check if a player is inside any vehicle (as a driver or passenger).</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="IsPlayerInVehicle" />
/// <seealso name="GetPlayerVehicleSeat" />
/// <returns><b><c>1</c></b> if the player is in a vehicle, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerInAnyVehicle(playerid);

/// <summary>Check if the player is currently inside a checkpoint, this could be used for properties or teleport points for example.</summary>
/// <param name="playerid">The player you want to know the status of</param>
/// <seealso name="SetPlayerCheckpoint" />
/// <seealso name="DisablePlayerCheckpoint" />
/// <seealso name="SetPlayerRaceCheckpoint" />
/// <seealso name="DisablePlayerRaceCheckpoint" />
/// <seealso name="IsPlayerInRaceCheckpoint" />
/// <seealso name="OnPlayerEnterCheckpoint" />
/// <seealso name="OnPlayerLeaveCheckpoint" />
/// <seealso name="OnPlayerEnterRaceCheckpoint" />
/// <seealso name="OnPlayerLeaveRaceCheckpoint" />
/// <returns><b><c>0</c></b> if player isn't in his checkpoint else <b><c>1</c></b>.</returns>
native bool:IsPlayerInCheckpoint(playerid);

/// <summary>Check if the player is inside their current set race checkpoint (<a href="#SetPlayerRaceCheckpoint">SetPlayerRaceCheckpoint</a>).</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="SetPlayerCheckpoint" />
/// <seealso name="DisablePlayerCheckpoint" />
/// <seealso name="IsPlayerInCheckpoint" />
/// <seealso name="SetPlayerRaceCheckpoint" />
/// <seealso name="DisablePlayerRaceCheckpoint" />
/// <seealso name="OnPlayerEnterCheckpoint" />
/// <seealso name="OnPlayerLeaveCheckpoint" />
/// <seealso name="OnPlayerEnterRaceCheckpoint" />
/// <seealso name="OnPlayerLeaveRaceCheckpoint" />
/// <returns><b><c>1</c></b> is the player is in a race checkpoint, <b><c>0</c></b> if not.</returns>
native bool:IsPlayerInRaceCheckpoint(playerid);

// Virtual Worlds

/// <summary>Set the virtual world of a player. They can only see other players or vehicles that are in that same world.</summary>
/// <param name="playerid">The ID of the player you want to set the virtual world of</param>
/// <param name="virtualWorld">The virtual world ID to put the player in</param>
/// <seealso name="GetPlayerVirtualWorld" />
/// <seealso name="SetVehicleVirtualWorld" />
/// <remarks>The default virtual world is <b><c>0</c></b></remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native SetPlayerVirtualWorld(playerid, virtualWorld);

/// <summary>Retrieves the current virtual world the player is in.</summary>
/// <param name="playerid">The ID of the player to get the virtual world of</param>
/// <seealso name="SetPlayerVirtualWorld" />
/// <seealso name="GetVehicleVirtualWorld" />
/// <seealso name="GetPlayerInterior" />
/// <returns>The ID of the virtual world the player is currently in.</returns>
native GetPlayerVirtualWorld(playerid);

// Insane Stunts

/// <summary>Toggle stunt bonuses for a player. Enabled by default.</summary>
/// <param name="playerid">The ID of the player to toggle stunt bonuses for</param>
/// <param name="enable"><b><c>1</c></b> to enable stunt bonuses and <b><c>0</c></b> to disable them</param>
/// <seealso name="EnableStuntBonusForAll" />
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player is not connected.
/// </returns>
native EnableStuntBonusForPlayer(playerid, bool:enable);

/// <summary>Enables or disables stunt bonuses for all players. If enabled, players will receive monetary rewards when performing a stunt in a vehicle (e.g. a wheelie).</summary>
/// <param name="enable"><b><c>1</c></b> to enable stunt bonuses or <b><c>0</c></b> to disable them</param>
/// <seealso name="EnableStuntBonusForPlayer" />
native EnableStuntBonusForAll(bool:enable);

/// <summary>Toggle whether a player is in spectator mode or not. While in spectator mode a player can spectate (watch) other players and vehicles. After using this function, either <a href="#PlayerSpectatePlayer">PlayerSpectatePlayer</a> or <a href="#PlayerSpectateVehicle">PlayerSpectateVehicle</a> needs to be used.</summary>
/// <param name="playerid">The ID of the player who should spectate</param>
/// <param name="toggle"><b><c>1</c></b> to enable spectating and <b><c>0</c></b> to disable</param>
/// <seealso name="PlayerSpectatePlayer" />
/// <seealso name="PlayerSpectateVehicle" />
/// <remarks>If the player is not loaded in before setting the spectate status to false, the connection can be closed unexpectedly.</remarks>
/// <remarks>When spectator mode is disabled, <a href="#OnPlayerSpawn">OnPlayerSpawn</a> will automatically be called, if you wish to restore player to state before spectating, you will have to handle that in <a href="#OnPlayerSpawn">OnPlayerSpawn</a>. Note also, that player can also go to class selection before if they used F4 during spectate, a player also CAN die in spectate mode due to various glitches.</remarks>
/// <remarks>When a player is in spectate mode their HUD is hidden, making it useful for setting a player's camera without the HUD. Also, objects near the player's camera will be streamed in, making this useful for interpolating cameras.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The player does not exist.
/// </returns>
native TogglePlayerSpectating(playerid, bool:toggle);

/// <summary>Makes a player spectate (watch) another player.</summary>
/// <param name="playerid">The ID of the player that will spectate</param>
/// <param name="targetid">The ID of the player that should be spectated</param>
/// <param name="mode">The mode to spectate with (optional=<b><c>SPECTATE_MODE_NORMAL</c></b>)</param>
/// <seealso name="PlayerSpectateVehicle" />
/// <seealso name="TogglePlayerSpectating" />
/// <remarks>Order is CRITICAL! Ensure that you use <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a> before <a href="#PlayerSpectatePlayer">PlayerSpectatePlayer</a>. </remarks>
/// <remarks>playerid and targetid's virtual world and interior must be the same for this function to work properly. </remarks>
/// <remarks>
///   <b>Spectate modes:</b><br />
///   <ul>
///     <li><b><c>SPECTATE_MODE_NORMAL</c></b> - normal spectate mode (third person point of view). Camera can not be changed.</li>
///     <li><b><c>SPECTATE_MODE_FIXED </c></b> - use SetPlayerCameraPos after this to position the player's camera, and it will track the player/vehicle set with PlayerSpectatePlayer/PlayerSpectateVehicle.</li>
///     <li><b><c>SPECTATE_MODE_SIDE</c></b> - the camera will be attached to the side of the player/vehicle (like when you're in first-person camera on a bike and you do a wheelie).</li>
///   </ul>
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. One of the players specified does not exist.
/// </returns>
native PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL);

/// <summary>Sets a player to spectate another vehicle. Their camera will be attached to the vehicle as if they are driving it.</summary>
/// <param name="playerid">The ID of the player who should spectate a vehicle</param>
/// <param name="targetid">The ID of the vehicle the player should spectate</param>
/// <param name="mode">The spectate mode. Can generally be left blank as it defaults to 'normal'</param>
/// <seealso name="PlayerSpectatePlayer" />
/// <seealso name="TogglePlayerSpectating" />
/// <remarks>Order is CRITICAL! Ensure that you use <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a> before <a href="#PlayerSpectatePlayer">PlayerSpectatePlayer</a>. </remarks>
/// <remarks>playerid and targetid have to be in the same interior for this function to work properly. </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Note that success is reported if the player is not in spectator mode (<a href="#TogglePlayerSpectating">TogglePlayerSpectating</a>), but nothing will happen. <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a> MUST be used first.<br />
///   <b><c>0</c></b>: The function failed to execute. The player, vehicle, or both don't exist.
/// </returns>
native PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL);

/// <summary>Starts recording a player's movements to a file, which can then be reproduced by an NPC.</summary>
/// <param name="playerid">The ID of the player to record</param>
/// <param name="recordType">The type of recording</param>
/// <param name="recordFile">The name of the file which will hold the recorded data. It will be saved in the scriptfiles directory, with an automatically added .rec extension, you will need to move the file to npcmodes/recordings to use for playback</param>
/// <seealso name="StopRecordingPlayerData" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, const recordFile[]);

/// <summary>Stops all the recordings that had been started with <a href="#StartRecordingPlayerData">StartRecordingPlayerData</a> for a specific player.</summary>
/// <param name="playerid">The player you want to stop the recordings of</param>
/// <seealso name="StartRecordingPlayerData" />
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native StopRecordingPlayerData(playerid);

/// <summary>Display the cursor and allow the player to select a textdraw.</summary>
/// <param name="playerid">The ID of the player that should be able to select a textdraw</param>
/// <param name="hoverColour">The colour of the textdraw when hovering over with mouse (<b>RGBA</b>)</param>
/// <seealso name="CancelSelectTextDraw" />
/// <seealso name="TextDrawSetSelectable" />
/// <seealso name="PlayerTextDrawSetSelectable" />
/// <seealso name="OnPlayerClickTextDraw" />
/// <seealso name="OnPlayerClickPlayerTextDraw" />
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks><a href="#TextDrawSetSelectable">TextDrawSetSelectable</a> or <a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a> MUST be used first, to allow a textdraw to be selectable.</remarks>
/// <remarks>It is the TEXT which will be highlighted when hovered over, NOT the box (if one is shown).</remarks>
native SelectTextDraw(playerid, hoverColour); // enables the mouse so the player can select a textdraw

/// <summary>Cancel textdraw selection with the mouse.</summary>
/// <param name="playerid">The ID of the player that should be the textdraw selection disabled</param>
/// <seealso name="SelectTextDraw" />
/// <seealso name="TextDrawSetSelectable" />
/// <seealso name="OnPlayerClickTextDraw" />
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>This function calls <a href="#OnPlayerClickTextDraw">OnPlayerClickTextDraw</a> with <b><c>INVALID_TEXT_DRAW</c></b> (<b><c>65535</c></b>). Using this function inside <a href="#OnPlayerClickTextDraw">OnPlayerClickTextDraw</a> without catching this case will cause clients to go into an infinite loop.</remarks>
native CancelSelectTextDraw(playerid);	// cancel textdraw selection with the mouse

// Explosion

/// <summary>Creates an explosion that is only visible to a single player. This can be used to isolate explosions from other players or to make them only appear in specific <a href="http://wiki.sa-mp.com/wiki/SetPlayerVirtualWorld">virtual worlds</a>.</summary>
/// <param name="playerid">The ID of the player to create the explosion for</param>
/// <param name="x">The x coordinate of the explosion</param>
/// <param name="y">The y coordinate of the explosion</param>
/// <param name="z">The z coordinate of the explosion</param>
/// <param name="type">The explosion type</param>
/// <param name="radius">The radius of the explosion</param>
/// <seealso name="CreateExplosion" />
/// <remarks>This function was added in <b>SA-MP 0.3z R2-2</b> and will not work in earlier versions!</remarks>
/// <remarks>There is a limit as to how many explosions can be seen at once by a player. This is roughly 10.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the function failed to excute (player doesn't exist, invalid radius, or invalid explosion type).</returns>
native CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius);

/// <summary>Perform a memory check on the client.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <param name="type">The type of check to perform</param>
/// <param name="memoryAddress">The base address to check</param>
/// <param name="memoryOffset">The offset from the base address</param>
/// <param name="byteCount">The number of bytes to check</param>
native SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount);

