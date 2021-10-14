//============================================================
//
//  title  : GoogleTest手動テストコード [Manualtest.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/11
//  Update : 2021/10/13
//
//============================================================
//#include "gtest/gtest.h"
//#include <gtest/gtest.h>
//#include "../DoublyLinkedList/doublyLinkedList.h"
#include "pch.h"


//namespace ex01_DataStructure
//{
//	namespace chapter2
//	{
//		
//	}
//}


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
/**********************************************************************************//**
	@brief		データ数の取得機能について、リストが空である場合の戻り値のテスト
	@details	ID:リスト-0(手動)\n
				データ数の取得機能のテストです。\n
				リストが空である場合の戻り値を確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_GET_DATA_NUM_IS_NULLマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(GetDataCountTest, TestGetDataNum)
{
#if defined TT_TEST_GET_DATA_NUM_IS_NULL
	DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataCount());
#endif //TT_TEST_GET_DATA_NUM_IS_NULL
	SUCCEED();
}


/**********************************************************************************//**
	@brief		データ数の取得機能について、リスト末尾への挿入を行った際の戻り値のテスト
	@details	ID:リスト-1(手動)\n
				データ数の取得機能のテストです。\n
				リスト末尾への挿入を行った際の戻り値を確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_LIST_END_INSERT_RETURN_1マクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(ListEndInsertReturn1Test, TestGetDataNum)
{
#if defined TT_TEST_LIST_END_INSERT_RETURN_1
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	list.Insert(it);
	EXPECT_EQ(1, list.GetDataCount());
#endif //TT_TEST_LIST_END_INSERT_RETURN_1
	SUCCEED();
}


/**********************************************************************************//**
	@brief		データ数の取得機能について、リスト末尾への挿入が失敗した際の戻り値のテスト
	@details	ID:リスト-2(手動)\n
				データ数の取得機能のテストです。\n
				リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_LIST_END_INSERT_RETURN_0マクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(ListEndInsertReturn0Test, TestGetDataNum)
{
#if defined TT_TEST_LIST_END_INSERT_RETURN_0
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it;
	list.Insert(it);
	EXPECT_EQ(0, list.GetDataCount());
#endif //TT_TEST_LIST_END_INSERT_RETURN_0
	SUCCEED();
}


/**********************************************************************************//**
	@brief		データ数の取得機能について、データの挿入を行った際の戻り値のテスト
	@details	ID:リスト-3(手動)\n
				データ数の取得機能のテストです。\n
				データの挿入を行った際の戻り値を確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_DATA_END_INSERT_RETURN_1マクロを定義すると有効になります。\n
*//***********************************************************************************/
//TEST(ListEndInsertReturn0Test, TestGetDataNum)
//{
//#if defined TT_TEST_DATA_END_INSERT_RETURN_1
//	DoublyLinkedList list;
//	DoublyLinkedList::Iterator it;
//	list.Insert(it);
//	EXPECT_EQ(0, list.GetDataCount());
//#endif //TT_TEST_DATA_END_INSERT_RETURN_1
//	SUCCEED();
//}