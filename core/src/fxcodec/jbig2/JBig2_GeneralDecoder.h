// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef _JBIG2_GENERAL_DECODER_H_
#define _JBIG2_GENERAL_DECODER_H_

#include "../../../include/fxcodec/fx_codec_def.h"
#include "../../../include/fxcrt/fx_coordinates.h"
#include "JBig2_ArithDecoder.h"
#include "JBig2_ArithIntDecoder.h"
#include "JBig2_Define.h"
#include "JBig2_SymbolDict.h"

class CJBig2_HuffmanTable;
class CJBig2_Image;
class CJBig2_PatternDict;
typedef enum {
    JBIG2_CORNER_BOTTOMLEFT = 0,
    JBIG2_CORNER_TOPLEFT	= 1,
    JBIG2_CORNER_BOTTOMRIGHT = 2,
    JBIG2_CORNER_TOPRIGHT	= 3
} JBig2Corner;
class CJBig2_GRDProc : public CJBig2_Object
{
public:
    CJBig2_GRDProc()
    {
        m_loopIndex = 0;
        m_pLine = NULL;
        m_pPause = NULL;
        m_DecodeType = 0;
        LTP = 0;
        m_ReplaceRect.left = 0;
        m_ReplaceRect.bottom = 0;
        m_ReplaceRect.top = 0;
        m_ReplaceRect.right = 0;
    }

