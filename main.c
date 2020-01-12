#include "headers/mkdd.h"

int player_itemrolls[] = { [0 ... 31] = -1};

void onSetItemboxTrigger(uint32* geogobjmgr, int player) {
    register struct GeoObject *itembox asm ("r29");
    GeographyObjManager__setKartHitItemBoxTrigger(geogobjmgr, player);
    OSReport("Player %i has hit an item box! The itembox that was hit is %x\n", player, itembox);
    struct SObject* sobj = itembox->sobj;
    OSReport("Itembox height: %i, parameter 4: %i \n", sobj->s16fixedpoint1, sobj->field_36);
    
    if (sobj->field_36 == 0) {
        player_itemrolls[player] = -1;
    }
    else {
        player_itemrolls[player] = sobj->field_36 - 1;
    }
}

int onItemShuffle(uint32* itemshufflemgr, uint32* kartrankdataset, int unk1, int unk2, bool unk3) {
    //OSReport("Do the item shuffle: %i %i %i\n", unk1, unk2, unk3);
    //OSReport("Hmm %x Player %x\n", *(kartrankdataset+8/4), *(kartrankdataset-8/4));
    int player = *(kartrankdataset-8/4);
    if (player_itemrolls[player] == -1)
        return ItemShuffleMgr__calcSlot(itemshufflemgr, kartrankdataset, unk1, unk2, unk3);
    else {
        return player_itemrolls[player];
    }
}

void onItemCarHitProc(int player, uint32** jpabaseemitter) {
    register struct GeoObject *itemcar asm ("r30");
    GeoItemCar__hitItemBoxProc(player, jpabaseemitter);
    
    struct SObject* sobj = itemcar->sobj;
    OSReport("Item car height: %i, parameter 4: %i \n", sobj->s16fixedpoint1, sobj->field_36);
    
    if (sobj->field_36 == 0) {
        player_itemrolls[player] = -1;
    }
    else {
        player_itemrolls[player] = sobj->field_36 - 1;
    }
}

void onSpawnMushroomFromCarHit(uint32* itemmgr, uint32 item, float* vec1, float* vec2) {
    register struct GeoObject *mushroomcar asm ("r30");
    struct SObject* sobj = mushroomcar->sobj;
    uint32 spawnitem = 5;
    if (sobj->field_36 > 0) {
        spawnitem = sobj->field_36-1;
    }
    
    ItemObjMgr__occurItem(itemmgr, spawnitem, vec1, vec2);
}