Gitian building
================

*Setup instructions for a Gitian build of Fujicoin Core using a VM or physical system.*

Gitian is the deterministic build process that is used to build the Fujicoin
Core executables. It provides a way to be reasonably sure that the
executables are really built from the git source. It also makes sure that
the same, tested dependencies are used and statically built into the executable.

Multiple developers build the source code by following a specific descriptor
("recipe"), cryptographically sign the result, and upload the resulting signature.
These results are compared and only if they match, the build is accepted and provided
for download.

More independent Gitian builders are needed, which is why this guide exists.
It is preferred you follow these steps yourself instead of using someone else's
VM image to avoid 'contaminating' the build.

Table of Contents
------------------

- [Preparing the Gitian builder host](#preparing-the-gitian-builder-host)
- [Getting and building the inputs](#getting-and-building-the-inputs)
- [Building Fujicoin Core](#building-bitzeny-core)

Preparing the Gitian builder host
---------------------------------

The first step is to prepare the host environment that will be used to perform the Gitian builds.
This guide explains how to set up the environment, and how to start the builds.

Gitian builds are known to be working on recent versions of Ubuntu.
If your machine is already running Ubuntu 18.04, you can perform Gitian builds on the actual hardware.
Alternatively, you can install one of the supported operating systems in a virtual machine.

Please refer to the following documents to set up the operating systems and Gitian.

|                                   | Ubuntu 18.04.                                                                            |
|-----------------------------------|------------------------------------------------------------------------------------|
| Setup virtual machine (optional)  | [Create Ubuntu VirtualBox](./gitian-building/gitian-building-create-vm-debian.md) |
| Setup Gitian                      | [Setup Gitian on Ubuntu](./gitian-building/gitian-building-setup-gitian-debian.md) |

Note that a version of `lxc-execute` higher or equal to 2.1.1 is required.
You can check the version with `lxc-execute --version`.
On Ubuntu 18.04.1 or higher you might have to compile a suitable version of lxc.

MacOS code signing
------------------
In order to sign builds for MacOS, you need to download the free SDK and extract a file. The steps are described [here](./gitian-building/gitian-building-mac-os-sdk.md). Alternatively, you can skip the OSX build by adding `--os=lw` below.

Initial Gitian Setup
--------------------
The `gitian-build.py` script will checkout different release tags, so it's best to copy it:

```
cp bitzeny/contrib/gitian-build.py .
```

You only need to do this once:

```
./gitian-build.py --setup satoshi z0.16.3
```
`reboot` is required.

By default, base VM of Ubuntu bionic will be created.

Where `satoshi` is your Github name and `z0.16.3` is the most recent tag. 

Build binaries
--------------
Windows and OSX have code signed binaries, but those won't be available until a few developers have gitian signed the non-codesigned binaries.

To build the most recent tag:

All:

 `./gitian-build.py --detach-sign --no-commit -b satoshi z0.16.3`

Linux:

 `./gitian-build.py --detach-sign --no-commit -b -o l satoshi z0.16.3`

Windows:

 `./gitian-build.py --detach-sign --no-commit -b -o w satoshi z0.16.3`

OSX:

 `./gitian-build.py --detach-sign --no-commit -b -o m satoshi z0.16.3`

How to see options:

`./gitian-build.py --help`

To speed up the build, use `-j 5 -m 5000` as the first arguments, where `5` is the number of CPU's you allocated to the VM plus one, and 5000 is a little bit less than then the MB's of RAM you allocated.

Build core v0.16.3
------------------
Linux:

```
./gitian-build.py --setup --suite trusty satoshi z0.16.3
./gitian-build.py --detach-sign --no-commit -b -o l satoshi z0.16.3
```

Windows:

```
./gitian-build.py --setup --suite bionic satoshi z0.16.3
./gitian-build.py --detach-sign --no-commit -b -o w satoshi z0.16.3
```

OSX:

```
./gitian-build.py --setup --suite trusty satoshi z0.16.3
./gitian-build.py --detach-sign --no-commit -b -o m satoshi z0.16.3
```

Note
----

- Do not run other programs as much as possible. It may be better to stop anti-virus as well.
- It is better to recreate the new gitian-builder folder before starting the next build operation. In that case, backing up the gitian-builder folder after setup can shorten the time.
