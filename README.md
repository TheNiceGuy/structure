structure
=======

This repository contains all of the project that I made during my c++ class.

Dependencies
------------

It order to use all the script, you'll need to install those dependencies:

- gcc
- make
- valgrind
- mingw
- wine
- gdb (optional)

Usage
-----

There is a couple of scripts in order to facilitate the workflow. The script `create` creates a project based on the template folder. The script `run` can execute a project from the root of the repository. Finaly, the script `clean` removes unused files that are left everywhere during the compilation process.

The most important script is `run`. It takes the path of a folder containing a `makefile` like this:

	$ ./run semaine-04/project-02

It supports some options too. It can debug using `valgrind` as follow:

	$ ./run --debug semaine-04/project-02

If needed, it can compile all the project in the repository with `--buildall`. It does not take a path since it does not execute something:

	$ ./run --buildall

The script even sends environment variables to the makefile. In order to change the compiler/linker, one can use those commands:

	$ export CC="clang++"
	$ export LD="clang++"
	$ ./run semaine-03/lab-02

Which can be written into a line:

	$ CC="clang++" LD="clang++" ./run semaine-03/lab-02

The debugger can be changed from `valgrind` to `gdb` using that command:

	$ DB="gdb" ./run ./run semaine-03/lab-02

It can cross-compile for Windows using `mingw`. Then, it executes the Windows binary with `wine`. It does not support debugging. This example would override any `$CC` or `$LD` that has been set:

	$ TARGET="win32" ./run semaine-03/lab-02

If needed, it can pass compiler's/linker's options to the makefile. Keep in mind that it would better to put these directly into the `makefile`.

	$ CCFLAGS="-g -W" LDFLAGS="-static" ./run semaine-02/project-03

For quick information, use:

	./run --help
