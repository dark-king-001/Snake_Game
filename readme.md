Introduction
This tutorial is the first one you should read if you're using SFML on Linux. It will explain how to install SFML, and compile projects that use it.

Installing SFML
There are different approaches to the installation of SFML on Linux:

Install it directly from your distribution's package repository
Get the source code, build it and install it
Download the precompiled SDK and manually copy the files
Option 1 is the preferred one; if the version of SFML that you want to install is available in the official repository, then install it using your package manager. For example, on Debian you would do:

sudo apt-get install libsfml-dev
Option 2 requires more work: you need to ensure all of SFML's dependencies including their development headers are available, make sure CMake is installed, and manually execute some commands. This will result in a package which is tailored to your system.
If you want to go this way, there's a dedicated tutorial on building SFML yourself.

Finally, option 3 is a good choice for quick installation if SFML is not available as an official package. Download the SDK from the download page, unpack it and copy the files to your preferred location: either a separate path in your personal folder (like /home/me/sfml), or a standard path (like /usr/local).

If you already had an older version of SFML installed, make sure that it won't conflict with the new version!

