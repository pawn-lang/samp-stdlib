# samp-stdlib

The San Andreas Multiplayer Pawn Standard Library Package - designed for the
[sampctl package management system](http://sampctl.com).

The current latest version is **0.3.7-R2-2-1**.

The master branch HEAD does not currently contain any RC libaries.

## Tags

The latest version of the SA:MP includes introduce many more tags to functions and callbacks.  These
are useful in the long run, but slightly annoying to upgrade to.  There are three symbols:
`NO_TAGS`, `WEAK_TAGS`, and `STRONG_TAGS`; that you can define before including `<a_samp>`, each one
enabling progressively more checks:

```pawn
#define STRONG_TAGS
#include <a_samp>
```

To encourage some adoption, the default is `WEAK_TAGS`.  Most old code uses will simply give a
warning when the wrong tag is found:

```pawn
// Gives a warning:
SetPlayerControllable(playerid, 1);

// Should be:
SetPlayerControllable(playerid, true);
```

However, there's a problem - callbacks give an error:

```pawn
forward OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);

public OnPlayerStateChange(playerid, newstate, oldstate)
{
}
```

This gives an error, when it should be fine.  Fixing it in a mode is easy - just use the correct
tags on the variables in the callbacks.  Fixing it in a generic library needs a few extra lines to
define a default tag when one isn't found (i.e. the user isn't using the improved includes):

```pawn
#if !defined PLAYER_STATE
	// Use the default tag (none, `_:`) when the improved includes aren't found.
	#define PLAYER_STATE: _:
#endif
public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
	return Hooked_OnPlayerStateChange(playerid, newstate, oldstate);
}

// Don't forget to use ALS as normal.
forward Hooked_OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);
```

### Complete List

* `OnPlayerStateChange`

```pawn
#if !defined PLAYER_STATE
	#define PLAYER_STATE: _:
#endif
forward OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);
```

* `OnPlayerClickPlayer`

```pawn
#if !defined CLICK_SOURCE
	#define CLICK_SOURCE: _:
#endif
forward OnPlayerClickPlayer(playerid, clickedplayerid, CLICK_SOURCE:source);
```

* `OnPlayerEditObject`

```pawn
#if !defined EDIT_RESPONSE
	#define EDIT_RESPONSE: _:
#endif
forward OnPlayerEditObject(playerid, playerobject, objectid, EDIT_RESPONSE:response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ);
```

* `OnPlayerEditAttachedObject`

```pawn
#if !defined EDIT_RESPONSE
	#define EDIT_RESPONSE: _:
#endif
forward OnPlayerEditAttachedObject(playerid, EDIT_RESPONSE:response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ);
```

* `OnPlayerSelectObject`

```pawn
#if !defined SELECT_OBJECT
	#define SELECT_OBJECT: _:
#endif
forward OnPlayerSelectObject(playerid, SELECT_OBJECT:type, objectid, modelid, Float:fX, Float:fY, Float:fZ);
```

* `OnPlayerWeaponShot`

```pawn
#if !defined BULLET_HIT_TYPE
	#define BULLET_HIT_TYPE: _:
#endif
forward OnPlayerWeaponShot(playerid, weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ);
```

* `OnPlayerKeyStateChange`

```pawn
#if !defined KEY
	#define KEY: _:
#endif
forward OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys);
```

## Why?

The package management system built into the `sampctl` tool is based on GitHub
(Simiar to that of the Go language) so it simplifies the process to have the
standard library stored here on GitHub too. This means there doesn't need to be
any special-case code written for the standard library, it can just be a package
like all others.

## How Do Versions Work?

### Versions are represented by [Git Tags](https://help.github.com/articles/working-with-tags/)

Always specify a version when working with sampctl. To depend on the latest
version, simply use `sampctl/samp-stdlib:0.3.7-R2-2-1` as a dependency.

### What happens during Release Candidates (RCs)?

The `master` branch will contain RC libraries if there is an active RC. The most
recent RC was 0.3.8, but since this was cancelled, this repository contains no
0.3.8 RC libraries.

### Version tags are fully compatible with [sampctl](https://github.com/Southclaws/sampctl/wiki/Dependencies#versioning)

[sampctl](http://bit.ly/sampctl) simplifies version control, this repository
exists to help sampctl users who work with multiple SA:MP server versions.

### Versioning starts at 0.3z (specifically, 0.3z-R1)

0.3z is the earliest version supported by [sampctl](http://bit.ly/sampctl). Most
servers use the latest version so it didn't seem worth archiving every SA:MP
library version.

### Some tags point to the same commit

Some releases only changed the server's internals and never touched the
libraries. In these cases, the version tags still exist in this repo but they
simply point to the same commit.
