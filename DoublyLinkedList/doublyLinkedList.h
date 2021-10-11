//============================================================
//
//  title  : 双方向リストクラス [doublyLinkedList.h]
//  Author : 原田 陽央
//   Date  : 2021/10/07
//  Update : 2021/10/11
//
//============================================================
#pragma once


//============================================================
//　インクルード
//============================================================
#include <iostream>
#include <string>
#include "iterator.h"
using namespace std;


//============================================================
//　構造体宣言
//============================================================
// 成績データ構造体
struct RecordData
{
	int score;        // スコア
	string userName;  // ユーザー名
};


//============================================================
//　クラス宣言
//============================================================
class DoublyLinkedList
{
public:
	// ノード構造体
	struct Node
	{
		Node* prevPtr;         // 前のノードへのポインタ
		Node* nextPtr;         // 次のノードへのポインタ

		RecordData recordData; // 成績データ
	};

	DoublyLinkedList();        // コンストラクタ
	~DoublyLinkedList();       // デストラクタ

	void AddTop(RecordData addRecordData);  // 先頭にデータを追加
	void AddEnd(RecordData addRecordData);  // 末尾にデータを追加
	Node* GetTopPtr(void);                  // 先頭のノードを取得
	Node* GetEndPtr(void);                  // 末尾のノードを取得
	void Sort(void);                        // ソート（並び替え）
	void Remove(int num);                   // データの削除
	int GetDataCount(void);                 // データの数の取得

	
	//void Insert();// データの挿入

	
	//Iterator GetTopIterator();        // 先頭イテレータ取得
	//ConstIterator GetConstIterator(); // 先頭コンストイテレータ取得
	//Iterator GetTopIterator();        // 末尾イテレータ取得
	//ConstIterator GetConstIterator(); // 末尾コンストイテレータ取得

private:
	
	Node* thisPtr; // ノードへのポインタ
};