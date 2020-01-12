from devkit_tools import Project 
from doltools import write_lis, write_ori

def patch_osarena_low(dol, size):
    # Assuming the two instructions setting up the OSArenaLo location 
    # exist at address 0x800E5CD4 in the DOL, we change the value.
    # Example: If the old OSArenaLo value was 0x803e2300 and we are 
    # inserting our code at 0x803e2300 then the new OSArenaLo value
    # will be the value of size (which is actually 0x803e2300+size of injected code+data)
    dol.seek(0x800E5CD4)
    write_lis(dol, 3, size >> 16, signed=False)
    write_ori(dol, 3, 3, size & 0xFFFF)

# This is the original dol we are patching and we want our code to be inserted
# at the location the old OSArenaLo value was pointing to, e.g. 0x803e2300
p = Project("mygame.dol", address=0x803e2300)

# Set the patching function
p.set_osarena_patcher(patch_osarena_low)

# The main file that has the code that should be inserted 
p.add_file("main.c")

# Apply gecko patches if there are any. 00, 02, 04, 06 and C6 codetypes are supported.
p.apply_gecko("geckopatches.txt")

# Set up the hook. Hijacking existing branchlinks is a good idea.
p.branchlink(0x801FBE20, "onSomeGameActionHappens")
# It's also possible to replace functions by inserting a branch instead of 
# a branchlink. That is a good idea for dummy functions that don't do anything 
# by themselves.

# Add linker file which is necessary if you want to call any of the game's functions
p.add_linker_file("gameSymbols.txt")

# Create new dol file. Code will be compiled and injected.
p.build("newgame.dol")
