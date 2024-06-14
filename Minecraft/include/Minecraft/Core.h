#ifndef MINECRAFT_CORE_H
#define MINECRAFT_CORE_H

#ifdef MINECRAFT_EXPORTS
	#define MINECRAFT_API __declspec(dllexport)
#else
	#define MINECRAFT_API __declspec(dllimport)
#endif


#endif
