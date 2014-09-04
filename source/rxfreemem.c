#define RETURN_INVALID                   40
#define RETURN_OK                        0
#define INCL_DOSMISC
#define INCL_REXXSAA
#include <os2.h>
#include <rexxsaa.h>
#include <stdlib.h>
#include <string.h>

RexxFunctionHandler RxFreeMem;

ULONG RxFreeMem(CHAR *name,
                ULONG numargs,
                RXSTRING args[],
                CHAR *qjunk,
                RXSTRING *rstring)
{
   ULONG freeMem;
   CHAR retbuff[11], argtemp[257], argbuff;

   if (numargs>1)
      return RETURN_INVALID;

   if (numargs==0)
      {
      argbuff='P';
      }
   else
      {
      strncpy(argtemp, args[0].strptr, args[0].strlength);
      argtemp[args[0].strlength]=0x00;
      }

   if (!strcmpi(argtemp, "virtual") || !strcmpi(argtemp, "v"))
      {
      DosQuerySysInfo(QSV_TOTAVAILMEM, QSV_TOTAVAILMEM, &freeMem, sizeof(freeMem));
      }
   else if (!strcmpi(argtemp, "physical") || !strcmpi(argtemp, "p"))
      {
      APIRET16 APIENTRY16 Dos16MemAvail(PULONG fMem);
      Dos16MemAvail(&freeMem);
      }
   else
      return RETURN_INVALID;

   _itoa(freeMem, retbuff, 10);
   strcpy(rstring->strptr, retbuff);
   rstring->strlength=strlen(retbuff);

   return RETURN_OK;
}
