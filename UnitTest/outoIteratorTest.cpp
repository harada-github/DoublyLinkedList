//============================================================
//
//  title  : イテレーターの自動テストコード [outoIteratorTest.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
#include "gtest/gtest.h"
#include "gtest/gtest-death-test.h"
#include "../DoublyLinkedList/doublyLinkedList.h"


//--------------------------------------------------------------------------------
// コンパイル関連自動テスト
//--------------------------------------------------------------------------------

//======================== イテレータの指す要素を取得する =============================
/**********************************************************************************//**
	@brief		イテレータの指す要素を取得する機能について、リストの参照がない状態で呼び出した際の挙動のテスト
	@details	ID:Iterator-0\n
				イテレータの指す要素を取得する機能のテストです。\n
				リストの参照がない状態で呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetIteratorData, NotListDeathTest)
{
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;

	// リストへの参照がないのでアサートが発生してプログラムが異常終了することを確認
	EXPECT_DEATH(it1.GetData(), "Assertion failed.*");
	EXPECT_DEATH(it2.GetConstData(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータの指す要素を取得する機能について、Iteratorから取得した要素に対して、値の代入が行えるかをチェックのテスト
	@details	ID:Iterator-1\n
				イテレータの指す要素を取得する機能のテストです。\n
				Iteratorから取得した要素に対して、値の代入が行えるかをチェックを確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetIteratorSubstitutionTest)
{
	// データを用意
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// データの代入
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	it.GetData().score = 2;

	// 変更した値と一致するかを確認
	EXPECT_EQ(2, list.GetTopIterator().GetData().score);
}

/**********************************************************************************//**
	@brief		イテレータの指す要素を取得する機能について、リストが空の際の、先頭イテレータに対して呼び出した際の挙動のテスト
	@details	ID:Iterator-3\n
				イテレータの指す要素を取得する機能のテストです。\n
				リストが空の際の、先頭イテレータに対して呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetTopIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(list.GetTopIterator().GetData(), "Assertion failed.*");
	EXPECT_DEATH(list.GetTopConstIterator().GetConstData(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータの指す要素を取得する機能について、末尾イテレータに対して呼び出した際の挙動のテスト
	@details	ID:Iterator-4\n
				イテレータの指す要素を取得する機能のテストです。\n
				末尾イテレータに対して呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetIteratorData, GetEndIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(list.GetEndIterator().GetData(), "Assertion failed.*");
	EXPECT_DEATH(list.GetEndConstIterator().GetConstData(), "Assertion failed.*");
}



//================= イテレータをリストの末尾に向かって一つ進める ======================

/**********************************************************************************//**
	@brief		イテレータをリストの末尾に向かって一つ進める機能について、リストの参照がない状態で呼び出した際の挙動のテスト
	@details	ID:Iterator-5\n
				イテレータをリストの末尾に向かって一つ進める機能のテストです。\n
				リストの参照がない状態で呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, NotListDeathTest)
{
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;

	// リストへの参照がないのでアサートが発生してプログラムが異常終了することを確認
	EXPECT_DEATH(++it1, "Assertion failed.*");
	EXPECT_DEATH(++it2, "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータをリストの末尾に向かって一つ進める機能について、リストが空の際の、先頭イテレータに対して呼び出した際の挙動のテスト
	@details	ID:Iterator-6\n
				イテレータをリストの末尾に向かって一つ進める機能のテストです。\n
				リストが空の際の、先頭イテレータに対して呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetTopIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(++list.GetTopIterator(), "Assertion failed.*");
	EXPECT_DEATH(++list.GetTopConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータをリストの末尾に向かって一つ進める機能について、末尾イテレータに対して呼び出した際の挙動のテスト
	@details	ID:Iterator-7\n
				イテレータをリストの末尾に向かって一つ進める機能のテストです。\n
				末尾イテレータに対して呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(++list.GetEndIterator(), "Assertion failed.*");
	EXPECT_DEATH(++list.GetEndConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータをリストの末尾に向かって一つ進める機能について、リストに二つ以上の要素がある場合に呼び出した際の挙動のテスト
	@details	ID:Iterator-8\n
				イテレータをリストの末尾に向かって一つ進める機能のテストです。\n
				リストに二つ以上の要素がある場合に呼び出した際の挙動を確認しています。\n
				次の要素を指していれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorWhenListIsTwoDataTest)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// イテレータの確認
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);
	++it;
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt = list.GetTopConstIterator();
	EXPECT_EQ(2, constIt.GetConstData().score);
	EXPECT_EQ("bb", constIt.GetConstData().userName);
	++constIt;
	EXPECT_EQ(1, constIt.GetConstData().score);
	EXPECT_EQ("a", constIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		イテレータをリストの末尾に向かって一つ進める機能について、
	            前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )のテスト
	@details	ID:Iterator-9\n
				イテレータをリストの末尾に向かって一つ進める機能のテストです。\n
				前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )を確認しています。\n
				次の要素を指していれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorPreIncrementTest)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	DoublyLinkedList::Iterator it = list.GetTopIterator();

	// インクリメントをする前の確認
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);

	// インクリメントをする
	++it;

	// インクリメントをした後の確認
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		イテレータをリストの末尾に向かって一つ進める機能について、
				後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )のテスト
	@details	ID:Iterator-10\n
				イテレータをリストの末尾に向かって一つ進める機能のテストです。\n
				後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )を確認しています。\n
				次の要素を指していれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListEnd, GetEndIteratorRetIncrementTest)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	DoublyLinkedList::Iterator it = list.GetTopIterator();

	// インクリメントをする前の確認
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);

	// インクリメントをする
	it++;

	// インクリメントをした後の確認
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}



//================= イテレータをリストの先頭に向かって一つ進める ======================

/**********************************************************************************//**
	@brief		イテレータをリストの先頭に向かって一つ進める機能について、リストの参照がない状態で呼び出した際の挙動のテスト
	@details	ID:Iterator-11\n
				イテレータをリストの先頭に向かって一つ進める機能のテストです。\n
				リストの参照がない状態で呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListTop, NotListDeathTest)
{
	DoublyLinkedList::Iterator it1;
	DoublyLinkedList::ConstIterator it2;

	// リストへの参照がないのでアサートが発生してプログラムが異常終了することを確認
	EXPECT_DEATH(--it1, "Assertion failed.*");
	EXPECT_DEATH(--it2, "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータをリストの先頭に向かって一つ進める機能について、リストが空の際の、末尾イテレータに対して呼び出した際の挙動のテスト
	@details	ID:Iterator-12\n
				イテレータをリストの先頭に向かって一つ進める機能のテストです。\n
				リストが空の際の、末尾イテレータに対して呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetEndIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(--list.GetEndIterator(), "Assertion failed.*");
	EXPECT_DEATH(--list.GetEndConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータをリストの先頭に向かって一つ進める機能について、先頭イテレータに対して呼び出した際の挙動のテスト
	@details	ID:Iterator-13\n
				イテレータをリストの先頭に向かって一つ進める機能のテストです。\n
				先頭イテレータに対して呼び出した際の挙動を確認しています。\n
				Assertが発生すれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorWhenListIsEmptyDeathTest)
{
	DoublyLinkedList list;
	EXPECT_DEATH(--list.GetTopIterator(), "Assertion failed.*");
	EXPECT_DEATH(--list.GetTopConstIterator(), "Assertion failed.*");
}

/**********************************************************************************//**
	@brief		イテレータをリストの先頭に向かって一つ進める機能について、リストに二つ以上の要素がある場合に呼び出した際の挙動のテスト
	@details	ID:Iterator-14\n
				イテレータをリストの先頭に向かって一つ進める機能のテストです。\n
				リストに二つ以上の要素がある場合に呼び出した際の挙動を確認しています。\n
				次の要素を指していれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorWhenListIsTwoDataTest)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// イテレータの確認
	DoublyLinkedList::Iterator it = list.GetEndIterator();
	--it;
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
	--it;
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt = list.GetEndConstIterator();
	++constIt;
	EXPECT_EQ(1, constIt.GetConstData().score);
	EXPECT_EQ("a", constIt.GetConstData().userName);
	++constIt;
	EXPECT_EQ(2, constIt.GetConstData().score);
	EXPECT_EQ("bb", constIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		イテレータをリストの先頭に向かって一つ進める機能について、
				前置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )のテスト
	@details	ID:Iterator-15\n
				イテレータをリストの先頭に向かって一つ進める機能のテストです。\n
				前置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )を確認しています。\n
				次の要素を指していれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorPreIncrementTest)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// イテレータの確認
	DoublyLinkedList::Iterator it = list.GetEndIterator();
	--it;

	// デクリメントをする前の確認
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// デクリメントをする
	--it;

	// デクリメントをした後の確認
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		イテレータをリストの先頭に向かって一つ進める機能について、
				後置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )のテスト
	@details	ID:Iterator-16\n
				イテレータをリストの先頭に向かって一つ進める機能のテストです。\n
				後置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )を確認しています。\n
				次の要素を指していれば成功です。\n
*//***********************************************************************************/
TEST(TestIteratorListTop, GetTopIteratorRetIncrementTest)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	DoublyLinkedList::Iterator it = list.GetEndIterator();
	it--;

	// デクリメントをする前の確認
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// デクリメントをする
	it--;

	// デクリメントをした後の確認
	EXPECT_EQ(2, it.GetData().score);
	EXPECT_EQ("bb", it.GetData().userName);
}


