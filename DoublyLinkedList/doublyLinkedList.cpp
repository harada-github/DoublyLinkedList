//============================================================
//
//  title  : 双方向リストクラス [doublyLinkedList.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/07
//  Update : 2021/10/22
//
//============================================================
#include "doublyLinkedList.h"
#include <assert.h>


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
// thisPtr：双方向リストのthisPtrをいれる
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
//【 リストの末尾向かって一つ進める（前置インクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++()
{
	assert(itePtr != nullptr);
	assert(itePtr->nextPtr != nullptr);

	itePtr = itePtr->nextPtr;
	return *this;
}


//------------------------------------------------------------
//【 リストの末尾に向かって一つ進める（後置インクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++(int)
{
	assert(itePtr != nullptr);

	ConstIterator it = *this;

	++(*this);

	return it;
}


//------------------------------------------------------------
//【 リストの先頭に向かって一つ進める（前置デクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--()
{
	assert(itePtr != nullptr);

	itePtr = itePtr->prevPtr;
	return *this;
}


//------------------------------------------------------------
//【 リストの先頭に向かって一つ進める（後置デクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--(int)
{
	assert(itePtr != nullptr);

	ConstIterator it = *this;

	--(*this);

	return it;
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
//【 コンストイテレータの指す要素を取得する 】
//------------------------------------------------------------
RecordData& DoublyLinkedList::ConstIterator::GetConstData() const
{
	assert(itePtr != nullptr);

	return itePtr->recordData;
}


//------------------------------------------------------------
//【 コンストイテレータの持つNodeを取得する 】
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::ConstIterator::GetConstIteratorNode()
{
	if (itePtr == nullptr) return nullptr;

	return itePtr;
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
// thisPtr：双方向リストのthisPtrをいれる
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
//【 リストの末尾向かって一つ進める（前置インクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++()
{
	// エラーチェック
	assert(itePtr != nullptr);

	itePtr = itePtr->nextPtr;
	return *this;
}


//------------------------------------------------------------
//【 リストの末尾に向かって一つ進める（後置インクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++(int)
{
	// エラーチェック
	assert(itePtr != nullptr);

	Iterator it = *this;

	++(*this);

	return it;
}


//------------------------------------------------------------
//【 リストの先頭に向かって一つ進める（前置デクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--()
{
	// エラーチェック
	assert(itePtr != nullptr);

	itePtr = itePtr->prevPtr;
	return *this;
}


//------------------------------------------------------------
//【 リストの先頭に向かって一つ進める（後置デクリメント） 】
//------------------------------------------------------------
DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--(int)
{
	// エラーチェック
	assert(itePtr != nullptr);

	Iterator it = *this;

	--(*this);

	return it;
}


//------------------------------------------------------------
//【 イテレータの指す要素を取得する 】
//------------------------------------------------------------
RecordData& DoublyLinkedList::Iterator::GetData()
{
	assert(itePtr != nullptr);

	return itePtr->recordData;
}


//------------------------------------------------------------
//【 イテレータの持つNodeを取得する 】
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::Iterator::GetIteratorNode()
{
	if (itePtr == nullptr) return nullptr;

	return itePtr;
}



//============================================================
//　双方向リストクラスの関数
//============================================================
//------------------------------------------------------------
//　【 コンストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::DoublyLinkedList()
{
	// ダミーのノードを作成
	thisPtr = new Node();
	//thisPtr->recordData.score = 0;
	//thisPtr->recordData.userName = "";

	// 値を初期化
	thisPtr->prevPtr = nullptr;
	thisPtr->nextPtr = nullptr;
}


//------------------------------------------------------------
//　【 デストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::~DoublyLinkedList()
{
	if (thisPtr != nullptr)
	{
		delete thisPtr;
	}
}


//------------------------------------------------------------
//　【 データの数の取得 】
//　return：データの数
//------------------------------------------------------------
int DoublyLinkedList::GetDataCount() const
{
	// データの数をカウントする変数
	int dataCount = 0;

	// 先頭ポインタがなければ0を返す
	if (thisPtr->nextPtr == nullptr)
	{
		return dataCount;
	}
	else
	{
		// 先頭ポインタを保存
		Node* temp = thisPtr->nextPtr;

		// 先頭分のデータを一つ確保
		dataCount++;

		// 次にあるデータがthisPtrのデータと一致するまで
		while (!(temp->nextPtr->recordData.score == 0 && temp->nextPtr->recordData.userName == ""))
		{
			// 末尾に一つ進める
			temp = temp->nextPtr;

			// データの数をカウント
			dataCount++;
		}
	}

	// データの数を返す
	return dataCount;
}


//------------------------------------------------------------
//　【 データの挿入 】
//　addIterator：追加するイテレータの情報
//　addScore：追加するデータのスコア情報
//------------------------------------------------------------
bool DoublyLinkedList::Insert(ConstIterator addConstIterator, int addScore, char* addUserName)
{
	// データ数を保持
	int dataCount = GetDataCount();

	// 挿入用の変数
	Node* temp = addConstIterator.GetConstIteratorNode();

	// 追加するデータを作成
	Node* add = new Node();
	add->recordData.score = addScore;
	add->recordData.userName = addUserName;

	if (dataCount == 0)
	{
		// データがない場合は先頭と末尾に作成したデータを設定

		// thisPtrの前後を作成したデータに設定する
		thisPtr->nextPtr = add;
		thisPtr->prevPtr = add;

		// 作成したデータとthisPtrをつなげる
		add->nextPtr = thisPtr;
		add->prevPtr = thisPtr;
	}
	else if (temp == thisPtr->nextPtr)
	{
		// 作成したデータを先頭に設定
		thisPtr->nextPtr = add;
		add->prevPtr = thisPtr;

		// 先頭だったデータとつなげる
		add->nextPtr = temp;
		temp->prevPtr = add;
	}
	else if (temp == thisPtr)
	{
		// 末尾データのノードを取得
		temp = thisPtr->prevPtr;

		temp->nextPtr = add;
		add->prevPtr = temp;

		thisPtr->prevPtr = add;
		add->nextPtr = thisPtr;
	}
	else if (temp == nullptr)
	{
		// 不正なイテレータの場合
		return false;
	}
	else
	{
		// 作成したデータの前後をつなげる
		add->nextPtr = temp;
		add->prevPtr = temp->prevPtr;

		// 作成したデータの前後のデータからつなげる
		temp->prevPtr = add;
		add->prevPtr->nextPtr = add;
	}

	return true;
}


//------------------------------------------------------------
//　【 データの挿入 】
//　addIterator：追加するイテレータの情報
//　addScore：追加するデータのスコア情報
//------------------------------------------------------------
bool DoublyLinkedList::Insert(Iterator addIterator, int addScore, char* addUserName)
{
	// データ数を保持
	int dataCount = GetDataCount();

	// 挿入用の変数
	Node* temp = addIterator.GetIteratorNode();

	// 追加するデータを作成
	Node* add = new Node();
	add->recordData.score = addScore;
	add->recordData.userName = addUserName;
	
	if (dataCount == 0)
	{
		// データがない場合は先頭と末尾に作成したデータを設定

		// thisPtrの前後を作成したデータに設定する
		thisPtr->nextPtr = add;
		thisPtr->prevPtr = add;

		// 作成したデータとthisPtrをつなげる
		add->nextPtr = thisPtr;
		add->prevPtr = thisPtr;
	}
	else if (temp == thisPtr->nextPtr)
	{
		// 作成したデータを先頭に設定
		thisPtr->nextPtr = add;
		add->prevPtr = thisPtr;

		// 先頭だったデータとつなげる
		add->nextPtr = temp;
		temp->prevPtr = add;
	}
	else if (temp == thisPtr)
	{
		// 末尾データのノードを取得
		temp = thisPtr->prevPtr;

		temp->nextPtr = add;
		add->prevPtr = temp;

		thisPtr->prevPtr = add;
		add->nextPtr = thisPtr;
	}
	else if (temp == nullptr)
	{
		// 不正なイテレータの場合
		return false;
	}
	else
	{
		// 作成したデータの前後をつなげる
		add->nextPtr = temp;
		add->prevPtr = temp->prevPtr;

		// 作成したデータの前後のデータからつなげる
		temp->prevPtr = add;
		add->prevPtr->nextPtr = add;
	}

	return true;
}


//------------------------------------------------------------
//　【 データの削除 】
//　removeIterator：削除するイテレータの情報
//------------------------------------------------------------
bool DoublyLinkedList::Remove(ConstIterator removeConstIterator)
{
	// データがなければFALSEを返す
	if (GetDataCount() == 0) return false;

	// データが一つの場合
	if (GetDataCount() == 1)
	{
		delete thisPtr->nextPtr;

		thisPtr->nextPtr = nullptr;
		thisPtr->prevPtr = nullptr;

		return true;
	}

	// データが二つ以上の場合
	// イテレータのノードを取得
	Node* temp = removeConstIterator.GetConstIteratorNode();

	if (temp == thisPtr->nextPtr)
	{
		// 先頭イテレータの場合
		thisPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = thisPtr;

		delete temp;
	}
	else if (temp == thisPtr)
	{
		// 末尾イテレータの場合はfalseを返す
		return false;
	}
	else if (temp == nullptr)
	{
		// 不正なイテレータの場合はfalseを返す
		return false;
	}
	else
	{
		// それ以外の場合
		temp->prevPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = temp->prevPtr;

		delete temp;
	}

	return true;
}


//------------------------------------------------------------
//　【 データの削除 】
//　removeIterator：削除するイテレータの情報
//------------------------------------------------------------
bool DoublyLinkedList::Remove(Iterator removeIterator)
{
	// データがなければFALSEを返す
	if (GetDataCount() == 0) return false;

	// データが一つの場合
	if (GetDataCount() == 1)
	{
		delete thisPtr->nextPtr;

		thisPtr->nextPtr = nullptr;
		thisPtr->prevPtr = nullptr;

		return true;
	}

	// データが二つ以上の場合
	// イテレータのノードを取得
	Node* temp = removeIterator.GetIteratorNode();

	if (temp == thisPtr->nextPtr)
	{
		// 先頭イテレータの場合
		thisPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = thisPtr;

		delete temp;
	}
	else if (temp == thisPtr)
	{
		// 末尾イテレータの場合はfalseを返す
		return false;
	}
	else if (temp == nullptr)
	{
		// 不正なイテレータの場合はfalseを返す
		return false;
	}
	else
	{
		// それ以外の場合
		temp->prevPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = temp->prevPtr;

		delete temp;
	}

	return true;
}


//------------------------------------------------------------
//　【 先頭イテレータ取得 】
//　return：先頭のイテレータ
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetTopIterator()
{
	// エラーチェック
	if (GetDataCount() == 0)
	{
		DoublyLinkedList::Iterator temp(thisPtr);

		// データがなければダミーノードを指すイテレータを返す
		return temp;
	}
	else
	{
		DoublyLinkedList::Iterator temp(thisPtr->nextPtr);

		// 先頭イテレータを返す
		return temp;
	}
}


//------------------------------------------------------------
//　【 先頭コンストイテレータ取得 】
//　return：先頭コンストイテレータ
//------------------------------------------------------------
DoublyLinkedList::ConstIterator DoublyLinkedList::GetTopConstIterator() const
{
	// エラーチェック
	if (GetDataCount() == 0)
	{
		DoublyLinkedList::ConstIterator temp(thisPtr);

		// データがなければダミーノードを指すイテレータを返す
		return temp;
	}
	else
	{
		DoublyLinkedList::ConstIterator temp(thisPtr->nextPtr);

		// 先頭イテレータを返す
		return temp;
	}
}


//------------------------------------------------------------
//　【 末尾イテレータ取得 】
//　return：末尾イテレータ
//------------------------------------------------------------
DoublyLinkedList::Iterator DoublyLinkedList::GetEndIterator()
{
	DoublyLinkedList::Iterator temp(thisPtr);

	// 末尾イテレータを返す
	return temp;
}


//------------------------------------------------------------
//　【 末尾コンストイテレータ取得 】
//　return：末尾コンストイテレータ
//------------------------------------------------------------
DoublyLinkedList::ConstIterator DoublyLinkedList::GetEndConstIterator() const
{
	DoublyLinkedList::ConstIterator temp(thisPtr);

	// 末尾イテレータを返す
	return temp;
}
