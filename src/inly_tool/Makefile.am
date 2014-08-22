
AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_srcdir)/src/libinly/

bin_PROGRAMS = inly_tool
inly_tool_SOURCES = inly_tool.cpp

inly_tool_LDFLAGS = `pkg-config cryptopp  --libs` -lboost_filesystem

inly_tool_LDADD = $(top_builddir)/src/libinly/.libs/libinly.a	#也可以写成libinly.so，但这种依赖于系统对so所在目录的配置