    CJBig2_Image *decode_Arith(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_V2(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_V1(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_MMR(CJBig2_BitStream *pStream);
    FXCODEC_STATUS Start_decode_Arith(CJBig2_Image** pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause = NULL);
    FXCODEC_STATUS Start_decode_Arith_V2(CJBig2_Image** pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause = NULL);
    FXCODEC_STATUS Start_decode_Arith_V1(CJBig2_Image** pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause = NULL);
    FXCODEC_STATUS Start_decode_MMR(CJBig2_Image** pImage, CJBig2_BitStream *pStream, IFX_Pause* pPause = NULL);
    FXCODEC_STATUS Continue_decode(IFX_Pause* pPause);
    FX_RECT		   GetReplaceRect()
    {
        return m_ReplaceRect;
    };
private:
    FXCODEC_STATUS decode_Arith(IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_V2(IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_V1(IFX_Pause* pPause);
    FXCODEC_STATUS decode_MMR();
    FXCODEC_STATUS decode_Arith_Template0_opt3(CJBig2_Image*pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_Template0_unopt(CJBig2_Image *pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_Template1_opt3(CJBig2_Image *pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_Template1_unopt(CJBig2_Image * pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_Template2_opt3(CJBig2_Image *pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_Template2_unopt(CJBig2_Image * pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_Template3_opt3(CJBig2_Image *pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FXCODEC_STATUS decode_Arith_Template3_unopt(CJBig2_Image * pImage, CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);
    FX_DWORD	m_loopIndex;
    uint8_t *	m_pLine;
    IFX_Pause*	m_pPause;
    FXCODEC_STATUS	m_ProssiveStatus;
    CJBig2_Image** m_pImage;
    CJBig2_ArithDecoder *m_pArithDecoder;
    JBig2ArithCtx *m_gbContext;
    FX_WORD		m_DecodeType;
    bool LTP;
    FX_RECT m_ReplaceRect;
private:

    CJBig2_Image *decode_Arith_Template0_opt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template0_opt2(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template0_opt3(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template0_unopt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template1_opt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template1_opt2(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template1_opt3(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template1_unopt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template2_opt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template2_opt2(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template2_opt3(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template2_unopt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template3_opt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template3_opt2(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template3_opt3(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);

    CJBig2_Image *decode_Arith_Template3_unopt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext);
public:
    bool MMR;
    FX_DWORD GBW;
    FX_DWORD GBH;
    uint8_t GBTEMPLATE;
    bool TPGDON;
    bool USESKIP;
    CJBig2_Image * SKIP;
    signed char GBAT[8];
};
class CJBig2_GRRDProc : public CJBig2_Object
{
public:

    CJBig2_Image *decode(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *grContext);

    CJBig2_Image *decode_Template0_unopt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *grContext);

    CJBig2_Image *decode_Template0_opt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *grContext);

    CJBig2_Image *decode_Template1_unopt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *grContext);

    CJBig2_Image *decode_Template1_opt(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *grContext);

    CJBig2_Image *decode_V1(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *grContext);
public:
    FX_DWORD GRW;
    FX_DWORD GRH;
    bool GRTEMPLATE;
    CJBig2_Image *GRREFERENCE;
    int32_t GRREFERENCEDX;
    int32_t GRREFERENCEDY;
    bool TPGRON;
    signed char	GRAT[4];
};
typedef struct {
    CJBig2_ArithIntDecoder *IADT,
                           *IAFS,
                           *IADS,
                           *IAIT,
                           *IARI,
                           *IARDW,
                           *IARDH,
                           *IARDX,
                           *IARDY;
    CJBig2_ArithIaidDecoder *IAID;
} JBig2IntDecoderState;
class CJBig2_TRDProc : public CJBig2_Object
{
public:

    CJBig2_Image *decode_Huffman(CJBig2_BitStream *pStream, JBig2ArithCtx *grContext);

    CJBig2_Image *decode_Arith(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *grContext,
                               JBig2IntDecoderState *pIDS = NULL);
public:
    bool SBHUFF;
    bool SBREFINE;
    FX_DWORD SBW;
    FX_DWORD SBH;
    FX_DWORD SBNUMINSTANCES;
    FX_DWORD SBSTRIPS;
    FX_DWORD SBNUMSYMS;

    JBig2HuffmanCode *SBSYMCODES;
    uint8_t SBSYMCODELEN;

    CJBig2_Image **SBSYMS;
    bool SBDEFPIXEL;

    JBig2ComposeOp SBCOMBOP;
    bool TRANSPOSED;

    JBig2Corner REFCORNER;
    signed char SBDSOFFSET;
    CJBig2_HuffmanTable *SBHUFFFS,
                        *SBHUFFDS,
                        *SBHUFFDT,
                        *SBHUFFRDW,
                        *SBHUFFRDH,
                        *SBHUFFRDX,
                        *SBHUFFRDY,
                        *SBHUFFRSIZE;
    bool SBRTEMPLATE;
    signed char SBRAT[4];
};
class CJBig2_SDDProc : public CJBig2_Object
{
public:

    CJBig2_SymbolDict *decode_Arith(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, JBig2ArithCtx *grContext);

    CJBig2_SymbolDict *decode_Huffman(CJBig2_BitStream *pStream, JBig2ArithCtx *gbContext, JBig2ArithCtx *grContext, IFX_Pause* pPause);
public:
    bool SDHUFF;
    bool SDREFAGG;
    FX_DWORD SDNUMINSYMS;
    CJBig2_Image ** SDINSYMS;
    FX_DWORD SDNUMNEWSYMS;
    FX_DWORD SDNUMEXSYMS;
    CJBig2_HuffmanTable *SDHUFFDH,
                        *SDHUFFDW,
                        *SDHUFFBMSIZE,
                        *SDHUFFAGGINST;
    uint8_t SDTEMPLATE;
    signed char SDAT[8];
    bool SDRTEMPLATE;
    signed char SDRAT[4];
};
class CJBig2_HTRDProc : public CJBig2_Object
{
public:

    CJBig2_Image *decode_Arith(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);

    CJBig2_Image *decode_MMR(CJBig2_BitStream *pStream, IFX_Pause* pPause);
public:
    FX_DWORD HBW,
             HBH;
    bool HMMR;
    uint8_t HTEMPLATE;
    FX_DWORD HNUMPATS;
    CJBig2_Image **HPATS;
    bool HDEFPIXEL;
    JBig2ComposeOp HCOMBOP;
    bool HENABLESKIP;
    FX_DWORD HGW,
             HGH;
    int32_t HGX,
             HGY;
    FX_WORD HRX,
            HRY;
    uint8_t HPW,
            HPH;
};
class CJBig2_PDDProc : public CJBig2_Object
{
public:

    CJBig2_PatternDict *decode_Arith(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);

    CJBig2_PatternDict *decode_MMR(CJBig2_BitStream *pStream, IFX_Pause* pPause);
public:
    bool HDMMR;
    uint8_t HDPW,
            HDPH;
    FX_DWORD GRAYMAX;
    uint8_t HDTEMPLATE;
};
class CJBig2_GSIDProc : public CJBig2_Object
{
public:

    FX_DWORD *decode_Arith(CJBig2_ArithDecoder *pArithDecoder, JBig2ArithCtx *gbContext, IFX_Pause* pPause);

    FX_DWORD *decode_MMR(CJBig2_BitStream *pStream, IFX_Pause* pPause);
public:
    bool GSMMR;
    bool GSUSESKIP;
    uint8_t GSBPP;
    FX_DWORD GSW,
             GSH;
    uint8_t GSTEMPLATE;
    CJBig2_Image *GSKIP;
};
#endif
