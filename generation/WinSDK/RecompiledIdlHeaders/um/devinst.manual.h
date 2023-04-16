/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    setupapi.h

Abstract:

    Public header file for Windows NT Setup and Device Installer services Dll.

--*/

#ifndef _INC_SETUPAPI
#define _INC_SETUPAPI

#if _MSC_VER > 1000
#pragma once
#endif
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#if defined (_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(push)
#pragma warning(disable:4201) /* nonstandard extension used : nameless struct/union */
#endif

//
// Define API decoration for direct importing of DLL references.
//
#if !defined(_SETUPAPI_)
#define WINSETUPAPI DECLSPEC_IMPORT
#else
#define WINSETUPAPI
#endif

//
// determine version of setupapi based on _WIN32_WINDOWS and _WIN32_WINNT
//
// NT4 version of setupapi   (_WIN32_WINNT_NT4) is earliest, and installed onto Win95 by IE.
// Win2k version of setupapi (_WIN32_WINNT_WIN2K) also shipped in WinME
// we'll use "0x0410" to indicate version of setupapi shipped with Win98
//
#ifndef _SETUPAPI_VER
#if defined(_WIN32_WINNT) && (!defined(_WIN32_WINDOWS) || (_WIN32_WINNT < _WIN32_WINDOWS))
#define _SETUPAPI_VER _WIN32_WINNT  // SetupAPI version follows Windows NT version
#elif defined(_WIN32_WINDOWS)
#if _WIN32_WINDOWS >= 0x0490
#define _SETUPAPI_VER _WIN32_WINNT_WIN2K        // WinME uses same version of SetupAPI as Win2k
#elif _WIN32_WINDOWS >= 0x0410
#define _SETUPAPI_VER 0x0410        // Indicates version of SetupAPI shipped with Win98
#else
#define _SETUPAPI_VER _WIN32_WINNT_NT4        // Earliest SetupAPI version
#endif // _WIN32_WINDOWS
#else // _WIN32_WINNT/_WIN32_WINDOWS
#define _SETUPAPI_VER _WIN32_WINNT_WINXP
#endif // _WIN32_WINNT/_WIN32_WINDOWS
#endif // !_SETUPAPI_VER

#ifndef __LPGUID_DEFINED__
#define __LPGUID_DEFINED__
typedef GUID *LPGUID;
#endif

//
// Include spapidef.h for basic definitions and flags
//
#include <spapidef.h>

//
// Include commctrl.h for our use of HIMAGELIST and wizard support.
//
#include <commctrl.h>

//
// Include devpropdef.h for our use of DEVPROPERTYKEY and DEVPROPTYPE.
//
#include <devpropdef.h>

#if defined(_WIN64)
#include <pshpack8.h>   // Assume 8-byte (64-bit) packing throughout
#else
#include <pshpack1.h>   // Assume byte packing throughout (32-bit processor)
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _SP_DEVICE_INTERFACE_DETAIL_DATA_A {
    DWORD  cbSize;
    CHAR   DevicePath[ANYSIZE_ARRAY];
} SP_DEVICE_INTERFACE_DETAIL_DATA_A, *PSP_DEVICE_INTERFACE_DETAIL_DATA_A;

typedef struct _SP_DEVICE_INTERFACE_DETAIL_DATA_W {
    DWORD  cbSize;
    WCHAR  DevicePath[ANYSIZE_ARRAY];
} SP_DEVICE_INTERFACE_DETAIL_DATA_W, *PSP_DEVICE_INTERFACE_DETAIL_DATA_W;

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#if defined (_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif // _INC_SETUPAPI
