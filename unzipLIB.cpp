//
// unzipLIB
// written by Larry Bank
// bitbank@pobox.com
//
// Copyright 2021 BitBank Software, Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//    http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//===========================================================================
#include "unzipLIB.h"

int UNZIP::open(uint8_t *pData, int iDataSize)
{
    _zip.pfnSeek = memSeek;
    _zip.pfnRead = memRead;
    _zip.pData = pData;
    _zip.iSize = iDataSize;
} /* open() */

int UNZIP::open(const char *szFilename, ZIP_OPEN_CALLBACK *pfnOpen, ZIP_CLOSE_CALLBACK *pfnClose, ZIP_READ_CALLBACK *pfnRead, ZIP_SEEK_CALLBACK *pfnSeek)
{
    _zip.pfnSeek = pfnSeek;
    _zip.pfnRead = pfnRead;
    _zip.pfnClose = pfnClose;

} /* open() */
void UNZIP::close();
int UNZIP::openCurrentFile();
void UNZIP::closeCurrentFile();
int UNZIP::readCurrentFile(uint8_t *buffer, int iLength);
int UNZIP::getCurrentFilePos();
int UNZIP::gotoFirstFile();
int UNZIP::gotoNextFile();
int UNZIP::locateFile(const char *szFilename);
int UNZIP::getFileInfo(FILEINFO *pInfo); // get info about the current file
int UNZIP::getLastError();
int UNZIP::getComment(char *destBuffer);
