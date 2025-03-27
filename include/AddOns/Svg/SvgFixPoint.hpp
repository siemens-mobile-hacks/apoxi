/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgFixPoint_hpp)
#define Apoxi_SvgFixPoint_hpp

typedef INT32 SvgFixPoint;

struct S_SvgFixPointTrans
{
    SvgFixPoint x_scale, y_scale; 
    SvgFixPoint x_trans, y_trans; 
    SvgFixPoint x_shear, y_shear; 
}; 
typedef struct S_SvgFixPointTrans SvgFixPointTrans; 

#define SVG_FP_TRANS_GET_X_SCALE(T) ((T)->x_scale)
#define SVG_FP_TRANS_GET_Y_SCALE(T) ((T)->y_scale)
#define SVG_FP_TRANS_GET_X_TRANS(T) ((T)->x_trans)
#define SVG_FP_TRANS_GET_Y_TRANS(T) ((T)->y_trans)
#define SVG_FP_TRANS_GET_X_SHEAR(T) ((T)->x_shear)
#define SVG_FP_TRANS_GET_Y_SHEAR(T) ((T)->y_shear)

#define SVG_FP_TRANS_SET_X_SCALE(T, V) (((T)->x_scale) = (V)); 
#define SVG_FP_TRANS_SET_Y_SCALE(T, V) (((T)->y_scale) = (V)); 
#define SVG_FP_TRANS_SET_X_TRANS(T, V) (((T)->x_trans) = (V)); 
#define SVG_FP_TRANS_SET_Y_TRANS(T, V) (((T)->y_trans) = (V)); 
#define SVG_FP_TRANS_SET_X_SHEAR(T, V) (((T)->x_shear) = (V)); 
#define SVG_FP_TRANS_SET_Y_SHEAR(T, V) (((T)->y_shear) = (V)); 

#define SVG_FP_INT_TO_FP(V) ((V) << 16)
#define SVG_FP_FP_TO_INT(V) ((V) >> 16)

void SvgFixPoint_Transform_Print(SvgFixPointTrans *a); 
void SvgFixPoint_Transform_Init(SvgFixPointTrans *a); 
void SvgFixPoint_Transform_Scale(SvgFixPointTrans *a, const SvgFixPoint scale_factor, const SvgFixPoint x_center, const SvgFixPoint y_center); 
void SvgFixPoint_Transform_XY_Scale(SvgFixPointTrans *a, const SvgFixPoint xs, const SvgFixPoint ys, const SvgFixPoint x_center, const SvgFixPoint y_center); 
void SvgFixPoint_Transform_Translate(SvgFixPointTrans *a, const SvgFixPoint x_trans, const SvgFixPoint y_trans); 
void SvgFixPoint_Transform_Rotate(SvgFixPointTrans *a, const SvgFixPoint angle, const SvgFixPoint x_center, const SvgFixPoint y_center); 

#define SvgFixPoint_Scalar_Add(A, B) ((A) + (B)) 
#define SvgFixPoint_Scalar_Sub(A, B) ((A) - (B)) 

SvgFixPoint SvgFixPoint_Scalar_Mul(const SvgFixPoint a, const SvgFixPoint b); 
void SvgFixPoint_Scalar_Print(SvgFixPoint a); 

#endif

