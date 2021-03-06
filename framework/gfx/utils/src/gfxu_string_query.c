#include "gfx/utils/inc/gfxu_string.h"

#include <stdlib.h>
#include <string.h>

#include "gfx/utils/inc/gfxu_string_utils.h"

/*typedef enum imageReaderState_t
{
    INTERNAL_STRING_TABLE_READ,
    ATTEMPT_STRING_ARRAY_SIZE_REQUEST,
    WAITING_FOR_STRING_ARRAY_SIZE,
    ATTEMPT_STRING_ENTRY_SIZE_REQUEST,
    WAITING_FOR_STRING_ENTRY_SIZE,
    ATTEMPT_STRING_DATA_REQUEST,
    WAITING_FOR_STRING_DATA,
    INTERNAL_FONT_DATA_READ,
    PREPARE_FONT_DATA_REQUEST,
    ATTEMPT_FONT_DATA_REQUEST,
    WAITING_FOR_FONT_DATA,
    DRAW_GLYPH_DATA,
    DONE
} imageReaderState;

typedef struct GFXU_StringQueryReader_t
{
    GFXU_ExternalAssetReader header;
    
    GFXU_StringTableAsset* string;
    GFXU_FontAsset* font;
    
    uint8_t* readAddress;
    uint32_t readCount;
    uint32_t readSize;
    
    uint32_t stringID;
    uint32_t entryID;
    
    uint8_t stringData[GFXU_STRING_MAX_CHAR_WIDTH];
    uint32_t codePoint;
    uint32_t stringWidth;
    
    uint32_t glyphOffset;
    uint32_t glyphWidth;
} GFXU_StringQueryReader;
*/
/*static void stringArraySizeRequestCompleted(GFXU_StringQueryReader* strReader)
{
    // have we iterated to the desired string array
    if(strReader->entryID == strReader->readCount)
    {
        strReader->readAddress += GFXU_STRING_ARRAY_SIZE;
        strReader->readCount = 0;
            
        strReader->header.state = ATTEMPT_STRING_ENTRY_SIZE_REQUEST;
        strReader->header.status = GFXU_READER_STATUS_READY;
    
        return;
    }
    
    // iterate to the next string array
    strReader->readAddress += strReader->readSize;
    strReader->readCount += 1;
    
    // read the next string table array size
    strReader->header.state = ATTEMPT_STRING_ARRAY_SIZE_REQUEST;
    strReader->header.status = GFXU_READER_STATUS_READY;
}*/

/*static GFX_Result requestStringArraySize(GFXU_StringQueryReader* strReader)
{
    // read the size of the next array of strings
    if(strReader->header.memIntf->read((GFXU_ExternalAssetReader*)strReader,
                                       strReader->string->header.dataLocation,
                                       strReader->readAddress,
                                       GFXU_STRING_ARRAY_SIZE,
                                       (uint8_t*)&strReader->readSize,
                                       (GFXU_MemoryReadRequestCallback_FnPtr)&stringArraySizeRequestCompleted) == GFX_FAILURE)
    {
        return GFX_FAILURE;
    }
        
    // wait for the next string table array size
    strReader->header.status = GFXU_READER_STATUS_WAITING;
    strReader->header.state = WAITING_FOR_STRING_ARRAY_SIZE; 
    
    return GFX_SUCCESS;                             
}*/

/*static void stringEntrySizeRequestCompleted(GFXU_StringQueryReader* strReader)
{
    // if this is the desired entry then read the next array of characters
    if(strReader->entryID == strReader->readCount)
    {
        strReader->readAddress += GFXU_STRING_ENTRY_SIZE;
        strReader->readCount = 0;
            
        strReader->header.state = ATTEMPT_STRING_DATA_REQUEST;
        strReader->header.status = GFXU_READER_STATUS_READY;
    
        return;
    }
    
    // move to the next string entry address
    strReader->readAddress += strReader->readSize;
    strReader->readCount += 1;
    
    // request the next string entry
    strReader->header.state = ATTEMPT_STRING_ENTRY_SIZE_REQUEST;
    strReader->header.status = GFXU_READER_STATUS_READY;
}*/

/*static GFX_Result requestStringEntrySize(GFXU_StringQueryReader* strReader)
{
    // request the size of the next entry
    if(strReader->header.memIntf->read((GFXU_ExternalAssetReader*)strReader,
                                       strReader->string->header.dataLocation,
                                       strReader->readAddress,
                                       GFXU_STRING_ENTRY_SIZE,
                                       (uint8_t*)&strReader->readSize,
                                       (GFXU_MemoryReadRequestCallback_FnPtr)&stringEntrySizeRequestCompleted) == GFX_FAILURE)
    {
        return GFX_FAILURE;
    }
        
    // wait for the string entry data
    strReader->header.status = GFXU_READER_STATUS_WAITING;
    strReader->header.state = WAITING_FOR_STRING_ENTRY_SIZE; 
    
    return GFX_SUCCESS;                             
}*/

