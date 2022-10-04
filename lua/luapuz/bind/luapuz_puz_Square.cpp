// ---------------------------------------------------------------------------
// luapuz_puz_Square.cpp was generated by puzbind.lua
//
// Any changes made to this file will be lost when the file is regenerated.
// ---------------------------------------------------------------------------

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "../luapuz_functions.hpp"
#include "../luapuz_tracking.hpp"

#include "luapuz_puz.hpp"
#include "luapuz_puz_Square.hpp"
// ---------------------------------------------------------------------------
// class Square
// ---------------------------------------------------------------------------



const char * Square_meta = "puz.Square";

// Create a new userdata with actual data and push it on the stack.
// The userdata will be tracked in the tracked objects table.
LUAPUZ_API void luapuz_newSquare(lua_State * L,
                               puz::Square * square,
                               bool should_gc)
{
    // Create the userdata
    Square_ud * ud =
        (Square_ud *)lua_newuserdata(L, sizeof(Square_ud));

    ud->should_gc = should_gc;

    // Set the data member
    ud->square = square;

    // Set the metatable
    luaL_getmetatable(L, Square_meta);
    lua_setmetatable(L, -2);

    // Track the object
    luapuz_track_object(L, square);
}



// Delete the data on garbage collection
int Square_gc(lua_State * L)
{
#ifdef LUAPUZ_DEBUG
    std::cout << "Garbage collecting puz::Square ";
#endif
    Square_ud * ud = luapuz_checkSquare_ud(L, 1);
    luapuz_untrack_object(L, ud->square);
    if (ud->should_gc)
    {
        // If the user calls Square:__gc() before this object
        // is garbage collected, we might try to delete ud->square twice.
        ud->should_gc = false;
        delete ud->square;
#ifdef LUAPUZ_DEBUG
        std::cout << "and deleting data" << std::endl;
#endif
    }
    else
    {
#ifdef LUAPUZ_DEBUG
        //std::cout << "but not deleting data" << std::endl;
#endif
    }
    return 0;
}

// tostring() -> userdata 0xHHHHH (puz.Square 0xHHHH)
int Square_tostring(lua_State * L)
{
    Square_ud * ud = luapuz_checkSquare_ud(L, 1);
    lua_pushfstring(L, "userdata: %p (%s: %p gc = %s)", ud, Square_meta, ud->square, ud->should_gc ? "true" : "false");
    return 1;
}

