//============================================================
//
//  title  : GoogleTest手動テストコードの定義、宣言 [Manualtest.h]
//  Author : 原田 陽央
//   Date  : 2021/10/11
//  Update : 2021/10/13
//
//============================================================
//#pragma once
#include "gtest/gtest.h"
#include "../DoublyLinkedList/doublyLinkedList.h"


#if !defined ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___
#define      ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___

//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// マクロ定義
//--------------------------------------------------------------------------------
// コンパイル関連手動テスト(リスト)

// リストが空である場合の戻り値のテスト
#define TT_TEST_GET_DATA_NUM_IS_NULL

// リスト末尾への挿入を行った際の戻り値のテスト
#define TT_TEST_LIST_END_INSERT_RETURN_1

// リスト末尾への挿入が失敗した際の戻り値のテスト
#define TT_TEST_LIST_END_INSERT_RETURN_0

// データの挿入を行った際の戻り値
#define TT_TEST_DATA_END_INSERT_RETURN_1


// ※コンパイルが通れば成功
//#define TT_TEST_GET_DATA_NUM_WHEN_CONST

// ※コンパイルが通らなければ成功
//#define TT_TEST_INSERT_WHEN_CONST


#endif // ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___
