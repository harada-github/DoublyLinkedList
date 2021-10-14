//============================================================
//
//  title  : 双方向リストクラス [doublyLinkedList.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/07
//  Update : 2021/10/07
//
//============================================================
#include "doublyLinkedList.h"


//============================================================
//　コンストイテレータクラスの関数
//============================================================
//------------------------------------------------------------
//【 コンストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator::ConstIterator()
{
	;
}


//------------------------------------------------------------
//【 引数付きコンストラクタ 】
// thisPtr：
//------------------------------------------------------------
DoublyLinkedList::ConstIterator::ConstIterator(Node* thisPtr)
{
	itePtr = thisPtr;
}


//------------------------------------------------------------
//【 デストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator::~ConstIterator()
{
	;
}


//------------------------------------------------------------
//【 リストの末尾向かって一つ進める 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++()
{
	// エラーチェック
	if (itePtr->nextPtr->recordData.score == 0 && itePtr->nextPtr->recordData.userName == "")
	{
		//return;
	}

	itePtr = itePtr->nextPtr;
	return *this;
}


//------------------------------------------------------------
//【 リストの先頭に向かって一つ進める 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--()
{
	// エラーチェック
	if (itePtr->prevPtr->recordData.score == 0 && itePtr->prevPtr->recordData.userName == "")
	{
		//return;
	}

	itePtr = itePtr->prevPtr;
	return *this;
}


//------------------------------------------------------------
//【 == 比較のオペレーター 】
// ite：比較するイテレータオブジェクト
//------------------------------------------------------------
bool DoublyLinkedList::ConstIterator::operator ==(const ConstIterator &ite) const
{
	return *this == ite;
}


//------------------------------------------------------------
//【 != 比較のオペレーター 】
// ite：比較するイテレータオブジェクト
//------------------------------------------------------------
bool DoublyLinkedList::ConstIterator::operator !=(const ConstIterator &ite) const
{
	return !(*this == ite);
}


//------------------------------------------------------------
//【 イテレータの指す要素を取得する 】
//------------------------------------------------------------
const RecordData& DoublyLinkedList::ConstIterator::GetConstData()
{
	return itePtr->recordData;
}



//============================================================
//　イテレータクラスの関数
//============================================================
//------------------------------------------------------------
//【 コンストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::Iterator::Iterator()
{
	;
}


//------------------------------------------------------------
//【 引数付きコンストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::Iterator::Iterator(Node* thisPtr)
{
	itePtr = thisPtr;
}


//------------------------------------------------------------
//【 デストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::Iterator::~Iterator()
{
	;
}


//------------------------------------------------------------
//【 イテレータの指す要素を取得する 】
//------------------------------------------------------------
RecordData& DoublyLinkedList::Iterator::GetData()
{
	return itePtr->recordData;
}



//============================================================
//　双方向リストクラスの関数
//============================================================
//------------------------------------------------------------
//　【 コンストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::DoublyLinkedList()
{
	// 値を初期化
	thisPtr = nullptr;
}


//------------------------------------------------------------
//　【 デストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::~DoublyLinkedList()
{
	;
}


//------------------------------------------------------------
//　【 データの数の取得 】
//　return：データの数
//------------------------------------------------------------
int DoublyLinkedList::GetDataCount()
{
	// データの数をカウントする変数
	int dataCount = 0;

	// 先頭ポインタを保存
	Node* temp = thisPtr->nextPtr;

	while (temp != nullptr)
	{
		// 末尾に一つ進める
		temp = temp->nextPtr;

		// データの数をカウント
		dataCount++;
	}

	// データの数を返す
	return dataCount;
}


//------------------------------------------------------------
//　【 データの挿入 】
//　addIterator：追加するイテレータの情報
//------------------------------------------------------------
void DoublyLinkedList::Insert(Iterator addIterator)
{
	// 追加するデータを作成
	Node* temp = new Node();
	temp->recordData.score = addIterator.GetData().score;
	temp->recordData.userName = addIterator.GetData().userName;

	// 末尾のポインタを保存
	Node* endPtr = thisPtr->prevPtr;

	if (endPtr == nullptr)
	{
		// 末尾にデータがない場合はtempを末尾データとする
		endPtr = temp;

		// tempの先をthisPtrにする
		temp->nextPtr = thisPtr;

		// thisPtrの前後の接続先をどちらもtempにする
		thisPtr->nextPtr = temp;
		thisPtr->prevPtr = temp;
	}
	else
	{
		endPtr->nextPtr = temp;
		temp->prevPtr = endPtr;
		temp->nextPtr = thisPtr;
		thisPtr->prevPtr = temp;
	}
}


//------------------------------------------------------------
//　【 データの削除 】
//　removeIterator：削除するイテレータの情報
//------------------------------------------------------------
void DoublyLinkedList::Remove(Iterator removeIterator)
{
	// 先頭のポインタを保存
	Node* temp = thisPtr->nextPtr;

	if (temp == nullptr)
	{
		// データがない場合はreturn
		return;
	}
	
	while (temp != nullptr)
	{

	}
}


//------------------------------------------------------------
//　【 先頭イテレータ取得 】
//　return：先頭のイテレータ
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetTopIterator()
{
	DoublyLinkedList::Iterator temp(thisPtr->nextPtr);

	// エラーチェック
	if (temp == NULL)
	{
		return NULL;
	}

	// 先頭イテレータを返す
	return temp;
}


//------------------------------------------------------------
//　【 先頭コンストイテレータ取得 】
//　return：先頭コンストイテレータ
//------------------------------------------------------------
const DoublyLinkedList::ConstIterator DoublyLinkedList::GetTopConstIterator()
{
	DoublyLinkedList::ConstIterator temp(thisPtr->nextPtr);

	// エラーチェック
	if (temp == NULL)
	{
		return NULL;
	}

	// 先頭イテレータを返す
	return temp;
}


//------------------------------------------------------------
//　【 末尾イテレータ取得 】
//　return：末尾イテレータ
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetEndIterator()
{
	DoublyLinkedList::Iterator temp(thisPtr->prevPtr);

	// エラーチェック
	if (temp == NULL)
	{
		return NULL;
	}

	// 先頭イテレータを返す
	return temp;
}


//------------------------------------------------------------
//　【 末尾コンストイテレータ取得 】
//　return：末尾コンストイテレータ
//------------------------------------------------------------
const DoublyLinkedList::ConstIterator DoublyLinkedList::GetEndConstIterator()
{
	DoublyLinkedList::ConstIterator temp(thisPtr->prevPtr);

	// エラーチェック
	if (temp == NULL)
	{
		return NULL;
	}

	// 先頭イテレータを返す
	return temp;
}
