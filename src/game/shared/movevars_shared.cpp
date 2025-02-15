//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//


#include "cbase.h"
#include "movevars_shared.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

// some cvars used by player movement system
#if defined(HL2_DLL) || defined(HL2_CLIENT_DLL)
#define DEFAULT_GRAVITY_STRING	"600"
#else
#define DEFAULT_GRAVITY_STRING	"800"
#endif

ConVar	sv_gravity		( "sv_gravity",DEFAULT_GRAVITY_STRING, FCVAR_NOTIFY | FCVAR_REPLICATED, "World gravity." );


ConVar	sv_stopspeed	( "sv_stopspeed","100", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Minimum stopping speed when on ground." );


ConVar	sv_noclipaccelerate( "sv_noclipaccelerate", "5", FCVAR_NOTIFY | FCVAR_ARCHIVE | FCVAR_REPLICATED);
ConVar	sv_noclipspeed	( "sv_noclipspeed", "5", FCVAR_ARCHIVE | FCVAR_NOTIFY | FCVAR_REPLICATED);
ConVar	sv_specaccelerate( "sv_specaccelerate", "5", FCVAR_NOTIFY | FCVAR_ARCHIVE | FCVAR_REPLICATED);
ConVar	sv_specspeed	( "sv_specspeed", "3", FCVAR_ARCHIVE | FCVAR_NOTIFY | FCVAR_REPLICATED);
ConVar	sv_specnoclip	( "sv_specnoclip", "1", FCVAR_ARCHIVE | FCVAR_NOTIFY | FCVAR_REPLICATED);
#ifdef PORTAL2_DLL
ConVar	sv_maxspeed		( "sv_maxspeed", "320", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY);
#else
ConVar	sv_maxspeed		("sv_maxspeed", "175", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY);
#endif


#ifdef _XBOX
	ConVar	sv_accelerate	( "sv_accelerate", "7", FCVAR_NOTIFY | FCVAR_REPLICATED);
#else
	ConVar	sv_accelerate	( "sv_accelerate", "10", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY);
#endif//_XBOX

ConVar	sv_airaccelerate(  "sv_airaccelerate", "10", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY );    
ConVar	sv_wateraccelerate(  "sv_wateraccelerate", "10", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY );     
ConVar	sv_waterfriction(  "sv_waterfriction", "1", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY );      
ConVar	sv_footsteps	( "sv_footsteps", "1", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Play footstep sound for players" );
ConVar	sv_rollspeed	( "sv_rollspeed", "200", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY);
ConVar	sv_rollangle	( "sv_rollangle", "0", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Max view roll angle");


ConVar	sv_friction		( "sv_friction","4", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "World friction." );


ConVar	sv_bounce		( "sv_bounce","0", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Bounce multiplier for when physically simulated objects collide with other objects." );
ConVar	sv_maxvelocity	( "sv_maxvelocity","3500", FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Maximum speed any ballistically moving object is allowed to attain per axis." );

#ifdef INFESTED_DLL
ConVar	sv_stepsize		( "sv_stepsize","24", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY );
#else
ConVar	sv_stepsize		( "sv_stepsize","18", FCVAR_NOTIFY | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY );
#endif

ConVar	sv_skyname		( "sv_skyname", "sky_urb01", FCVAR_ARCHIVE | FCVAR_REPLICATED, "Current name of the skybox texture" );
ConVar	sv_backspeed	( "sv_backspeed", "0.6", FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "How much to slow down backwards motion" );
ConVar  sv_waterdist	( "sv_waterdist","12", FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Vertical view fixup when eyes are near water plane." );

// Vehicle convars
ConVar r_VehicleViewDampen( "r_VehicleViewDampen", "1", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED );

// Jeep convars
ConVar r_JeepViewDampenFreq( "r_JeepViewDampenFreq", "7.0", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED );
ConVar r_JeepViewDampenDamp( "r_JeepViewDampenDamp", "1.0", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED);
ConVar r_JeepViewZHeight( "r_JeepViewZHeight", "10.0", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED );

// Airboat convars
ConVar r_AirboatViewDampenFreq( "r_AirboatViewDampenFreq", "7.0", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED );
ConVar r_AirboatViewDampenDamp( "r_AirboatViewDampenDamp", "1.0", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED);
ConVar r_AirboatViewZHeight( "r_AirboatViewZHeight", "0.0", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED );
