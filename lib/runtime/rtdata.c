/*++

Copyright (c) 1998  Intel Corporation

Module Name:

    data.c

Abstract:

    EFI library global data



Revision History

--*/

#include "lib.h"


//
// RT - pointer to the runtime table
//

EFI_RUNTIME_SERVICES    *RT;

//
// LibStandalone - TRUE if lib is linked in as part of the firmware.
// N.B. The EFI fw sets this value directly
//

BOOLEAN  LibFwInstance;

//
// EFIDebug - Debug mask
//

UINTN    EFIDebug    = EFI_DBUG_MASK;

//
// LibRuntimeDebugOut - Runtime Debug Output device
//

SIMPLE_TEXT_OUTPUT_INTERFACE    *LibRuntimeDebugOut;

//
// LibRuntimeRaiseTPL, LibRuntimeRestoreTPL - pointers to Runtime functions from the 
//                                            Boot Services Table
//

EFI_RAISE_TPL   LibRuntimeRaiseTPL   = NULL;
EFI_RESTORE_TPL LibRuntimeRestoreTPL = NULL;

