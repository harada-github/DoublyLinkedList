//============================================================
//
//  title  : 双方向リストの自動テストコード [outoListTest.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
#include "gtest/gtest.h"
#include "../DoublyLinkedList/doublyLinkedList.h"


//--------------------------------------------------------------------------------
// コンパイル関連自動テスト
//--------------------------------------------------------------------------------

//=================================== データ数の取得 ===================================
/**********************************************************************************//**
	@brief		データ数の取得機能について、リストが空である場合の戻り値のテスト
	@details	ID:リスト-0\n
				データ数の取得機能のテストです。\n
				リストが空である場合の戻り値を確認しています。\n
				データ数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, GetDataCountTest)
{
	DoublyLinkedList list;
	EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		データ数の取得機能について、リスト末尾への挿入を行った際の戻り値のテスト
	@details	ID:リスト-1\n
				データ数の取得機能のテストです。\n
				リスト末尾への挿入を行った際の戻り値を確認しています。\n
				データ数が1増えていれば成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, ListEndInsertReturn1Test)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetEndIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));
	EXPECT_EQ(1, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		データ数の取得機能について、リスト末尾への挿入が失敗した際の戻り値のテスト
	@details	ID:リスト-2\n
				データ数の取得機能のテストです。\n
				リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
				データ数が増えていなければ成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, ListEndInsertReturn0Test)
{
	// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
	//DoublyLinkedList list;
	//DoublyLinkedList::Iterator it = list.GetEndIterator();
	//ASSERT_FALSE(list.Insert(it, 1));
	//EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		データ数の取得機能について、データの挿入を行った際の戻り値のテスト
	@details	ID:リスト-3\n
				データ数の取得機能のテストです。\n
				データの挿入を行った際の戻り値を確認しています。\n
				データ数が1であれば成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndInsertReturn1Test)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	EXPECT_EQ(1, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		データ数の取得機能について、データの挿入に失敗した際の戻り値のテスト
	@details	ID:リスト-4\n
				データ数の取得機能のテストです。\n
				データの挿入に失敗した際の戻り値を確認しています。\n
				データ数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndInsertReturn0Test)
{
	// 失敗時のためここではスキップ
	//DoublyLinkedList list;
	//DoublyLinkedList::Iterator it = list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it, 1));
	//EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		データ数の取得機能について、データの削除を行った際の戻り値のテスト
	@details	ID:リスト-5\n
				データ数の取得機能のテストです。\n
				データの削除を行った際の戻り値を確認しています。\n
				データ数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndRemoveReturn0Test)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));
	ASSERT_TRUE(list.Remove(it));
	EXPECT_EQ(0, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		データ数の取得機能について、データの削除が失敗した際の戻り値のテスト
	@details	ID:リスト-6\n
				データ数の取得機能のテストです。\n
				データの削除が失敗した際の戻り値を確認しています。\n
				データ数が増えていなければ成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndRemoveReturn1Test)
{
	// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
	//DoublyLinkedList list;
	//DoublyLinkedList::Iterator it = list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it, 1));
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(1, list.GetDataCount());
}

/**********************************************************************************//**
	@brief		データ数の取得機能について、リストが空である場合に、データの削除を行った際の戻り値のテスト
	@details	ID:リスト-7\n
				データ数の取得機能のテストです。\n
				リストが空である場合に、データの削除を行った際の戻り値を確認しています。\n
				データ数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestGetDataNum, DataEndRemoveReturn0WhenListIsEmptyTest)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_FALSE(list.Remove(it));
	EXPECT_EQ(0, list.GetDataCount());
}




//=================================== データの挿入 ===================================

/**********************************************************************************//**
	@brief		データの挿入機能について、リストが空である場合に、挿入した際の挙動のテスト
	@details	ID:リスト-9\n
				データの挿入機能のテストです。\n
				リストが空である場合に、挿入した際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestInsertData, DataInsertWhenListIsEmpty)
{
	DoublyLinkedList list;

	// 先頭と末尾のイテレータそれぞれを確認
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	//DoublyLinkedList::Iterator it = list.GetEndIterator();

	EXPECT_EQ(true, list.Insert(it, 1, "a"));
}

/**********************************************************************************//**
	@brief		データの挿入機能について、リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動のテスト
	@details	ID:リスト-10\n
				データの挿入機能のテストです。\n
				リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestInsertData, TopDataInsertWhenListIsNoEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		データの挿入機能について、リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動のテスト
	@details	ID:リスト-11\n
				データの挿入機能のテストです。\n
				リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestInsertData, EndDataInsertWhenListIsNoEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "b"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		データの挿入機能について、リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動のテスト
	@details	ID:リスト-12\n
				データの挿入機能のテストです。\n
				リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestInsertData, DataInsertWhenListIsNoEmpty)
{
	// データを2つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	
	// 先頭と末尾と中央のイテレータでそれぞれ確認する
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	//DoublyLinkedList::Iterator it3 = list.GetEndIterator();
	//DoublyLinkedList::Iterator it3 = ++list.GetTopIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		データの挿入機能について、ConstIteratorを指定して挿入を行った際の挙動のテスト
	@details	ID:リスト-13\n
				データの挿入機能のテストです。\n
				ConstIteratorを指定して挿入を行った際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestInsertData, ConstIteratorDataInsert)
{
	// データを2つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// 先頭と末尾と中央のイテレータでそれぞれ確認する
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	//DoublyLinkedList::ConstIterator it3 = list.GetEndConstIterator();
	//DoublyLinkedList::ConstIterator it3 = ++list.GetTopConstIterator();
	EXPECT_EQ(true, list.Insert(it3, 3, "ccc"));
}

/**********************************************************************************//**
	@brief		データの挿入機能について、不正なイテレータを渡して、挿入した場合の挙動のテスト
	@details	ID:リスト-14\n
				データの挿入機能のテストです。\n
				不正なイテレータを渡して、挿入した場合の挙動を確認しています。\n
				戻り値が false であれば成功です。\n
*//***********************************************************************************/
TEST(TestInsertData, NotIteratorDataInsert)
{
	// データを2つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// リストを参照しないイテレータを引数にいれる
	DoublyLinkedList::Iterator it3;
	EXPECT_EQ(false, list.Insert(it3, 3, "ccc"));
}




