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

/* Client context should be considered an opaque pointer. */
typedef PVOID PBDHKM_CLIENT_CONTEXT;

/* TODO
* clientContext : Registered client context.
*/
BDHKMAPI __fastcall BOOL BdhkmBeginHooking(
	_In_ PBDHKM_CLIENT_CONTEXT clientContext
	);

/* Commit hooks declared since the last BdhkmBeginHooking call on the given client
*		context.
* clientContext : Registered client context.
*/
BDHKMAPI __fastcall NTSTATUS BdhkmEndHooking(
	_In_ PBDHKM_CLIENT_CONTEXT clientContext);

UNEXPLORED BdhkmInstallEatHook
UNEXPLORED BdhkmInstallIatHook
UNEXPLORED BdhkmInstallInlineHook
UNEXPLORED BdhkmInstallPointerHook
UNEXPLORED BdhkmIsApiDllImports
UNEXPLORED BdhkmQueryRegion

/* TODO
* Returns an NTSTATUS with following meaning
* 0xEA040007 : Client context allocation failed.
*/
BDHKMAPI __fastcall NTSTATUS BdhkmRegisterClient();

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
* ppImageImportByName : Pointer at a location that on successfull return will contain
*    the descriptor of the searched artefact.
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

/* Retrieve the in memory address of the function having the given name in the module
* loaded at the given address.
* hModule : Handle to the module to be scanned for imports.
* functionName : The name of the searched function.
* ppProcedureAddress : Pointer at a location that on successfull return will contain
*    the in memory address of the searched function.
* Returns : TRUE on successfull retrieval, FALSE otherwise.
* REMARKS : There is no validation of the hModule value itself. However the retrieval
* of the exported artefact is tightly bound to the official PE format. Attempt to use
* a non legit hModule value would very likely fail. Should it succeed it is not
* expected to provide any advantage or bypass.
*/
BDHKMAPI __fastcall BOOL BdhkmResolveInlineFunctionAddress(
	_In_ HMODULE hModule,
	_In_ STRING functionName,
	_Inout_ PVOID* ppProcedureAddress);

UNEXPLORED BdhkmResolveRvaExportTableAddress
UNEXPLORED BdhkmResumeEatHook
UNEXPLORED BdhkmResumeIatHook
UNEXPLORED BdhkmResumeInlineHook
UNEXPLORED BdhkmResumePointerHook
UNEXPLORED BdhkmSuspendEatHook
UNEXPLORED BdhkmSuspendIatHook
UNEXPLORED BdhkmSuspendInlineHook
UNEXPLORED BdhkmSuspendPointerHook

/* Unregister a client context previously acquired by BdhkmRegisterClient or
* BdhkmRegisterClient2.
* clientContext : Registered client context.
* INVALID_PARAMETER_1 : clientContext is a null pointer.
*/
BDHKMAPI __fastcall NTSTATUS BdhkmUnregisterClient(
	_In_ PBDHKM_CLIENT_CONTEXT clientContext);
#endif