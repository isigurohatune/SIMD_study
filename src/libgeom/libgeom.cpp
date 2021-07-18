// libgeom.cpp : スタティック ライブラリ用の関数を定義します。
//
#include "pch.h"
#include <intrin.h>
#include "../include/libgeom.h"

// 4つのfloat が num個の配列をsrcからdstにコピー
void copy_vector4_array(float* dst, const float* src, int num)
{
#if 1

	for (int i = 0; i < num * 4; i += 4)
	{

		__m128 pd = _mm_load_ps(src + i);
		_mm_store_ps( dst + i, pd);

	}
	// ToDo: SIMD計算を使って実装して下さい
#else
	float* pd = dst;
	const float* ps = src;
#endif
	
}

// 4つのfloat が num個の配列 src0, src1を足してdstに出力
void add_vector4_array(float* dst, const float* src0, const float* src1, int num)
{
#if 1
	for (int i = 0; i < num * 4; i += 4) 
	{
		__m128 ps0 = _mm_load_ps(src0 + i);
		__m128 ps1 = _mm_load_ps(src1 + i);

		__m128 ps = _mm_add_ps(ps0, ps1);
		_mm_store_ps(dst + i, ps);
	}

	// ToDo: SIMD計算を使って実装して下さい
#else
	float* pd = dst;
	const float* ps0 = src0;
	const float* ps1 = src1;
	}
#endif
}

// 4つのfloat に num個の配列 src にmatrix[4][4] の行列を掛けてdstに出力
void apply_matrix_vector4_array(float* dst, const float* src, const float* matrix, int num)
{
#if 1
	for (int i = 0; i < num * 4; i += 4) 
	{
		__m128 ps = _mm_load_ps(src + i);
		__m128 mat = _mm_load_ps(matrix + i);

		__m128 a = _mm_mul_ps(ps, mat);
		_mm_store_ps(dst + i,a);


	}
	// ToDo: SIMD計算を使って実装して下さい
#else
	float* pd = dst;
	const float* ps = src;
	}
#endif
}
