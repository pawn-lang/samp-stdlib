# samp-stdlib

The San Andreas Multiplayer Pawn Standard Library Package - designed for the
[sampctl package management system](http://sampctl.com).

The current latest version is **0.3.7-R2-2-1**.

The master branch HEAD does not currently contain any RC libaries.

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
