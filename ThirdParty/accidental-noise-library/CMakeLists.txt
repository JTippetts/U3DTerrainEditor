cmake_minimum_required(VERSION 2.6)

add_definitions(-DUSETHREAD)

include_directories(ThirdParty/lua-5.1.4/src/ ThirdParty/toluapp/include/)

file(GLOB sources ThirdParty/lua-5.1.4/src/lapi.c 
ThirdParty/lua-5.1.4/src/lauxlib.c
ThirdParty/lua-5.1.4/src/lbaselib.c
ThirdParty/lua-5.1.4/src/lcode.c
ThirdParty/lua-5.1.4/src/ldblib.c
ThirdParty/lua-5.1.4/src/ldebug.c
ThirdParty/lua-5.1.4/src/ldo.c
ThirdParty/lua-5.1.4/src/ldump.c
ThirdParty/lua-5.1.4/src/lfunc.c
ThirdParty/lua-5.1.4/src/lgc.c
ThirdParty/lua-5.1.4/src/linit.c
ThirdParty/lua-5.1.4/src/liolib.c
ThirdParty/lua-5.1.4/src/llex.c
ThirdParty/lua-5.1.4/src/lmathlib.c
ThirdParty/lua-5.1.4/src/lmem.c
ThirdParty/lua-5.1.4/src/loadlib.c
ThirdParty/lua-5.1.4/src/lobject.c
ThirdParty/lua-5.1.4/src/lopcodes.c
ThirdParty/lua-5.1.4/src/loslib.c
ThirdParty/lua-5.1.4/src/lparser.c
ThirdParty/lua-5.1.4/src/lstate.c
ThirdParty/lua-5.1.4/src/lstring.c
ThirdParty/lua-5.1.4/src/lstrlib.c
ThirdParty/lua-5.1.4/src/ltable.c
ThirdParty/lua-5.1.4/src/ltablib.c
ThirdParty/lua-5.1.4/src/ltm.c
ThirdParty/lua-5.1.4/src/lundump.c
ThirdParty/lua-5.1.4/src/lvm.c
ThirdParty/lua-5.1.4/src/lzio.c
ThirdParty/lua-5.1.4/src/print.c
ThirdParty/toluapp/src/lib/tolua_event.c
ThirdParty/toluapp/src/lib/tolua_is.c
ThirdParty/toluapp/src/lib/tolua_map.c
ThirdParty/toluapp/src/lib/tolua_push.c
ThirdParty/toluapp/src/lib/tolua_to.c
Framework/main.cpp
Bindings/bind_anl.cpp
)

add_executable(anl ${sources})