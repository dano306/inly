
AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_srcdir)/src/libinly/

bin_PROGRAMS = inly_tool
inly_tool_SOURCES = src/inly_tool/inly_tool.cpp

#inly_tool_LDFLAGS = 
inly_tool_LDADD = $(top_builddir)/src/libinly/.libs/libinly.so