/*static void stringDataRequestCompleted(GFXU_StringQueryReader* strReader)
{
    uint32_t charSize = 0;
    
    // attempt to calculate the code point for the glyph
    if(GFXU_DecodeGlyph(strReader->string->encodingMode,
                        strReader->stringData,
                        strReader->readSize - strReader->readCount,
                        &strReader->codePoint,
                        &charSize) == GFX_FAILURE)
    {
        // the string data is invalid, abort operation
        strReader->header.status = GFXU_READER_STATUS_FINISHED;
        strReader->header.state = DONE;
        
        return;
    }              
    
    // advance the string character read count
    strReader->readCount += charSize;
    strReader->readAddress += charSize;

    // get the font glyph info from one of the available lookup tables
    if(GFXU_FontGetGlyphInfo(strReader->font,
                             strReader->codePoint,
                             &strReader->glyphOffset,
                             &strReader->glyphWidth) == GFX_FAILURE)
    {
        // the glyph codepoint is not in the available ranges
        // skip this glyph
        strReader->header.state = ATTEMPT_STRING_DATA_REQUEST;
        strReader->header.status = GFXU_READER_STATUS_READY;
    }
    
    strReader->stringWidth += strReader->glyphWidth;
        
    strReader->header.status = GFXU_READER_STATUS_READY;
}*/

/*static GFX_Result requestStringData(GFXU_StringQueryReader* strReader)
{
    // have we read the entire string?
    if(strReader->readCount == strReader->readSize)
    {
        strReader->header.status = GFXU_READER_STATUS_FINISHED;
        strReader->header.state = DONE;
        
        strReader->header.result = (int32_t)strReader->glyphWidth;
        
        return GFX_SUCCESS; 
    }
    
    // read a chunk of string data
    if(strReader->header.memIntf->read((GFXU_ExternalAssetReader*)strReader,
                                       strReader->string->header.dataLocation,
                                       strReader->readAddress,
                                       strReader->readSize,
                                       (uint8_t*)&strReader->stringData,
                                       (GFXU_MemoryReadRequestCallback_FnPtr)&stringDataRequestCompleted) == GFX_FAILURE)
    {
        return GFX_FAILURE;
    }
        
    strReader->header.status = GFXU_READER_STATUS_WAITING;
    strReader->header.state = WAITING_FOR_STRING_DATA; 
    
    return GFX_SUCCESS;                             
}*/

/*static GFX_Result run(GFXU_ExternalAssetReader* reader)
{
    GFXU_StringQueryReader* strReader = (GFXU_StringQueryReader*)reader;
    
    if(strReader == GFX_NULL)
        return GFX_FAILURE;
    
    switch(strReader->header.state)
    {
        case ATTEMPT_STRING_ARRAY_SIZE_REQUEST:
            return requestStringArraySize(strReader);
        case ATTEMPT_STRING_ENTRY_SIZE_REQUEST:
            return requestStringEntrySize(strReader);
        case ATTEMPT_STRING_DATA_REQUEST:
            return requestStringData(strReader);
        default:
            return GFX_SUCCESS;
    }
}*/

/*
uint32_t calculateWidthExternal(GFXU_StringTableAsset* str,
                                GFXU_FontAsset* fnt,
                                uint32_t id,
                                uint32_t lang,
                                GFXU_MemoryIntf* memIntf,
                                GFXU_ExternalAssetReader** reader)
{
    GFXU_StringQueryReader* strReader;
    
    // create the reader state manager object
    strReader = (GFXU_StringQueryReader*)memIntf->heap.calloc(1, 
                                             sizeof(GFXU_StringQueryReader));
    
    if(strReader == GFX_NULL)
        return GFX_FAILURE;
    
    // set reader state manager member variables
    strReader->header.memIntf = memIntf;
    strReader->header.run = &run;
    strReader->header.status = GFXU_READER_STATUS_READY;
    
    strReader->string = str;
    strReader->stringID = id;
    strReader->entryID = lang;
    
    strReader->font = fnt;
    
    strReader->readAddress = (uint8_t*)str->header.dataAddress;
    
    // first thing to do is examine the string table
    if(strReader->string->header.dataLocation == GFXU_ASSET_LOCATION_INTERNAL)
        strReader->header.state = INTERNAL_STRING_TABLE_READ;
    else
        strReader->header.state = ATTEMPT_STRING_ARRAY_SIZE_REQUEST;
    
    // return the reader as a generic pointer
    *reader = (GFXU_ExternalAssetReader*)strReader;

    return GFX_SUCCESS;
}*/

