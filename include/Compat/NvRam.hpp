/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AdcExtensions_NvRam_hpp)
#define Apoxi_AdcExtensions_NvRam_hpp

/* Read from Nv-Ram starting from addr len bytes and store it into data */
void NvRamRead(void *addr, void *data, INT len);

/* Write len bytes data into Nv-Ram starting at addr */
void NvRamWrite(void *addr, void *data, INT len);

/* Return starting address of Nv-Ram */
void *GetNvRamStartAddress();

/* Return size of Nv-Ram */
INT GetNvRamSize();

#endif //Apoxi_AdcExtensions_NvRam_hpp