//=================================== データの削除 ===================================

/**********************************************************************************//**
	@brief		データの削除機能について、リストが空である場合に、削除を行った際の挙動のテスト
	@details	ID:リスト-16\n
				データの削除機能のテストです。\n
				リストが空である場合に、削除を行った際の挙動を確認しています。\n
				戻り値が false であれば成功です。\n
*//***********************************************************************************/
TEST(TestRemoveData, DataRemoveWhenListIsEmpty)
{
	DoublyLinkedList list;

	// 先頭と末尾のイテレータでそれぞれ確認する
	//DoublyLinkedList::Iterator it = list.GetTopIterator();
	DoublyLinkedList::Iterator it = list.GetEndIterator();

	EXPECT_EQ(false, list.Remove(it));
}

/**********************************************************************************//**
	@brief		データの削除機能について、リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動のテスト
	@details	ID:リスト-17\n
				データの削除機能のテストです。\n
				リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestRemoveData, TopDataRemoveWhenListIsNoEmpty)
{
	// データを3つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it = list.GetTopIterator();
	EXPECT_EQ(true, list.Remove(it));
}

/**********************************************************************************//**
	@brief		データの削除機能について、リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動のテスト
	@details	ID:リスト-18\n
				データの削除機能のテストです。\n
				リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動を確認しています。\n
				戻り値が false であれば成功です。\n
*//***********************************************************************************/
TEST(TestRemoveData, EndDataRemoveWhenListIsNoEmpty)
{
	// データを3つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it = list.GetEndIterator();
	EXPECT_EQ(false, list.Remove(it));
}

