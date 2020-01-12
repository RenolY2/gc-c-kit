# gc-c-kit
A toolkit for compiling C code using devkitppc and injecting it into a Gamecube Executable (dol). 
It has been written in such a way that it can be adapted to different GC games.

# How to use it 
You need Python 3 and devkitppc installed. Check the paths at the top of devkit_tools.py as to
where devkitppc needs to exist.

project.py is the main project file that handles the following things:
* setting up patching the game executable (DOL) 
* setting which .c file to compile
* setting if gecko codes from a file should be patched into the dol (only 00, 02, 04, 06 and C6 codetypes are supported)
* setting up branchlink and branch instructions for hooking into the game's functions
* building the new DOL 

You need to run project.py to compile and inject code into the DOL.

Example files are included for educational use. You can look at them for further explanations and to get 
an idea of how to structure your files for adapting to a different game:
*gameSymbols.txt
*geckopatches.txt
*main.c
*headers/example.h 

Special thanks to masterf0x and his Super Mario Sunshine C Kit. It is where I took inspiration 
and the devkitppc calls from to create this Python-based C Kit. 
