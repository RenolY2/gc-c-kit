
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#define PRESS_START	0x1000
#define PRESS_B		0x0200
#define PRESS_A		0x0100
#define PRESS_Z		0x0010
#define PRESS_X		0x0400
#define PRESS_Y		0x0800
#define PRESS_DU	0x0008
#define PRESS_DD	0x0004
#define PRESS_DL	0x0001
#define PRESS_DR	0x0002

#define ANALOG_UP       0x0800
#define ANALOG_DOWN     0x0400
#define ANALOG_LEFT     0x0100 
#define ANALOG_RIGHT    0x0200

typedef unsigned int uint32;
typedef unsigned char byte;
typedef unsigned char bool;
typedef signed short __int16;

void GeographyObjManager__setKartHitItemBoxTrigger(uint32* geogobjmgr, int player);
int ItemShuffleMgr__calcSlot(uint32* shufflemgr, uint32* kartshuffle, int unk1, int unk2, bool unk3);
void GeoItemCar__hitItemBoxProc(int unk, uint32** jpabaseemitter);
void ItemObjMgr__occurItem(uint32* itemobjmgr, uint32 item, float* vec1, float* vec2);

struct GeoObject
{
  char field_0[232];
  struct SObject* sobj;
};

/* 2 */
struct SObject
{
  int xpos;
  int ypos;
  int zpos;
  int xscale;
  int yscale;
  int zscale;
  __int16 forwardx;
  __int16 forwardy;
  __int16 forwardz;
  __int16 upx;
  __int16 upy;
  __int16 upz;
  __int16 objectid;
  __int16 link;
  __int16 field_28;
  __int16 targetpoint;
  char proclevel_filter;
  char proclevel;
  char collisionflag;
  char field_2F;
  __int16 s16fixedpoint1;
  __int16 s16fixedpoint2;
  __int16 field_34;
  __int16 field_36;
  __int16 s16fixedpoint3;
  __int16 s16fixedpoint4;
  __int16 field_3C;
  __int16 idk_availability;
};