//=========================== イテレータのコピーを行う ================================

/**********************************************************************************//**
	@brief		イテレータのコピーを行う機能について、
				コピーコンストラクト後の値がコピー元と等しいことをチェックのテスト
	@details	ID:Iterator-18\n
				イテレータのコピーを行う機能のテストです。\n
				コピーコンストラクト後の値がコピー元と等しいことをチェックを確認しています。\n
				コピーコンストラクト後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestIteratorCopy, GetIteratorCopyIqualTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	
	// イテレータの確認
	it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2(it1);
	EXPECT_EQ(1, it2.GetData().score);
	EXPECT_EQ("a", it2.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2(constIt1);
	EXPECT_EQ(1, constIt2.GetConstData().score);
	EXPECT_EQ("a", constIt2.GetConstData().userName);
}


//=========================== イテレータの代入を行う ==================================

/**********************************************************************************//**
	@brief		イテレータの代入を行う機能について、
				代入後の値がコピー元と等しいことをチェックのテスト
	@details	ID:Iterator-20\n
				イテレータの代入を行う機能のテストです。\n
				代入後の値がコピー元と等しいことをチェックを確認しています。\n
				代入後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestIteratorSubstitution, GetIteratorSubstitutionIqualTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// イテレータの確認
	it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = it1;
	EXPECT_EQ(1, it2.GetData().score);
	EXPECT_EQ("a", it2.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = constIt1;
	EXPECT_EQ(1, constIt2.GetConstData().score);
	EXPECT_EQ("a", constIt2.GetConstData().userName);
}


//============== 二つのイテレータが同一のものであるか、比較を行う======================

/**********************************************************************************//**
	@brief		二つのイテレータが同一のものであるか、比較を行う機能について、
				リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェックのテスト
	@details	ID:Iterator-21\n
				二つのイテレータが同一のものであるか、比較を行う機能のテストです。\n
				二つのイテレータが同一のものであるか、比較を行うをチェックを確認しています。\n
				代入後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestTwoIteratorIqual, TwoIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	
	EXPECT_EQ(true, list.GetTopIterator().GetData().score == list.GetEndIterator().GetData().score);
	EXPECT_EQ(true, list.GetTopIterator().GetData().userName == list.GetEndIterator().GetData().userName);
	EXPECT_EQ(true, list.GetTopConstIterator().GetConstData().score == list.GetEndConstIterator().GetConstData().score);
	EXPECT_EQ(true, list.GetTopConstIterator().GetConstData().userName == list.GetEndConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		二つのイテレータが同一のものであるか、比較を行う機能について、
				同一のイテレータを比較した際の挙動のテスト
	@details	ID:Iterator-22\n
				二つのイテレータが同一のものであるか、比較を行う機能のテストです。\n
				同一のイテレータを比較した際の挙動を確認しています。\n
				代入後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestTwoIteratorIqual, IqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// イテレータの確認
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	EXPECT_EQ(true, it1.GetData().score == it2.GetData().score);
	EXPECT_EQ(true, it1.GetData().userName == it2.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = list.GetTopConstIterator();
	EXPECT_EQ(true, constIt1.GetConstData().score == constIt2.GetConstData().score);
	EXPECT_EQ(true, constIt1.GetConstData().userName == constIt2.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		二つのイテレータが同一のものであるか、比較を行う機能について、
				異なるイテレータを比較した際の挙動のテスト
	@details	ID:Iterator-23\n
				二つのイテレータが同一のものであるか、比較を行う機能のテストです。\n
				異なるイテレータを比較した際の挙動を確認しています。\n
				代入後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestTwoIteratorIqual, NotIqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator ite1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite1, 1, "a"));
	DoublyLinkedList::Iterator ite2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite2, 2, "bb"));

	// イテレータの確認
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = ++list.GetTopIterator();
	EXPECT_EQ(false, it1.GetData().score == it2.GetData().score);
	EXPECT_EQ(false, it1.GetData().userName == it2.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = ++list.GetTopConstIterator();
	EXPECT_EQ(false, constIt1.GetConstData().score == constIt2.GetConstData().score);
	EXPECT_EQ(false, constIt1.GetConstData().userName == constIt2.GetConstData().userName);
}



//============== 二つのイテレータが異なるものであるか、比較を行う======================

/**********************************************************************************//**
	@brief		二つのイテレータが異なるものであるか、比較を行う機能について、
				リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェックのテスト
	@details	ID:Iterator-21\n
				二つのイテレータが異なるものであるか、比較を行う機能のテストです。\n
				二つのイテレータが同一のものであるか、比較を行うをチェックを確認しています。\n
				代入後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestTwoIteratorNotIqual, TwoIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;

	EXPECT_EQ(false, list.GetTopIterator().GetData().score != list.GetEndIterator().GetData().score);
	EXPECT_EQ(false, list.GetTopIterator().GetData().userName != list.GetEndIterator().GetData().userName);
	EXPECT_EQ(false, list.GetTopConstIterator().GetConstData().score != list.GetEndConstIterator().GetConstData().score);
	EXPECT_EQ(false, list.GetTopConstIterator().GetConstData().userName != list.GetEndConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		二つのイテレータが異なるものであるか、比較を行う機能について、
				同一のイテレータを比較した際の挙動のテスト
	@details	ID:Iterator-22\n
				二つのイテレータが異なるものであるか、比較を行う機能のテストです。\n
				同一のイテレータを比較した際の挙動を確認しています。\n
				代入後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestTwoIteratorNotIqual, IqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// イテレータの確認
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	EXPECT_EQ(false, it1.GetData().score != it2.GetData().score);
	EXPECT_EQ(false, it1.GetData().userName != it2.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = list.GetTopConstIterator();
	EXPECT_EQ(false, constIt1.GetConstData().score != constIt2.GetConstData().score);
	EXPECT_EQ(false, constIt1.GetConstData().userName != constIt2.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		二つのイテレータが異なるものであるか、比較を行う機能について、
				異なるイテレータを比較した際の挙動のテスト
	@details	ID:Iterator-23\n
				二つのイテレータが異なるものであるか、比較を行う機能のテストです。\n
				異なるイテレータを比較した際の挙動を確認しています。\n
				代入後の値がコピー元と等しければ成功です。\n
*//***********************************************************************************/
TEST(TestTwoIteratorNotIqual, NotIqualIteratorWhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator ite1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite1, 1, "a"));
	DoublyLinkedList::Iterator ite2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(ite2, 2, "bb"));

	// イテレータの確認
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	DoublyLinkedList::Iterator it2 = ++list.GetTopIterator();
	EXPECT_EQ(true, it1.GetData().score != it2.GetData().score);
	EXPECT_EQ(true, it1.GetData().userName != it2.GetData().userName);

	// コンストイテレータの確認
	DoublyLinkedList::ConstIterator constIt1 = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator constIt2 = ++list.GetTopConstIterator();
	EXPECT_EQ(true, constIt1.GetConstData().score != constIt2.GetConstData().score);
	EXPECT_EQ(true, constIt1.GetConstData().userName != constIt2.GetConstData().userName);
}