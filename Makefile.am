
AUTOMAKE_OPTIONS = foreign

# _LTLIBRARIES 是 Automake 支持 Libtool 的原语
lib_LTLIBRARIES = libinly.la
libinly_la_SOURCES = src/libinly/CInly.cpp
libinly_la_CPPFLAGS = $(AM_CPPFLAGS) -Wall
libinly_la_CXXFLAGS=$(AM_CFLAGS) #"pkg-config xxxx --cflags" 

# 可以通过 _LDFLAGS 传递选项给 Libtool 
#libinly_la_LDFLAGS = 

# 通过 _LIBADD 可以指定库依赖关系
#libinly_la_LIBADD  = -lm

includedir=${prefix}/include/inly/
nobase_include_HEADERS = src/libinly/CInly.h

############################################################

bin_PROGRAMS = inly_tool
inly_tool_SOURCES = src/inly_tool/inly_tool.cpp
#inly_tool_LDFLAGS = 
inly_tool_LDADD = $(top_builddir)/src/libinly/libinly.la
