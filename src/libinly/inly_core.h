#ifndef	__FILE_INLY_CORE_H__
#define	__FILE_INLY_CORE_H__

//���ļ���libinly�ڲ������๲�õġ����ͬ������Ϣ��һ��Ҳ��Ҫ������libinly���ⲿʹ����

#include <iostream>
#include <stdio.h>
#include <string>

#ifdef	INLY_DEBUG		//ͨ���������룬����ȥ����ӡ������صĺ�

	#define	printf(format, args...)	printf("%s %s %d: " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args)
	#define	printf__s(var)	printf("%s = %s", #var, var)
	#define	printf__size_t(var)	printf("%s = %lu", #var, var)
	#define	printf__str(var)	printf("%s = %s", #var, (var).c_str())
	#define inly_cout(var)	std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << ": " << #var << " = " << (var) << std::endl

#else

	#define	printf(format, args...)
	#define	printf__s(var)
	#define	printf__size_t(var)
	#define	printf__str(var)
	#define inly_cout(var)

#endif	

#define	NS_INLY		inly
#define	NAMESPACE_BEGIN__INLY	namespace NS_INLY {
#define	NAMESPACE_END__INLY	}
#define	NAMESPACE_USING__INLY	using namespace NS_INLY;

NAMESPACE_BEGIN__INLY
typedef	std::string		std_string;

NAMESPACE_END__INLY

#endif	//__FILE_INLY_CORE_H__
