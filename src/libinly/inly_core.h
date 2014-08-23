#ifndef	__FILE_INLY_CORE_H__
#define	__FILE_INLY_CORE_H__

//此文件是libinly内部所有类共用的“大而同”的信息，一般也需要引出给libinly的外部使用者
//INLY_DEBUG宏的引入，可通过命令: make CPPFLAGS=-DINLY_DEBUG

//#warning	"当前正处于调试的状态，自动定义宏INLY_DEBUG"
//#define	INLY_DEBUG

#include <iostream>
#include <cstdio>
#include <string>

#ifdef	INLY_DEBUG		//通过条件编译，快速去掉打印调试相关的宏

	#warning	"检测到已定义宏INLY_DEBUG"

	#define	inly_printf(format, args...)	printf("%s %s %d: " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args)
	#define	inly_printf__s(var)				inly_printf("%s = %s", #var, var)
	#define	inly_printf__size_t(var)		inly_printf("%s = %lu", #var, var)
	#define	inly_printf__str(var)			inly_printf("%s = %s", #var, (var).c_str())
	#define inly_cout(var)	std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << ": " << #var << " = " << (var) << std::endl

#else

	#define	inly_printf(format, args...)
	#define	inly_printf__s(var)
	#define	inly_printf__size_t(var)
	#define	inly_printf__str(var)
	#define inly_cout(var)

#endif

#define	NS_INLY		inly
#define	NAMESPACE_BEGIN__INLY	namespace NS_INLY {
#define	NAMESPACE_END__INLY	}
#define	NAMESPACE_USING__INLY	using namespace NS_INLY;

NAMESPACE_BEGIN__INLY
typedef	std::string		std_string;		//限定在名字空间里，所以不担心污染使用者的名字空间

NAMESPACE_END__INLY

#endif	//__FILE_INLY_CORE_H__
