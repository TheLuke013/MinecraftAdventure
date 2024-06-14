#ifndef CORE_H
#define CORE_H

#ifdef _WIN32
	#ifdef EXPORT_API
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#endif

#endif