GFXU_CHAR GFXU_GetCharAt(GFXU_StringTableAsset* tbl,
                         uint32_t id,
                         uint32_t lang,
                         uint32_t idx)
{
    GFXU_FontAsset* fnt = GFX_NULL;
    uint16_t stringIdx;
    uint8_t* stringAddress;
    uint32_t stringSize;
    uint32_t i, j;
    uint32_t codePoint;
    uint32_t offset = 0;
    
    if(tbl == GFX_NULL)
        return 0;
    
    fnt = GFXU_StringFontIndexLookup(tbl, id, lang);
    
    if(fnt == GFX_NULL)
        return 0;
    
    stringIdx = GFXU_StringIndexLookup(tbl, id, lang);
    
    if(GFXU_StringLookup(tbl, stringIdx, &stringAddress, &stringSize))
        return GFX_FAILURE;
    
    j = 0;
    
    for(i = 0; i < stringSize;)
    {
        if(GFXU_DecodeCodePoint(tbl->encodingMode,
                                stringAddress + i,
                                stringSize,
                                &codePoint,
                                &offset) == GFX_FAILURE)
            return GFX_FAILURE;
        
        i += offset;
        
        if(j == idx)
            return codePoint;
        
        j++;
    }
    
    return 0;
}

uint32_t GFXU_GetStringLength(GFXU_StringTableAsset* tbl,
                              uint32_t id,
                              uint32_t lang)
{
    uint16_t idx;
    uint8_t* stringAddress;
    uint32_t stringSize;
    uint32_t stringLength = 0;
    uint32_t codePoint;
    uint32_t offset = 0;
    uint32_t i;
    
    idx = GFXU_StringIndexLookup(tbl, id, lang);
    
    if(GFXU_StringLookup(tbl, idx, &stringAddress, &stringSize))
        return GFX_FAILURE;
        
    for(i = 0; i < stringSize;)
    {
        if(GFXU_DecodeCodePoint(tbl->encodingMode,
                                stringAddress + i,
                                stringSize,
                                &codePoint,
                                &offset) == GFX_FAILURE)
            return GFX_FAILURE;
        
        i += offset;
        
        stringLength += 1;
    }
        
    return stringLength;
}

uint32_t GFXU_GetStringSizeInBytes(GFXU_StringTableAsset* tbl,
                              uint32_t id,
                              uint32_t lang)
{
    uint16_t idx;
    uint8_t* stringAddress;
    uint32_t stringSize;
    
    idx = GFXU_StringIndexLookup(tbl, id, lang);
    
    if(GFXU_StringLookup(tbl, idx, &stringAddress, &stringSize))
        return GFX_FAILURE;
        
    return stringSize;
}

GFX_Result GFXU_GetStringRect(GFXU_StringTableAsset* tbl,
                              uint32_t id,
                              uint32_t lang,
                              GFX_Rect* rect)
{
    if(tbl == GFX_NULL ||
       id >= tbl->stringCount || 
       lang >= tbl->languageCount ||
       rect == GFX_NULL)
        return GFX_FAILURE;
        
    rect->x = 0;
    rect->y = 0;
    rect->width = GFXU_CalculateStringWidth(tbl, id, lang);
    rect->height = GFXU_GetStringHeight(tbl, id, lang);
    
    return GFX_SUCCESS;
}

static uint32_t calculateWidth(GFXU_StringTableAsset* tbl,
                               GFXU_FontAsset* fnt,
                               uint32_t id,
                               uint32_t lang)
{
    uint16_t idx;
    uint8_t* stringAddress;
    uint32_t stringSize;
    uint32_t i;
    uint32_t codePoint;
    uint32_t offset = 0;
    uint32_t width;
    uint32_t totalWidth = 0;
    
    if(tbl == GFX_NULL || fnt == GFX_NULL)
        return 0;
        
    idx = GFXU_StringIndexLookup(tbl, id, lang);
    
    if(GFXU_StringLookup(tbl, idx, &stringAddress, &stringSize))
        return GFX_FAILURE;
    
    for(i = 0; i < stringSize;)
    {
        if(GFXU_DecodeCodePoint(tbl->encodingMode,
                                stringAddress + i,
                                stringSize,
                                &codePoint,
                                &offset) == GFX_FAILURE)
            return GFX_FAILURE;
        
        i += offset;
        
        GFXU_FontGetGlyphInfo(fnt,
                              codePoint,
                              &offset,
                              &width);
            
        totalWidth += width;
    }
    
    return totalWidth;
}

