//============================================================
//
//  title  : GoogleTest手動テストコード [test.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
#include "pch.h"


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------

//=================================== データ数の取得 ===================================
/**********************************************************************************//**
	@brief		データ数の取得機能について、constのメソッドであるかのテスト
	@details	ID:リスト-8(手動)\n
				データ数の取得機能のテストです。\n
				constのメソッドであるかを確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_DATA_IS_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataCountIsConstTest)
{
#if defined TT_TEST_DATA_COUNT_IS_CONST
	const DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataCount());

#endif //TT_TEST_DATA_IS_CONST
	SUCCEED();
}


//=================================== データの挿入 ===================================
/**********************************************************************************//**
	@brief		データの挿入機能について、非constのメソッドであるかのテスト
	@details	ID:リスト-15(手動)\n
				データの挿入機能のテストです。\n
				非constのメソッドであるかを確認しています。\n
				有効にしてコンパイルが通らなければ成功です。\n
				TT_TEST_DATA_INSERT_IS_NO_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestInsertData, DataInsertIsNoConstTest)
{
#if defined TT_TEST_DATA_INSERT_IS_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	EXPECT_EQ(0, list.Insert(it, 1, "a"));

#endif //TT_TEST_DATA_INSERT_IS_NO_CONST
	SUCCEED();
}


//=================================== データの削除 ===================================
/**********************************************************************************//**
	@brief		データの削除機能について、非constのメソッドであるかのテスト
	@details	ID:リスト-22\n
				データの削除機能のテストです。\n
				非constのメソッドであるかを確認しています。\n
				有効にしてコンパイルが通らなければ成功です。\n
				TT_TEST_DATA_REMOVE_IS_NO_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestRemoveData, DataRemoveIsNoConstTest)
{
#if defined TT_TEST_DATA_REMOVE_IS_NO_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	EXPECT_EQ(0, list.Remove(it));

#endif //TT_TEST_DATA_REMOVE_IS_NO_CONST
	SUCCEED();
}


//=============================== 先頭イテレータの取得 ================================
/**********************************************************************************//**
	@brief		先頭イテレータの取得機能について、constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェックのテスト
	@details	ID:リスト-28\n
				先頭イテレータの取得機能のテストです。\n
				constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェックを確認しています。\n
				有効にしてコンパイルが通らなければ成功です。\n
				TT_TEST_CONSTLIST_GET_TOPITERATORマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestGetTopIterator, ConstListGetTopIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_TOPITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();

#endif //TT_TEST_CONSTLIST_GET_TOPITERATOR
	SUCCEED();
}


//======================== 先頭コンストイテレータの取得 ================================
/**********************************************************************************//**
	@brief		先頭コンストイテレータの取得機能について、constのメソッドであるかのテスト
	@details	ID:リスト-34\n
				先頭コンストイテレータの取得機能のテストです。\n
				constのメソッドであるかを確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_CONSTLIST_GET_TOPCONSTITERATORマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, ConstListGetTopConstIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_TOPCONSTITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();

#endif //TT_TEST_CONSTLIST_GET_TOPCONSTITERATOR
	SUCCEED();
}


//=============================== 末尾イテレータの取得 ================================
/**********************************************************************************//**
	@brief		末尾イテレータの取得機能について、constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェックのテスト
	@details	ID:リスト-40\n
				先頭イテレータの取得機能のテストです。\n
				constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェックを確認しています。\n
				有効にしてコンパイルが通らなければ成功です。\n
				TT_TEST_CONSTLIST_GET_ENDITERATORマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestGetTopIterator, ConstListGetEndIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_ENDITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetEndIterator();

#endif //TT_TEST_CONSTLIST_GET_ENDITERATOR
	SUCCEED();
}


//======================== 末尾コンストイテレータの取得 ================================
/**********************************************************************************//**
	@brief		末尾コンストイテレータの取得機能について、constのメソッドであるかのテスト
	@details	ID:リスト-46\n
				末尾コンストイテレータの取得機能のテストです。\n
				constのメソッドであるかを確認しています。\n
				有効にしてコンパイルが通れば成功です。\n
				TT_TEST_CONSTLIST_GET_ENDCONSTITERATORマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, ConstListGetEndConstIteratorTest)
{
#if defined TT_TEST_CONSTLIST_GET_ENDCONSTITERATOR
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetEndConstIterator();

#endif //TT_TEST_CONSTLIST_GET_ENDCONSTITERATOR
	SUCCEED();
}


//======================== イテレータの指す要素を取得する =============================
/**********************************************************************************//**
	@brief		イテレータの指す要素を取得する機能について、ConstIteratorから取得した要素に対して、値の代入が行えないかをチェックのテスト
	@details	ID:Iterator-2\n
				イテレータの指す要素を取得する機能のテストです。\n
				ConstIteratorから取得した要素に対して、値の代入が行えないかをチェックを確認しています。\n
				有効にしてコンパイルが通らなければ成功です。\n
				TT_TEST_GET_CONSTITERATOR_SUBSTITUTIONマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetConstIteratorSubstitutionTest)
{
#if defined TT_TEST_GET_CONSTITERATOR_SUBSTITUTION

	// データを用意
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// データの代入
	RecordData data = {2, "bb"};
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	it.GetConstData() = data;


#endif //TT_TEST_GET_CONSTITERATOR_SUBSTITUTION
	SUCCEED();
}


//=========================== イテレータのコピーを行う ================================

/**********************************************************************************//**
	@brief		イテレータのコピーを行う機能について、
				ConstIteratorから、Iteratorのコピーが作成されないかをチェックのテスト
	@details	ID:Iterator-17\n
				イテレータのコピーを行う機能のテストです。\n
				ConstIteratorから、Iteratorのコピーが作成されないかをチェックを確認しています。\n
				有効にしてコンパイルが通らなければ成功です。\n
				TT_TEST_ITERATOR_COPYマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestIteratorCopy, GetTopIteratorCopyIqualTest)
{
#if defined TT_TEST_ITERATOR_COPY

	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1;
	DoublyLinkedList::Iterator it2(it1);

#endif //TT_TEST_ITERATOR_COPY
	SUCCEED();
}


//=========================== イテレータの代入を行う ==================================
/**********************************************************************************//**
	@brief		イテレータの代入を行う機能について、
				IteratorにConstIteratorを代入できない事をチェックのテスト
	@details	ID:Iterator-19\n
				イテレータの代入を行う機能のテストです。\n
				IteratorにConstIteratorを代入できない事をチェックを確認しています。\n
				有効にしてコンパイルが通らなければ成功です。\n
				TT_TEST_ITERATOR_SUBSTITUTIONマクロを定義すると有効になります。\n
*//***********************************************************************************/
TEST(TestIteratorSubstitution, IteratorSubstitutionConstIteratorTest)
{
#if defined TT_TEST_ITERATOR_SUBSTITUTION

	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;
	it1 = it2;

#endif //TT_TEST_ITERATOR_SUBSTITUTION
	SUCCEED();
}