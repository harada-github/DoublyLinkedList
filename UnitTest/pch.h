//============================================================
//
//  title  : GoogleTest手動テストコードの定義、宣言 [test.h]
//  Author : 原田 陽央
//   Date  : 2021/10/11
//  Update : 2021/10/22
//
//============================================================
//#pragma once
#include "gtest/gtest.h"
#include "../DoublyLinkedList/doublyLinkedList.h"


//--------------------------------------------------------------------------------
// マクロ定義
//--------------------------------------------------------------------------------
// コンパイル関連手動テスト(リスト)

// 〇データ数の取得のマクロ〇
// constのメソッドであるか（手動確認）
// ※有効にしてコンパイルが通れば成功です
//#define TT_TEST_DATA_IS_CONST

// 〇データの挿入のマクロ〇
// 非constのメソッドであるか（手動確認）
// ※有効にしてコンパイルが通らなければ成功です
//#define TT_TEST_DATA_INSERT_IS_NO_CONST

// 〇データの削除のマクロ〇
// 非constのメソッドであるか（手動確認）
// ※有効にしてコンパイルが通らなければ成功です
//#define TT_TEST_DATA_REMOVE_IS_NO_CONST

// 〇先頭イテレータの取得のマクロ〇
// constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック（手動確認）
// ※有効にしてコンパイルが通らなければ成功です
//#define TT_TEST_CONSTLIST_GET_TOPITERATOR

// 〇先頭コンストイテレータの取得のマクロ〇
// constのメソッドであるか（手動確認）
// ※有効にしてコンパイルが通れば成功です
//#define TT_TEST_CONSTLIST_GET_TOPCONSTITERATOR

// 〇末尾イテレータの取得のマクロ〇
// constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック（手動確認）
// ※有効にしてコンパイルが通らなければ成功です
//#define TT_TEST_CONSTLIST_GET_ENDITERATOR

// 〇末尾コンストイテレータの取得のマクロ〇
// constのメソッドであるか（手動確認）
// ※有効にしてコンパイルが通れば成功です
//#define TT_TEST_CONSTLIST_GET_ENDCONSTITERATOR

// 〇イテレータの指す要素を取得のマクロ〇
// ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック（手動確認）
// ※有効にしてコンパイルが通らなければ成功です
//#define TT_TEST_GET_CONSTITERATOR_SUBSTITUTION

// 〇イテレータのコピーを行う〇
// ConstIteratorから、Iteratorのコピーが作成されないかをチェック（手動確認）
// ※有効にしてコンパイルが通らなければ成功です
//#define TT_TEST_ITERATOR_COPY

// 〇イテレータの代入を行う〇
// IteratorにConstIteratorを代入できない事をチェック（手動確認）
// ※有効にしてコンパイルが通らなければ成功です
//#define TT_TEST_ITERATOR_SUBSTITUTION