/*  SA-MP Actor Functions
 *
 *  (c) Copyright 2015, SA-MP Team
 *
 */

#if defined _INC_a_actor
	#endinput
#endif
#define _INC_a_actor
#define _actor_included

#define SAMP_CONST_CORRECT

#pragma tabsize 4

/// <summary>Create a static 'actor' in the world. These 'actors' are like NPCs, however they have limited functionality. They do not take up server player slots.</summary>
/// <param name="modelid">The model ID (skin ID) the actor should have</param>
/// <param name="x">The x coordinate to create the actor at</param>
/// <param name="y">The y coordinate to create the actor at</param>
/// <param name="z">The z coordinate to create the actor at</param>
/// <param name="angle">The facing angle (rotation) for the actor to have</param>
/// <seealso name="DestroyActor" />
/// <seealso name="SetActorPos" />
/// <seealso name="GetActorPos" />
/// <seealso name="SetActorFacingAngle" />
/// <seealso name="GetActorFacingAngle" />
/// <seealso name="SetActorVirtualWorld" />
/// <seealso name="GetActorVirtualWorld" />
/// <seealso name="ApplyActorAnimation" />
/// <seealso name="ClearActorAnimations" />
/// <seealso name="GetPlayerCameraTargetActor" />
/// <seealso name="IsActorStreamedIn" />
/// <seealso name="SetActorHealth" />
/// <seealso name="GetActorHealth" />
/// <seealso name="SetActorInvulnerable" />
/// <seealso name="IsActorInvulnerable" />
/// <seealso name="IsValidActor" />
/// <seealso name="GetActorPoolSize" />
/// <seealso name="GetPlayerTargetActor" />
/// <seealso name="OnActorStreamIn" />
/// <seealso name="OnActorStreamOut" />
/// <seealso name="OnPlayerGiveDamageActor" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   Actors are completely separate from NPCs. They do NOT use player IDs/slots on the server and CANNOT be handled like NPCs.<br />
///   Actors are limited to <b><c>1000</c></b> (<b><c>MAX_ACTORS</c></b>).<br />
///   Actors can be pushed by vehicles, use a timer to put them back at their positions.<br />
///   As of <b>0.3.7 R2</b> actors default to being <a href="http://wiki.sa-mp.com/wiki/SetActorInvulnerable">invulnerable</a>.
/// </remarks>
/// <returns>
///   The created Actor ID (start at <b><c>0</c></b>).<br />
///   <b><c>INVALID_ACTOR_ID</c></b> (<b><c>65535</c></b>) If the actor limit (<b><c>1000</c></b>) is reached.
/// </returns>
native CreateActor(modelid, Float:x, Float:y, Float:z, Float:angle);

/// <summary>Destroy an actor which was created with <a href="#CreateActor">CreateActor</a>.</summary>
/// <param name="actorid">The ID of the actor to destroy. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <seealso name="CreateActor" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The actor with the ID specified does not exist.
/// </returns>
native DestroyActor(actorid);

/// <summary>Checks if an actor is streamed in for a player.</summary>
/// <param name="actorid">The ID of the actor</param>
/// <param name="playerid">The ID of the player</param>
/// <seealso name="CreateActor" />
/// <seealso name="IsPlayerStreamedIn" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the actor is streamed in for the player, or <b><c>0</c></b> if it is not.</returns>
native bool:IsActorStreamedIn(actorid, playerid);

/// <summary>Set the virtual world of an actor. Only players in the same world will see the actor.</summary>
/// <param name="actorid">The ID of the actor (returned by <a href="#CreateActor">CreateActor</a>) to set the virtual world of</param>
/// <param name="virtualWorld">The virtual world to put the actor ID</param>
/// <seealso name="GetActorVirtualWorld" />
/// <seealso name="CreateActor" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native SetActorVirtualWorld(actorid, virtualWorld);

/// <summary>Get the virtual world of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the virtual world of</param>
/// <seealso name="SetActorVirtualWorld" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>The virtual world of the actor. By default this is <b><c>0</c></b>. Also returns <b><c>0</c></b> if actor specified does not exist.</returns>
native GetActorVirtualWorld(actorid);

/// <summary>Apply an animation to an actor.</summary>
/// <param name="actorid">The ID of the actor to apply the animation to</param>
/// <param name="animationLibrary">The animation library from which to apply an animation</param>
/// <param name="animationName">The name of the animation to apply, within the specified library</param>
/// <param name="delta">The speed to play the animation (use <b><c>4.1</c></b>)</param>
/// <param name="loop">If set to <b><c>1</c></b>, the animation will loop. If set to <b><c>0</c></b>, the animation will play once</param>
/// <param name="lockX">If set to <b><c>0</c></b>, the actor is returned to their old x coordinate once the animation is complete (for animations that move the actor such as walking). <b><c>1</c></b> will not return them to their old position</param>
/// <param name="lockY">Same as above but for the y axis. Should be kept the same as the previous parameter</param>
/// <param name="freeze">Setting this to <b><c>1</c></b> will freeze an actor at the end of the animation. <b><c>0</c></b> will not</param>
/// <param name="time">Timer in milliseconds. For a never-ending loop it should be <b><c>0</c></b></param>
/// <seealso name="ClearActorAnimations" />
/// <remarks>You must preload the animation library for the player the actor will be applying the animation for, and not for the actor. Otherwise, the animation won't be applied to the actor until the function is executed again.</remarks>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
/// <b><c>1</c></b>: The function executed successfully.<br />
/// <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native ApplyActorAnimation(actorid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time);