/**********************************************************************************//**
	@brief		データの削除機能について、リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動のテスト
	@details	ID:リスト-19\n
				データの削除機能のテストです。\n
				リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestRemoveData, DataRemoveWhenListIsNoEmpty)
{
	// データを3つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it = ++list.GetTopIterator();
	EXPECT_EQ(true, list.Remove(it));
}

/**********************************************************************************//**
	@brief		データの削除機能について、ConstIteratorを指定して削除を行った際の挙動のテスト
	@details	ID:リスト-20\n
				データの削除機能のテストです。\n
				ConstIteratorを指定して削除を行った際の挙動を確認しています。\n
				戻り値が true であれば成功です。\n
*//***********************************************************************************/
TEST(TestRemoveData, ConstIteratorDataRemove)
{
	// データを3つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	EXPECT_EQ(true, list.Remove(it));
}

/**********************************************************************************//**
	@brief		データの削除機能について、不正なイテレータを渡して、削除した場合の挙動のテスト
	@details	ID:リスト-21\n
				データの削除機能のテストです。\n
				不正なイテレータを渡して、削除した場合の挙動を確認しています。\n
				戻り値が false であれば成功です。\n
*//***********************************************************************************/
TEST(TestRemoveData, NotIteratorDataRemove)
{
	// データを3つ挿入して3つ目のデータで検証
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	DoublyLinkedList::Iterator it;
	EXPECT_EQ(false, list.Remove(it));
}




//=============================== 先頭イテレータの取得 ===================================