static uint32_t calculatePartialWidth(GFXU_StringTableAsset* tbl,
                                      GFXU_FontAsset* fnt,
                                      uint32_t id,
                                      uint32_t lang,
                                      uint32_t length)
{
    uint16_t idx;
    uint8_t* stringAddress;
    uint32_t stringSize;
    uint32_t i;
    uint32_t codePoint;
    uint32_t offset = 0;
    uint32_t width;
    uint32_t totalWidth = 0;
    uint32_t maxLength = 0;
    
    if(tbl == GFX_NULL || fnt == GFX_NULL)
        return 0;
        
    maxLength = GFXU_GetStringLength(tbl, id, lang);
        
    if(length > maxLength)
        length = maxLength;
        
    idx = GFXU_StringIndexLookup(tbl, id, lang);
    
    if(GFXU_StringLookup(tbl, idx, &stringAddress, &stringSize))
        return GFX_FAILURE;
    
    idx = 0;
    
    for(i = 0; i < stringSize;)
    {
        if(GFXU_DecodeCodePoint(tbl->encodingMode,
                                stringAddress + i,
                                stringSize,
                                &codePoint,
                                &offset) == GFX_FAILURE)
            return GFX_FAILURE;
        
        i += offset;
        
        GFXU_FontGetGlyphInfo(fnt,
                              codePoint,
                              &offset,
                              &width);
            
        totalWidth += width;
        
        idx++;
        
        if(idx >= length)
            break;
    }
    
    return totalWidth;
}

uint32_t GFXU_GetStringHeight(GFXU_StringTableAsset* tbl,
                              uint32_t id,
                              uint32_t lang)
{
    GFXU_FontAsset* ast;
    
    if(tbl == NULL || id >= tbl->stringCount || lang >= tbl->languageCount)
        return 0;
        
    ast = GFXU_StringFontIndexLookup(tbl, id, lang);
    
    if(ast == GFX_NULL)
        return 0;
    
    return ast->height;
}

uint32_t GFXU_GetCharWidth(GFXU_CHAR chr, GFXU_FontAsset* fnt)
{
    uint32_t offset;
    uint32_t width;
    
    if(fnt == NULL)
        return 0;
    
    GFXU_FontGetGlyphInfo(fnt, chr, &offset, &width);
    
    return width;
}

uint32_t GFXU_CalculateStringWidth(GFXU_StringTableAsset* tbl, 
                                   uint32_t id,
                                   uint32_t lang)
{
    GFXU_FontAsset* fnt = GFX_NULL;
    
    if(tbl == GFX_NULL)
        return 0;
    
    fnt = GFXU_StringFontIndexLookup(tbl, id, lang);
    
    if(fnt == GFX_NULL)
        return 0;
        
    return calculateWidth(tbl, fnt, id, lang);
}

uint32_t GFXU_CalculatePartialStringWidth(GFXU_StringTableAsset* tbl, 
                                          uint32_t id,
                                          uint32_t lang,
                                          uint32_t length)
{
    GFXU_FontAsset* fnt = GFX_NULL;
    
    if(tbl == GFX_NULL)
        return 0;
    
    fnt = GFXU_StringFontIndexLookup(tbl, id, lang);
    
    if(fnt == GFX_NULL)
        return 0;
        
    return calculatePartialWidth(tbl, fnt, id, lang, length);
}

uint32_t GFXU_CalculateCharStringWidth(GFXU_CHAR* str, GFXU_FontAsset* fnt)
{
    uint32_t len;
    uint32_t codePoint;
    uint32_t offset;
    uint32_t totalWidth;
    uint32_t width;
    uint32_t i;
    
    len = 0;
    i = 0;
    
    if(str == NULL || fnt == NULL)
        return 0;
    
    while(str[len] != '\0')
        len++;
        
    if(len == 0)
        return 0;
    
    totalWidth = 0;
    
    for(i = 0; i < len; i++)
    {
        codePoint = str[i];
        
        GFXU_FontGetGlyphInfo(fnt,
                              codePoint,
                              &offset,
                              &width);
        
        totalWidth += width;
    }
    
    return totalWidth;
}

uint32_t GFXU_CalculatePartialCharStringWidth(GFXU_CHAR* str,
                                              GFXU_FontAsset* fnt,
                                              uint32_t size)
{
    uint32_t len;
    uint32_t codePoint;
    uint32_t offset;
    uint32_t totalWidth;
    uint32_t width;
    uint32_t i;
    
    len = 0;
    i = 0;
    
    if(str == NULL || fnt == NULL)
        return 0;
    
    while(str[len] != '\0')
        len++;
        
    if(len == 0)
        return 0;
        
    if(size > len)
        size = len;
    
    totalWidth = 0;
    
    for(i = 0; i < size; i++)
    {
        codePoint = str[i];
        
        GFXU_FontGetGlyphInfo(fnt,
                              codePoint,
                              &offset,
                              &width);
        
        totalWidth += width;
    }
    
    return totalWidth;
}