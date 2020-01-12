from devkit_tools import Project 
from doltools import write_lis, write_ori

def patch_osarena_low(dol, size):
    #dol.seek(0x800e5c9c)
    dol.seek(0x800E5CD4)
    write_lis(dol, 3, size >> 16, signed=False)
    write_ori(dol, 3, 3, size & 0xFFFF)
    
    print("New size", hex(size))

p = Project("mkdd.dol", address=0x803e2300)#address=0x803e4300)
p.set_osarena_patcher(patch_osarena_low)

p.add_file("main.c")

#p.apply_gecko("geckopatches.txt")
p.branchlink(0x801FBE20, "onSetItemboxTrigger")
p.branchlink(0x8020CBC4, "onItemShuffle")
p.branchlink(0x8019A6BC, "onItemCarHitProc")
p.branchlink(0x80198D50, "onSpawnMushroomFromCarHit")
p.add_linker_file("mkddSymbols.txt")

p.build("D:\\Wii games\\MKDDModdedFolder\\P-GM4E\\sys\\main.dol")
