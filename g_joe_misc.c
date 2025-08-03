// g_joe_misc.c

// JOSEPH 14-JUN-99 ALL

#include "g_local.h"

/*QUAKED light_fire_esm (1 0 0) (-8 -8 -8) (8 8 8) X X X DYNAMIC
Cool fire extra-small 

alphalevel 1 - 10 (default 5) 
*/

/*QUAKED light_fire_sm (1 0 0) (-16 -16 -16) (16 16 16) X X X DYNAMIC
Cool fire small

alphalevel 1 - 10 (default 5)
*/

/*QUAKED light_fire_med (1 0 0) (-24 -24 -24) (24 24 24) X X X DYNAMIC
Cool fire medium

alphalevel 1 - 10 (default 5)
*/

/*QUAKED light_fire_lg (1 0 0) (-32 -32 -32) (32 32 32) X X X DYNAMIC
Cool fire large

alphalevel 1 - 10 (default 5)
*/
/*
void SP_light_fire_esm (edict_t *self)
{
	self->movetype = MOVETYPE_NONE;
	self->solid = SOLID_NOT;
	self->s.modelindex = gi.modelindex("sprites/fire.sp2");
	self->s.frame = 0;
	self->s.sound = 0;
	self->s.effects |= EF_ROTATE;
	self->s.renderfx |= RF_FULLBRIGHT;
	gi.linkentity(self);
}

void SP_light_fire_sm (edict_t *self)
{
	self->movetype = MOVETYPE_NONE;
	self->solid = SOLID_NOT;
	self->s.modelindex = gi.modelindex("sprites/fire.sp2");
	self->s.frame = 0;
	self->s.sound = 0;
	self->s.effects |= EF_ROTATE;
	self->s.renderfx |= RF_FULLBRIGHT;
	gi.linkentity(self);
}*/
void smallflame(edict_t *self)
{
	if (self->s.frame >= 10)
		self->s.frame = 0;
	else
		self->s.frame++;
	self->nextthink = level.time + FRAMETIME;
}
void SP_light_fire_med (edict_t *self)
{
	self->movetype = MOVETYPE_NONE;
	self->solid = SOLID_NOT;
	self->s.modelindex = gi.modelindex("models/props/fire/tris.md2");
	self->s.frame = 0;
	self->s.sound = 0;
	self->s.effects |= EF_ROTATE;
//	self->s.renderfx |= RF_TRANSLUCENT;
	self->s.renderfx |= RF_GLOW;
	self->nextthink = level.time + FRAMETIME;
	self->think = smallflame;
	gi.linkentity(self);
}
/*
void SP_light_fire_lg (edict_t *self)
{
	self->movetype = MOVETYPE_NONE;
	self->solid = SOLID_NOT;
	self->s.modelindex = gi.modelindex("sprites/fire.sp2");
	self->s.frame = 0;
	self->s.sound = 0;
	self->s.effects |= EF_ROTATE;
	self->s.renderfx |= RF_FULLBRIGHT;
	gi.linkentity(self);
}*/


