/* BdhkmApi.h
* Authored by BlueSkeye
* Governed by the MIT licence
*
* Defines known exported functions from 64 bit version of Bdhkm64 library/DLL
*/

#ifndef _BDHKMAPI_H_
#define _BDHKMAPI_H_
#include <ntdef.h>
#include <winnt.h>
#include <windef.h>
#include "Commons.h"

#define BDHKMAPI DECLSPEC_IMPORT

UNEXPLORED BdhkmBeginHooking
UNEXPLORED BdhkmEndHooking
UNEXPLORED BdhkmInstallEatHook
UNEXPLORED BdhkmInstallIatHook
UNEXPLORED BdhkmInstallInlineHook
UNEXPLORED BdhkmInstallPointerHook
UNEXPLORED BdhkmIsApiDllImports
UNEXPLORED BdhkmQueryRegion
UNEXPLORED BdhkmRegisterClient
UNEXPLORED BdhkmRegisterClient2
UNEXPLORED BdhkmRemoveEatHook
UNEXPLORED BdhkmRemoveIatHook
UNEXPLORED BdhkmRemoveInlineHook
UNEXPLORED BdhkmRemovePointerHook

/* Retrieve a pointer to an IMAGE_IMPORT_BY_NAME structure describing a given
* imported by name artefact.
* hModule : Handle to the module to be scanned for imports.
* dllName : The name of the DLL exporting the artefact.
* exportName : Artefact's name
* Returns : TRUE on successfull retrieval, FALSE otherwise.
* REMARKS : There is no validation of the hModule value itself. However the retrieval
* of the exported artefact is tightly bound to the official PE format. Attempt to use
* a non legit hModule value would very likely fail. Should it succeed it is not
* expected to provide any advantage or bypass.
*/
BDHKMAPI __fastcall BOOL BdhkmResolveImportAddress(
	_In_ HMODULE hModule,
	_In_ PSTRING dllName,
	_In_ PSTRING exportName,
	_Inout_ PIMAGE_IMPORT_BY_NAME* ppImageImportByName);

UNEXPLORED BdhkmResolveInlineFunctionAddress
UNEXPLORED BdhkmResolveRvaExportTableAddress
UNEXPLORED BdhkmResumeEatHook
UNEXPLORED BdhkmResumeIatHook
UNEXPLORED BdhkmResumeInlineHook
UNEXPLORED BdhkmResumePointerHook
UNEXPLORED BdhkmSuspendEatHook
UNEXPLORED BdhkmSuspendIatHook
UNEXPLORED BdhkmSuspendInlineHook
UNEXPLORED BdhkmSuspendPointerHook
UNEXPLORED BdhkmUnregisterClient
#endif