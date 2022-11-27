# samp-stdlib

The San Andreas Multiplayer Pawn Standard Library Package - designed for the
[sampctl package management system](http://sampctl.com).

The current latest version is **0.3.7-R2-2-1**.

The master branch HEAD does not currently contain any RC libaries.

## Why?

The package management system built into the `sampctl` tool is based on GitHub
(Similar to that of the Go language) so it simplifies the process to have the
standard library stored here on GitHub too. This means there doesn't need to be
any special-case code written for the standard library, it can just be a package
like all others.

## Const-Correctness

Some functions, like `SendRconCommand`, take strings; some functions, like `GetPlayerName`, modify strings.  These are different operations with different considerations.  Consider the following code:

```pawn
GetPlayerName(playerid, "Bob");
```

This code doesn't make any sense.  "Bob" is a string literal, you can't store someone's name in to the word `"Bob"`, it would be like trying to do:

```pawn
"Bob" = GetPlayerName(playerid);
```

`"Bob"` is a *constant*, it is a value fixed by the compiler that can't be modified at runtime.  `GetPlayerName` modifies its values at runtime, so cannot take a constant only a variable.  For this reason it is declared as:

```pawn
native GetPlayerName(playerid, name[], size = sizeof (name));
```

But what of `SendRconCommand`?  The following *is* valid:

```pawn
SendRconCommand("loadfs objects");
```

`SendRconCommand` does not return a string, it doesn't modify the value passed in.  If it were declared in the same way as `GetPlayerName` it would have to take a variable that could be modified:

```pawn
native SendRconCommand(cmd[]);
new cmd[] = "loadfs objects";
// `cmd` must be modifiable because `SendRconCommand` doesn't say it won't.
SendRconCommand(cmd);
```

This is cumbersome and pointless.  Again, we know that `SendRconCommand` cannot change the data given, so we tell the compiler this as well.  Anything between `""`s is a *constant*, so make `SendRconCommand` accept them with `const`:

```pawn
native SendRconCommand(const cmd[]);
// Allowed again because we know this call won't modify the string.
SendRconCommand("loadfs objects");
```

This is called *const correctness* - using `const` when data will not be modified, and not using `const` when the parameter will be modified.  This is mainly only useful for strings and arrays (differentiated in the includes by the use of a `string:` tag) as they are pass-by-reference, but when in doubt use the rules on normal numbers as well.

Functions that are `const` can also take variables which may be modified.  `const` means the function promises not modify the variable (`GetPlayerName` in the SA:MP includes incorrectly used `const` and broke this promise), but that doesn't mean you can't pass varaibles that don't mind being modified - there's no such thing as a variable that *must* be modified:

```pawn
native SendRconCommand(const string:cmd[]);
new cmd[32];
format(cmd, _, "loadfs %s", scriptName);
// `cmd` is allowed to be modified, but `SendRconCommand` won't do so.
SendRconCommand(cmd);
```

As a side note, the following code is now also a warning:

```pawn
Func(const &var)
{
	printf("%d", var);
}
```

`const` means a variable can't be modified, while `&` means it can.  Since modifiying a normal variable is the only reason to pass it by reference adding `const` to the declaration is, as with all warnings, probably a mistake.

## More Tags

The latest version of the SA:MP includes introduce many more tags to functions and callbacks.  These are useful in the long run, but slightly annoying to upgrade to.  There are three symbols:  `NO_TAGS`, `WEAK_TAGS`, and `STRONG_TAGS`; that you can define before including `<a_samp>`, each one enabling progressively more checks:

```pawn
#define STRONG_TAGS
#include <a_samp>
```

To encourage some adoption, the default is `WEAK_TAGS`.  Most old code uses will simply give a warning when the wrong tag is found:

```pawn
// Gives a warning:
SetPlayerControllable(playerid, 1);

// Should be:
SetPlayerControllable(playerid, true);
```

Generally parameters that only accept a limited range of values (for example, object attachment bones) are now all enumerations so that passing invalid values gives a warning:

```pawn
TextDrawAlignment(textid, TEXT_DRAW_ALIGN_LEFT); // Fine
TextDrawFont(textid, 7); // Warning
```

Functions that take or return just `true`/`false` all have `bool:` tags.  More functions than might be expected return booleans; most player functions return `true` when they succeed and `false` when the player is not connected, sometimes skipping the need for `IsPlayerConnected`:

```pawn
new Float:x, Float:y, Float:z;
// If the player is connected get their position.
if (GetPlayerPos(playerid, x, y, z))
{
	// Timer repeats are on or off, so booleans.
	SetTimer("TimerFunc", 1000, false);
}
```

In cases where there were existing defines already for valid values (like `OBJECT_MATERIAL_SIZE_512x64`) these names have been reused for the enumerations and thus tagged.  Therefore code that already made use of the defines will continue to operate correctly, and code that wishes to remain backwards-compatible can start using the names in place of (usually) bare numbers (so always put `OBJECT_MATERIAL_TEXT_ALIGN_LEFT` instead of `0`).

For parameters the default is to make these new tags *weak*, meaning that you get warnings when passing untagged values to tagged parameters, but not the other way around.  This applies to function returns so saving a tag result in an untagged variable will not give a warning.  This second group can also be upgraded by specifying the use of *strong* tags instead:

```pawn
#define STRONG_TAGS
#include <a_samp>
```

Alternatively, if you really hate help:

```pawn
#define NO_TAGS
#include <a_samp>
```

The only breaking change introduced by these new tags are on callbacks.  For some reason tag mismatch warnings in function prototypes are an error, not a warning (probably because of code generation issues related to overloaded operators).  The best way to deal with these is to ensure that the `public` part of the callback will compile regardless of tag settings by falling back to `_:` when none is specified:

```pawn
#if !defined SELECT_OBJECT
	#define SELECT_OBJECT: _:
#endif
forward OnPlayerSelectObject(playerid, SELECT_OBJECT:type, objectid, modelid, Float:fX, Float:fY, Float:fZ);
```

See lower down for a full list of all updated callbacks.  This is the main problem change, but it is important to note that the following code will work with any include, with or without the new tags:

```pawn
#if !defined CLICK_SOURCE
	#define CLICK_SOURCE: _:
#endif
public OnPlayerClickPlayer(playerid, clickedplayerid, CLICK_SOURCE:source)
{
	return 1;
}
```

Thus writing backwards-compatible code remains possible.  Forward for ALS as normal:

```pawn
#if !defined PLAYER_STATE
	// Use the default tag (none, `_:`) when the improved includes aren't found.
	#define PLAYER_STATE: _:
#endif
public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
	return Hooked_OnPlayerStateChange(playerid, newstate, oldstate);
}

forward Hooked_OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);
```

### Tag Warning Example

```pawn
if (GetPVarType(playerid, "MY_DATA") == 1)
{
	printf("Found an int");
}
```

This code is correct, and will give the correct answer, so why add warnings?

```pawn
switch (GetPVarType(playerid, "MY_DATA"))
{
case 0:
	printf("Unknown type");
case 1:
	printf("Found an int");
case 2:
	printf("Found a float");
case 3:
	printf("Found a string");
case 4:
	printf("Found a boolean");
}
```

This code is subtly wrong, take a moment to try and work out how - the compiler will not help you.

It could take a lot of testing and debugging to find the problem here without a lot of familiarity with the functions in question, fortunately the a_samp includes now return a `VARTYPE:` tag from `GetPVarType` and this code will give tag-mismatch warnings.  Once we try and fix the warnings using the defined constants the mistakes become instantly obvious:

```pawn
switch (GetPVarType(playerid, "MY_DATA"))
{
case PLAYER_VARTYPE_NONE:
	printf("Unknown type");
case PLAYER_VARTYPE_INT:
	printf("Found an int");
case PLAYER_VARTYPE_STRING:
	printf("Found a float");
case PLAYER_VARTYPE_FLOAT:
	printf("Found a string");
case PLAYER_VARTYPE_BOOL:
	printf("Found a boolean");
}
```

The string/float mixup still needs some manual review, but it is now far more obvious that those two are the wrong way around.  In fact there's a good chance that the person updating the code would have used them the correct way round without even realising that they have now fixed a prior bug.  The `VARTYPE_BOOL:` line will give an error that the symbol doesn't exist because there is no type `4`.  The old code quite happily compiled without issues and had an impossible branch.  The effects aren't serious in this example, but they could be.  But, again, the old code will still compile and run.  More warnings help to highlight issues, they do not introduce new ones.

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

* `OnPlayerRequestDownload`

```pawn
#if !defined DOWNLOAD_REQUEST
	#define DOWNLOAD_REQUEST: _:
#endif
forward OnPlayerRequestDownload(playerid, DOWNLOAD_REQUEST:type, crc);
```

### Streamer Plugin

There is a PR to extend these improved checks to the streamer plugin as well: https://github.com/samp-incognito/samp-streamer-plugin/pull/435  This PR includes more information on the tags.

* `Streamer_OnItemStreamIn`

```pawn
#if !defined STREAMER_TYPE
	#define STREAMER_TYPE: _:
#endif
public Streamer_OnItemStreamIn(STREAMER_TYPE:type, STREAMER_ALL_TAGS:id, forplayerid)
{
}
```

* `Streamer_OnItemStreamOut`

```pawn
#if !defined STREAMER_TYPE
	#define STREAMER_TYPE: _:
#endif
public Streamer_OnItemStreamOut(STREAMER_TYPE:type, STREAMER_ALL_TAGS:id, forplayerid)
{
}
```

### Upgrade Tool

Y_Less has been working on a tool to make porting code easier, here:

https://github.com/openmultiplayer/upgrade

This can scan all pawn files (`.inc`, `.p`, `.pawn`, `.pwn`) in a directory and search for function calls that look like the ones in these includes with new tags.  It will find hook declarations following a standard `Lib_Native` naming scheme where `Native` is one known to have been enhanced, and thus upgrade these hooks automatically.  It will also find many calls to the upgraded natives using bare numbers, so for example:

```pawn
SetTimer("MyFunction", 1000, 0);
```

Will be found and replaced by:

```pawn
SetTimer("MyFunction", 1000, false);
```

See the readme with the tool for more information, including adding your own upgrades, and checking output before applying the changes (always make backups first).

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
