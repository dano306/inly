
AUTOMAKE_OPTIONS = foreign

SUBDIRS = src/libinly src/inly_tool

nobase_include_HEADERS = inly_config.h

#对应关系：xxxxdir => xxxx_DATA
pkgconfigdir = /usr/lib64/pkgconfig/
pkgconfig_DATA = support-files/inly.pc

ldconfigdir = /etc/ld.so.conf.d/
ldconfig_DATA = support-files/inly.conf

############################################################

#这里要获取的是libdir的路径，而不是变量+路径，所以通过makefile来做，aucoconf做不了
$(builddir)/support-files/inly.conf : $(srcdir)/support-files/inly.conf.in
	sed -e 's|___libdir___|@libdir@|g' $< > $@


#安装时的顺序install-exec > install-data
#对应的hook也是这个调用顺序
#uninstall时只有一个hook

#install-exec-hook:
#

install-data-hook:
	ldconfig

#注意，这里一般与$(DESTDIR)前缀联合使用，以指向正确的文件路径
uninstall-hook:
	ldconfig
