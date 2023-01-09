 samp-stdlib
=============

The San Andreas Multiplayer Pawn Standard Library Package as a wrapper for those provided in open.mp
Designed for the [sampctl package management system](http://sampctl.com).

 Why?
------

The package management system built into the `sampctl` tool is based on GitHub (similar to that of
the Go language) so it simplifies the process to have the standard library stored here on GitHub
too.  This means there doesn't need to be any special-case code written for the standard library, it
can just be a package like all others.

 Using omp-stdlib
------------------

Many legacy libraries using sampctl will reference `samp-stdlib` and `pawn-stdlib` directly, which open.mp replaces entirely.  We need to trick sampctl in to not downloading those libraries so that that one takes precedence.  A new `@open.mp` branch has been added to both projects to achieve this.  They are completely empty so there are no duplicates of files.  Using this tag version in `pawn.json` in your project will ensure that and other dependencies including those libraries transitively will use the same tag, and then including `<open.mp>` in your main file will correctly set all the requisite defines to appear to those libraries like you have included `<a_samp>`.  Basically your `pawn.json` should first include:

```json
	"dependencies": [
		"openmultiplayer/omp-stdlib",
		"pawn-lang/samp-stdlib@open.mp",
		"pawn-lang/pawn-stdlib@open.mp"
	],
```

All other dependencies go ***after*** these three lines.

