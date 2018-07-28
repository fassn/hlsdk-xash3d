#ifndef GRAVGUNMOD_H
#define GRAVGUNMOD_H


extern cvar_t cvar_allow_gravgun;
extern cvar_t cvar_allow_ar2;
extern cvar_t cvar_ar2_mp5;
extern cvar_t cvar_ar2_bullets;
extern cvar_t cvar_ar2_balls;
extern cvar_t cvar_wresptime;
extern cvar_t cvar_iresptime;

extern cvar_t cvar_gibtime;
extern cvar_t cvar_hgibcount;
extern cvar_t cvar_agibcount;

extern cvar_t mp_spectator;
extern cvar_t mp_fixhornetbug;
extern cvar_t mp_checkentities;
extern cvar_t mp_touchmenu;

void GGM_RegisterCVars( void );
void Ent_RunGC( bool common, bool enttools, const char *userid );
class CBasePlayer;
void GGM_ClientPutinServer(edict_t *pEntity , CBasePlayer *pPlayer);
void GGM_ClientFirstSpawn(CBasePlayer *pPlayer );
const char *GGM_GetPlayerID( edict_t *player );
edict_t *GGM_PlayerByID( const char *id );
enum PlayerState
{
	STATE_UNINITIALIZED = 0,
	STATE_CONNECTED,
	STATE_SPECTATOR_BEGIN,
	STATE_SPAWNED,
	STATE_SPECTATOR,
	STATE_POINT_SELECT
};

enum PlayerMenuState
{
	MENUSTATE_NONE = 0,
	MENUSTATE_COOPMENU,
	MENUSTATE_COOPMENU_SPEC,
	MENUSTATE_CHECKPOINT,
	MENUSTATE_GLOBAL,
	MENUSTATE_LOCAL_CONFIRM
};


class GGM_PlayerMenu
{
	struct GGM_MenuItem
	{
		char command[256];
		char name[32];
	} m_items[5];
	int m_iCount;
	char m_sTitle[32];

public:
	CBasePlayer *pPlayer;
	bool MenuSelect( int select );
	GGM_PlayerMenu &SetTitle(const char *title);
	GGM_PlayerMenu &New(const char *title);
	GGM_PlayerMenu &Add( const char *name, const char *command );
	GGM_PlayerMenu &Clear();
	void Show();
};


struct GGMData
{
	float m_flSpawnTime;
	PlayerState m_state;
	bool m_fTouchMenu;
	int m_iMenuState;
	int m_iLocalConfirm;
	int m_iConfirmKey;
	float m_flEntScope;
	float m_flEntTime;
	char uid[33];
	GGM_PlayerMenu menu;
};

#endif // GRAVGUNMOD_H

