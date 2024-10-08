/**************************************************************************************************
*                                                                                                 *
* This file is part of BLASFEO.                                                                   *
*                                                                                                 *
* BLASFEO -- BLAS for embedded optimization.                                                      *
* Copyright (C) 2019 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* The 2-Clause BSD License                                                                        *
*                                                                                                 *
* Redistribution and use in source and binary forms, with or without                              *
* modification, are permitted provided that the following conditions are met:                     *
*                                                                                                 *
* 1. Redistributions of source code must retain the above copyright notice, this                  *
*    list of conditions and the following disclaimer.                                             *
* 2. Redistributions in binary form must reproduce the above copyright notice,                    *
*    this list of conditions and the following disclaimer in the documentation                    *
*    and/or other materials provided with the distribution.                                       *
*                                                                                                 *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND                 *
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED                   *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE                          *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR                 *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES                  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;                    *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND                     *
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT                      *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS                   *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                    *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include <blasfeo_common.h>
#include <blasfeo_d_kernel.h>
#if defined(BLASFEO_REF_API)
#include <blasfeo_d_blasfeo_ref_api.h>
#endif



// dgemm with A diagonal matrix (stored as strvec)
void blasfeo_hp_dgemm_dn(int m, int n, double alpha, struct blasfeo_dvec *sA, int ai, struct blasfeo_dmat *sB, int bi, int bj, double beta, struct blasfeo_dmat *sC, int ci, int cj, struct blasfeo_dmat *sD, int di, int dj)
	{
#if defined(BLASFEO_REF_API)
	blasfeo_ref_dgemm_dn(m, n, alpha, sA, ai, sB, bi, bj, beta, sC, ci, cj, sD, di, dj);
#else
#ifdef EXT_DEP
	printf("\nblasfeo_dgemm_dn: feature not implemented yet\n");
#endif	
	exit(1);
#endif
	}



// dgemm with B diagonal matrix (stored as strvec)
void blasfeo_hp_dgemm_nd(int m, int n, double alpha, struct blasfeo_dmat *sA, int ai, int aj, struct blasfeo_dvec *sB, int bi, double beta, struct blasfeo_dmat *sC, int ci, int cj, struct blasfeo_dmat *sD, int di, int dj)
	{
#if defined(BLASFEO_REF_API)
	blasfeo_ref_dgemm_nd(m, n, alpha, sA, ai, aj, sB, bi, beta, sC, ci, cj, sD, di, dj);
#else
#ifdef EXT_DEP
	printf("\nblasfeo_dgemm_nd: feature not implemented yet\n");
#endif	
	exit(1);
#endif
	}



#if defined(LA_HIGH_PERFORMANCE)



void blasfeo_dgemm_dn(int m, int n, double alpha, struct blasfeo_dvec *sA, int ai, struct blasfeo_dmat *sB, int bi, int bj, double beta, struct blasfeo_dmat *sC, int ci, int cj, struct blasfeo_dmat *sD, int di, int dj)
	{
	blasfeo_hp_dgemm_dn(m, n, alpha, sA, ai, sB, bi, bj, beta, sC, ci, cj, sD, di, dj);
	}



void blasfeo_dgemm_nd(int m, int n, double alpha, struct blasfeo_dmat *sA, int ai, int aj, struct blasfeo_dvec *sB, int bi, double beta, struct blasfeo_dmat *sC, int ci, int cj, struct blasfeo_dmat *sD, int di, int dj)
	{
	blasfeo_hp_dgemm_nd(m, n, alpha, sA, ai, aj, sB, bi, beta, sC, ci, cj, sD, di, dj);
	}



#endif

