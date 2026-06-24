/*++

Copyright (c) 1998  Intel Corporation

Module Name:

    str.c

Abstract:

    String runtime functions


Revision History

--*/

#include "lib.h"

INTN
RUNTIMEFUNCTION
RtStrCmp (
    IN CONST CHAR16   *s1,
    IN CONST CHAR16   *s2
    )
// compare strings
{
    while (*s1) {
        if (*s1 != *s2) {
            break;
        }

        s1 += 1;
        s2 += 1;
    }

    return *s1 - *s2;
}

VOID
RUNTIMEFUNCTION
RtStrCpy (
    IN CHAR16   *Dest,
    IN CONST CHAR16   *Src
    )
// copy strings
{
    while (*Src) {
        *(Dest++) = *(Src++);
    }
    *Dest = 0;
}

VOID
RUNTIMEFUNCTION
RtStrnCpy (
    IN CHAR16   *Dest,
    IN CONST CHAR16   *Src,
    IN UINTN     Len
    )
// copy strings
{
    
    UINTN Size = RtStrnLen(Src, Len);
    if (Size != Len)
        RtSetMem(Dest + Size, (Len - Size) * sizeof(CHAR16), '\0');
    RtCopyMemC(Dest, Src, Size * sizeof(CHAR16));
}

CHAR16 *
RUNTIMEFUNCTION
RtStpCpy (
    IN CHAR16   *Dest,
    IN CONST CHAR16   *Src
    )
// copy strings
{
    while (*Src) {
        *(Dest++) = *(Src++);
    }
    *Dest = 0;
    return Dest;
}

CHAR16 *
RUNTIMEFUNCTION
RtStpnCpy (
    IN CHAR16   *Dest,
    IN CONST CHAR16   *Src,
    IN UINTN     Len
    )
// copy strings
{
    
    UINTN Size = RtStrnLen(Src, Len);
    if (Size != Len)
        RtSetMem(Dest + Size, (Len - Size) * sizeof(CHAR16), '\0');
    RtCopyMemC(Dest, Src, Size * sizeof(CHAR16));
    return Dest + Size;
}

VOID
RUNTIMEFUNCTION
RtStrCat (
    IN CHAR16   *Dest,
    IN CONST CHAR16   *Src
    )
{
    RtStrCpy(Dest+RtStrLen(Dest), Src);
}

VOID
RUNTIMEFUNCTION
RtStrnCat (
    IN CHAR16   *Dest,
    IN CONST CHAR16   *Src,
    IN UINTN    Len
    )
{
    UINTN DestSize, Size;

    DestSize = RtStrLen(Dest);
    Size = RtStrnLen(Src, Len);
    RtCopyMemC(Dest + DestSize, Src, Size * sizeof(CHAR16));
    Dest[DestSize + Size] = '\0';
}

UINTN
RUNTIMEFUNCTION
RtStrLen (
    IN CONST CHAR16   *s1
    )
// string length
{
    UINTN        len;

    for (len=0; *s1; s1+=1, len+=1) ;
    return len;
}

UINTN
RUNTIMEFUNCTION
RtStrnLen (
    IN CONST CHAR16   *s1,
    IN UINTN           Len
    )
// string length
{
    UINTN i;
    for (i = 0; *s1 && i < Len; i++)
        s1++;
    return i;
}

UINTN
RUNTIMEFUNCTION
RtStrSize (
    IN CONST CHAR16   *s1
    )
// string size
{
    UINTN        len;

    for (len=0; *s1; s1+=1, len+=1) ;
    return (len + 1) * sizeof(CHAR16);
}

UINT8
RUNTIMEFUNCTION
RtBCDtoDecimal(
    IN  UINT8 BcdValue
    )
{
    UINTN   High, Low;

    High    = BcdValue >> 4;
    Low     = BcdValue - (High << 4);

    return ((UINT8)(Low + (High * 10)));
}

UINT8
RUNTIMEFUNCTION
RtDecimaltoBCD (
    IN  UINT8 DecValue
    )
{
    UINTN   High, Low;

    High    = DecValue / 10;
    Low     = DecValue - (High * 10);

    return ((UINT8)(Low + (High << 4)));
}