/**********************************************************************************//**
	@brief		先頭イテレータの取得機能について、リストが空である場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-23\n
				先頭イテレータの取得機能のテストです。\n
				リストが空である場合に、呼び出した際の挙動を確認しています。\n
				戻り値が末尾イテレータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator topIt = list.GetTopIterator();
	DoublyLinkedList::Iterator endIt = list.GetEndIterator();

	// 先頭と末尾のイテレータが指す要素が一致することを確認
	EXPECT_EQ(topIt.GetData().score, endIt.GetData().score);
	EXPECT_EQ(topIt.GetData().userName, endIt.GetData().userName);
}

/**********************************************************************************//**
	@brief		先頭イテレータの取得機能について、リストに要素が一つある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-24\n
				先頭イテレータの取得機能のテストです。\n
				リストに要素が一つある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータのデータが用意したデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenListIsOneData)
{
	// データを一つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// 用意したデータと一致するかを確認
	EXPECT_EQ(1, list.GetTopIterator().GetData().score);
	EXPECT_EQ("a", list.GetTopIterator().GetData().userName);
}

/**********************************************************************************//**
	@brief		先頭イテレータの取得機能について、リストに二つ以上の要素がある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-25\n
				先頭イテレータの取得機能のテストです。\n
				リストに二つ以上の要素がある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータのデータが用意した二つ目のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenListIsTwoData)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// 用意したデータと一致するかを確認
	EXPECT_EQ(2, list.GetTopIterator().GetData().score);
	EXPECT_EQ("bb", list.GetTopIterator().GetData().userName);
}

/**********************************************************************************//**
	@brief		先頭イテレータの取得機能について、データの挿入を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-26\n
				先頭イテレータの取得機能のテストです。\n
				データの挿入を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータのデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenDataInsert)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを挿入
	// 先頭と末尾と中央のイテレータでそれぞれ確認する

	// 先頭に挿入を行った場合の確認
	DoublyLinkedList::Iterator it4 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	EXPECT_EQ(4, list.GetTopIterator().GetData().score);
	EXPECT_EQ("dddd", list.GetTopIterator().GetData().userName);

	// 中央に挿入を行った場合の確認
	//DoublyLinkedList::Iterator it4 = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);

	// 末尾に挿入を行った場合の確認
	//DoublyLinkedList::Iterator it4 = list.GetEndIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);
}

/**********************************************************************************//**
	@brief		先頭イテレータの取得機能について、データの削除を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-27\n
				先頭イテレータの取得機能のテストです。\n
				データの削除を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータのデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopIterator, TopIteratorWhenDataRemove)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを削除
	// 先頭と末尾と中央のイテレータでそれぞれ確認する

	// 先頭の削除を行った場合の確認
	DoublyLinkedList::Iterator it = list.GetTopIterator();
	ASSERT_TRUE(list.Remove(it));
	EXPECT_EQ(2, list.GetTopIterator().GetData().score);
	EXPECT_EQ("bb", list.GetTopIterator().GetData().userName);

	// 中央の削除を行った場合の確認
	//DoublyLinkedList::Iterator it = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);

	// 末尾の削除を行った場合の確認
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopIterator().GetData().score);
	//EXPECT_EQ("ccc", list.GetTopIterator().GetData().userName);
}




//========================= 先頭コンストイテレータの取得 ===================================

/**********************************************************************************//**
	@brief		先頭コンストイテレータの取得機能について、リストが空である場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-29\n
				先頭コンストイテレータの取得機能のテストです。\n
				リストが空である場合に、呼び出した際の挙動を確認しています。\n
				戻り値が末尾コンストイテレータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator topIt = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator endIt = list.GetEndConstIterator();

	// 先頭と末尾のコンストイテレータが指す要素が一致することを確認
	EXPECT_EQ(topIt.GetConstData().score, endIt.GetConstData().score);
	EXPECT_EQ(topIt.GetConstData().userName, endIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		先頭コンストイテレータの取得機能について、リストに要素が一つある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-30\n
				先頭コンストイテレータの取得機能のテストです。\n
				リストに要素が一つある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータのデータが用意したデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenListIsOneData)
{
	// データを一つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it, 1, "a"));

	// 用意したデータと一致するかを確認
	EXPECT_EQ(1, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("a", list.GetTopConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		先頭コンストイテレータの取得機能について、リストに二つ以上の要素がある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-31\n
				先頭コンストイテレータの取得機能のテストです。\n
				リストに二つ以上の要素がある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータのデータが用意した二つ目のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenListIsTwoData)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// 用意したデータと一致するかを確認
	EXPECT_EQ(2, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("bb", list.GetTopConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		先頭コンストイテレータの取得機能について、データの挿入を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-32\n
				先頭コンストイテレータの取得機能のテストです。\n
				データの挿入を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータのデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenDataInsert)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを挿入
	// 先頭と末尾と中央のコンストイテレータでそれぞれ確認する

	// 先頭に挿入を行った場合の確認
	DoublyLinkedList::ConstIterator it4 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	EXPECT_EQ(4, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("dddd", list.GetTopConstIterator().GetConstData().userName);

	// 中央に挿入を行った場合の確認
	//DoublyLinkedList::ConstIterator it4 = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);

	// 末尾に挿入を行った場合の確認
	//DoublyLinkedList::ConstIterator it4 = list.GetEndConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);
}

/**********************************************************************************//**
	@brief		先頭コンストイテレータの取得機能について、データの削除を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-33\n
				先頭コンストイテレータの取得機能のテストです。\n
				データの削除を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータのデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetTopConstIterator, TopConstIteratorWhenDataRemove)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを削除
	// 先頭と末尾と中央のコンストイテレータでそれぞれ確認する

	// 先頭の削除を行った場合の確認
	DoublyLinkedList::ConstIterator it = list.GetTopConstIterator();
	ASSERT_TRUE(list.Remove(it));
	EXPECT_EQ(2, list.GetTopConstIterator().GetConstData().score);
	EXPECT_EQ("bb", list.GetTopConstIterator().GetConstData().userName);

	// 中央の削除を行った場合の確認
	//DoublyLinkedList::ConstIterator it = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);

	// 末尾の削除を行った場合の確認
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//ASSERT_TRUE(list.Remove(it));
	//EXPECT_EQ(3, list.GetTopConstIterator().GetConstData().score);
	//EXPECT_EQ("ccc", list.GetTopConstIterator().GetConstData().userName);
}




//============================== 末尾イテレータの取得 ===================================

/**********************************************************************************//**
	@brief		末尾イテレータの取得機能について、リストが空である場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-35\n
				末尾イテレータの取得機能のテストです。\n
				リストが空である場合に、呼び出した際の挙動を確認しています。\n
				戻り値が先頭イテレータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator topIt = list.GetTopIterator();
	DoublyLinkedList::Iterator endIt = list.GetEndIterator();

	// 先頭と末尾のイテレータが指す要素が一致することを確認
	EXPECT_EQ(endIt.GetData().score, topIt.GetData().score);
	EXPECT_EQ(endIt.GetData().userName, topIt.GetData().userName);
}

/**********************************************************************************//**
	@brief		末尾イテレータの取得機能について、リストに要素が一つある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-36\n
				末尾イテレータの取得機能のテストです。\n
				リストに要素が一つある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータの一つ前のデータが用意したデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenListIsOneData)
{
	// データを一つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetEndIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// 用意したデータと一致するかを確認
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		末尾イテレータの取得機能について、リストに二つ以上の要素がある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-37\n
				末尾イテレータの取得機能のテストです。\n
				リストに二つ以上の要素がある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータの一つ前のデータが用意した二つ目のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenListIsTwoData)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// 用意したデータと一致するかを確認
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		末尾イテレータの取得機能について、データの挿入を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-38\n
				末尾イテレータの取得機能のテストです。\n
				データの挿入を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータの一つ前のデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenDataInsert)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを挿入
	// 先頭と末尾と中央のイテレータでそれぞれ確認する

	// 先頭に挿入を行った場合の確認
	DoublyLinkedList::Iterator it4 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// 中央に挿入を行った場合の確認
	//DoublyLinkedList::Iterator it4 = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(1, it.GetData().score);
	//EXPECT_EQ("a", it.GetData().userName);

	// 末尾に挿入を行った場合の確認
	//DoublyLinkedList::Iterator it4 = list.GetEndIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(4, it.GetData().score);
	//EXPECT_EQ("dddd", it.GetData().userName);
}

/**********************************************************************************//**
	@brief		末尾イテレータの取得機能について、データの削除を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-39\n
				末尾イテレータの取得機能のテストです。\n
				データの削除を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のイテレータのデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndIterator, EndIteratorWhenDataRemove)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it1 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::Iterator it2 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::Iterator it3 = list.GetTopIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを削除
	// 先頭と末尾と中央のイテレータでそれぞれ確認する

	// 先頭の削除を行った場合の確認
	DoublyLinkedList::Iterator removeIt = list.GetTopIterator();
	ASSERT_TRUE(list.Remove(removeIt));
	DoublyLinkedList::Iterator it = --list.GetEndIterator();
	EXPECT_EQ(1, it.GetData().score);
	EXPECT_EQ("a", it.GetData().userName);

	// 中央の削除を行った場合の確認
	//DoublyLinkedList::Iterator removeIt = ++list.GetTopIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(1, it.GetData().score);
	//EXPECT_EQ("a", it.GetData().userName);

	// 末尾の削除を行った場合の確認
	//DoublyLinkedList::Iterator removeIt = --list.GetEndIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::Iterator it = --list.GetEndIterator();
	//EXPECT_EQ(2, it.GetData().score);
	//EXPECT_EQ("bb", it.GetData().userName);
}




//========================= 末尾コンストイテレータの取得 ===================================

/**********************************************************************************//**
	@brief		末尾コンストイテレータの取得機能について、リストが空である場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-41\n
				末尾コンストイテレータの取得機能のテストです。\n
				リストが空である場合に、呼び出した際の挙動を確認しています。\n
				戻り値が先頭コンストイテレータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenListIsEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator topIt = list.GetTopConstIterator();
	DoublyLinkedList::ConstIterator endIt = list.GetEndConstIterator();

	// 先頭と末尾のコンストイテレータが指す要素が一致することを確認
	EXPECT_EQ(endIt.GetConstData().score, topIt.GetConstData().score);
	EXPECT_EQ(endIt.GetConstData().userName, topIt.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		末尾コンストイテレータの取得機能について、リストに要素が一つある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-42\n
				末尾コンストイテレータの取得機能のテストです。\n
				リストに要素が一つある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータの一つ前のデータが用意したデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenListIsOneData)
{
	// データを一つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetEndConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));

	// 用意したデータと一致するかを確認
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		末尾コンストイテレータの取得機能について、リストに二つ以上の要素がある場合に、呼び出した際の挙動のテスト
	@details	ID:リスト-43\n
				末尾コンストイテレータの取得機能のテストです。\n
				リストに二つ以上の要素がある場合に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータの一つ前のデータが用意した二つ目のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenListIsTwoData)
{
	// データを二つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));

	// 用意したデータと一致するかを確認
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		末尾コンストイテレータの取得機能について、データの挿入を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-44\n
				末尾コンストイテレータの取得機能のテストです。\n
				データの挿入を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータの一つ前のデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenDataInsert)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを挿入
	// 先頭と末尾と中央のイテレータでそれぞれ確認する

	// 先頭に挿入を行った場合の確認
	DoublyLinkedList::ConstIterator it4 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);

	// 中央に挿入を行った場合の確認
	//DoublyLinkedList::ConstIterator it4 = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(1, it.GetConstData().score);
	//EXPECT_EQ("a", it.GetConstData().userName);

	// 末尾に挿入を行った場合の確認
	//DoublyLinkedList::ConstIterator it4 = list.GetEndConstIterator();
	//ASSERT_TRUE(list.Insert(it4, 4, "dddd"));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(4, it.GetConstData().score);
	//EXPECT_EQ("dddd", it.GetConstData().userName);
}

/**********************************************************************************//**
	@brief		末尾コンストイテレータの取得機能について、データの削除を行った後に、呼び出した際の挙動のテスト
	@details	ID:リスト-45\n
				末尾コンストイテレータの取得機能のテストです。\n
				データの削除を行った後に、呼び出した際の挙動を確認しています。\n
				戻り値のコンストイテレータのデータが先頭のデータと一致すれば成功です。\n
*//***********************************************************************************/
TEST(TestGetEndConstIterator, EndConstIteratorWhenDataRemove)
{
	// データを三つ用意する
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it1 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it1, 1, "a"));
	DoublyLinkedList::ConstIterator it2 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it2, 2, "bb"));
	DoublyLinkedList::ConstIterator it3 = list.GetTopConstIterator();
	ASSERT_TRUE(list.Insert(it3, 3, "ccc"));

	// データを削除
	// 先頭と末尾と中央のイテレータでそれぞれ確認する

	// 先頭の削除を行った場合の確認
	DoublyLinkedList::ConstIterator removeIt = list.GetTopConstIterator();
	ASSERT_TRUE(list.Remove(removeIt));
	DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	EXPECT_EQ(1, it.GetConstData().score);
	EXPECT_EQ("a", it.GetConstData().userName);

	// 中央の削除を行った場合の確認
	//DoublyLinkedList::ConstIterator removeIt = ++list.GetTopConstIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(1, it.GetConstData().score);
	//EXPECT_EQ("a", it.GetConstData().userName);

	// 末尾の削除を行った場合の確認
	//DoublyLinkedList::ConstIterator removeIt = --list.GetEndConstIterator();
	//ASSERT_TRUE(list.Remove(removeIt));
	//DoublyLinkedList::ConstIterator it = --list.GetEndConstIterator();
	//EXPECT_EQ(2, it.GetConstData().score);
	//EXPECT_EQ("bb", it.GetConstData().userName);
}