// Square functions
//----------------
// short GetCol()
static int Square_GetCol(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    // Adjust to a lua index (1-based)
    short returns = square->GetCol() + 1;
    lua_pushnumber(L, returns);
    return 1;
}
// short GetRow()
static int Square_GetRow(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    // Adjust to a lua index (1-based)
    short returns = square->GetRow() + 1;
    lua_pushnumber(L, returns);
    return 1;
}
// Map<T|B|R|L, true/false> GetBars()
static int Square_GetBars(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);

    lua_newtable(L);

    lua_pushboolean(L, square->m_bars[puz::BAR_TOP]);
    lua_setfield(L, -2, "T");

    lua_pushboolean(L, square->m_bars[puz::BAR_LEFT]);
    lua_setfield(L, -2, "L");

    lua_pushboolean(L, square->m_bars[puz::BAR_RIGHT]);
    lua_setfield(L, -2, "R");

    lua_pushboolean(L, square->m_bars[puz::BAR_BOTTOM]);
    lua_setfield(L, -2, "B");

    return 1;
}
// void SetBars(Map<T|B|R|L, true/false>)
static int Square_SetBars(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    luaL_checktype(L, 2, LUA_TTABLE);

    lua_getfield(L, 2, "T");
    square->m_bars[puz::BAR_TOP] = lua_toboolean(L, -1);

    lua_getfield(L, 2, "L");
    square->m_bars[puz::BAR_LEFT] = lua_toboolean(L, -1);

    lua_getfield(L, 2, "R");
    square->m_bars[puz::BAR_RIGHT] = lua_toboolean(L, -1);

    lua_getfield(L, 2, "B");
    square->m_bars[puz::BAR_BOTTOM] = lua_toboolean(L, -1);

    return 0;
}
// bool IsWhite()
static int Square_IsWhite(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsWhite();
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsBlack()
static int Square_IsBlack(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsBlack();
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsBlank()
static int Square_IsBlank(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsBlank();
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsSolutionWhite()
static int Square_IsSolutionWhite(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsSolutionWhite();
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsSolutionBlack()
static int Square_IsSolutionBlack(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsSolutionBlack();
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsSolutionBlank()
static int Square_IsSolutionBlank(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsSolutionBlank();
    lua_pushboolean(L, returns);
    return 1;
}
// puz::string_t GetText()
static int Square_GetText(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t returns = square->GetText();
    luapuz_pushstring_t(L, returns);
    return 1;
}
// char GetPlainText()
static int Square_GetPlainText(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    char returns = square->GetPlainText();
    luapuz_pushchar(L, returns);
    return 1;
}
// int GetTextSymbol()
// Separate try/catch function
static int Square_GetTextSymbol_try(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int returns;
    try {
        returns = square->GetTextSymbol();
        lua_pushnumber(L, returns);
        return 1;
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return -1; // An error is on the stack
}
// The lua function (no exceptions)
static int Square_GetTextSymbol(lua_State * L)
{
    int code = Square_GetTextSymbol_try(L);
    if (code == -1)
        lua_error(L);
    return code;
}
// void SetText(puz::string_t text)
// Separate try/catch function
static int Square_SetText_try(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t text = luapuz_checkstring_t(L, 2);
    try {
        square->SetText(text);
        return 0;
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return -1; // An error is on the stack
}
// The lua function (no exceptions)
static int Square_SetText(lua_State * L)
{
    int code = Square_SetText_try(L);
    if (code == -1)
        lua_error(L);
    return code;
}
// bool HasTextRebus()
static int Square_HasTextRebus(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasTextRebus();
    lua_pushboolean(L, returns);
    return 1;
}
// bool HasTextSymbol()
static int Square_HasTextSymbol(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasTextSymbol();
    lua_pushboolean(L, returns);
    return 1;
}
// puz::string_t GetSolution()
static int Square_GetSolution(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t returns = square->GetSolution();
    luapuz_pushstring_t(L, returns);
    return 1;
}
// char GetPlainSolution()
static int Square_GetPlainSolution(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    char returns = square->GetPlainSolution();
    luapuz_pushchar(L, returns);
    return 1;
}
// int GetSolutionSymbol()
// Separate try/catch function
static int Square_GetSolutionSymbol_try(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int returns;
    try {
        returns = square->GetSolutionSymbol();
        lua_pushnumber(L, returns);
        return 1;
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return -1; // An error is on the stack
}
// The lua function (no exceptions)
static int Square_GetSolutionSymbol(lua_State * L)
{
    int code = Square_GetSolutionSymbol_try(L);
    if (code == -1)
        lua_error(L);
    return code;
}
// void SetSolution(puz::string_t solution)
// Separate try/catch function
static int Square_SetSolution1_try(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t solution = luapuz_checkstring_t(L, 2);
    try {
        square->SetSolution(solution);
        return 0;
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return -1; // An error is on the stack
}
// The lua function (no exceptions)
static int Square_SetSolution1(lua_State * L)
{
    int code = Square_SetSolution1_try(L);
    if (code == -1)
        lua_error(L);
    return code;
}
// void SetSolution(puz::string_t solution, char plain)
// Separate try/catch function
static int Square_SetSolution2_try(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t solution = luapuz_checkstring_t(L, 2);
    char plain = luapuz_checkchar(L, 3);
    try {
        square->SetSolution(solution, plain);
        return 0;
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return -1; // An error is on the stack
}
// The lua function (no exceptions)
static int Square_SetSolution2(lua_State * L)
{
    int code = Square_SetSolution2_try(L);
    if (code == -1)
        lua_error(L);
    return code;
}
// SetSolution overload resolution
static int Square_SetSolution(lua_State * L)
{

    luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L) - 1;
    if (argCount >= 2)
    {
        // Only one function
        return Square_SetSolution2(L);
    }
    else if (argCount >= 1)
    {
        // Only one function
        return Square_SetSolution1(L);
    }
    // Else we didn't find a function
    luaL_error(L, "Unable to find overload");
    return 0;
}

// void SetPlainSolution(char plain)
static int Square_SetPlainSolution(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    char plain = luapuz_checkchar(L, 2);
    square->SetPlainSolution(plain);
    return 0;
}
// void SetSolutionRebus(puz::string_t rebus)
// Separate try/catch function
static int Square_SetSolutionRebus_try(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t rebus = luapuz_checkstring_t(L, 2);
    try {
        square->SetSolutionRebus(rebus);
        return 0;
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return -1; // An error is on the stack
}
// The lua function (no exceptions)
static int Square_SetSolutionRebus(lua_State * L)
{
    int code = Square_SetSolutionRebus_try(L);
    if (code == -1)
        lua_error(L);
    return code;
}
// void SetSolutionSymbol(int symbol)
// Separate try/catch function
static int Square_SetSolutionSymbol_try(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int symbol = luaL_checknumber(L, 2);
    try {
        square->SetSolutionSymbol(symbol);
        return 0;
    }
    catch (...) {
        luapuz_handleExceptions(L);
    }
    return -1; // An error is on the stack
}
// The lua function (no exceptions)
static int Square_SetSolutionSymbol(lua_State * L)
{
    int code = Square_SetSolutionSymbol_try(L);
    if (code == -1)
        lua_error(L);
    return code;
}
// bool HasSolutionRebus()
static int Square_HasSolutionRebus(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasSolutionRebus();
    lua_pushboolean(L, returns);
    return 1;
}
// bool HasSolutionSymbol()
static int Square_HasSolutionSymbol(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasSolutionSymbol();
    lua_pushboolean(L, returns);
    return 1;
}
// bool Check(bool checkBlank = false, bool strictRebus = false)
static int Square_Check(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    bool checkBlank = (argCount >= 2 ? luapuz_checkboolean(L, 2) : false);
    bool strictRebus = (argCount >= 3 ? luapuz_checkboolean(L, 3) : false);
    bool returns = square->Check(checkBlank, strictRebus);
    lua_pushboolean(L, returns);
    return 1;
}
// bool HasNumber()
static int Square_HasNumber(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasNumber();
    lua_pushboolean(L, returns);
    return 1;
}
// puz::string_t GetNumber()
static int Square_GetNumber(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t returns = square->GetNumber();
    luapuz_pushstring_t(L, returns);
    return 1;
}
// void SetNumber(puz::string_t number)
static int Square_SetNumber1(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t number = luapuz_checkstring_t(L, 2);
    square->SetNumber(number);
    return 0;
}
// void SetNumber(int number)
static int Square_SetNumber2(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int number = luaL_checknumber(L, 2);
    square->SetNumber(number);
    return 0;
}
// SetNumber overload resolution
static int Square_SetNumber(lua_State * L)
{

    luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L) - 1;
    if (argCount >= 1)
    {
        // Argument 1
        switch(lua_type(L, 2)) {
            case LUA_TSTRING:
                // Only one function
                return Square_SetNumber1(L);
            break;
            case LUA_TNUMBER:
                // Only one function
                return Square_SetNumber2(L);
            break;
        }
    }
    // Else we didn't find a function
    luaL_error(L, "Unable to find overload");
    return 0;
}

// bool WantsClue()
static int Square_WantsClue1(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->WantsClue();
    lua_pushboolean(L, returns);
    return 1;
}
// bool WantsClue(puz::GridDirection dir)
static int Square_WantsClue2(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::GridDirection dir = luapuz_checkGridDirection(L, 2);
    bool returns = square->WantsClue(dir);
    lua_pushboolean(L, returns);
    return 1;
}
// WantsClue overload resolution
static int Square_WantsClue(lua_State * L)
{

    luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L) - 1;
    if (argCount >= 1)
    {
        // Only one function
        return Square_WantsClue2(L);
    }
    else if (argCount >= 0)
    {
        // Only one function
        return Square_WantsClue1(L);
    }
    // Else we didn't find a function
    luaL_error(L, "Unable to find overload");
    return 0;
}

// bool SolutionWantsClue()
static int Square_SolutionWantsClue1(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->SolutionWantsClue();
    lua_pushboolean(L, returns);
    return 1;
}
// bool SolutionWantsClue(puz::GridDirection dir)
static int Square_SolutionWantsClue2(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::GridDirection dir = luapuz_checkGridDirection(L, 2);
    bool returns = square->SolutionWantsClue(dir);
    lua_pushboolean(L, returns);
    return 1;
}
// SolutionWantsClue overload resolution
static int Square_SolutionWantsClue(lua_State * L)
{

    luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L) - 1;
    if (argCount >= 1)
    {
        // Only one function
        return Square_SolutionWantsClue2(L);
    }
    else if (argCount >= 0)
    {
        // Only one function
        return Square_SolutionWantsClue1(L);
    }
    // Else we didn't find a function
    luaL_error(L, "Unable to find overload");
    return 0;
}

// void SetFlag(unsigned short flag)
static int Square_SetFlag(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    unsigned short flag = luapuz_checkuint(L, 2);
    square->SetFlag(flag);
    return 0;
}
// void AddFlag(unsigned short flag, bool doit = true)
static int Square_AddFlag(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    unsigned short flag = luapuz_checkuint(L, 2);
    bool doit = (argCount >= 3 ? luapuz_checkboolean(L, 3) : true);
    square->AddFlag(flag, doit);
    return 0;
}
// void RemoveFlag(unsigned short flag)
static int Square_RemoveFlag(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    unsigned short flag = luapuz_checkuint(L, 2);
    square->RemoveFlag(flag);
    return 0;
}
// void ToggleFlag(unsigned short flag)
static int Square_ToggleFlag(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    unsigned short flag = luapuz_checkuint(L, 2);
    square->ToggleFlag(flag);
    return 0;
}
// unsigned short GetFlag()
static int Square_GetFlag(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    unsigned short returns = square->GetFlag();
    lua_pushnumber(L, returns);
    return 1;
}
// bool HasFlag(unsigned short flag)
static int Square_HasFlag(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    unsigned short flag = luapuz_checkuint(L, 2);
    bool returns = square->HasFlag(flag);
    lua_pushboolean(L, returns);
    return 1;
}
// bool HasCircle()
static int Square_HasCircle(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasCircle();
    lua_pushboolean(L, returns);
    return 1;
}
// void SetCircle(bool doit = true)
static int Square_SetCircle(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    bool doit = (argCount >= 2 ? luapuz_checkboolean(L, 2) : true);
    square->SetCircle(doit);
    return 0;
}
// bool IsMissing()
static int Square_IsMissing(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsMissing();
    lua_pushboolean(L, returns);
    return 1;
}
// void SetMissing(bool doit = true)
static int Square_SetMissing(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    bool doit = (argCount >= 2 ? luapuz_checkboolean(L, 2) : true);
    square->SetMissing(doit);
    return 0;
}
// bool IsTheme()
static int Square_IsTheme(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsTheme();
    lua_pushboolean(L, returns);
    return 1;
}
// void SetTheme(bool doit = true)
static int Square_SetTheme(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    bool doit = (argCount >= 2 ? luapuz_checkboolean(L, 2) : true);
    square->SetTheme(doit);
    return 0;
}
// bool IsAnnotation()
static int Square_IsAnnotation(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->IsAnnotation();
    lua_pushboolean(L, returns);
    return 1;
}
// void SetAnnotation(bool doit = true)
static int Square_SetAnnotation(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    bool doit = (argCount >= 2 ? luapuz_checkboolean(L, 2) : true);
    square->SetAnnotation(doit);
    return 0;
}
// bool HasColor()
static int Square_HasColor(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasColor();
    lua_pushboolean(L, returns);
    return 1;
}
// void SetColor(unsigned char red, unsigned char green, unsigned char blue)
static int Square_SetColor(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    unsigned char red = luapuz_checkuint(L, 2);
    unsigned char green = luapuz_checkuint(L, 3);
    unsigned char blue = luapuz_checkuint(L, 4);
    square->SetColor(red, green, blue);
    return 0;
}
// puz::string_t GetHtmlColor()
static int Square_GetHtmlColor(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::string_t returns = square->GetHtmlColor();
    luapuz_pushstring_t(L, returns);
    return 1;
}
// void RemoveColor()
static int Square_RemoveColor(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    square->RemoveColor();
    return 0;
}
// void SetHighlight(bool doit = true)
static int Square_SetHighlight(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    bool doit = (argCount >= 2 ? luapuz_checkboolean(L, 2) : true);
    square->SetHighlight(doit);
    return 0;
}
// bool HasHighlight()
static int Square_HasHighlight(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    bool returns = square->HasHighlight();
    lua_pushboolean(L, returns);
    return 1;
}
// Square * Next(puz::GridDirection dir = puz::ACROSS)
static int Square_Next(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    puz::GridDirection dir = (argCount >= 2 ? luapuz_checkGridDirection(L, 2) : puz::ACROSS);
    puz::Square * returns = square->Next(dir);
    luapuz_pushSquare(L, returns);
    return 1;
}
// Square * Prev(puz::GridDirection dir = puz::ACROSS)
static int Square_Prev(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    int argCount = lua_gettop(L);
    puz::GridDirection dir = (argCount >= 2 ? luapuz_checkGridDirection(L, 2) : puz::ACROSS);
    puz::Square * returns = square->Prev(dir);
    luapuz_pushSquare(L, returns);
    return 1;
}
// bool IsLast(puz::GridDirection dir)
static int Square_IsLast(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::GridDirection dir = luapuz_checkGridDirection(L, 2);
    bool returns = square->IsLast(dir);
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsFirst(puz::GridDirection dir)
static int Square_IsFirst(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::GridDirection dir = luapuz_checkGridDirection(L, 2);
    bool returns = square->IsFirst(dir);
    lua_pushboolean(L, returns);
    return 1;
}
// bool HasWord(puz::GridDirection dir)
static int Square_HasWord(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::GridDirection dir = luapuz_checkGridDirection(L, 2);
    bool returns = square->HasWord(dir);
    lua_pushboolean(L, returns);
    return 1;
}
// static bool IsValidString(puz::string_t str)
static int Square_IsValidString(lua_State * L)
{
    puz::string_t str = luapuz_checkstring_t(L, 1);
    bool returns = puz::Square::IsValidString(str);
    lua_pushboolean(L, returns);
    return 1;
}
// static bool IsSymbol(puz::string_t str)
static int Square_IsSymbol(lua_State * L)
{
    puz::string_t str = luapuz_checkstring_t(L, 1);
    bool returns = puz::Square::IsSymbol(str);
    lua_pushboolean(L, returns);
    return 1;
}
// bool IsBetween(puz::Square * start, puz::Square * end)
static int Square_IsBetween(lua_State * L)
{
    puz::Square * square = luapuz_checkSquare(L, 1);
    puz::Square * start = luapuz_checkSquare(L, 2);
    puz::Square * end = luapuz_checkSquare(L, 3);
    bool returns = square->IsBetween(start, end);
    lua_pushboolean(L, returns);
    return 1;
}
static const luaL_reg Squarelib[] = {
    {"GetCol", Square_GetCol},
    {"GetRow", Square_GetRow},
    {"GetBars", Square_GetBars},
    {"SetBars", Square_SetBars},
    {"IsWhite", Square_IsWhite},
    {"IsBlack", Square_IsBlack},
    {"IsBlank", Square_IsBlank},
    {"IsSolutionWhite", Square_IsSolutionWhite},
    {"IsSolutionBlack", Square_IsSolutionBlack},
    {"IsSolutionBlank", Square_IsSolutionBlank},
    {"GetText", Square_GetText},
    {"GetPlainText", Square_GetPlainText},
    {"GetTextSymbol", Square_GetTextSymbol},
    {"SetText", Square_SetText},
    {"HasTextRebus", Square_HasTextRebus},
    {"HasTextSymbol", Square_HasTextSymbol},
    {"GetSolution", Square_GetSolution},
    {"GetPlainSolution", Square_GetPlainSolution},
    {"GetSolutionSymbol", Square_GetSolutionSymbol},
    {"SetSolution", Square_SetSolution},
    {"SetPlainSolution", Square_SetPlainSolution},
    {"SetSolutionRebus", Square_SetSolutionRebus},
    {"SetSolutionSymbol", Square_SetSolutionSymbol},
    {"HasSolutionRebus", Square_HasSolutionRebus},
    {"HasSolutionSymbol", Square_HasSolutionSymbol},
    {"Check", Square_Check},
    {"HasNumber", Square_HasNumber},
    {"GetNumber", Square_GetNumber},
    {"SetNumber", Square_SetNumber},
    {"WantsClue", Square_WantsClue},
    {"SolutionWantsClue", Square_SolutionWantsClue},
    {"SetFlag", Square_SetFlag},
    {"AddFlag", Square_AddFlag},
    {"RemoveFlag", Square_RemoveFlag},
    {"ToggleFlag", Square_ToggleFlag},
    {"GetFlag", Square_GetFlag},
    {"HasFlag", Square_HasFlag},
    {"HasCircle", Square_HasCircle},
    {"SetCircle", Square_SetCircle},
    {"IsMissing", Square_IsMissing},
    {"SetMissing", Square_SetMissing},
    {"IsTheme", Square_IsTheme},
    {"SetTheme", Square_SetTheme},
    {"IsAnnotation", Square_IsAnnotation},
    {"SetAnnotation", Square_SetAnnotation},
    {"HasColor", Square_HasColor},
    {"SetColor", Square_SetColor},
    {"GetHtmlColor", Square_GetHtmlColor},
    {"RemoveColor", Square_RemoveColor},
    {"SetHighlight", Square_SetHighlight},
    {"HasHighlight", Square_HasHighlight},
    {"Next", Square_Next},
    {"Prev", Square_Prev},
    {"IsLast", Square_IsLast},
    {"IsFirst", Square_IsFirst},
    {"HasWord", Square_HasWord},
    {"IsValidString", Square_IsValidString},
    {"IsSymbol", Square_IsSymbol},
    {"IsBetween", Square_IsBetween},
    {NULL, NULL}
};

const luaL_reg classSquarelib[] = {
    { "__gc",        Square_gc },
    { "__index",     luapuz_index },
    { "__newindex",  luapuz_newindex },
    { "__tostring",  Square_tostring },
    { NULL, NULL }
};

void luapuz_openSquarelib (lua_State *L) {
    // The Square table, and the metatable for Square objects
    luaL_newmetatable(L, Square_meta);

    // register metatable functions
    luaL_register(L, NULL, Squarelib);
    luaL_register(L, NULL, classSquarelib);

    // puz.Square = the table
    lua_setfield(L, -2, "Square");
}
