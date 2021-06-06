// ---------------------------------------------------------------------------
// luapuz_puz_Clue.hpp was generated by puzbind.lua
//
// Any changes made to this file will be lost when the file is regenerated.
// ---------------------------------------------------------------------------

#ifndef luapuz_puz_Clue_hpp
#define luapuz_puz_Clue_hpp

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "../luapuz_functions.hpp"
#include "../luapuz_tracking.hpp"

// ---------------------------------------------------------------------------
// class Clue
// ---------------------------------------------------------------------------

#include "puz/Clue.hpp"

LUAPUZ_API extern const char * Clue_meta;

// Clue userdata
// Userdata member should_gc is used to suppress garbage collection of the
// actual data.
// Calling luapuz_newClue() with default parameters enables
// garbage collection.
// Calling luapuz_pushClue/Ref() with default parameters
// suppresses garbage collection.
struct LUAPUZ_API Clue_ud
{
    puz::Clue * clue;
    bool should_gc;
};

// Get the userdata
inline Clue_ud * luapuz_checkClue_ud(lua_State * L, int index)
{
    return (Clue_ud *)luaL_checkudata(L, index, Clue_meta);
}

// Get the actual data
inline puz::Clue * luapuz_checkClue(lua_State * L, int index)
{
    Clue_ud * ud = luapuz_checkClue_ud(L, index);
    if (! ud->clue)
        luaL_typerror(L, index, Clue_meta);
    return ud->clue;
}


// Check if this is the correct data type
inline bool luapuz_isClue(lua_State *L, int index)
{
    return luapuz_isudata(L, index, Clue_meta);
}

// Create a new userdata with actual data and push it on the stack.
// The userdata will be tracked in the tracked objects table.
LUAPUZ_API void luapuz_newClue(lua_State * L, puz::Clue * clue, bool should_gc = true);

// Push the actual data.
// If we have already tracked this userdata, push that userdata.
inline void luapuz_pushClue(lua_State * L, puz::Clue * clue, bool should_gc = false)
{
    if (! clue)
        lua_pushnil(L);
    else if (! luapuz_push_tracked_object(L, clue, Clue_meta))
        luapuz_newClue(L, clue, should_gc);
}


void luapuz_openCluelib (lua_State *L);
#endif // luapuz_puz_Clue_hpp