/// <summary>Clear any animations applied to an actor.</summary>
/// <param name="actorid">The ID of the actor (returned by <a href="#CreateActor">CreateActor</a>) to clear the animations for</param>
/// <seealso name="ApplyActorAnimation" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native ClearActorAnimations(actorid);

/// <summary>Set the position of an actor.</summary>
/// <param name="actorid">The ID of the actor to set the position of. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <param name="x">The x coordinate to position the actor at</param>
/// <param name="y">The y coordinate to position the actor at</param>
/// <param name="z">The z coordinate to position the actor at</param>
/// <seealso name="GetActorPos" />
/// <seealso name="CreateActor" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>When creating an actor with <a href="#CreateActor">CreateActor</a>, you specify it's position. You do not need to use this function unless you want to change its position later.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native SetActorPos(actorid, Float:x, Float:y, Float:z);

/// <summary>Get the position of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the position of. Returned by <a href="# CreateActor">CreateActor</a></param>
/// <param name="x">A float variable, passed by reference, in which to store the x coordinate of the actor</param>
/// <param name="y">A float variable, passed by reference, in which to store the y coordinate of the actor</param>
/// <param name="z">A float variable, passed by reference, in which to store the z coordinate of the actor</param>
/// <seealso name="SetActorPos" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.<br />
/// </returns>
native GetActorPos(actorid, &Float:x, &Float:y, &Float:z);

/// <summary>Set the facing angle of an actor.</summary>
/// <param name="actorid">The ID of the actor to set the facing angle of. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <param name="angle">The facing angle to set for the actor</param>
/// <seealso name="GetActorFacingAngle" />
/// <seealso name="SetActorPos" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>Players will see actor's facing angle changed only when it is restreamed to them.</remarks>
/// <remarks>When creating an actor with <a href="#CreateActor">CreateActor</a>, you specify it's facing angle. You do not need to use this function unless you want to change its facing angle later.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native SetActorFacingAngle(actorid, Float:angle);

/// <summary>Get the facing angle of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the facing angle of. Returned by <a href="#CreateActor">CreateActor</a></param>
/// <param name="angle">A float variable, passed by reference, in to which the actor's facing angle will be stored</param>
/// <seealso name="SetActorFacingAngle" />
/// <seealso name="GetActorPos" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<br />
///   <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native GetActorFacingAngle(actorid, &Float:angle);

/// <summary>Set the health of an actor.</summary>
/// <param name="actorid">The ID of the actor to set the health of</param>
/// <param name="health">The value to set the actors's health to</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b> on success.<br />
///   <b><c>0</c></b> on failure (i.e. actor is not created).
/// </returns>
native SetActorHealth(actorid, Float:health);

/// <summary>Get the health of an actor.</summary>
/// <param name="actorid">The ID of the actor to get the health of</param>
/// <param name="health">A float variable, passed by reference, in to which to store the actor's health</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b> - success.<br />
///   <b><c>0</c></b> - failure (i.e. actor is not created).<br />
/// </returns>
native GetActorHealth(actorid, &Float:health);

/// <summary>Toggle an actor's invulnerability.</summary>
/// <param name="actorid">The ID of the actor to set invulnerability</param>
/// <param name="invulnerable"><b><c>false</c></b> to make them vulnerable, <b><c>true</c></b> to make them invulnerable (optional=<b><c>true</c></b>)</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>Once set invulnerable, the actor does not call <a href="#OnPlayerGiveDamageActor">OnPlayerGiveDamageActor</a>.</remarks>
/// <remarks>Players will have actor's invulnerability state changed only when it is restreamed to them.</remarks>
/// <returns>
///   <b><c>1</c></b> - Success.<br />
///   <b><c>0</c></b> - Failure (i.e. Actor is not created).
/// </returns>
native SetActorInvulnerable(actorid, bool:invulnerable = true);

/// <summary>Check if an actor is invulnerable.</summary>
/// <param name="actorid">The ID of the actor to check</param>
/// <seealso name="CreateActor" />
/// <seealso name="SetActorInvulnerable" />
/// <seealso name="SetActorHealth" />
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the actor is invulnerable, <b><c>0</c></b> otherwise.</returns>
native bool:IsActorInvulnerable(actorid);

/// <summary>Checks if an actor ID is valid.</summary>
/// <param name="actorid">The ID of the actor to check</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the actor is valid, <b><c>0</c></b> if not.</returns>
native bool:IsValidActor(actorid);

