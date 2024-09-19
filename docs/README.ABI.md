1) When using gnu-efi 4.0 with an application which was written
for gnu-efi 3.0, it may be required to set the `GNU_EFI_3_0_COMPAT` compile flag
this changes the default versions of some changed functions back to their prior
versions

   This currently includes the following functions:
   - ReallocatePool
   - CopyMem
   - CompareGuid

2) Applications which haven't been updated in a while may also be missing the
required `.rodata` section which contains needed read-only data which will prevent
any binary missing this section from running correctly